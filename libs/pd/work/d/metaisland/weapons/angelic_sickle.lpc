
#include <std.h>
#include <metallicana.h>
inherit WEAPON;
int weapon_hit(object atk);

void create() {
    ::create();
    set_name("Angelic Sickle");
    set_short("%^YELLOW%^Ang%^WHITE%^el%^YELLOW%^ic S%^WHITE%^ick%^YELLOW%^le");
    set_long("A magically imbued sickle wielded by the Guardian.");
    set_id(({"angelic sickle", "sickle"}));
    set_mass(68);
    set_curr_value("gold", 0);
    set_type("blade");
    set_hit ( (: weapon_hit :) );
    set_wield("%^YELLOW%^A Massive aura envelopes you.%^RESET%^\n");
    set_unwield("%^YELLOW%^The aura leaves you.%^RESET%^\n");
    set_wc(8);
    set_ac(0);
}


int weapon_hit(object atk)
{
    int result;
    if(random(290) > 160) {
        write("%^YELLOW%^The sickle glows as it slices through.%^RESET%^\n");
        say("%^YELLOW%^The sickle glows as it slices through.%^RESET%^\n");
        result=(random(50))+((this_player()->query_level()));
        result = random(result) + 51;
    }
}

int query_auto_load(){ 
    if (this_player()->query_level() > 70) return 1;
}
