inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
    set_long("A vague shimmer in the air");
    set_name("stalker");
    set_light_limits(-50,200);  // should be in light_defs.inc
    reset_get();
}

/* This is makeing a mess for me. */
void set_racial_bonuses() 
{
}

int query_skill_bonus(int lvl, string skill) 
{
    return 0;
}

int start_player(object ob)
{
    object aura;
    if(!present("aura of menace"))
    {
        aura = clone_object("/std/races/shadows/stalker_thing");
        if(aura) aura->move(ob);
    }
    return ::start_player(ob);
}
string query_desc(object ob) 
{
    switch(ob->query_gender())
    {
    default:
    case 0: return "An invisible thing.\n";
    case 1: return "An invisible stalker (male.\n)";
    case 2: return "An invisible stalker (female.\n)";
    }
}
