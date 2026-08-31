#include <std.h>
inherit ARMOUR;

int armor_hit();

void create() {
    :: create();

    set_name("robes");
    set_short("Mage Robes");
    set_long("These robes are filled with magic, and are probably much better
than they look.");
    set_id(({"robes", "mage robes"}));
    set_ac(3);
    set_mass(30);
    set_curr_value("gold",60+random(40));
    set_type("robes");
    set_limbs(({"torso", "left arm", "right arm"}));
    set_struck((: this_object(), "armor_hit" :));
}

int armor_hit() {
  int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^RESET%^%^ORANGE%^The longsword rips peices of "+atk->query_cap_name()+" free from its body.%^RESET%^");
        say("%^RESET%^%^ORANGE%^"+(string)this_player()->query_cap_name()+"'s longsword rips out peices of "+atk->query_cap_name()+".%^RESET%^");
       
result=(80+random(50))+((this_player()->query_level()));
return result/5;
   }
}
int query_auto_load() { 
  if(this_player()->query_level() < 27) return 0;
  return 1;
}
