#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("dress");
   set_short("%^BOLD%^%^BLUE%^a %^CYAN%^lo%^BLUE%^ve%^CYAN%^ly "
     "b%^BLUE%^lu%^CYAN%^e dr%^BLUE%^e%^CYAN%^ss%^RESET%^");
   set_id(({ "dress" }));
   set_long("An increadibly thin dress for one of small size or of an excellent "
     "figure.. or both. This dress is made of a silky light blue material.");
   set_weight(3);
    set_curr_value("silver", 300);
   set_type("dress");
   set_limbs(({ "right arm", "left arm", "left leg", "right leg",
      "torso" }));
   set_ac(1);
}

int query_auto_load() { if (this_player()->query_level() >= 3) return 1; }
