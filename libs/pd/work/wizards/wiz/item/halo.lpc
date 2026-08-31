#include <std.h>
inherit ARMOUR;

void go_away(object ob) {
   tell_object(ob, "%^BOLD%^%^RED%^The halo dissolves into a searing mist, "
     "marking the burn on your head.");
   ob->damage(random(25));
   if (!present("burn_mark", ob))
     new("/wizards/inferno/angel/tatoo")->move(ob);
   this_object()->remove();
   return;
}

int query_auto_load() { if (this_player()->query_race() == "archangel") return 1; }

string check_wear() {
   if (this_player()->query_race() == "archangel") message("info", "%^YELLOW%^"
     "The halo floats just above your head.", this_player());
   else {
   call_out("go_away", 4, this_player());
   message("info", "%^BOLD%^RED%^The halo rests atop your head, searing and "
     "burning your forehead.", this_player());
   }
   return "";
}

int spin(string str) {
   if (str != "halo") return notify_fail("Spin what?\n");
if (!present("halo", this_player())) return 0;
if (!query_worn()) return 0;
   say(this_player()->query_cap_name()+" spins "
     +this_player()->query_title_gender()+" halo and watches it whiz around "
     +this_player()->query_title_gender()+" head.", this_player());
   write("%^BOLD%^You spin your halo and watch it whiz around your head.");
   return 1;
}

void init() {
 ::init();
   add_action("spin", "spin");
}

void create() {
 ::create();
   set_name("halo");
   set_short("%^RESET%^%^ORANGE%^a%^YELLOW%^ "
     "go%^BOLD%^%^WHITE%^ld%^RESET%^en%^BOLD%^ "
     "h%^YELLOW%^al%^RESET%^%^ORANGE%^o%^RESET%^");
   set_long("The golden halo of the angels is a holy relic symbolizing eternal "
     "peace and the power of good. Archangels, angels, and cherrubs all wear "
     "this symbol of their faith to the higher powers of good. The halo is a "
     "thin golden circlet that mystically floats above your head. A glowing aura "
     "of peace and protection radiates from the halo.");
   set_weight(0);
   set_value(0);
   set_property("no steal", 1);
   set_id(({ "halo", "golden halo", "circlet", "symbol" }));
   set_type("halo");
   set_ac(1);
   set_limbs(({ "head" }));
//   set_wear( (: check_wear() :) );
}
