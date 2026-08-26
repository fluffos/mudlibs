#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("nightmare");
    set_spell_level(([ "mage" : 5, "bard":5, "innate" : 5 ]));
    set_domains("nightmare");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS nightmare on TARGET");
    set_damage_desc("mental, fatigue for clevel / 4 + 1  rounds");
    set_description("The nightmare prevents restful sleep and causes target to become fatigued for a very long period of time. Nightmare clerics casting this spell as an innate spell must expend one Divine grace point.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
    evil_spell(1);
}

string query_cast_string()
{
    return "%^RESET%^%^C055%^" + caster->QCN + " %^RESET%^%^C055%^makes a few passes in the %^RESET%^%^C087%^air%^RESET%^%^C055%^, %^RESET%^%^C057%^w%^C063%^h%^C069%^i%^C075%^s%^C081%^p%^C087%^e%^C081%^r%^C075%^i%^C063%^n%^C057%^g %^RESET%^%^C055%^in %^RESET%^%^C240%^d%^C241%^r%^C242%^e%^C241%^a%^C240%^d %^RESET%^%^C055%^undertones.%^CRST%^";
}

int preSpell() {
    
    if(caster->is_class("cleric") && spell_type == "innate")
    {
        if(!(int)USER_D->spend_pool(this_player(), 1, "grace"))
        {
            tell_object(caster, "You don't have the Divine Grace to cast Nightmare!");
            return 0;
        }
    }
    
    return 1;
}

spell_effect()
{

    if (!do_save(target, 0)) {
        if (mind_immunity_damage(target, "default")) {
            spell_successful();
            dest_effect();
            return;
        }
        "/std/effect/status/fatigued"->apply_effect(target, clevel / 4 + 1);
    }

    damage_targ(target, target->return_target_limb(), sdamage, "mental");

    tell_object(target, "%^RESET%^%^C055%^A heavy %^RESET%^%^C240%^n%^C241%^i%^C242%^g%^C243%^h%^C244%^t%^C245%^m%^C244%^a%^C243%^r%^C242%^i%^C241%^s%^C240%^h v%^RESET%^%^C241%^i%^C242%^s%^C243%^i%^C241%^o%^C240%^n %^RESET%^%^C055%^descends upon you as " + caster->QCN + " %^RESET%^%^C055%^completes the spell.%^CRST%^");
    tell_room(ENV(target), "%^RESET%^%^C055%^" + target->QCN + " %^RESET%^%^C057%^s%^C063%^h%^C069%^u%^C075%^d%^C081%^d%^C069%^e%^C063%^r%^C057%^s %^RESET%^%^C055%^and %^RESET%^%^C053%^s%^C054%^t%^C055%^a%^C056%^g%^C057%^g%^C055%^e%^C054%^r%^C053%^s %^RESET%^%^C055%^as feeling of %^RESET%^%^C240%^d%^C241%^r%^C242%^e%^C241%^a%^C240%^d %^RESET%^%^C055%^swipes by the area.%^CRST%^", target);

}
