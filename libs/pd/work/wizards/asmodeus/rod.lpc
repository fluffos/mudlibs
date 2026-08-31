#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"rod", "tenticle rod", "golden rod", "golden tenticle rod"}));
set_name("tenticle rod");
set_short("%^YELLOW%^golden tenticle rod%^RESET%^");
set_long("A small rod measuring just over a half a meter in length and made of
pure gold.  Its perfect cylindrical shape is broken on by three small
indentations near the one of the ends.");
set_weight(8);
set_value(300);
set("skill level", 80);
set_wc(13);
set_ac(0);
set_type("blunt");
set_hands(1);
set_wield("%^YELLOW%^The rod begins to hum.%^RESET%^");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object  ob, atk;
   ob = this_object()->query_current_attacker(); 
  
atk = (object)this_player()->query_current_attacker();
if(random(100) >80) {
write("%^YELLOW%^The rod flashes brightly then comes to life!%^RESET%^");
say((string)"%^YELLOW%^"+this_player()->query_cap_name()+"'s tenticle rod flashes brightly then comes to life!%^RESET%^");
switch (random(5)) {
     case 1:  // One
       write( "A tenticle lashes out from the rod striking viciously!");
       result = (random(this_player()->query_skill("faith")/4));
       break;
     case 2:  // Two
      write( "%^ORANGE%^Two slithering tenticles lash out from the rod with devastating force!%^RESET%^");
       result = (random(this_player()->query_skill("faith")/3));
       break;
     case 3:  // Three
      write( "%^BOLD%^RED%^Three tenticles shoot forth from the rod causing horrendous damage to their target!%^RESET%^");
       result = (random(this_player()->query_skill("faith")/2));
       break;
     case 4:  // Four
       write( "%^BOLD%^BLACK%^A thundering %^BLUE%^BOOM%^BLACK%^ rings through the area as the rod blasts "+atk->query_cap_name()+" with all four tenticles!%^RESET%^");
       write("%^BOLD%^"+atk->query_cap_name()+" is left feebleminded!%^RESET%^");
        result =(random(this_player()->query_skill("faith")/2));
       break;
case 5:  // Two
      write( "%^ORANGE%^Two slithering tenticles lash out from the rod with devastating force!%^RESET%^");
       result =(random(this_player()->query_skill("faith")/3));
       break;     
     default: // One
       write( "A tenticle lashes out from the rod striking viciously!");
     result =(random(this_player()->query_skill("faith")/4));
   }



}
}
int query_auto_load() {
if(this_player()->query_race() != "drow-elf") return 0;
if(this_player()->query_subclass() != "priest") return 0;
if(this_player()->query_level() > 24) return 0;
 return 1; 
}
