#include <spell.h>
#include <magic.h>

inherit SPELL;

#define RECAST_SPELL "/cmds/spells/m/_mind_blank"

create()
{
    ::create();
    set_spell_name("communal mind blank");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("abjuration");
    set_syntax("cast CLASS communal mind blank");
    set_description("This spell applies mind blank spell to all your followers and party members.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" chants rhythmically, "+caster->QP+" voice getting slowly lower and harder to hear.";
}

int preSpell()
{
    object * party, dude;
    object nspell;

    party = ob_party(caster) + (caster->query_followers() - caster->query_attackers()) + ({caster});

    party = distinct_array(party);

    foreach(dude in party)
    {
        nspell = new(RECAST_SPELL);
        nspell->set_silent_casting(1);
        nspell->use_spell(this_player(), dude, clevel, 100, "mage");
    }

    spell_successful();
    return 1;
}