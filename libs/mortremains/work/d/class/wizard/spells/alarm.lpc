/*
** File:  alram.c
** Purpose:  1st level mage spell
** Credits:
**    20 Apr 97  Cyanide wrote this stuff on paper.
**    03 Jun 97  Cyanide FINALLY got around to creating this file.
*/

#include <mudlib.h>
#include <m_spells.h>

#define SPELL_COST 8

varargs int cast_alarm(string str, int obj) { 
  object alarm;

  seteuid(getuid());

  alarm = present("#ALARM_OB#", environment(this_player()) );
  if (alarm) {
    if (alarm->query("master") == this_player()) {
      write("You have already alarmed this area.\n");
    }
  }

  if (!obj) {
    if (!TP->cast_spell(SPELL_COST)) {
      write("You cannot muster the energies to cast that spell.\n");
      return 1;
    }
    write("You begin casting alarm...\n"); 
    say(TPN+ " begins casting...\n");
  }

  if ((environment(TP)->local_spell_effects(({"abjuration"})))==-1)
    return 1;

  alarm = clone_object(M_OBJ(alarm_ob.c));
  if (!alarm) {
    write ("Nothing happens...  Please notify Cyanide.\n");
    say ("Nothing happens.\n");
    return 1;
  }

  alarm->move(environment(TP));
  if (alarm->start_spell(this_player()) != 1) {
    write ("The nature of magic shifts a moment.\n"+
      "Please notify Cyanide.\n");
    destruct(alarm);
    return 1;
  }

  write("You successfully alarm the area.\n");
  say(TPN+" utters a strange incantation...\n");   
  return 1;
}  //end cast_alram()
string spellcraft() {
    return (@EndSpell
Alarm (Level I Wizard Spell - Abjuration, Evocation)

Cost: 8 Spell Points

This spell alerts the caster whenever somebody enters
the warded area. It will also wake a resting caster.
EndSpell
    );
}
