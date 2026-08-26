/*
  _sacred_flame.c
  
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
    
    set_spell_name("sacred flame");
    set_spell_level( ([ "cantrip" : 1 ]) );
    set_spell_sphere("invocation_evocation");
    set_syntax("cast cantrip sacred flame on TARGET");
    set_damage_desc("radiant damage on target on failed reflex save");
    set_description("This spell attempts to burn the target with pure radiant energy. On a failed reflex save, the target takes radiant damage.");
    set_target_required(1);
    set_save("reflex");
    set_immunities( ({ "radiant" }) );
}

string query_cast_string()
{
    return "%^YELLOW%^BOLD%^" + caster->QCN+" shouts out words of a divine plea while pointing with "+caster->QP+" finger.%^RESET%^";
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
        tell_object(target, "You scramble out of the way of the sacred flame!");
        tell_room(place, "%^BOLD%^" + t_name + " scrambles out of the way of the sacred flame!", target);
        return;
    }
    
    tell_room(place, "%^YELLOW%^BOLD%^A flash of light explodes, splashing " + t_name + " with radiant energy!%^RESET%^", target);
    tell_object(target, "%^YELLOW%^A flash of light explodes, splashing you with radiant energy!"); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "radiant");
    spell_kill(target, caster);
}
    
    

