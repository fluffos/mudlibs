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

/* This define lists the subdirectories with the man hierarchy,
    which should be searched in building the apropos database
 */
#define EXTENDED_MAN_DIR_LIST \
  ({ "/doc/functions/untroffed/lfuns", \
     "/doc/functions/untroffed/simul_efuns", \
     "/doc/driverdoc/applies", \
     "/doc/driverdoc/efuns/arrays", \
     "/doc/driverdoc/efuns/bitstrings", \
     "/doc/driverdoc/efuns/buffers", \
     "/doc/driverdoc/efuns/communication", \
     "/doc/driverdoc/efuns/core", \
     "/doc/driverdoc/efuns/debugging", \
     "/doc/driverdoc/efuns/filesystem", \
     "/doc/driverdoc/efuns/interactive", \
     "/doc/driverdoc/efuns/mappings", \
     "/doc/driverdoc/efuns/math", \
     "/doc/driverdoc/efuns/objects", \
     "/doc/driverdoc/efuns/properties", \
     "/doc/driverdoc/efuns/security", \
     "/doc/driverdoc/efuns/sockets", \
     "/doc/driverdoc/efuns/state", \
     "/doc/driverdoc/efuns/strings", \
     "/doc/driverdoc/efuns/system", \
     "/doc/driverdoc/efuns/types" })



/* EOF */
