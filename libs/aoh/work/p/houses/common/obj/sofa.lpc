/************************************************************/
/* This file has been done by Joern for the Woodland Domain */
/************************************************************/
/* Last Update: September 27th '94      [Joern]             */
/************************************************************/

#include <properties.h>
inherit "std/thing";

varargs void create(){
 ::create();
 SetShort("a comfy couch");
 SetLong("It looks very comfortable!\n");
 AddId("couch");
 AddId("sofa");
 AddAdjective("comfy");
 SetWeight(20000);
 SetValue(2000);
 SetNoGet("You can't steal the cow-ch!\n");
}

varargs string QueryLong() {
  return "\n\
       ______________(__)_________________    \n\
     /_______________(oo)_______________ /    \n\
     |                \\/                ||    \n\
    _|_                                _||    \n\
   /__/_______________________________/__/|   \n\
  (   )                              (   )|   \n\
   | |________________________________| | |   \n\
   \\_____________________________________/]   \n\
    []               []               []      \n\
\n\
The cow-ch looks very comfortable.\n";
}

void init() {
 ::init();
 add_action("rest","sit");
}

int rest() {
  write("You sit down on the comfortable couch.\n");
  say(capitalize(({string})this_player()->QueryName())+" sits down on the couch.\n");
  return 1;
}
