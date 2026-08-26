//hound belt - LoKi - 2021 
	
#include <std.h>
inherit "/std/armour";

string thread;

void create() {
   ::create();

   set_name("Hound Militia Belt");
   set_id(({"belt", "black leather belt", "officer belt","hound militia belt"}));
   set_short("%^C247%^Hou%^C094%^n%^C247%^d "+
   "Mili%^C094%^t%^C247%^ia "+
   "B%^C094%^e%^C247%^lt%^CRST%^");
   set_obvious_short("%^C246%^bla%^C094%^"+
   "c%^C246%^k leat%^C094%^h%^C246%^er belt%^CRST%^");
   set_long("%^C245%^Woven from %^C250%^black "+
   "leather%^C245%^, this belt is both "+
   "%^C142%^simple %^C245%^and "+
   "%^C192%^functional%^C245%^, without losing too "+
   "much %^C135%^style%^C245%^. It has a simple "+
   "%^C252%^ivory belt buckle%^C245%^ that is set "+
   "with two forks, one to wear the belt snug "+
   "against the waist, another to wear it low on "+
   "one hip for a %^C094%^heavy holster%^C245%^ or "+
   "%^C094%^sheath%^C245%^.%^CRST%^\n");    
   set_lore("%^C095%^Its a belt! Don't you "+
   "backcountry farmers know what simple clothing "+
   "is? Gods help us!%^C096%^\n- Captain Crenar, "+
   "Expedition Commander%^C250%^: From the "+
   "Hound Operations Manual %^CRST%^");
   set_value(5000);
   set_item_bonus("fortitude", 4);
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
