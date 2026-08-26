/*
** File:  invis_ob.c
** Purpose:  Spell object for 1st level wizard "invis" spell.
** Credits:
**    06 Nov 97  Cyanide created the spell.
*/

#include <magic.h>
#include <mudlib.h>

inherit OBJECT;

object subject = this_object();
int called = 0;

void create() {
  called = 0;
  seteuid(getuid());
  set("enchantment", DIM);
  set("schools", ({ "illusion" }) );
  set("id", ({ "#INVIS_OB#", "#INVIS_SPELL#" }) );
  set("prevent_drop", 1);
  set("dest_at_die", 1);
  set("dest_at_kill", 1);
}

void init() {
  add_action("dispel", "dispel");
}

int begin_spell(int level) {
  set("level", level);

  subject = environment(TO);
  if (!subject) {
    destruct(TO);
    return 0;
  }

  subject->set("invisible", 1);
  subject->do_new();

  tell_object(subject, "You slowly fade from view!\n");
  tell_room(environment(subject), subject->query("cap_name") +
    " slowly fades from view.\n", subject);
  set("extra_look", "$N is completely invisible to everyone ELSE!\n");
  return 1;
}

int remove() {
  if (environment() && living(environment()) && (called==0)) {   
    subject->set("invisible", 0);
    subject->do_new();
    tell_object(environment(), "You become visible again!\n");
    tell_room(environment(subject), subject->query("cap_name")+
      " fades into visibility!\n", subject);
    called++;
  }
  ::remove();
  return 1;
}

void upon_attacking() {
  remove();
  return;
}

int dispel (string str) {
   if (str!="invis" && str!="invisibility") return 0;

   write("You choose to end your Invisibility spell.\n");
   remove();
   return 1;
}
