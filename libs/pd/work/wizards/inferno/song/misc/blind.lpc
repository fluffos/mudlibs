#include <std.h>
inherit OBJECT;

void see_again() {
   message("woohoo", "%^YELLOW%^The haze before your eyes clears.",
     environment(this_object()));
   this_object()->remove();
   return;
}

int haha() {
   if (archp(this_player())) {
     write("Your archhood just saved you from blindness.");
     this_object()->remove();
     return 0;
   }
   write("The light of the world is hidden from your eyes.");
   return 1;
}

void init() {
 ::init();
   add_action("haha", "look");
   add_action("haha", "peer");
   add_action("haha", "survey");
   add_action("haha", "peek");
}

int set_blind(int x) {
   call_out("see_again", x);
}

int query_auto_load() { return 1; }

void create() {
 ::create();
   set_name("blinder");
   set_long("You do not see that here.");
   set_short("");
   set_weight(0);
   set_value(0);
   set_blind(20);
}
