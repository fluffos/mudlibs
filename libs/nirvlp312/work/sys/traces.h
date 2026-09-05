/*
 * traces.h defines the macros used in combination with traces
 */
#ifndef _sys_traces_h
#define _sys_traces_h

#include "server.h"

#define TR_TIME  "time"
#define TR_ROOM  "room"
#define TR_DELAY "delay"

#define TRACE_OBJECT "complex/trace"

#define IS_SE_TRACES(x) ((x) == find_object(SE_TRACES))

#endif  /* _sys_traces_h */
