#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("shortsword");
     set_short("a %^BOLD%^cu%^RESET%^r%^BOLD%^v%^RESET%^e%^BOLD%^d %^RESET%^shortsword");
     set_long("This sword is very long and thin, curving slowly at the base and hooking at the very end.  It looks like it could cause quite a bit of damage.");
     set_id( ({"sword", "curved shortsword", "diranweapon", "curved sword", "shortsword"}) );
     set_mass(17);
     set_wc(13);
     set_value(50+random(50));
     set_type("sword");
     set_hands(1);
          set_material(({"iron", "titanium"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("The hook on the tip of your sword catches your enemy, wounding them greatly.");
say((string)""+this_player()->query_cap_name()+"'s sword catches on their opponent's flesh!");
result=(random(40));
return result;
}
}
