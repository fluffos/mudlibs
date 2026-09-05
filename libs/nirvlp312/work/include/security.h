#ifndef SECURITY_H
#define SECURITY_H

#include "mudlib.h"
#include "/obj/lib/security/all.h"  /* Only TEMPORARTY */

/* Minimum security level to edit 'master' files
** 'master' objects have full file access
 */

#define MASTER_SECURITY SEC8

/* Unique objects that have 'master' file access */
#define MASTER_OBJECTS \
  ({ MASTER, SIMUL_EFUN, SPARE_SIMUL_EFUN_FILE, SECURITY_FILE, /* BIN_D */ })

/* Directories that have 'master' file access */
#define MASTER_DIRECTORIES ({ "/include/%s", })

/* Directories that are flagged as 'restricted' paths */
#define RESTRICTED_PATHS \
  ({ "/include/%s", "/obj/%s", "/usr/%s", "/secure/%s", "/inherit/%s", \
     "/function/%s", "/skills/%s", \
})

/* Cloned objects that can use 'restricted' paths */
#define RESTRICTED_PATH_OBJECTS ({ PLAYER, })

/* Files that are 'open' read access */
#define OPEN_FILES ({ WELCOME, NEWS, DEBUG_LOG, MAIN_LOG, \
  LOG_HB_ERROR, "/log/SHOUTS", "/lpmud.log", \
})

#endif /* SECURITY_H */

