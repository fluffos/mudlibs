#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("staff");    set_short("%^RESET%^%^BLUE%^s%^BOLD%^p%^YELLOW%^ark%^BLUE%^in%^RESET%^%^BLUE%^g s%^BOLD%^t%^YELLOW%^a%^BLUE%^f%^RESET%^%^BLUE%^f%^RESET%^");
     set_long("This staff is made of white wood, with yellow and blue markings carved into it.  It seems to be emitting sparks.");
     set_id( ({"staff", "diranweapon", "sparking staff"}) );
     set_mass(25);
     set_wc(17);
     set_value(50+random(50));
     set_type("blunt");
     set_hands(2);
          set_material(({"wood", "electricity"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("Your staff %^BOLD%^%^BLUE%^sparks%^RESET%^ brightly, hitting your opponent with lightning!");
say((string)""+this_player()->query_cap_name()+"'s axe shoots lightning at their foe.");
result=(random(40));
return result;
}
}
