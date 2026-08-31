#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"insideous claws", "claws", "monk claws"}));
set_name("claws");
set_short("%^BOLD%^BLUE%^I%^BOLD%^BLACK%^nsideous %^BOLD%^GREEN%^C%^BOLD%^WHITE%^laws%^RESET%^");
set_long("%^BOLD%^BLUE%^A set of razor sharp steel claws fastened upon leather wrist straps.  They offer little protection to the hands but are incredibly destructive and lightweight.  There are two claws on each hand and each measures just over a foot in length.  The claws are designed to be used in conjunction with melee combat and therefore are quite dependent upon ones melee prowess.%^RESET%^");
set_value(175);
set_weight(14);
set_wc(14);
set_ac(0);
set_type("melee");
set_hit( (: weapon_hit :) );
set_hands(2);
set_wield("%^BOLD%^BLUE%^You tighten the straps around your wrists and clench your fists in anticipation.%^RESET%^");
}

void init() {
 ::init();
   add_action("Destruct", "sell");
}

int Destruct(string str) {
   if (!str) return 0;
   if (present(str, this_player()) != this_object()) return 0;
write("%^BOLD%^GREEN%^As you try to sell the claws, they dissolve "
         "in your hands!");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
"'s claws dissolve as "+
         this_player()->query_subjective()
         +"tries to sell them!", ({ this_player() }));
   this_object()->remove();
   return 1;
}

int weapon_hit(object atk) {
   int result;
   object atk;
   atk = (object)atk;

if(random(100) > 83) {
write("%^BOLD%^BLUE%^You rake your opponent across the face with your claw!%^RESET%^");
say("%^BOLD%^BLUE%^"+(string)this_player()->query_cap_name()+"'s claw rakes its victim across the face!%^RESET%^");
result = (random(40+random(30)-random(30)))*((this_player()->query_level()/10)+1);
      result=random(result)+1;
      return result;
   }
   return 0;
}
int weapon_hit(object atk) {
   int result;
if(random(100) > 82) {
write("%^BOLD%^RED%^You crack your foe upside the skull with the palm of your hand momentarily stunning them!%^RESET%^");
result =
(random(40+random(30)-random(30)))*((this_player()->query_level()/10)+1);
      result=random(result)+1;
atk->set_paralyzed(random(4));
      return result;
   }
   return 0;
}

int query_auto_load() { if (this_player()->query_level() >= 40) return 1; }
