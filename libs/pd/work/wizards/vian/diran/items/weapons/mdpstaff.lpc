#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("staff");
     set_short("a %^BOLD%^crystal%^RESET%^ staff");
     set_long("This staff is made completely of a milky crystal.  It has a large clear stone set on top of it.");
     set_id( ({"staff", "diranweapon", "crystal staff"}) );
     set_mass(25);
     set_wc(13);
     set_value(50+random(50));
     set_type("blunt");
     set_hands(1);
          set_material(({"crystal", "stone"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("The stone on top of your staff %^BOLD%^glows brightly%^RESET%^, revitalizing your mind.");
say((string)""+this_player()->query_cap_name()+"'s staff %^BOLD%^grows brightly%^RESET%^.");
result=(random(50))+((this_player()->query_level())*2);;
        this_player()->add_mp(result);
return result;
}
}

