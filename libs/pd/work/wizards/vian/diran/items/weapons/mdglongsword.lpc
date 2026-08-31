#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("steel longsword");
     set_short("%^BOLD%^%^WHITE%^steel%^RESET%^ longsword");
     set_long("This two-handed blade is quite long.  The hilt has the symbol for the Diran Mountain Dwarf clan scratched into it.");
     set_id( ({"longsword", "diranweapon", "sword", "steel longsword"}) );
     set_hands(1);
     set_mass(30);
     set_wc(18);
     set_value(50+random(50));
     set_type("blade");
     set_hands(2);
          set_material(({"steel", "metal"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("Your longsword gashes deeply into your enemy.");
say((string)""+this_player()->query_cap_name()+"'s longsword gashes deeply into their opponent!");
result=(random(40));
return result;
}
}
