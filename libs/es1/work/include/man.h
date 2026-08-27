/* config.h - Oct19/91 by Jubal@TMI */

/* Configuration file for the manpage reader. */


#define __MAN_CONFIG_H


/* Fairly standard definition of a null pointer */
#define NULL 0


/* This defines the directory under which the manpage hierarchy is
        found. */

#define man_root "/doc/functions"


/* This defines the list of subirectories within the man hierarchies,
        and the order in which they will be searched.  Note that a
        hierarchy need not contain every directory.  
*/

#define MAN_DIRLIST  ({ "applies", "simul_efuns", "efuns", "lfuns", "misc" })



/* EOF */
