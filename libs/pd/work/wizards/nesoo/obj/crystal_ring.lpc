#include <std.h>

inherit ARMOUR;

int on_wear();
int on_remove();
int twist_cmd(string);
void remove_flag(object);

void create()
{
    ::create();
    set_name("crystal ring");
    set_id(({ "ring", "crystal ring" }));
    set_short("a crystal ring");
    set_long("A rather plain looking round ring made out of " +
        "crystal.  It shimmers when it catches the light just right.");
    set_type("ring");
    set_ac(0);
    set_limbs( ({ "left hand" }) );
    set_weight(1);
    set_curr_value("gold", 20 + random(20) + random(15));
    set_wear( (: on_wear :) );
    set_remove( (: on_remove :) );
    set_property("magic item", ({ "twist" }) );
}

void init()
{
    ::init();
    add_action("twist_cmd", "twist"); // function, command
}

int on_wear()
{
    if( !this_player()->query("nes_x6272797374616C2072696E67") )
    {
        this_player()->set("nes_x6272797374616C2072696E67", 1);
        return 1;
    }
    
    message("info", "The ring refuses to slide onto your finger.",
        this_player());
    return 0;
}

int on_remove()
{
    this_player()->set("nes_x6272797374616C2072696E67", 0);
    return 1;
}

int twist_cmd(string str)
{
    string stat;
    string adj;
    int bonus;
    
    if( !query_worn() || query_worn() != this_player() )
        return 0;
    
    if( !str || !present(str, this_player()) )
        return notify_fail("Twist what?\n");
    
    if( present(str, this_player()) != this_object() )
        return 0;
    
    if( this_player()->query_disable() )
        return notify_fail("You are too busy!\n");
    
    if( this_player()->query("nes_crystal_ring_flag") )
    {
        message("info", "Nothing happens.", this_player());
        return 1;
    }
    
    switch( random(6) )
    {
        case 0:
            stat = "strength";
            adj = "stronger";
            break;
        case 1:
            stat = "dexterity";
            adj = "more nimble";
            break;
        case 2:
            stat = "charisma";
            adj = "more charming";
            break;
        case 3:
            stat = "constitution";
            adj = "hardier";
            break;
        case 4:
            stat = "intelligence";
            adj = "smarter";
            break;
        case 5:
            stat = "wisdom";
            adj = "insightful";
            break;
        default:
            stat = "charisma";
            adj = "more charming";
            break;
    }
    
    bonus = 1 + to_int(random(to_int(this_player()->query_level() / 10)));
    
    message("info", "You twist the ring, and it sparkles.\n" +
        "Suddenly, you feel " + adj +"!", this_player());
    message("info", this_player()->query_cap_name() + " twists " +
        this_player()->query_possessive() + " crystal ring. It " +
        "sparkles for a moment.", environment(this_player()),
        this_player());
    
    this_player()->set("nes_crystal_ring_flag", 1);
    this_player()->add_stat_bonus(stat, bonus, 60);
    this_player()->set_disable(1);
    call_out("remove_flag", 90, this_player());
    return 1;
}

void remove_flag(object tp)
{
    if( !tp )
        return;
    
    tp->set("nes_crystal_ring_flag", 0);
}

int query_auto_load()
{
    if( this_player()->query_level() > 35 )
        return 1;
    return 0;
}

