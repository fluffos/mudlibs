/*
** FILE:        glitter.c (Glitterdust)
** PURPOSE:     2nd level conjuration spell.
** COST:        15 SP
** EFFECTS:     Has the effect of rendering everybody in the room visible,
**              with the exception of immortals.
** DURATION:    Instantaneous.
** CREDITS: 
**    06 Nov 97  Cyanide wrote the spell.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 15

void do_dust(object);

inherit SPELL;

int cast_glitter (string str, int obj) {
    object *obs;
    int x;

    seteuid(getuid());

    if ((environment(TP)->local_spell_effects(({"conjuration"})))==-1)
	return 0;

    if (!TP->cast_spell(COST)) { 
	write(NOT_ENOUGH_SP);
	return 0;
    }
    TP->delete("power_delay");

    say(TPN+" begins casting...\n");
    write("You begin casting Glitterdust...\n");

    tell_room(environment(this_player()), "A cloud of glittering golden "+
      "particles fills the room!\n");

    obs = all_inventory(environment(this_player()));
    for (x=0;x<sizeof(obs);x++)
	if (living(obs[x])) do_dust(obs[x]);

    return 1;
}

void do_dust(object targ) {
    object ob;

    ob = present("#INVIS_OB#", targ);
    if (!wizardp(targ)) {
	if (ob) ob->remove();
	if (targ->query("invisible")) {
	    targ->set("invisible", 0);
	    targ->do_new();
	    tell_object(targ, "You are coated with the glitter, and are visible!\n");
	    tell_room(environment(targ), targ->query("cap_name") +
	      " is made visible by the glitter!\n", ({ targ }) );
	}
    }
    return;
}
string spellcraft() {
    return (@EndSpell
Glitterdust (Level II Wizard Spell - Conjuration)

Cost: 15 Spell Points

This spell renders all invisible creatures in a room visible to all.
EndSpell
    );
}
