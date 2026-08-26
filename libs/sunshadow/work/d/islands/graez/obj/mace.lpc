#include <std.h>
inherit "/d/common/obj/weapon/mace";

void create(){
   ::create();
   set_id(({"mace of undeath","unedad","mace"}));
   set_name("%^RESET%^%^BLUE%^Mace of undeath%^RESET%^");
   set_short("%^RESET%^%^BLUE%^Mace of undeath%^RESET%^");
   set_obvious_short("A black mace");
   set_long("%^C066%^This black metal footsman's mace is three feet long and the length of it is inscribed with dark runes of Nilith. The head of the mace has flanges and a heavy spike at the end. %^CRST%^");
   set_property("enchantment",4);
   set("value",500);
   set_hit((: TO,"extra_hit" :));
}



int extra_hit(object targ){
   targ = ETO->query_current_attacker();
   if(!random(5)) {
     if(ALIGN->is_good(targ)) {
       tell_object(ETO,"%^BLUE%^Your mace %^BOLD%^glows%^RESET%^%^BLUE%^ as you smite the forces of good!%^RESET%^");
	 tell_object(targ,"%^BLUE%^Your soul cries out as you are stuck by "+ETOQCN+"'s black mace!");
       tell_room(EETO,"%^BLUE%^"+targ->QCN+" cries out in agony as "+ETOQCN+" stikes "+targ->QS+" with the "
"black mace!%^RESET%^",(({ETO,targ})));
       return(roll_dice(4,6));
     }
     return 0;
   }
}
