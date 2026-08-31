#include <std.h>
inherit ARMOUR;

int check_wear();

void create() {
 ::create();
   set_name("helm of justice");
   set_short("%^BOLD%^%^CYAN%^He%^WHITE%^l%^CYAN%^m of J%^BLUE%^u%^CYAN%^s%^WHITE%^t%^CYAN%^i%^BLUE%^c%^CYAN%^e%^RESET%^");
   set_id(({ "armour", "helm", "helmet", "helm of justice" }));
   set_long("The blue and silver helm has a set of small wings on "
      "each side, giving the helmet a look of speed and agility.");
   set_weight(8);
   set_curr_value("gold", 25+random(20));
   set_type("helmet");
   set_limbs(({ "head" }));
   set_ac(5);
   set_wear( (: check_wear() :) );
}

int check_wear() {
   if (this_player()->query_alignment() < 0) {
     write("You are repulsed by the goodness of this helm!");
     return 0;
   }
   write("You feel righteous with the helm upon your head.");
   return 1;
}

int query_auto_load() { if (this_player()->query_level() >= 23) return 1; }
