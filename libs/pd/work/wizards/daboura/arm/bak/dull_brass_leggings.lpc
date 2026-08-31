#include <std.h>

inherit ARMOUR;

int can_wear();
int can_remove();
object tp;

void create()
{
    ::create();
    set_name("brass leggings");
    set_id(({ "leggings", "brass leggings", "dull brass leggings" }));
    set_short("dull brass leggings");
    set_long("leggings made of brass, they are very dull and old.");
    set_type("leggings"); // "man balarm" for types
    set_ac(1);
    set_limbs( ({ "right leg", "left leg" }) );
    set_weight(21);
    set_curr_value("gold", 35);
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
        if(!tp->query("crystal_leggings"))
        {   
            tp->set("crystal_leggings", 1);
            this_object()->set_name("crystal leggings");
            this_object()->set_short("%^BOLD%^%^WHITE%^crystal leggings%^RESET%^");
            this_object()->set_long("Leggings made of solid crystal, they reflect any light that shines on them.");
            this_object()->set_id(({ "leggings", "crystal leggings" }));
            this_object()->set_ac(6);
            message("player","%^BOLD%^%^WHITE%^Your brass leggings transform into crystal!%^RESET%^", tp);
            message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s brass leggings transform into crystal!%^RESET%^", environment(tp), tp);
        }
    }
    else if(tp->query("crystal_leggings"))
    {
        tp->set("crystal_leggings", 0);

        this_object()->set_name("brass leggings");
        this_object()->set_short("dull brass leggings");
        this_object()->set_long("Leggings made of brass, they are very dull and old.");
        this_object()->set_id(({ "leggings", "brass leggings", "dull brass leggings" }));
        this_object()->set_ac(1);
        message("player","%^BOLD%^%^WHITE%^Your crystal leggings transform into brass!%^RESET%^", tp);
        message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s crystal leggings transform into brass!%^RESET%^", environment(tp), tp);
    }

}

int can_remove()
{

    tp->set("brass_leggings", 0);
    this_object()->set_name("brass leggings");
    this_object()->set_short("dull brass leggings");
    this_object()->set_long("Leggings made of brass, they are very dull and old.");
    this_object()->set_id(({ "leggings", "brass leggings", "dull brass leggings" }));
    this_object()->set_ac(1);
    tp->set("brass_leggings", 0);
    tp->set("crystal_leggings", 0);
    set_heart_beat(0);
    return 1;
}

int can_wear()
{   
        tp = this_player();
        tp->set("brass_leggings", 1);
        set_heart_beat(1);
        return 1;
}

int query_auto_load()
{
    if (this_player()->query_level() > 19) return 1;
    return 0;
}
