/*
  _scorching_ray.c
  
  infernal warlock/mage/sorc spell
  
  -- Tlaloc --
*/

#include <std.h>
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    
    set_spell_name("scorching ray");
    set_spell_level( ([ "warlock" : 1, "mage" : 2 ]) );
    set_heritage("infernal");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS scorching ray on TARGET");
    set_damage_desc("Fire damage to target on successful ranged touch attack");
    set_description("You blast an enemy with a searing ray of scorching fire. This spell requires a successful ranged touch attack to hit.");
    set_target_required(1);
    set_immunities( ({ "fire" }) );
}

string query_cast_string()
{
    return "%^RED%^BOLD%^" + caster->QCN+" utters an arcane spell and points with "+caster->QP+" finger.%^RESET%^";
}

int preSpell()
{
    if(!caster->ok_to_kill(target))
    {
        dest_effect();
        return 0;
    }

    return 1;
}

void spell_effect(int prof)
{
    int roll;
       
    if(!objectp(target))
    {
        tell_object(caster, "Your target is no longer here.");
        dest_effect();
        return;
    }
    
    spell_successful();
    
    roll = (int)BONUS_D->process_hit(caster, target, 1, 0, 0, 1);
    
    if(roll < 1)
    {
        tell_object(caster, "You fire a scorching ray at " + target->QCN + " but miss!");
        dest_effect();
        return;
    }
    
    tell_object(caster, "%^RED%^BOLD%^A ray of scorching fire shoots out of your finger and squarely strikes " + target->QCN + " with a spray of embers!%^RESET%^");
    tell_room(place, "%^RED%^BOLD%^" + caster->QCN + " shoots a ray of scorching fire out of " + caster->QP + " finger, striking " + target->QCN + " with a spray of embers.%^RESET%^", ({ caster })); 
    
    target->cause_typed_damage(target, target->return_target_limb(), sdamage, "fire");
    spell_kill(target, caster);
}
    
    

