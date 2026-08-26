
#include <m_spells.h>
#include <mudlib.h>

#define COST 20

inherit SPELL;

int cast_deadly_aim(string str, int obj) {
  object ob;

  seteuid(getuid());

  if ((environment(TP)->local_spell_effects(({"alteration"})))==-1)
    return 1;

   if (present("#TDEADLYAIM#", TP)) {
    write("You already have this spell up!\n");
    return 0;
  }

  if (!obj) {
    if (!TP->cast_spell(COST)) { 
      write(NOT_ENOUGH_SP);
    write("Your spell fails.\n");
    }

    write("You attempt to cast Tenser's Deadly Aim\n");
    say(TPN+" mumbles something in an arcane language.\n");
    obj = query_caster_level(TP, "wizard");
  }

   ob = clone_object("/d/Prime/Oerth/ghcity/spells/tdeadlyaim_ob");
  if (!ob) {
   write("Your spells fails.\n");
    return 0;
  }

  ob->move(TP);
  ob->begin_spell(TP, obj);
  return 1;
}

/* EOF */
