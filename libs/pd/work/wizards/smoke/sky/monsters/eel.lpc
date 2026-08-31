#include <std.h>
#include <cp.h>
inherit MONSTER;

create() {
         ::create();
         set_name("electric eel");
         set_id(({ "eel", "electric eel" }));
         set_short("%^BOLD%^%^CYAN%^el%^YELLOW%^ec%^CYAN%^tr%^YELLOW%^ic %^CYAN%^e%^YELLOW%^e%^CYAN%^l%^RED%^");
         set_long("The eel swims gracefully in the pond. It lights up "
                 "occassionally to warn its predators that this is a "
                 "well-defended adversary. ");
         set_race("electric eel");
         set_class("clergy");
         set_subclass("monk");
add_limb("head", "torso", 1500, 0 ,
50);
add_limb("torso", "head", 1500, 0 ,
50);
add_limb("tail", "torso", 800, 0 ,
30);
         set("aggressive", 75);
         set_gender("neuter");
         set_level(64);
set_spell_chance(50);
         set_spells(({"stuntouch", "chistrike"}));

}
