#ifndef _GLOBAL_H
#define _GLOBAL_H

#pragma combine_strings
// #pragma no_warn_missing_return

#include "switches.h"

#if 0
#define contents(ob) all_inventory((ob))
#define deletem(m, d) efun::m_delete((m), (d))
#define this_verb() query_verb()
#define atoi(str) to_int(str)
#define keys(m) m_indices(m)
#define mapp(m) mappingp(m)
#endif

#define DEBUG_POINT(x,a) debug((x),({ sprintf("*** line %4d, file %s", \
                                              __LINE__,__FILE__)}) +   \
                                   (pointerp(a)? (a) : (a)? ({ a }) : ({})))
#define DEBUG_POINT_TP(x,a) do {                     \
    if (this_player() &&                             \
        this_player()->query_real_name() == (x))     \
      debug((x),({ sprintf("*** line %4d, file %s",  \
                           __LINE__,__FILE__)}) +    \
                   (pointerp(a)? (a) :               \
                    (a)? ({ a }) : ({})));           \
  } while(0)

#define _D_(f,v) debug_message(sprintf("%s,%d: %s(%O)\n",__FILE__,__LINE__,f,v))

#define NOTIFY_ERROR_FULL(text,file,obj,line) \
        __MASTER_OBJECT__->runtime_error(text,file,obj,line)
#define NOTIFY_ERROR(text) \
        NOTIFY_ERROR_FULL(text,__FILE__,object_name(this_object()),__LINE__)

#define NO_WARN_MISSING_RETURN       \
        return raise_error("This code should not be reached.\n"),0

#endif /* _GLOBAL_H */
