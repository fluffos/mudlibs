#ifndef _BBOARD_DEFS_H
#define _BBOARD_DEFS_H

#define	F_BBOARD_NO_NOTIFY		0x0001
#define	F_BBOARD_MISC_NOTES		0x0002
#define	F_BBOARD_NO_DIRECT_ACCESS	0x0004

#define BB_READ_CODER	1
#define BB_WRITE_CODER	2
#define BB_READ_PLAYER	3
#define BB_WRITE_PLAYER	4
#define BB_READ_CLOSURE  5
#define BB_WRITE_CLOSURE  6

#define BB_INFO_HEADERS 2
#define BB_INFO_MESSAGE 3
#define BB_INFO_HELP    4
#define	BB_INFO_ALL	5
#define	BB_INFO_ALL2	6

#define CMD_BB_WRITE    1
#define CMD_BB_REMOVE   2
#define CMD_BB_POST	3

#define	BBOARD_FILE	"/std/obj/bboard"

#endif
