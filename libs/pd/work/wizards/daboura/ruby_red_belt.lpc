
#include <std.h>

inherit ARMOUR;

int stored = 0;

void create()
{
    ::create();
    set_name("ruby red belt");
    set_id(({ "ruby red belt", "ruby belt", "red belt", "belt" }));
    set_short("%^BOLD%^%^RED%^R%^RESET%^%^RED%^ub%^BOLD%^y r%^RESET%^%^RED%^e%^BOLD%^d %^RESET%^belt");
    set_long("A large red belt with a ruby where the buckle is, the ruby is deep red in color, and rather large.");
    set_type("belt"); // "man balarm" for types
    set_ac(2);
    set_limbs( ({ "torso" }) );
    set_weight(30);
    set_curr_value("gold", 75+random(50));
    set_property("magic item", ({ "shift" }) );
    set_heart_beat(1);
}
int query_auto_load()
{
    if (this_player()->query_level() > 29) return 1;
    return 0;
}

void init()
{
    ::init();
    add_action("shift_func", "shift"); // function, command
}

void heart_beat()
{
    object tp;
    if(this_object()->query_worn()) 
    {
        tp = this_object()->query_worn();
        if(tp->query_current_attacker()) 
        {
            if(random(100) > 85)
            {
                message("info","%^BOLD%^%^RED%^Your belt's ruby flashes brightly!%^RESET%^", tp);
                message("room", "%^RED%^%^BOLD%^" +tp->query_cap_name()+ "'s belt flashes red!%^RESET%^", environment(tp), tp);
                stored = stored + 25 + random(tp->query_level());
            }
        }
    }
}

int shift_func(string str)
{
    string what;
    int num;
    object tp = this_object()->query_worn();
    
    if(!tp)
    {
        write("You must wear the belt to use it!");
        return 1;
    }
    if(tp->query_busy())
    {
        write("You are too busy to use your belt.");
        return 1;
    }
    if(!str)
    {
        write("Shift to hp, sp, or mp?");
        return 1;
    }
    
    if (sscanf(str,"to %s", what) != 1) {
        write("Shift to hp, sp, or mp?");
        return 1;
    }
    
    if(what == "hp")
    {
        if(stored < 100 + tp->query_level())
        {
            write("The ruby is too dim.");
            return 1;
        }
        num = 25 + random(tp->query_level());
        tp->add_hp(num);
        stored = stored - (num * 2);
    }
    else if(what == "sp")
    {
        if(stored < 100 + tp->query_level())
        {
            write("The ruby is too dim.");
            return 1;
        }
        num = 20 + random(tp->query_level());
        tp->add_sp(num);
        stored = stored - (num * 2);
    }
    else if(what == "mp")
    {
        if(stored < 100 + tp->query_level())
        {
            write("The ruby is too dim.");
            return 1;
        }
        num = 30 + random(tp->query_level());
        tp->add_mp(num);
        stored = stored - (num * 5 / 3);
    }
    tp->set_disable();
    write("You feel energy surge through you!");
    return 1;
}
