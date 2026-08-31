#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("staff");    set_short("%^BOLD%^%^RED%^f%^RESET%^%^RED%^i%^YELLOW%^er%^RESET%^%^RED%^y s%^RESET%^%^RED%^t%^YELLOW%^%^BOLD%^a%^RESET%^%^RED%^f%^BOLD%^f%^RESET%^");
     set_long("This staff is made of white wood, and covered with bright red and yellow magical flames.");
     set_id( ({"staff", "diranweapon", "flaming staff"}) );
     set_mass(25);
     set_wc(17);
     set_value(50+random(50));
     set_type("blunt");
     set_hands(2);
         set_material(({"fire", "wood"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

     
}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("Your staff %^BOLD%^%^RED%shoots flames%^RESET%^ at your opponent!");
say((string)""+this_player()->query_cap_name()+"'s staff shoots flames at their foe.");
result=(random(40));
return result;
}
}
