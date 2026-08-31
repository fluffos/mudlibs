#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("axe");
     set_short("a %^BOLD%^%^BLACK%^Valkyrie %^RESET%^battleaxe");
     set_long("This double-headed axe has been carved with viking runes.  The handle is made of a sturdy looking wood, while the double-head is a very sharp titanium.");
     set_id( ({"axe", "valkyrie axe", "diranweapon", "double-headed axe"}) );
     set_mass(17);
     set_wc(18);
     set_value(100+random(50));
     set_type("axe");
     set_hands(2);
          set_material(({"wood", "titanium"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);
}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("You slash into your opponent with your axe, and it glows %^BOLD%^%^CYAN%^bright blue%^RESET%^, healing you.");
say((string)""+this_player()->query_cap_name()+"'s axe glows %^BOLD%^%^CYAN%^bright blue%^RESET%^.");
result=(random(40));
        this_player()->add_hp(result);
return result;
}
}
