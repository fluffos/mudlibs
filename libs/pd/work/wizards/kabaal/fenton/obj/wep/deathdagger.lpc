#include <std.h>
#include <fenton.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"dagger", "dagger of death", "death dagger", "knife"}));
set_name("Dagger of Death");
set_short("Dagger of Death");
set_long("The Dagger of Death has a long, slender blade for being a dagger.  
The handle is black with a skull and crossbones embroidered into it.");
set_value(700);
set_weight(12);
set_wc(15);
set_ac(2);
set_type("knife");
set_hit( (: this_object(), "weapon_hit" :) );
  set_wield("Something whispers to you \"Death to them all!\"");
set_unwield("The dagger won't let go.  You drop the dagger and pick it back up.");
  set_decay_rate(250);
}

void init() {
 ::init();
   add_action("Destruct", "sell");
}

int Destruct(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
   write("As you try to sell the dagger, it explodes into nothingness!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
         "'s dagger explodes as "+
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
      write("%^BOLD%^%^BLACK%^The dagger leaps out of your hands and screaches towards your enemy!%^RESET%^");
      say((string)this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^dagger%^RESET%^ leaps from their hands"
" and screaches towards their opponent!");
      result =
(random(55+random(50)-random(50)))*((this_player()->query_level()/20)+1);
      result=random(result)+1;
this_player()->add_sp(result);
atk->set_paralyzed(random(4));
      return result;
   }
   return 0;
}
