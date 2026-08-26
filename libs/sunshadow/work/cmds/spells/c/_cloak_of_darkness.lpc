/*
  _cloak_of_darkness.c
  
  Shadow mystery innate power.
  
  -- Tlaloc --
*/

#include <spell.h>
#include <daemons.h>

inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("cloak of darkness");
    set_spell_level(([ "innate" : 1 ]));
    set_spell_sphere("illusion");
    set_mystery("shadow");
    set_syntax("cast CLASS cloak of darkness");
    set_bonus_type(({ "armor", "circumstance" }));
    set_damage_desc("clevel / 10 + 1 to AC. clevel / 10 + 1 to stealth skill");
    set_description("You conjure a cloak of shadowy darkness that grants you a scaling armor and stealth bonus.");
    //set_verbal_comp();
    //set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->query_cap_name() + " begins to beckon the shadows.%^RESET%^";
}

void spell_effect(int prof)
{   
    if(!objectp(caster))
        return;
    
    spell_successful();
    
    bonus = clevel / 10 + 1;
    caster->add_ac_bonus(bonus);
    caster->add_skill_bonus("stealth", bonus);
    
    tell_object(caster, CRAYON_D->color_string("You draw on the shadows around you and they wrap you in a protective cloak of darkness.", "very black"));
    tell_room(place, CRAYON_D->color_string(caster->query_cap_name() + " draws on the shadows around " + caster->query_objective() + " in a protective cloak of darkness.", "very black"), caster);
    
    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster, "%^BLACK%^BOLD%^The cloak of shadows slips from around you.%^RESET%^");
        caster->add_ac_bonus(-bonus);
        caster->add_skill_bonus("stealth", -bonus);
    }
    
    ::dest_effect();
}
    
    
    

    