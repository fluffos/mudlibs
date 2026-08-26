/*
** FILE:        vocalize.c
** PURPOSE:     2nd level universal spell.
** COST:        15 SP
** EFFECTS:     Allows somebody to cast when in a "silence"-ed room.
** DURATION:    1 minute/level.
** CREDITS: 
**    06 Noc 97  Cyanide created the file.
*/               

#include <m_spells.h>
#include <mudlib.h>

#define COST 15

inherit SPELL;

int cast_vocalize(string str, int obj) {
  object ob;

  seteuid(getuid());

  if ((environment(TP)->local_spell_effects(({"abjuration"})))==-1)
    return 1;

  if (present("#VOCALIZE_OB#", TP)) {
    write("You are already empowered to cast without speech.\n");
    return 0;
  }

  if (!obj) {
    if (!cast_spell(TP, COST)) return 0;

    write("You attempt to cast Vocalize.\n");
    say(TPN+" silently performs arcane gesticulations.\n");
  }

  ob = clone_object(M_OBJ(vocalize_ob));
  if (!ob) {
    write("Your spell fails.  Notify Cyanide.\n");
    say(TPN+" spells fizzles.\n");
    return 0;
  }

  ob->move(TP);
  ob->begin_spell(TP);
  return 1;
}
string spellcraft() {
    return (@EndSpell
Vocalize (Level II Wizard Spell - Universal)

Cost: 15 Spell Points

This spell allows the caster to cast while 
affected by silencing effects.
EndSpell
    );
    }
