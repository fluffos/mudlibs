#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"sword", "blade"}));
set_name("sword");
set_short("%^RESET%^BLUE%^S%^GREEN%^w%^BLUE%^or%^BOLD%^BLACK%^d%^RESET%^BLUE%^ of C%^GREEN%^h%^BLUE%^ao%^BOLD%^BLACK%^s%^RESET%^");
set_long("%^GREEN%^The Sword of Chaos is shaped much like an enlongated butcher knife with a silver-blue blade.  It's hilt is made of pure platinum and is adorned by two sapphires and an emerald.  A black star seems to float lazily inside the large emerald.%^RESET%^");
set_value(500);
set_weight(17);
set_wc(13);
set_ac(2);
set_type("blade");
set_hit( (: this_object(), "weapon_hit" :) );
set_hands(1);
set_wield("Your mind is filled with %^RED%^c%^YELLOW%^o%^MAGENTA%^l%^ORANGE%^o%^BLUE%^r%^RED%^s%^RESET%^ that quickly melt and blend back into reality.");
set_unwield("%^YELLOW%^S%^RESET%^t%^YELLOW%^a%^RESET%^r%^YELLOW%^s%^RESET%^ momentarily flood your vision as you unwield sword.");
}

void init() {
 ::init();
   add_action("Destruct", "sell");
}

int Destruct(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   write("%^YELLOW%^As you try to sell the sword, it disolves "
         "in your hands!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
         "'s sword disovles as "+
         this_player()->query_subjective()
         +"tries to sell it!", ({ this_player() }));
   this_object()->remove();
   return 1;
}

int weapon_hit() {
   int result;
   object atk;
   atk = (object)this_player()->query_current_attacker();

if(random(100) > 90) {
      write("The sword flashes %^YELLOW%^brightly%^RESET%^ as the sword warps your foe's existence with %^BLUE%^c%^RESET%^GREEN%^h%^RESET%^BLUE%^ao%^RESET%^BLACK%^s%^RESET%^!");
      say((string)this_player()->query_cap_name()+"'s sword flashes %^YELLOW%^brightly%^RESET%^ as it strikes.");
      result = (random(55+random(50)-random(50)))*((this_player()->query_level()/20)+1);
      result=random(result)+1;
this_player()->add_sp(result);
atk->set_paralyzed(random(4));
      return result;
   }
   return 0;
}
