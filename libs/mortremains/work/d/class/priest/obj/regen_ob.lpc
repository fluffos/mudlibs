/*
** File:  enlarge_ob.c
** Purpose:  Spell object for "enlarge" spell.
** Credits:
**    21 Jul 97  Cyanide created the spell.
*/

#include <magic.h>
#include <mudlib.h>


inherit SPELL;
inherit OBJECT;


void create() {
  
  seteuid(getuid());
  set("enchantment", DIM);
  set("schools", ({ "necromancy" }) );
  set("id", ({ "#REGEN_OB#" }) );
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

int begin_spell(int level) {
 int regen;
 object subject;
 
  set("level", level);

  subject = environment(TO);
  if (!subject) {
    destruct(TO);
    return 0;
  }
subject->add("regeneration", (1 * (TP->query_level())));
 

  tell_object(subject, "You begin to regenerate.\n");
 
  call_out("remove", 30*level);
  return 1;
}

int remove() {
object subject;
  if (environment() && living(environment())) { 
   subject = environment(this_object());   
    environment()->add("regeneration", (-1 * (TP->query_level())));
    tell_object(subject, "You stop regenerating.\n");
  }
  ::remove();
  return 1;
}


