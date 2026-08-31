#include <std.h>
inherit WEAPON;

create() {
::create();
set_id(({"dagger", "red dagger"}));
  set_name("red dagger");
  set_short("A large red dagger");
  set_long("A large red dagger. Hot to the touch");
  set_mass(15);
  set_value(2000);
  set_wc(50);
  set_ac(1);
  set_type("knife");
  set_hands(1);
  set_unwield("You sigh as your hands cool down.");
  set_hit((:this_object(), "weapon_hit":));
  set_skill_level(query_wc()*30/10);
  }

int weapon_hit()
{
  int result;
  object atk;
  atk = (object)this_player()->query_current_attacker();
  if(random(102) > 85) {
    write("Your dagger sends you a soothing feeling through your body.");
    say((string)this_player()->query_cap_name()+
      "'s dagger sucks power from "
      +this_player()->query_possessive()+".");
    result=(random(155+random(50)-random(50))*((this_player()query_level()/10+10));
    result=random(result)+1
    this_player()add_hp(result);
    return result;
}
  }
