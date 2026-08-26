#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

object *tracker = ({});
int bonus;

string color(string str)
{
    return CRAYON_D->color_string(str, "grey");
}

void create()
{
    ::create();
    set_spell_name("battlecry");
    set_spell_level(([ "innate" : 1 ]));
    set_mystery("battle");
    set_bonus_type("morale");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS battlecry");
    set_damage_desc("clevel / 22 + 1 to attack, damage bonus, clevel to hp bonus to allies");
    set_description("You raise a shout, encouraging your allies to fight harder, granting a morale bonus to attack, damage, and max hp to all of those allies.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return color(caster->query_cap_name() + " begins to raise a shout to " + caster->query_possessive() + " allies.");
}

int spell_effect()
{
    int duration;
    object * allies, ally;

    duration = ROUND_LENGTH * (clevel * 6);

    //bonus = clevel / 22 + 1;
    bonus = 1;
    
    allies = ({});
    allies = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({ caster });
    allies = distinct_array(allies);
    allies = filter_array(allies, (: environment($1) == $2 :), place);

    tell_room(place, color(caster->query_cap_name() + " shouts to the sky, encouraging those around " + caster->query_objective() + " to fight harder!"), caster);
    tell_object(caster,color("You shout to the sky, encouraging your allies around you to fight harder!"));

    foreach(ally in allies)
    {
        if(!objectp(ally))
            continue;

        if(ally->query_property("morale"))
        {
            tell_room(place,"%^RESET%^%^WHITE%^The shout washes over " + ally->query_cap_name() + "%^WHITE%^, but nothing happens.%^RESET%^");
            continue;
        }

        tell_object(ally,color("As the shout washes over you, you feel motivated to fight harder!"));
        ally->add_damage_bonus(bonus);
        ally->add_attack_bonus(bonus);
        ally->add_max_hp_bonus(clevel);
        ally->set_property("morale", 1);
        tracker += ({ally});
    }

    caster->set_property("spelled",({TO}));
    spell_successful();
    addSpellToCaster();
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect()
{
    object ally;
    foreach(ally in tracker)
    {
        if (!objectp(ally)) {
            continue;
        }

        tell_object(ally, "%^WHITE%^You feel your motivation to fight harder fade away.");

        ally->add_damage_bonus(-bonus);
        ally->add_attack_bonus(-bonus);
        ally->add_max_hp_bonus(-clevel);
        ally->remove_property("morale");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
