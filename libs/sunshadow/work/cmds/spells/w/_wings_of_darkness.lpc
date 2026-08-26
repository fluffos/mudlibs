/*
  _wings_of_darkness.c

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
    set_spell_name("wings of darkness");
    set_spell_level(([ "innate" : 5 ]));
    set_spell_sphere("illusion");
    set_mystery("shadow");
    set_syntax("cast CLASS wings of darkness");
    set_damage_desc("flight ability");
    set_description("You manifest a set of translucent, inky wings that grant you the ability to fly.");
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

    if(caster->query_property("flying"))
    {
        tell_object(caster,"You're already under a similar effect!");
        this_object()->remove();
        return;
    }

    spell_successful();

    caster->set_property("added short",({"%^BOLD%^%^CYAN%^ (trailed by %^BLACK%^%^BOLD%^inky black wings%^CYAN%^)%^RESET%^"}));
    caster->set_property("flying", 1);

    tell_object(caster, CRAYON_D->color_string("You draw on the shadows around you to form a set of translucent, inky wings.", "very black"));
    tell_room(place, CRAYON_D->color_string(caster->query_cap_name() + " draws on the shadows around " + caster->query_objective() + " to form a set of translucent, inky wings.", "very black"), caster);

    addSpellToCaster();
}

void dest_effect()
{
    if(objectp(caster))
    {
        tell_object(caster, "%^BLACK%^BOLD%^The wings of darkness fade.%^RESET%^");
        tell_room(environment(caster), "%^BOLD%^%^BLACK%^The wings of darkness fade from "+caster->QCN+".%^RESET%^", caster);
        caster->remove_property_value("added short",({"%^BOLD%^%^CYAN%^ (trailed by %^BLACK%^%^BOLD%^inky black wings%^CYAN%^)%^RESET%^"}));
        caster->remove_property("flying");
    }

    ::dest_effect();
}
