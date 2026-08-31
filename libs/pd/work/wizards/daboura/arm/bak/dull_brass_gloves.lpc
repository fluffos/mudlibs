#include <std.h>

inherit ARMOUR;

int can_wear();
int can_remove();
object tp;

void create()
{
    ::create();
    set_name("brass gloves");
    set_id(({ "gloves", "brass gloves", "dull brass gloves" }));
    set_short("dull brass gloves");
    set_long("gloves made of brass, they are very dull and old.");
    set_type("gloves"); // "man balarm" for types
    set_ac(1);
    set_limbs( ({ "right hand", "left hand" }) );
    set_weight(11);
    set_curr_value("gold", 3);
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
        if(!tp->query("crystal_gloves"))
        {   
            tp->set("crystal_gloves", 1);
            this_object()->set_name("crystal gloves");
            this_object()->set_short("%^BOLD%^%^WHITE%^crystal gloves%^RESET%^");
            this_object()->set_long("Gloves made of solid crystal, they reflect any light that shines on them.");
            this_object()->set_id(({ "gloves", "crystal gloves" }));
            this_object()->set_ac(5);
            message("player","%^BOLD%^%^WHITE%^Your brass gloves transform into crystal!%^RESET%^", tp);
            message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s brass gloves transform into crystal!%^RESET%^", environment(tp), tp);
        }
    }
    else if(tp->query("crystal_gloves"))
    {
        tp->set("crystal_gloves", 0);

        this_object()->set_name("brass gloves");
        this_object()->set_short("dull brass gloves");
        this_object()->set_long("Gloves made of brass, they are very dull and old.");
        this_object()->set_id(({ "gloves", "brass gloves", "dull brass gloves" }));
        this_object()->set_ac(1);
        message("player","%^BOLD%^%^WHITE%^Your crystal gloves transform into brass!%^RESET%^", tp);
        message("room", "%^BOLD%^%^WHITE%^" +tp->query_cap_name()+ "'s crystal gloves transform into brass!%^RESET%^", environment(tp), tp);
    }

}

int can_remove()
{

    tp->set("brass_gloves", 0);
    this_object()->set_name("brass gloves");
    this_object()->set_short("dull brass gloves");
    this_object()->set_long("Gloves made of brass, they are very dull and old.");
    this_object()->set_id(({ "gloves", "brass gloves", "dull brass gloves" }));
    this_object()->set_ac(1);
    tp->set("brass_gloves", 0);
    tp->set("crystal_gloves", 0);
    set_heart_beat(0);
    return 1;
}

int can_wear()
{   
        tp = this_player();
        tp->set("brass_gloves", 1);
        set_heart_beat(1);
        return 1;
}

int query_auto_load()
{
    if (this_player()->query_level() > 19) return 1;
    return 0;
}
