#include <std.h>
#include <pastarlon.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();;
     set_name("Zolenian War Hawk");;
     set_short("%^BOLD%^%^BLACK%^Zol%^RESET%^eni%^BOLD%^a%^BLACK%^n W%^RESET%^ar %^BOLD%^H%^BLACK%^awk%^RESET%^");;
     set_long("This axe is bound to a black hilt, with a sharp primary cutting edge that moves into a row of serration on the top of the blade, ending with a piercing point on the back end.");;
     set_id( ({"hawk", "zolenian war hawk", "war hawk", "axe"}) );;
     set_hands(1);;
     set_wc(11);;
     set_curr_value("gold", 250+random(35));;
     set_type("axe");;
     set_hit((:weapon_hit:));;
     set_weight(21);
}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 7) {
     write("Your %^BOLD%^%^BLACK%^Zol%^RESET%^eni%^BOLD%^a%^BLACK%^n W%^RESET%^ar %^BOLD%^H%^BLACK%^awk%^RESET%^'s serrated edge cuts deeply into your enemy, paralyzing them.");;
     say((string)""+this_player()->query_cap_name()+"'s %^BOLD%^%^BLACK%^Zol%^RESET%^eni%^BOLD%^a%^BLACK%^n W%^RESET%^ar %^BOLD%^H%^BLACK%^awk%^RESET%^ cuts deeply into their enemy.");;
result=(random(15+random(15)-random(10)))*((this_player()->query_level()/10)+1);
      result=random(result)+1;
atk->set_paralyzed(random(4));
return result;;
}
}
int query_auto_load() {
  return (this_player() && this_player()->query_level() > 29);
}

