/*
  _toll_the_dead.c
  
  Cantrip attack spell for cleric.
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("toll the dead");
    set_spell_level( ([ "cantrip" : 1 ]) );
    set_spell_sphere("necromancy");
    set_syntax("cast cantrip toll the dead on TARGET");
    set_damage_desc("negative energy damage on target on failed will save");
    set_description("You point at one creature and the sound of dolorous bells fills the air around them. They instantly feel the call of the grave, tugging at their soul. The target must make a will save or suffer negative energy damage.");
    set_target_required(1);
    set_save("will");
    set_immunities( ({ "negative energy" }) );
}

string query_cast_string()
{
    return "%^BLUE%^BOLD%^" + caster->QCN+" speaks in undulating tongues, pointing with "+caster->QP+" finger.%^RESET%^";
}

void spell_effect(int prof)
{
    int roll;
    string t_name;
    
    if(!objectp(target))
    {
        tell_object(caster, "Your target is no longer here.");
        return;
    }
       
    spell_successful();
    
    roll = do_save(target, 0);
    t_name = target->query_cap_name();
    
    if(roll)
    {
        tell_object(target, "The sound of dolorous bells fills the air, but you manage to resist their tolling!");
        tell_room(place, t_name + " resists the tolling of a myriad of bells!", target);
        return;
    }
    
    tell_room(place, "%^BLUE%^BOLD%^The tolling of dolorous bells fills the air, causing " + t_name + " to suffer the call of the grave!%^RESET%^", target);
    tell_object(target, "%^BLUE%^You are wracked with pain as a myriad of dolorous bells call you to the grave!"); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "negative energy");
    spell_kill(target, caster);
}
    
    

