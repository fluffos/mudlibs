//legion cassocks - LoKi - 2021 
	
#include <std.h>
inherit "/std/armour";

string thread;

void create() {
   ::create();
   switch (random(3)){
   case 0:
   //officer
      set_name("Pearl Legion officer cassock");
      set_id(({"cassock", "white woven cassock", "officer cassock","Pearl Legion Officer cassock"}));
      set_short("%^C231%^Pea%^C228%^r%^C231%^l "+
	  "L%^C228%^e%^C231%^gion officer casso%^C229%^c%^C231%^k%^CRST%^");
      set_obvious_short("%^C231%^e%^C228%^m%^C231%^"+
	  "br%^C249%^o%^C231%^id%^C228%^e%^C250%^r%^C231%^ed "+
	  "wh%^C228%^i%^C231%^te c%^C249%^a%^C231%^ss%^C228%^o%^C250%^c%^C231%^k%^CRST%^");
      thread = "%^C229%^gold%^CRST%^";
	  set_item_bonus("influence", 10);
   break;

   case 1:
   // academician
      set_name("Pearl Legion academician cassock");
      set_id(({"cassock", "white woven cassock", "academician cassock","Pearl Legion Academician cassock"}));
      set_short("%^C231%^Pea%^C111%^r%^C231%^l "+
	  "L%^C111%^e%^C231%^gion academician casso%^C111%^"+
	  "c%^C231%^k%^CRST%^");
      set_obvious_short("%^C231%^e%^C111%^m%^C231%^b"+
	  "r%^C249%^o%^C231%^id%^C111%^e%^C250%^r%^C231%^ed "+
	  "wh%^C111%^i%^C231%^te c%^C249%^a%^C231%^ss%^C111%^"+
	  "o%^C250%^c%^C231%^k%^CRST%^");
      thread = "%^C062%^blue%^CRST%^";
	  set_item_bonus("academics", 10);
   break;

   case 2:
   //inquisitor
      set_name("Pearl Legion inquisitor cassock");
      set_id(({"cassock", "white woven cassock", "inquisitor cassock","Pearl Legion Magus cassock"}));
      set_short("%^C231%^Pea%^C246%^r%^C231%^l L%^C247%^"+
	  "e%^C231%^gion inquisitor casso%^C247%^c%^C231%^"+
	  "k%^CRST%^");
      set_obvious_short("%^C231%^e%^C250%^m%^C231%^b"+
	  "r%^C249%^o%^C231%^ide%^C250%^r%^C231%^ed white "+
	  "c%^C249%^a%^C231%^sso%^C250%^c%^C231%^k%^CRST%^");
      thread = "%^C252%^silver%^CRST%^";
	  set_item_bonus("perception", 10);
   break;
   }
   set_long("%^C248%^This long %^C251%^cassock %^C248%^has been expertly "+
   "stitched from %^C255%^fine white cotton%^C248%^ and is quite "+
   "distinguished looking. Each panel of it though has also been "+
   "%^C247%^reinforced %^C248%^so this is obviously more than just "+
   "a simple garment. It runs all the way to the ground, but high "+
   "enough to not run along the %^C095%^ground %^C248%^and get dirty. "+
   "The %^C231%^white cloth%^C248%^ has been stitched with a "+thread+"%^C251%^ "+
   "that creates an %^C111%^intricate design%^C248%^ of flowing %^C111%^waves "+
   "%^C248%^that peak on the back of the garment where a detailed "+thread+"%^C251%^ "+
   "embroidering of a %^C231%^sphere %^C248%^with a %^C241%^shield	%^C248%^behind it.%^CRST%^\n");   
   set_lore("%^C110%^Let it be known this day that two hundred "+
   "companies have destroyed their ledgers and the Legion of "+
   "Pearl is formed in the Conclave. Long live the people of "+
   "Serakii and death to the Hounds!\n- %^C093%^Inquisitor Baltsar "+
   "Albrecht%^CRST%^: From the "+
   "Legion Reformation");
   set_weight(4);
   set_value(5000);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_property("enchantment",5);
   set_wear((:this_object(), "extra_wear":));
   set_remove((:TO,"removeme":));
   set_struck((:TO,"struck":));
}

int extra_wear(){


   return 1;    
}

int removeme() {

   	return 1;
}

int strike_fnc(int damage, object what, object who){
    if(random(1000) < 100){
        tell_room(environment(query_worn()),"%^C124%^"+
            ""+ETOQCN+" %^C124%^turns as "+who->QCN+" %^C124%^strikes "+
			"them, softening the blow!",({ETO,who}));
        tell_object(ETO,"%^C124%^You turn as "+who->QCN+" %^C124%^strikes "+
		"you, it hurts, but you're saved from the worst of it!");
        tell_object(who,"%^C124%^"+ETOQCN+" %^C124%^turns as you hit them!");
        return (damage/3);
    }
    return damage;
}

 
