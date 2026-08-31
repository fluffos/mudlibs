#include <std.h>

inherit ARMOUR;

int can_wear();
int can_remove();
object tp;

void create()
{
    ::create();
    set_name("brass helmet");
    set_id(({ "helmet", "brass helmet", "dull brass helmet" }));
    set_short("dull brass helmet");
    set_long("a helmet made of brass, it is very dull and old.");
    set_type("helmet"); // "man balarm" for types
    set_ac(1);
    set_limbs( ({ "head" }) );
    set_weight(13);
    set_curr_value("gold", 6);
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
        if(!tp->query("crystal_helmet"))
        {   
            tp->set("crystal_helmet", 1);
            this_object()->set_name("crystal helmet");
            this_object()->set_short("%^BOLD%^%^WHITE%^crystal helmet%^RESET%^");
            this_object()->set_long("A helmet made of solid crystal, it reflect any light that shines on it.");
            this_object()->set_id(({ "helmet", "crystal helmet" }));
            this_object()->set_ac(12);
            message("player","%^BOLD%^%^WHITE%^Your brass helmet transforms into crystal!%^RESET%^", tp);
            message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s brass helmet transforms into crystal!%^RESET%^", environment(tp), tp);
        }
    }
    else if(tp->query("crystal_helmet"))
    {
        tp->set("crystal_helmet", 0);

        this_object()->set_name("brass helmet");
        this_object()->set_short("dull brass helmet");
        this_object()->set_long("A helmet made of brass, it is very dull and old.");
        this_object()->set_id(({ "helmet", "brass helmet", "dull brass helmet" }));
        this_object()->set_ac(1);
        message("player","%^BOLD%^%^WHITE%^Your crystal helmet transforms into brass!%^RESET%^", tp);
        message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s crystal helmet transforms into brass!%^RESET%^", environment(tp), tp);
    }

}

int can_remove()
{
    if(!this_player()) return 0;
    this_player()->set("brass_helmet", 0);
    this_object()->set_name("brass helmet");
    this_object()->set_short("dull brass helmet");
    this_object()->set_long("A helmet made of brass, it is very dull and old.");
    this_object()->set_id(({ "helmet", "brass helmet", "dull brass helmet" }));
    this_object()->set_ac(1);
    tp->set("brass_helmet", 0);
    tp->set("crystal_helmet", 0);
    set_heart_beat(0);
    return 1;
}

int can_wear()
{   
        tp = this_player();
        tp->set("brass_helmet", 1);
        set_heart_beat(1);
        return 1;
}

int query_auto_load()
{
    if (this_player()->query_level() > 19) return 1;
    return 0;
}
