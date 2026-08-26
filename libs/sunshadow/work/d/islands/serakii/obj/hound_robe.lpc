//hound robes - LoKi - 2021 
	
#include <std.h>
inherit "/std/armour";

string thread;

void create() {
   ::create();
   switch (random(2)){
   case 0:
   //officer
      set_name("Hound Militia Officer Robe");
      set_id(({"robe", "black woven robe", "officer robe","Hound Militia Officer Robe"}));
      set_short("%^C246%^Hou%^C228%^n%^C246%^d "+
	  "Mi%^C228%^l%^C246%^itia Offi%^C229%^"+
	  "c%^C246%^er R%^C229%^o%^C246%^be%^CRST%^");
      set_obvious_short("%^C246%^em%^C229%^"+
	  "b%^C246%^roidered bla%^C229%^c%^C246%^"+
	  "k r%^C230%^o%^C246%^be%^CRST%^");
      thread = "%^C229%^gold%^CRST%^";
	  set_item_bonus("influence", 10);
   break;

   case 1:
   // medic
      set_name("Hound Militia Medic Robe");
      set_id(({"robe", "black woven robe", "medic robe","Hound Militia Medic Robe"}));
      set_short("%^C246%^Hou%^C124%^n%^C246%^"+
	  "d Mi%^C124%^l%^C246%^itia Med%^C124%^"+
	  "i%^C246%^c R%^C124%^o%^C246%^be%^CRST%^");
      set_obvious_short("%^C246%^em%^C124%^"+
	  "b%^C246%^roidered bla%^C124%^c%^C246%^"+
	  "k r%^C124%^o%^C246%^be%^CRST%^");
      thread = "%^C124%^crimson%^CRST%^";
	  set_item_bonus("healing", 10);
   break;

   case 2:
   //magus
      set_name("Hound Militia Magus Robe");
      set_id(({"robe", "black woven robe", "magus robe","Hound Militia Magus Robe"}));
      set_short("%^C246%^Hou%^C252%^n%^C246%^"+
	  "d Mi%^C252%^l%^C246%^itia Mag%^C252%^"+
	  "u%^C246%^s R%^C252%^o%^C246%^be%^CRST%^");
      set_obvious_short("%^C246%^em%^C252%^"+
	  "b%^C246%^roidered bla%^C254%^c%^C246%^"+
	  "k r%^C254%^o%^C246%^be%^CRST%^");
      thread = "%^C252%^silver%^CRST%^";
	  set_item_bonus("spell craft", 10);
   break;
   }
   
   set_long("%^C246%^This long robe cotton has been "+
   "expertly crafted to not only protect the wearer "+
   "from the %^C027%^elements%^C246%^, but has been "+
   "reinforced at several points internally to shield "+
   "the wearer from some glancing blows. It has been "+
   "woven from %^C250%^black cotton%^C246%^ and all "+
   "along the hems is "+thread+"%^C246%^ thread. On "+
   "the back of the robe is a large "+thread+"%^C246%^ "+
   "stitching of a %^C095%^canine %^C246%^paw.%^CRST%^\n");   
   set_lore("%^C095%^There is no real regular uniform "+
   "for a Hound. When alone you will wear whatever "+
   "lets you blend in with the populous in the region "+
   "you are assigned. Once we surge you add the robe "+
   "of your group to ensure the populous understands "+
   "how many of us there are before we bring the "+
   "hammer down.%^C096%^\n- Captain Crenar, "+
   "Expedition Commander%^C250%^: From the "+
   "Hound Operations Manual %^CRST%^");
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

int strike_func(int damage, object what, object who){
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

 
