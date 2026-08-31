#include <std.h>

inherit ARMOUR;

int can_wear();
int can_remove();
object tp;

void create()
{
    ::create();
    set_name("brass chest plate");
    set_id(({ "chest plate", "brass chest plate", "dull brass chest plate", "brass plate", "plate" }));
    set_short("dull brass chest plate");
    set_long("a chest plate made of brass, it is very dull and old.");
    set_type("armour"); // "man balarm" for types
    set_ac(1);
    set_limbs( ({ "right arm", "left arm", "torso" }) );
    set_weight(22);
    set_curr_value("gold", 14);
    set_wear((:can_wear:));
    set_remove((:can_remove:));

}

void heart_beat()
{
    if(!tp) return;

    if(tp->query("brass_boots") && tp->query("brass_bracers") && tp->query("brass_chest_plate")
        && tp->query("brass_gloves") && tp->query("brass_helmet") && tp->query("brass_leggings")
        && tp->query("brass_pendant") && tp->query("brass_shield"))
    {
        if(!tp->query("crystal_chest_plate"))
        {   
            tp->set("crystal_chest_plate", 1);
            this_object()->set_name("crystal chest plate");
            this_object()->set_short("%^BOLD%^%^WHITE%^crystal chest plate%^RESET%^");
            this_object()->set_long("A chest plate made of solid crystal, it reflect any light that shines on it.");
            this_object()->set_id(({ "chest plate", "crystal chest plate" }));
            this_object()->set_ac(15);
            message("player","%^BOLD%^%^WHITE%^Your brass chest plate transforms into crystal!%^RESET%^", tp);
            message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s brass chest plate transforms into crystal!%^RESET%^", environment(tp), tp);
        }
    }
    else if(tp->query("crystal_chest_plate"))
    {
        tp->set("crystal_chest_plate", 0);

        this_object()->set_name("brass chest plate");
        this_object()->set_short("dull brass chest plate");
        this_object()->set_long("A chest plate made of brass, it is very dull and old.");
        this_object()->set_id(({ "chest plate", "brass chest plate", "dull brass chest plate", "brass plate", "plate" }));
        this_object()->set_ac(1);
        message("player","%^BOLD%^%^WHITE%^Your crystal chest plate transforms into brass!%^RESET%^", tp);
        message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s crystal chest plate transforms into brass!%^RESET%^", environment(tp), tp);
    }

}

int can_remove()
{

    tp->set("brass_chest_plate", 0);
    this_object()->set_name("brass chest plate");
    this_object()->set_short("dull brass chest plate");
    this_object()->set_long("A chest plate made of brass, it is very dull and old.");
    this_object()->set_id(({ "chest plate", "brass chest plate", "dull brass chest plate", "brass plate", "plate" }));
    this_object()->set_ac(1);
    tp->set("brass_chest_plate", 0);
    tp->set("crystal_chest_plate", 0);
    set_heart_beat(0);
    return 1;
}

int can_wear()
{   
        tp = this_player();
        tp->set("brass_chest_plate", 1);
        set_heart_beat(1);
        return 1;
}

int query_auto_load()
{
    if (this_player()->query_level() > 19) return 1;
    return 0;
}
