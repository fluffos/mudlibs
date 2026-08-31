/* config.h - Oct19/91 by Jubal@TMI */

/* Configuration file for the manpage reader. */


#ifndef __MAN_CONFIG_H
#define __MAN_CONFIG_H


/* Fairly standard definition of a null pointer */
#define NULL 0


/* This defines the directory under which the manpage hierarchy is
        found. */

#define man_root "/man"


/* This defines the list of subirectories within the man hierarchies,
        and the order in which they will be searched.  Note that a
        hierarchy need not contain every directory.  All names are
        assumed to be prefixed with cat for manpages, man for whatis
        entries. */

#define man_dirlist ({ \
        "1", "w", "3", "2", "o", "l", "6", "5", "4" \
        })


#endif !__MAN_CONFIG_H


/* EOF */
