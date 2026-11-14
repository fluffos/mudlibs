/*
** acl.h
**
** Copyright (C) 1993 Peter Eriksson <pen@lysator.liu.se>
*/

/* Valid ACCESS rights for the ACL system */

#define ACL_ALL  0xFF
#define ACL_NONE 0x00

#define ACL_P    0x01   /* Protect, modify ACL protection */
#define ACL_D    0x02   /* Delete fsys objects from a directory */
#define ACL_A    0x04   /* Add entries to a directory */
#define ACL_L    0x08   /* List directory */
#define ACL_U    0x10   /* Use directory (can "cd" to it) */
#define ACL_R    0x20   /* Read, can read files */
#define ACL_W    0x40   /* Write, can write files */
#define ACL_X    0x80   /* eXecute, can clone_object() & load_object() */
