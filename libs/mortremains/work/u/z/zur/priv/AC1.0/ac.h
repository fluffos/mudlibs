#ifndef __AUTOCODER__
nosave string fname;
nosave string file;
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
