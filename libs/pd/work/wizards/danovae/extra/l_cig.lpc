
#include <std.h>
inherit OBJECT;

int uses;

void create() {
   ::create();
   uses = 15;

   set_name("a lit cigarette");
   set_id( ({ "cigarette","cig","smoke","marlboro" }) );
   set_short("%^BOLD%^%^WHITE%^A Lit Marlboro%^RED%^ Red%^RESET%^");
   set_long("A lit cigarette.");
   set_mass(1);
   set_curr_value("gold",0);
}

void init() {
   ::init();
   add_action("smoke","smoke");
   add_action("extinguish","extinguish");
}

int smoke(string str) {
   if(str != "cig")
   {
   notify_fail("Eh, buddy? smoke what?\n");
   return 0;
   }

   write("You take a Long blissful drag on a cigarette.");
   write("You exhale a magnificent cloud of smoke.\n");
   say(this_player()->query_cap_name()+" exhales a cloud of smoke.");
   uses--;
   if(uses > 1)
   this_object()->remove();
   write("You put out a completely used up cigarette.\n");
   return 1;
}

