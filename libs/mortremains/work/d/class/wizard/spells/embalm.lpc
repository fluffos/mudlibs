/*
**  FILE:    embalm.c
**  DATE:    August 26, 1996
**
**  PURPOSE: The level 12 power of the necromancers guild, i.e.
**               "The Dark Cabal"
**      Now a level 3 mages' necromancy spell.
**
**  CHANGES:
**    26 Aug 96    Cyanide    Created the spell.
**    15 Apr 98    Cyanide    Raped the code for his OWN mud.  ;)
*/

#include <m_spells.h>

inherit SPELL;

#define COST 35

varargs int cast_embalm (string arg, int obj) {
  object body, embalmee;
  int mass;
  string name, killer;

  seteuid(getuid());
  body = present("dead body", environment(TP));
  if (!body) {
    write("There is no corpse here for you to embalm.\n");
    return 1;
   }

  if ((body->query("embalmed")) || (body->query("undead"))) {
    write ("I don't think you need to embalm that...\n"+
      "It doesn't seem to be going anywhere anytime soon...\n");
    return 1;
   }

  name = body->query("name");
  mass = (int)(body->query("mass"));
  killer = body->query("killer");

  if (!obj)
     if (!cast_spell(TP, COST)) return 0;

  embalmee = clone_object(M_OBJ(em_corpse.c));
  embalmee->set("killer", killer);
  embalmee->set("embalmer", TPN);
  embalmee->set("name", name);
  embalmee->set("mass", mass);
  embalmee->set("embalmed", 1);
  embalmee->set("schools", ({ "alteration", "necromancy" }) );
  embalmee->set("enchanted", 2);
  embalmee->move(environment(this_player()));

  body->remove();

  write("You carefully embalm the corpse of "+name+".\n");
  say (TPN+" carefully embalms the corpse of "+name+".\n");
  return 1;
 }
string spellcraft() {
    return (@EndSpell
Embalm (Level III Wizard Spell - Necromancy)

Cost: 35 Spell Points

Necromancer's use this spell to preserve a corpse so
that it may be animated at a later time.
EndSpell
    );
}