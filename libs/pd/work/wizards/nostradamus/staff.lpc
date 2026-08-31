#include <std.h>
inherit WEAPON;

void create() {
::create();
   set_name("staff");
set_short("A long metal staff");
   set_long("The staff is extremly light for its size.  You would "
   "think that a metal object like this would weight a ton.  It is "
    "made of a very light and very strong metal.");
   set_id(({"staff", "metal staff", "long metal staff"}));
   set_mass(100);
   set_value(1000);
   set_type("blunt");
   set_wc(30);
   set_ac(2);
   set_unwield("You unwield silver staff and you hands feel much "
    "lighter");
}
int query_auto_load() { return 1; }

 
int weapon_hit()
{
   int result;
   object atk;
   atk = (object)this_player()->query_current_attacker();
   if(random(102) > 85) {
    write("Your silver staff glows as it hits your opponent.");
    say((string)this_player()->query_cap_name()+
    "'s silver staff glows as it hits "
    +this_player()->query_possessive()+".");
    result=(random(55+random(50)-random(50))*((this_player()->query_level
    ()/20)+1));
    result=random(result)+1;
    this_player()->add_hp(result);
    return result;
    }
}
