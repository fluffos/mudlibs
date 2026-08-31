#include <std.h>
#include <purgatory.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("%^BOLD%^%^RED%^A Bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^dy %^RESET%^WHITE%^Le%^BOLD%^%^WHITE%^ath%^RESET%^%^WHITE%^er %^ORANGE%^Dress%^RESET%^");
    
    set_short("%^BOLD%^%^RED%^A Bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^dy %^RESET%^WHITE%^Le%^BOLD%^%^WHITE%^ath%^RESET%^%^WHITE%^er %^ORANGE%^Dress%^RESET%^");
    set_long("%^BOLD%^%^RED%^This dress is spattered with blood from the many struggles"
             "%^BOLD%^%^RED%^ of the children of Purgatory. %^RESET%^%^RED%^Old blood%^BOLD%^%^RED%^ and new share spaces across"
             "%^BOLD%^%^RED%^ across the bodice of this dress. ");
    set_id(({"dress"}));
    set_ac(2);
    set_mass(21);
    set_type("dress");
    set_curr_value("gold", 1);  
    set_wear("%^BOLD%^%^RED%^The Bl%^RESET%^%^RED%^oo%^BOLD%^%^RED%^dy %^RESET%^WHITE%^Le%^BOLD%^%^WHITE%^ath%^RESET%^%^WHITE%^er%^BOLD%^%^RED%^ feels really slimy now.") ;
    set_remove("%^RED%^The ickiness of the %^RESET%^WHITE%^le%^BOLD%^%^WHITE%^ath%^RESET%^%^WHITE%^er%^RED%^ stays with you as you remove the dress.");
    set_limbs(({ "torso", "right arm", "left arm", "right leg", "left leg"
}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
