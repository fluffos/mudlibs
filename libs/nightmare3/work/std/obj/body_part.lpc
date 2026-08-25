#include <std.h>

#define DECAY_TIME 100

inherit OBJECT;

int decay;
string whose,what;

void create() {
    ::create();
   set_weight(100);
   decay = 2;
   set_id(({"limb"}));
}

void set_limb(string who, string type) {
   whose = who; what = type;
   set_short(what);
   set_long("This is the " + what + " of " + whose + ".\n");
    set_id(query_id() + ({ what }));
   call_out("decay", DECAY_TIME);
}

decay() {
   decay -= 1;
   if(decay > 0) {
      call_out("decay", 20);
      return;
   }
   remove();
}

string query_short() {
   if(decay == 2)
    return "the "+what+" of "+whose;
   else
      return "the somewhat decayed " + what + " of " + whose;
}
