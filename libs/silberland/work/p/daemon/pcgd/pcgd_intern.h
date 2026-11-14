#ifndef _H_PCGD_INTERN_
#define _H_PCGD_INTERN_

#define _DEBUG_

#include "pcgd.h"

#define F_NAME_DESCRIPTION "description"
#define F_NAME_ENVIRONMENT "environment"

#define BIOME_IND_DESCRIPTION 0
#define BIOME_IND_DESCR_LONG 0
#define BIOME_IND_DESCR_LONG_BUCKET_CHANCES 0
#define BIOME_IND_DESCR_LONG_BUCKET_LINES   1
#define BIOME_IND_DESCR_SYNONYMS 1
#define BIOME_IND_DESCR_DETAILS 2

#define BIOME_IND_ENVIRONMENT 1
#define ENVIRONMENT_ALLOWED_KEYS ({"TEMPERATURE_LOWER", "TEMPERATURE_UPPER", "TERRAIN", "INDOORS"})

// states for parsing biome files state engine
#define STATE_NONE     0
#define STATE_LONG     1
#define STATE_SYNONYMS 2
#define STATE_DETAIL   3

// cache areas
#define CACHE_MAPS   0
#define CACHE_BIOMES 1

#define CACHE_E_VALUE     0
#define CACHE_E_TIMESTAMP 1

//#define CACHE_TTL 86400 // cache items are alive for 24 hours
#define CACHE_TTL 300 // ttl as test is 5 minutes

#define this this_object()

#ifdef _DEBUG_
#define DB(x) write(x);
#else 
#ifdef _DEBUG_TRACE_ 
#define DB(x) log_file("daemon/pcgd/trace", x, 50000, 2);
#else 
#define DB(x)
#endif
#endif

#endif