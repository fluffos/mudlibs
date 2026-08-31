#include <std.h>
#include <diran.h>
inherit WEAPON;

int weapon_hit(object atk);
void create() {::create();
     set_name("dagger");
     set_short("a serrated %^BOLD%^%^RED%^garnet%^RESET%^ dagger");
     set_long("This dagger is made of a very hard titanium alloy.  The blade is very sharp with serrated edges.  The hilt is made of platinum, with a large garnet set in the middle");
     set_id( ({"dagger", "serrated dagger", "diranweapon", "knife", "garnet dagger"}) );
     set_mass(13);
     set_wc(13);
     set_value(50+random(50));
     set_type("knife");
     set_hands(1);
          set_material(({"titanium", "platinum"}));
     set_hit((:weapon_hit:));
     set_auto_load(20);

}
int weapon_hit(object atk)
{
int result;

     if(random(100) < 20) {write("Your dagger flashes brightly as it pierces your enemy deeply, and a magical surge of energy flows through you.");
say((string)""+this_player()->query_cap_name()+"'s dagger flashes brightly!");
result=(random(50));
        this_player()->add_sp(result);
return result;
}
}
