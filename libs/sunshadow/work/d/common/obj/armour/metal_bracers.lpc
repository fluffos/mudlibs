// Chernobog (3/23/22)
// New bracers file, the random assortment in the original was conflicting with crafting

#include <std.h>

inherit ARMOUR;

int metal;

void create(){
    ::create();
    set_id(({"bracers", "bracers", "armor"}));
    set_name("bracers");
    set_short("set of metal bracers");
    set_long("%^BOLD%^%^WHITE%^These bracers are made from flawless %^RESET%^%^CYAN%^adamantium%^BOLD%^%^WHITE%^, one of the strongest substances known to the world.  The metal is highly polished and studded with all manner of %^BOLD%^%^RED%^j%^RESET%^%^ORANGE%^e%^YELLOW%^w%^GREEN%^e%^CYAN%^l%^BLUE%^s%^BOLD%^%^WHITE%^.  The inner portion of the bracers has been lined with the %^RESET%^softest wool%^BOLD%^, making the bracers exquisitely comfortable.");
    set_limbs(({"left arm", "right arm"}));
    set_ac(1);
    set_property("repairtype",({ "jewel","armorsmith" }));
    set_type("bracer");
    set_limbs(({"left arm", "right arm"}));
    set_weight(2);
    set_wear( (:TO,"check":) );
    set_size(-1);
    metal = 1;
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