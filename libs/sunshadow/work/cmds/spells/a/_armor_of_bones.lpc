/*
  _armor_of_bones.c
  
  Bones mystery innate power.
  
  -- Tlaloc --
*/

#include <spell.h>
#include <daemons.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("armor of bones");
    set_spell_level(([ "innate" : 1 ]));
    set_spell_sphere("necromancy");
    set_mystery("bones");
    set_syntax("cast CLASS armor of bones");
    set_bonus_type(({ "armor" }));
    set_damage_desc("clevel / 10 + 1 to AC");
    set_description("You conjure a a carapace of bones to protect you from physical harm. This spell requires a corpse to be present and it consumes the corpse.");
    //set_verbal_comp();
    //set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BLACK%^%^BOLD%^" + caster->query_cap_name() + " begins to utter a macabre chant.%^RESET%^";
}

int preSpell()
{
    if(!present("corpse", place))
    {
        tell_object(caster, "You need a corpse to be present to use this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{   
    object corpse;
    
    ::spell_effect();
    
    if(!objectp(caster))
        return;
    
    corpse = present("corpse", place);
    
    if(!corpse)
    {
        tell_object(caster, "The corpse is no longer here.");
        return;
    }
    
    spell_successful();
    
    bonus = clevel / 10 + 1;
    caster->add_ac_bonus(bonus);
    
    tell_object(caster, CRAYON_D->color_string("You draw on necromantic energy to pull the bones from the corpse, forming a protective carapace around you.", "very black"));
    tell_room(place, CRAYON_D->color_string(caster->query_cap_name() + " draws on necromanctic energy to pull the bones from the corpse and form a protective carapace around " + caster->query_objective() + ".", "very black"), caster);
    
    tell_room(place, "The boneless corpse collapses into nothing.");
    corpse->remove();
    
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster, "%^BLACK%^BOLD%^The armor of bones falls from around you.%^RESET%^");
        caster->add_ac_bonus(-bonus);
    }
    
    ::dest_effect();
}
    
    
    

    