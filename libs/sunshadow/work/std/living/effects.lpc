///////////////////////////////////////////
// effects.c
//
// Modular to add a list of spells/
// poison/curses/etc that are affecting
// the player.
//
// Tlaloc
///////////////////////////////////////////


//active_effects = ([ "name": object source, "source name", "effect string" ])
//example : ([ "eyebite curse": ({ /cmds/spells/e/eyebite.c, "eyebite", "-2 cha, staggered" }) ])
//Needs to be a saved variable to avoid logout to remove
mapping active_effects;

mapping query_active_effects()
{
    if(!mapp(active_effects))
        active_effects = ([  ]);
    
    return active_effects;
}

int add_active_effect(string effect_name, object source, string source_name, string effect_string)
{
    if(!objectp(source))
        return 0;
    
    if(!strlen(effect_name))
        return 0;
    
    //Prevents duplication...have to consider this
    if(member_array(effect_name, keys(active_effects)) >= 0)
        return 0;
    
    if(!strlen(source_name))
        source_name = "Unknown";
    if(!strlen(effect_string))
        effect_string = "Unknown";
    
    active_effects += ([ effect_name : ({ source, source_name, effect_string }) ]);
    
    return 1;
}

int remove_active_effect(string effect_name)
{
    if(!strlen(effect_name))
        return 0;
    
    if(!mapp(active_effects))
        active_effects = ([  ]);
    
    map_delete(active_effects, effect_name);
    
    return 1;
}

mixed *query_effect_info(string str)
{
    if(!strlen(str))
        return ({  });
    
    if(!mapp(active_effects))
        active_effects = ([  ]);
    
    if(!pointerp(active_effects[str]))
        return ({  });
    
    return active_effects[str];
}




    