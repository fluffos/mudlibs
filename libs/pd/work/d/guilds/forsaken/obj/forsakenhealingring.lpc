#include <std.h>
#define THIS_ID "forsaken_healing_ring_id"

inherit ARMOUR;

int can_wear();
int can_remove();

void create()
{
    ::create();
    set_name("forsaken ring");
    set_short("%^BLUE%^BOLD%^F%^WHITE%^o%^BLUE%^r%^BLACK%^sa%^BLUE%^BOLD%^k%^WHITE%^e%^BLUE%^n %^BLUE%^R%^WHITE%^i%^BLACK%^n%^BLUE%^g%^RESET%^");
set_id(({ "ring", THIS_ID, "healing ring", "forsakenhealingring", "forsaken ring" }));
    set_long("%^BLACK%^BOLD%^A symbol of your membership in the %^BLUE%^For%^RESET%^sa%^BLUE%^BOLD%^ken%^BLACK%^ guild. The ring is a simple %^RESET%^o%^BLACK%^BOLD%^n%^RESET%^y%^BLACK%^BOLD%^x band, with a %^BLUE%^sw%^BLACK%^ir%^BLUE%^li%^BLACK%^n%^BLUE%^g%^BLACK%^ dark %^BLUE%^b%^RESET%^BLUE%^l%^BOLD%^u%^RESET%^BLUE%^e%^BLACK%^BOLD%^ %^WHITE%^c%^RESET%^r%^BOLD%^y%^RESET%^s%^BOLD%^t%^RESET%^a%^BOLD%^l%^BLACK%^ set into the top. The ring seems to %^WHITE%^in%^RESET%^v%^BOLD%^ig%^RESET%^or%^BOLD%^at%^RESET%^e%^BLACK%^BOLD%^ you.%^RESET%^");
    set_type("ring"); // "man balarm" for types
    set_ac(1);
    set_limbs( ({ "right hand" }) );
    set_weight(5);
set_curr_value("gold", 60000);
    set_wear((:can_wear:));
    set_remove((:can_remove:));

}
void heart_beat()
{
    object tp;
    if (!this_object()) return;
    if(this_object()->query_worn())
    {
        tp = this_object()->query_worn();
        if(random(3) == 0)
        {
            tp->add_hp(3 + random(5));
            tp->add_sp(3 + random(4));
            tp->add_mp(5 + random(7));
        }
    }
}
int can_remove()
{
    set_heart_beat(0);
    return 1;
}
int can_wear()
{
    object *rings;
    rings = filter(all_inventory(this_player()), (: ($1->id(THIS_ID) &&
$1->query_worn()) :) );
    if (!sizeof(rings))
    {
        set_heart_beat(1);
        return 1;
    }
    write("You can only wear one of that type of ring at a time!");
    return 0;
}
int query_auto_load()
{
    if(this_player()->query_guild() == "forsaken") return 1;
}
