/* preprocessor definitions for /d/nacht/region
 * ____________________________________(i) Anatol@Silberland (1999-2012) */


#ifndef _REGION_NACHT_H_
#define _REGION_NACHT_H_

#include "../defines.h"

#define REGION_NACHT NACHT "region/"

// Tools

#define REGION_NACHT_TOOLS REGION_NACHT "tools/"
#ifdef TOOLS    
#undef TOOLS
#endif
#define TOOLS     REGION_NACHT_TOOLS

// Master

#define REGION_NACHT_MASTER REGION_NACHT "master/"
#ifdef MASTER    
#undef MASTER
#endif
#define MASTER     REGION_NACHT_MASTER

// log file directory

#define REGION_NACHT_LOG    REGION_NACHT "log/"
#ifdef LOG    
#undef LOG
#endif
#define LOG             REGION_NACHT_LOG

// don't define as SAVE, for this is used in properties.h

#define REGION_NACHT_SAVE   REGION_NACHT "save/"
#ifdef SAVEDIR
#undef SAVEDIR
#endif
#define SAVEDIR         REGION_NACHT_SAVE

#define MAP_CLIENT REGION_NACHT_MASTER "karte"
#define MAP_SERVER REGION_NACHT_MASTER "map"
#define MAP_STORE  REGION_NACHT_MASTER "map_archive"

#endif
