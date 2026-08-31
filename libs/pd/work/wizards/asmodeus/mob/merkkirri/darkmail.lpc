#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("armor");
set_short("%^RESET%^CYAN%^D%^BOLD%^BLACK%^a%^rk%^RESET%^CYAN%^M%^BOLD%^BLACK%^ail%^RESET%^");
set_long("%^BOLD%^WHITE%^A gift from the Merkkirri queen to Samul, DarkMail armor is composed of swirling dark energy that encompasses the user perfectly.  The armors exact style and design are dependent upon the person wearing it as it is scuplted according to the users darkest fears.%^RESET%^");
set_wear("%^CYAN%^You will the %^BOLD%^BLACK%^dark%^RESET%^CYAN%^ energy to envelop you.%^RESET%^");
set_remove("%^CYAN%^You will the %^BOLD%^BLACK%^dark%^RESET%^CYAN%^ energy to release you from its protection.%^RESET%^");
set_id(({"armor", "armour", "darkmail", "Darkmail"}));
set_ac(21);
set_weight(100);
set_type("armour");
set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg"}));
}
int query_auto_load() {
if (this_player()->query_level() < 35) return 0;
return 1;
 }
