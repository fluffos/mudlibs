#ifndef _QUESTS_
#define _QUESTS_

#include "config.h"

/* Configuration is mostly done within of the QUESTMASTER */

/* Quest classes used by various functions. May be combined by '|'.        */
/* Note: values must be powers of 2. If adding more, some functions must   */
/* be internally changed appropriate.                                      */

#define QT_OFFICIAL     1                               /* official quests */
#define QT_HLP          2                               /* HLP quests      */
#define QT_MINI         4                               /* Miniquests      */
#define QT_ALL          (QT_OFFICIAL|QT_HLP|QT_MINI)

#endif

