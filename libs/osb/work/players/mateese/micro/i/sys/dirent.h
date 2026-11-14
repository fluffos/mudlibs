#ifndef DIRENT_H
#define DIRENT_H 1

// get_dir() can take a second optional argument. This integer argument is a
// 3 bit mask. See the following defines for the meaning of these bits.

#define FILE_NAME    1
#define FILE_SIZE    2
#define FILE_DATE    4
#define FILE_NOSORT 32

#endif
