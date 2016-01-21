#ifndef _SYSCALL_NB_H_
#define _SYSCALL_NB_H_

typedef enum {
    SYSCALL_PUTC = 1,
    SYSCALL_PUTS = 2,
    SYSCALL_EXEC = 3,
    SYSCALL_GETC = 4,
    SYSCALL_FILE_STAT = 5,
    SYSCALL_FILE_READ = 6,
    SYSCALL_FILE_REMOVE = 7,
    SYSCALL_FILE_ITERATOR = 8,
    SYSCALL_FILE_NEXT = 9,
    SYSCALL_GET_TICKS = 10,
    SYSCALL_SET_CURSOR = 11,
    __SYSCALL_END__
} syscall_t;

#endif
