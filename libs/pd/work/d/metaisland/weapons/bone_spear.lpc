#include <std.h>
#include <metallicana.h>
inherit WEAPON;
int weapon_hit(object atk);

void create() {
    ::create();
    set_name("Bone Spear");
    set_short("%^BOLD%^BLACK%^B%^WHITE%^on%^BLACK%^e S%^WHITE%^pea%^BLACK%^r%^RESET%^");
    set_long("The long shaft is thick and sturdy, with a sharpened bone tip. The entire spear is made from bone.");
    set_id(({"bone spear", "spear"}));
    set_mass(45);
    set_curr_value("gold", 113);
    set_type("projectile");
    set_hit ( (: weapon_hit :) );
    set_wield("%^BOLD%^%^BLACK%^Clenching the Spear you feelexhilerated.%^RESET%^\n");
    set_unwield("%^BOLD%^%^BLACK%^As you let go the feeling leaves you.%^RESET%^\n");
    set_wc(9);
    set_ac(0);
}


int weapon_hit(object atk)
{
    int result;
    if(random(90) > 72) {
        write("%^BOLD%^You throw the spear, penetrating your enemys rib cage.%^RESET%^\n");
        say("%^BOLD%^"+this_player()->query_cap_name()+" throws their spear, penetrating your rib cage.%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 8;
    }
}

int query_auto_load(){                                   
    if (this_player()->query_level() > 44) return 1;
 }
