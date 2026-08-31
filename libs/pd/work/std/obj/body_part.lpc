#include <std.h>

#define DECAY_TIME 100

inherit OBJECT;

int decay;
int preserved=0;
string whose,what;

void create() {
    ::create();
   set_weight(3);
   set_property("no auction", 1);
   decay = 2;
   set_id(({"limb"}));
}

void preserve_me() { preserved = 1; }

int query_preserved() { return preserved; }

void set_limb(string who, string type) {
   whose = who; what = type;
   set_short(what);
   set_long("This is the " + what + " of " + whose + ".");
   add("id", what);
   call_out("decay", DECAY_TIME);
}

void decay() {
  if (query_preserved()) return;
   decay -= 1;
   if(decay > 0) {
      call_out("decay", 20);
      return;
   }
   if (!preserved)
     remove();
}

string query_short() {
   if(decay == 2)
    return "the "+what+" of "+whose;
   else
      return "the somewhat decayed " + what + " of " + whose;
}

int is_limb() { return 1; }
