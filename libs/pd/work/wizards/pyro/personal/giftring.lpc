#include <std.h>
inherit ARMOUR;

#define ORIG_LONG "A gift from Pyro.\n%^BOLD%^%^RED%^It is a ring crafted from pure fire. The surface of the ring is hard like stone and cool to the touch, but the very substance that the ring is made of ebbs, flows, and flickers softly as it spins about beneath the surface of the ring in small yet intricate patterns. On the front of the ring, a small amount of pure blue fire spins about in a pattern, forming the letter %^BLUE%^P%^RED%^.%^RESET%^"

string inscription;

void set_inscription(string str);

void create() {
  ::create();
  set_name("ring");
  set_short("%^BOLD%^%^RED%^P%^RESET%^%^RED%^yr%^BOLD%^o'%^YELLOW%^s ri%^RESET%^%^BOLD%^%^RED%^n%^RESET%^%^RED%^g");
  set_long(ORIG_LONG);
  set_id( ({ "ring", "Pyro's ring", "pyro's ring", "pyros ring" }) );
  set_ac(0);
  set_mass(0);
  set_curr_value("gold",0);
  set_type("ring");
  set_limbs(({"left hand", "right hand"}));
  inscription = "";
  set_property("no steal", 1);
  set_property("no auction", 1);
}

void set_inscription(string str) {
  if(str == "" || !str) {
    inscription = "";
    set_long(ORIG_LONG);
    remove_read("default");
    return;
  }
  inscription = str;
  set_long(ORIG_LONG + "\n%^BOLD%^%^BLACK%^The flames on the back of the ring seem to form letters.%^RESET%^");
  set_read("default", "%^YELLOW%^"+inscription);
}

void init_arg(mixed *args) {
  if (sizeof(args)) {
    set_inscription(args[0]);
  }
}

mixed *query_auto_load() {
  return ({ base_name(this_object()), ({
    inscription,
   })
  });
}

int drop() { return 1; }
int give() { return 1; }
