#ifndef _CONFIG_
#define _CONFIG_ 1

/* The config.h contains some very security sensible things, so it is moved
 * to /secure/config.h .
 * Pepel
 */

#include "secure/config.h"

#define DAY_LENGTH    28800  /* total length of day, in sec: 28800 sec = 8 h */
#define MAX_SUNBRIGHT   100
#define STD_WEATHER   "/std/weather"

// notify_fail() priorities

#define NOTIFY_DEFAULT     (1<<31)

#define NOTIFY_NOT_CMD    -1
#define NOTIFY_NOT_OBJ     0
#define NOTIFY_ILL_ARG     1
#define NOTIFY_NOT_VALID   2

#define NOTIFY_DO_ALL      (~(1<<31))

#endif
