#include <std.h>

inherit ARMOUR;

void create()
{
        ::create();
        set_name("Krimson Shadow");
        set_short("%^RED%^K%^BOLD%^rimson %^RESET%^%^RED%^S%^BOLD%^hadow%^RESET%^");
        set_long("The legendary cape of Luthien Bedwyr. It is said to make the wearer invisible and all shadows cast by thier fo
rm leave a krimson shadow burned into the ground");
        set_id(({"krimson shadow", "shadow", "krimson", "kshadow"}));
        set_type("cape");
        set_limbs(({"torso"}));
        set_wear((: "stuff" :));
}

int query_auto_load()
{
        return 1;
}

int stuff()
{
    say(this_player()->query_cap_name() + " seems to fade into nothingness.");
    return 1;

}
