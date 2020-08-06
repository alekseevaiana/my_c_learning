#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my_tar.h"

int add_to_archive(int fd_archive, tar_options* options)
{
    int res = 0;
    int fd_file = open(options->archive_name, O_RDONLY);
    int file_size = get_file_size(fd_file);
    int end_of_last_arch_file = file_size - (BLOCKSIZE * 2);

    res = res + write_file_content(fd_archive, options->archive_name);
    lseek(fd_archive, end_of_last_arch_file, SEEK_SET);
    res = create_archive(fd_archive, options);

    return res;
}

// prepend list with node and return new head
header_node* prepend_to_list(tar_header node, header_node* head)
{
    header_node* new_head = malloc(sizeof(header_node));

    new_head->should_add = true;
    new_head->value = node;
    new_head->next = head;

    return new_head;
}

header_node* options_to_headers(tar_options* options)
{
    t_argument* current_arg = options->args;
    header_node* head = NULL;
    tar_header* current_header;

    while (current_arg->filename != NULL)
    {
        // fullfill current arg with header-posix inform
        current_header = get_metadata(current_arg->filename);
        head = prepend_to_list(*current_header, head);
        free(current_header);
        current_arg = current_arg->next;
    }

    return head;
}

int number_from_oct(char* oct_str)
{
    return oct_to_dec(my_atoi(oct_str));
}

bool should_skip(tar_header origin, tar_header for_replace)
{
    bool is_equal_name = my_strcmp(origin.name, for_replace.name) == 0;

    if (!is_equal_name)
    {
        return false;
    }

    int origin_time = number_from_oct(origin.mtime);
    int for_replace_time = number_from_oct(for_replace.mtime);

    if (for_replace_time - origin_time < 0)
    {
        return false;
    }

    return true;
}

// 1. from arch, 2. from args
void mark_for_skip(tar_header header, header_node* list)
{
    while (list != NULL)
    {
        if (should_skip(header, list->value))
        {
            list->should_add = false;
        }
        list = list->next;
    }
}

int calc_next_position(int position, tar_header header) // <<<<<< POINTER
{
    int file_size = number_from_oct(header.size);
    int remainder = file_size % BLOCKSIZE;
    int header_size = BLOCKSIZE;

    if (remainder == 0)
    {
        return file_size + BLOCKSIZE;
    }
    else
    {
        return position + header_size + (BLOCKSIZE - remainder + file_size);
    }
}

void free_list(header_node* head)
{
    header_node* current = head;
    header_node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

// do not forget to checksum!!! your archive
int add_if_modifided(int fd_archive, tar_options* options)
{
    int res = 0;
    int pos;

    tar_header current_header;

    header_node* headers_list = options_to_headers(options);
    header_node* copy_headers_list = headers_list;
    
    int fd_file = open(options->archive_name, O_RDONLY);
    int arch_size = get_file_size(fd_file); // ok
    int end_of_arch = arch_size - (BLOCKSIZE * 2); // ok

    char buf[BLOCKSIZE];

    pos = 0;
    
    while (pos < end_of_arch)
    {
        lseek(fd_file, pos, SEEK_SET);
        read(fd_file, buf, 100);
        my_strncpy(current_header.name, buf, 100);

        lseek(fd_file, pos + 124, SEEK_SET);
        read(fd_file, buf, 12);
        my_strncpy(current_header.size, buf, 12);

        lseek(fd_file, pos + 136, SEEK_SET);
        read(fd_file, buf, 12);
        my_strncpy(current_header.mtime, buf, 12);

        mark_for_skip(current_header, headers_list);
        pos = calc_next_position(pos, current_header);
    }
    
    lseek(fd_archive, pos, SEEK_SET);
    while (headers_list != NULL)
    { 
        if (headers_list->should_add == true)
        {
            if (headers_list->value.typeflag == '5')
            {
            
                write(fd_archive, &headers_list->value, sizeof(tar_header));
                lseek(fd_archive, 12, SEEK_CUR);
                my_bzero(buf, 12);
            }
            else
            {
                write(fd_archive, &headers_list->value, sizeof(tar_header));
                my_bzero(buf, 12);
                lseek(fd_archive, 12, SEEK_CUR);
                write_file_content(fd_archive, headers_list->value.name);
            }
        }
        headers_list = headers_list->next;
    }
    end_of_archive(fd_archive);

    free_list(copy_headers_list);

    return res;
}