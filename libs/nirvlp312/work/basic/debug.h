/*
 * /basic/debug.h
 */

#idndef _basic_debug_h
#define _basic_debug_h

#ifndef NDEBUG
#  define DEBUG(x) ("/basic/debug"->debug(x))
#  define DUMP(x)  ("/basic/debug"->debug_dump(x))
#else
#  define DEBUG(x)  /* x */
#  define DUMP(x)   /* x */
#endif

#endif /* _basic_debug_h */
