// taken from old nf
// updated by magictcs - 3 jul 97

#include <properties.h>
#include <sykorath.h>

inherit "/std/thing";

create(){
 ::create();
 SetShort("a comfy couch");
 SetLong("It looks very comfortable!\n");
 AddId("couch");
 AddId("sofa");
 AddAdjective("comfy");
 SetWeight(2000);
 SetValue(2000);
 SetNoGet("You can't steal the cow-ch!\n");
}

QueryLong() {
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

init() {
 ::init();
 add_action("rest","sit");
}

rest() {
  write("You sit down on the comfortable couch.\n");
  show(NAME+" sits down on the couch.\n");
  return 1;
}

