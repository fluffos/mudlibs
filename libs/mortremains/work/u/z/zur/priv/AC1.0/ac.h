#ifndef __AUTOCODER__
// make_room.lpc declares these; base.lpc inherits it and defines AC_INHERITED before it includes this header again (macros only)
#ifndef AC_INHERITED
nosave string fname;
nosave string file;
#endif
int finish_up();
int make_int(string str) {
   int num;

   if(!str || sscanf(str, "%d", num) != 1)  return 0;

   return num;
  }
#define __AUTOCODER__    1
#endif
#include <mudlib.h>
#define TP this_player()
#define PROMPT "[-]:"
#define IPROMPT(x) "["+x+"]:"
#define TMP   "/tmp/autcoder.desc."+TP->query("name")
