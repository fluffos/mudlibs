// Chernobog (3/23/22)
// New bracers file, the random assortment in the original was conflicting with crafting

#include <std.h>

inherit ARMOUR;

int metal;

void create(){
    ::create();
    set_id(({"bracers", "bracers", "armor"}));
    set_name("bracers");
    set_short("set of wooden bracers");
    set_long("%^RESET%^%^ORANGE%^These bracers are made from sturdy oak, two halves shaped to fit about the forearms and offer some protection. They are held secure by several knotted cords, linking each set.%^RESET%^");
    set_limbs(({"left arm", "right arm"}));
    set_ac(1);
    set_property("repairtype",({ "woodworker" }));
    set_type("bracer");
    set_limbs(({"left arm", "right arm"}));
    set_weight(2);
    set_wear( (:TO,"check":) );
    set_size(-1);
    metal = 0;
}

int check(){
   int level;

   if(objectp(ETO) && ETO->query_property("no bracers")){
       tell_object(ETO,"You are currently using an object that cannot be worn with bracers.");
       return 0;
   }
   return 1;
}

int is_metal() { return metal; }