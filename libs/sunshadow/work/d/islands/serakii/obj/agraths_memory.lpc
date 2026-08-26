//Agraths Memory - LoKi 2022
#include <std.h>
inherit "/std/armour";


void create()
{
   ::create();
      set_name("Agrath's Memory");
      set_id(({"crown","bone crown","Bown Crown","agrath crown","Agrath's Memory"}));
      set_obvious_short("%^C195%^b%^C248%^o%^C250%^n%^C195%^e %^C250%^c%^C246%^r%^C195%^o%^C251%^w%^C195%^n%^CRST%^");
      set_short("%^C231%^A%^C252%^g%^C247%^r%^C231%^at%^C246%^"+
	  "h%^C231%^'s M%^C249%^e%^C251%^m%^C231%^o%^C251%^r%^C231%^y%^CRST%^");
      set_long("%^C246%^This crown is shaped completely "+
	  "out of %^C195%^bone%^C246%^, though you do not know "+
	  "how as it is in a form that is unnatural for "+
	  "a %^C195%^bone %^C246%^to grow, and there are no "+
	  "cut marks. It is as if this crown was grown or "+
	  "imagined into existence. The %^C195%^bone %^C246%^itself "+
	  "is %^C254%^pure white%^C246%^ and set into each point "+
	  "on the crown is a small perfectly cut %^C063%^s%^C057%^a%^C063%^pp%^C057%^h%^C063%^i"+
	  "r%^C069%^e%^C063%^s %^C246%^and at the front of the "+
	  "crown is a larger %^C255%^pure white diamond%^C246%^.%^RESET%^ "+
	  "%^C246%^As you turn the crown in your hand you swear you see "+
	  "different images reflected in the %^C255%^diamond %^C246%^of other "+
	  "places.%^CRST%^\n");
        set_lore("%^C066%^When the enemy struck down our "+
		"great colossus they cut down the spirit of Kismet's "+
		"angel of memory, Agrath. How Agrath was trapped by a "+
		"simple archmage is troubling to most, horrendous "+
		"and blasphemy to one such as I. How could my personal "+
		"patron, the angel of memory be lost to us bards. "+
		"Without memory we are simple jesters and "+
		"fools.%^CRST%^\n%^C068%^- An Incomplete History "+
		"of Serakii -%^CRST%^ %^C152%^Carrow Davin%^CRST%^\n");
      set_property("lore difficulty",40);      
      set_weight(3);
      set_property("repairtype",({"jewel"}));
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
      set_value(50000);
      set_type("clothing");
      set_limbs(({"head"}));
      set_ac(0);
      set_property("no curse",1);
      set_property("enchantment",5);
      set_item_bonus("intelligence", 6);
      set_item_bonus("bonus_spell_slots_8", 2);
      set_item_bonus("bonus_spell_slots_9", 1);
      set_property("no disenchant",1);
      set_property("no alter",1);
}


int wear_func(){
   object room, player;
   
   player = environment(this_object());    
   room = environment(this_object());

   tell_room(room,"%^C195%^With a slight head tilt, "+player->query_cap_name()+" %^C195%^places the crown on their head.%^CRST%^",player);
   tell_object(player,"%^C195%^You place the crown on your head and suddenly your memory is filled with random insight.%^CRST%^");
   return 1;
}

int remove_func(){
   object room, player;
   
   player = environment(this_object());    
   room = environment(this_object());

   tell_room(room,"%^C195%^As "+player->query_cap_name()+" %^C195%^pulls "+
   "off the crown they frown.%^CRST%^",player);
   tell_object(player,"%^C195%^You remove the crown and the "+
   "insight leaves you.%^CRST%^");
   return 1;
}

int is_metal() { return 0; }