
/* Danovae: 2001 - Hand of God */

#include <std.h>
inherit ARMOUR;
int wear_glove();

void create() {
   ::create();
   set_name("gauntlet");
   set_id( ({"glove","gauntlet","godhand","hand"}) );
   set_short("The Hand of God");
   set_long(
     "God will get back with you shortly."
   );
   set_ac(1);
   set_mass(9999);
   set_value(1);
   set_type("glove");
   set_limbs( ({ "right hand" }) );
   set_wear( (: wear_glove() :) );
   set_remove(
     "%^MAGENTA%^%^BOLD%^The power leaves you swiftly.%^RESET%^\n"
   );
}



void init() {
   ::init();
   add_action("zap","zap");
   add_action("dorkify","dorkify");

}

int wear_glove() {
   message("info","%^BLUE%^%^BOLD%^" +this_player()->query_cap_name()+
     " %^BOLD%^%^BLUE%^now controls the Hand of God.%^RESET%^\n",users());
   this_player()->add_skill("melee", 30);
   return 1;
}
int zap(string str) {
   if(!str || str=="") {
   notify_fail("Who do you want to zap?\n");
   return 0;
}
   write("You buzz with energy.");
   say(this_player()->query_name()+" buzzes with energy.");
   return 1;
}

int dorkify(string str) {
   if(str == "") {
   notify_fail("Who needs to be a dork?\n");
   return 0;
}
   if(!present(str)) {
   notify_fail("That person is not here.\n");
   return 0;
   }
   write("You hear the sounds of total dorkdom.");
   find_living(str)->force_me("shout I AM A DORK!!!");
   return 1;
}


