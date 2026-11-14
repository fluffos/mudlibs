/* preprocessor definitions for /d/nacht 
 * ____________________________________(i) Anatol@Silberland (1999-2012) */


#pragma strict_types

#ifndef _ANATOL_NACHT_H_
#define _ANATOL_NACHT_H_

#include "../defines.h"

#define ANATOL_NACHT NACHT "anatol/"

// log file directory (should be, on the long run, 

#define ANATOL_NACHT_LOG    ANATOL_NACHT "log/"
#ifdef LOG    
#undef LOG
#endif
#define LOG             ANATOL_NACHT_LOG

// std ...

// don't define as SAVE, for this is used in properties.h

#define ANATOL_NACHT_SAVE   ANATOL_NACHT "save/"
#ifdef SAVEDIR
#undef SAVEDIR
#endif
#define SAVEDIR         ANATOL_NACHT_SAVE


// ----------------------------------------------------------------------------

// special properties and property handling  macros

#endif
