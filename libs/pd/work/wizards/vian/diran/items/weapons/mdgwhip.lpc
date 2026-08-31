#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("staff");
     set_short("a %^BOLD%^%^BLACK%^braided%^RESET%^ whip");
     set_long("This whip is made from two long strands of leather, braided together with some sort of blue material.  It looks as if it can cause a lot of pain.");
     set_id( ({"whip", "diranweapon", "braided whip"}) );
     set_mass(15);
     set_wc(12);
     set_value(50+random(50));
     set_type("flail");
     set_hands(1);
          set_material(({"leather", "metal"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("The blue stand of your whip glows brightly as you strike your opponent.");
say((string)""+this_player()->query_cap_name()+"'s whip %^BOLD%^glows brightly%^RESET%^.");
result=(random(40));
        this_player()->add_mp(result);
return result;
}
}
