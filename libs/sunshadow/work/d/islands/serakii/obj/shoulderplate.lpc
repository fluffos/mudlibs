//Mantle of the Lion shoulderplates - 
#include <std.h>;
inherit ARMOUR;

void create(){
    ::create();
    set_name("shoulder plates");
    set_id(({"shoulderplates","shoulder plates","plate","plates",
"ornate golden shoulderplates","mantle of the lion"}));
    set_obvious_short("%^RESET%^%^YELLOW%^or%^RESET%^%^ORANGE%^n%^RESET%^%^YELLOW%^a"+
"%^RESET%^%^WHITE%^te%^RESET%^%^YELLOW%^ gol%^RESET%^%^ORANGE%^d%^RESET%^%^WHITE%^"+
"e%^RESET%^%^YELLOW%^n shou%^RESET%^%^ORANGE%^l%^RESET%^%^YELLOW%^der%^RESET%^"+
"%^WHITE%^p%^RESET%^%^YELLOW%^late%^RESET%^%^ORANGE%^s%^RESET%^");
    set_short("%^RESET%^%^YELLOW%^M%^RESET%^%^WHITE%^a%^RESET%^%^YELLOW%^ntle of "+
"t%^RESET%^%^WHITE%^h%^RESET%^%^YELLOW%^e Li%^RESET%^%^ORANGE%^o%^RESET%^"+
"%^YELLOW%^n%^RESET%^");
    set_long("%^RESET%^%^YELLOW%^These shoulder plates are crafted from go"+
"%^RESET%^%^ORANGE%^l%^RESET%^%^YELLOW%^d and extend from each shoulder on "+
"the wearer a foot and a half. The two shoulder plates attach together with "+
"a small plate at the front which may be worn over armor, yet would stop the "+
"wearer from wearing either a necklace or cape.  Each shoulder plate is adorned"+
" with a detailed relief of %^RESET%^%^ORANGE%^lions %^RESET%^%^YELLOW%^carved "+
"into the gold and inset with precious gems. The front plate is shaped as a head"+
" of a %^RESET%^%^ORANGE%^lion %^RESET%^%^YELLOW%^with it's jaw opened in a "+
"perpetual roar.%^RESET%^");
    set_lore("%^RESET%^%^YELLOW%^Legend tells of a templar of Jarmila named Devinn"+
" Bergan who served his patron Jarmila in a crusade against the Lich Sorceress Siilak."+
" Despite the uncountable undead swarming over the Jarmilian position in the last"+
" battle, Devinn stood alone on the ramparts and single handedly held off the undead"+
" for several hours, allowing the safe retreat of the entire settlement of refugees."+
" It is said that in the moment Devinn fell, Jarmila intervened and elevated the fallen"+
" warrior to the host of devas.%^RESET%^");
    set_property("lore difficulty",16);
    set_weight(5);
    set_limbs(({"neck"}));
    set_type("clothing");
        set_value(20000);
    set_ac(2);
    set_property("enchantment",5);
    set_item_bonus("strength",4); 
    set_wear((:TO, "extra_wear":));
    set_remove("%^RESET%^%^ORANGE%^You unlatch the shoulderplates and slip them off.");
}
int extra_wear() {
    if((int)ETO->query_lowest_level() < 30) {
	tell_object(ETO,"%^RESET%^%^RED%^This is the armor of an experienced "+
         "warrior...  You are not ready.%^RESET%^");
	return 0;
    }
    tell_object(ETO,"%^RESET%^%^ORANGE%^You slip the gold shoulderplates "+
         "onto over your shoulders and attach them to the front plate.%^RESET%^");
    return 1;
}
