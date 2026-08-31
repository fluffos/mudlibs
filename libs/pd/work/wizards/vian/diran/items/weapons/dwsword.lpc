#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("sword");
     set_short("an %^BOLD%^%^BLACK%^onyx%^RESET%^ and %^BOLD%^%^BLUE%^lapis%^RESET%^ sword");
     set_long("This sword is made from a very dark and shiny onyx.  There are small lapis stones set along the handle which shimmer even without light.");
     set_id( ({"sword", "diranweapon", "lapis sword", "onyx and lapis sword", "onyx sword"}) );
     set_mass(14);
     set_wc(13);
     set_value(50+random(50));
     set_type("blade");
     set_hands(1);
     set_material(({"onyx", "lapis"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("The lapis stones on your sword glow brightly as you feel revitalized.");
say((string)""+this_player()->query_cap_name()+"'s sword glows bright %^BLUE%^blue%^RESET%^.");
result=(random(40));
        this_player()->add_sp(result);
return result;
}
}
