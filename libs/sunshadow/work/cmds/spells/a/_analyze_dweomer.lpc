#include <spell.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("analyze dweomer");
    set_spell_level(([ "mage" : 6, "bard" : 6, "cleric" : 6 ]));
    set_domains("magic");
    set_spell_sphere("divination");
    set_syntax("cast CLASS analyze dweomer on TARGET");
    set_description("This spell allows you to sense what spells and magical afflictions affect the target. If the target passes their save they will know the caster has analyzed them with a magic probe.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_helpful_spell(1);
    set_save("will");
    diminish_returns();
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " closes their eyes while chanting.%^RESET%^";
}

void spell_effect()
{
    object* slist, spl;
    spell_successful();

    if (do_save(target, 0)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^"+target->query_cap_name()+" %^BOLD%^%^CYAN%^shakes off your attempt to analyze them.");
        tell_object(target, "%^BOLD%^%^CYAN%^You sense a magical probe from "+caster->query_cap_name()+" %^BOLD%^%^CYAN%^trying to analyze your spells.");
        dest_effect();
        return;
    }

    slist = target->query_property("dispellable spells") + target->query_property("spelled");
    if (!sizeof(slist)) {
        tell_object(caster, "%^BOLD%^%^CYAN%^You sense no spells are affecting the target.");
        dest_effect();
        return;
    }
    slist = distinct_array(slist);

    tell_object(caster, "%^BOLD%^%^CYAN%^You sense the following spells:");
    foreach(spl in slist)
    {
        if (!objectp(spl)) {
            continue;
        }
        tell_object(caster, "  %^BOLD%^%^GREEN%^" + spl->query_name());
    }
}
