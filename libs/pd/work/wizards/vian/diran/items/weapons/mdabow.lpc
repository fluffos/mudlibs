#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("spiked steel bow");
     set_short("%^BOLD%^%^BLACK%^spiked steel%^RESET%^ bow");
     set_long("This bow is made of a shining dark steel.  It has long spikes on the top of it, and looks like it could be used as a fair weapon even without arrows.");
     set_id( ({"bow", "steel bow", "diranweapon", "spiked steel bow"}) );
     set_mass(30);
     set_wc(16);
     set_value(50+random(50));
     set_type("blunt");
     set_hands(2);
          set_material(({"steel", "spikes"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("You push the spikes on the top of your boe into your enemy!");
say((string)""+this_player()->query_cap_name()+" pushes the spikes on top of their bow into their opponent!");
result=(random(40));
return result;
}
}
