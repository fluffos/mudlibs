//legion sash - LoKi - 2021 
	
#include <std.h>
inherit "/std/armour";

string thread;

void create() {
   ::create();

   set_name("Legion Sash");
   set_id(({"sash", "blue silk sash", "officer sash","pearl legion sash"}));
   set_short("%^C063%^P%^C250%^e%^C063%^arl "+
   "Leg%^C249%^i%^C063%^on o%^C110%^f%^C063%^ficer's "+
   "sa%^C111%^s%^C063%^h%^CRST%^");
   set_obvious_short("%^C063%^bl%^C111%^u%^C063%^e si%^C110%^"+
   "l%^C063%^k s%^C110%^a%^C063%^sh%^CRST%^");
   set_long("%^C063%^This deceptively simple sash of "+
   "%^C056%^blue silk%^C063%^ is long enough to wrap several "+
   "times around the waist and has a %^C250%^clasp %^C063%^in "+
   "the shape of a %^C245%^shield %^C063%^made of %^C251%^"+
   "pea%^C255%^r%^C251%^l %^C063%^to attach at the wearer's "+
   "side. The silk itself is a %^C111%^brilliant colour%^C063%^ "+
   "and would be quite striking against %^C248%^armour%^C063%^.%^CRST%^\n");    
   set_lore("%^C110%^It is said that the officer sashes were made from all "+
   "of the flags from the fallen companies. They cut them up, redyed them "+
   "and that is why an officer's sash is so important to them. A little "+
   "piece of lost brothers and sisters.\n- %^C093%^Quartermaster "+
   "Hartmannus%^CRST%^: Personal Diary");
   set_value(5000);
   set_item_bonus("will", 4);
   set_weight(4);
   set_value(5000);
   set_type("clothing");
   set_limbs(({"waist"}));
   set_property("enchantment",4);
   set_wear((:this_object(), "extra_wear":));
   set_remove((:TO,"removeme":));
}

int is_metal() { return 0; }

int extra_wear(){


   return 1;    
}

int removeme() {

   	return 1;
}
