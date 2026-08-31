#include <std.h>

#define THIS_ID "special_healing_ring_id"

inherit ARMOUR;

int can_wear();
int can_remove();

void create()
{
    ::create();
    set_name("healing ring");
    set_id(({ "ring", THIS_ID, "healing ring", "golden ring" }));
    set_short("small golden ring");
    set_long("A very small golden ring, it glows a very soft blue.");
    set_type("ring"); // "man balarm" for types
    set_ac(1);
    set_limbs( ({ "right hand" }) );
    set_weight(5);
    set_curr_value("gold", 10000);
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
    rings = filter(all_inventory(this_player()), (: ($1->id(THIS_ID) && $1->query_worn()) :) );
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
    if (this_player()->query_level() > 5) return 1;
    return 0;
}
