#include <std.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("detect thoughts");
    set_spell_level(([ "bard":2, "inquisitor":2, "mage":2]));
    set_spell_sphere("divination");
    set_damage_desc("indicates presence of telepathic communication in the area");
    set_save("will");
    set_syntax("cast CLASS detect thoughts");
    set_description("This spell allows you to detect who is communicating with whom in the area. This detection is identified with a save, and if the difference between the intelligence scores of the listener and target is too high it will leave the listener stunned and end the spell. This version of the spell doesn't allow you to discern what is being spoken.");

    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell() {
    if (caster->query_property("detecting_thoughts")) {
        tell_object(caster, "You are already detecting thoughts.");
        return 0;
    }
    return 1;
}

spell_effect()
{
    tell_object(caster,"%^CYAN%^You quickly touch your temples, attuning yourself to detect the presence of telepathic communication.");
    tell_room(place, "%^CYAN%^" + caster->QCN + " quickly touches " + caster->QP + " temples.", caster);

    spell_successful();
    caster->set_property("spelled", ({ TO }) );
    caster->set_property("detecting_thoughts", TO);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

dest_effect()
{
    if (objectp(caster)) {
        if (caster->query_property("detecting_thoughts")) {
            caster->remove_property("detecting_thoughts");
            tell_object(caster,"%^CYAN%^You sense you lose your grasp on detecting thoughts.");
        }
    }

    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
