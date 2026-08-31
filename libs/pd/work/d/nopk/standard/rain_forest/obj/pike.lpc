#include <std.h>
#include <rain.h>
inherit WEAPON;
int weapon_hit(object atk);

create() {
   ::create();
   set_name("pike");
   set_short("A %^BOLD%^%^BLUE%^royal%^RESET%^ pike");
   set_wc(6);
   set_curr_value("gold", 58);
   set_type("projectile");
   set_mass(18);
   set_hands(2);
   set_id(({"pike", "royal pike"}));
   set_long("This is a long %^BOLD%^%^BLUE%^royal%^RESET%^ pike. "
            "its total length is around 5 feet. It is strong but "
            "sturdy");
 set_hit((:weapon_hit:));
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 15) {
write("The pike flies out of your hand hitting your opponent.");
say("The pike flies out of "+ this_player()->query_cap_name() +"'s hand "
    "and hits their opponent, shattering on impact.");
result=(random(100))+((this_player()->query_level()));
this_object()->remove();
return result;
}
}
