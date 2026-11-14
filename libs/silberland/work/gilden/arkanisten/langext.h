/*
* This header implements several language extensions that may be useful for LPC.
*
* 1. `bool` datatype:
*    The datatype `bool` can be used (it is an alias for int) as well as true (1) and false (0),
*
* 2. `foreach` function example:
     foreach(name, names, {
        write("Hello, " + name + "!\n");
    });
*/

#ifndef _H_LANGEXT_
#define _H_LANGEXT_

// boolean type
#ifndef true
#define true 1
#endif

#ifndef false 
#define false 0
#endif

#define bool int

// foreach
#define foreach(idx, list, item, block) \
  for (idx = 0; idx < sizeof(list); ++idx) { \
    item = list[idx]; \
    block; \
  }

#endif