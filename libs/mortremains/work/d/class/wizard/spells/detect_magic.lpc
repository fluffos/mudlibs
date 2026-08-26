/*
** File: detect_magic.c
** Purpose: Detect Magic
**    1st level Univeral spell.
** Cost: 9 SP
** Credits:
**   31 July 97   Cyanide wrote the file.
**   10/28/97 Ilzarion added support for armors and stuff with bonus
*/

#include <magic.h>
#include <m_spells.h>

#define COST 9
#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

// Prototypes...
int cast_detect_magic();
int detect_living (object, int);
int detect_thing(object, int);

int counter = 0;

inherit SPELL;

int cast_detect_magic() {
  object *obs=({});
  int i=0;

  if (!environment(TP)) {
    write("Detect Magic cannot be cast in the void!\n");
    return 0;
  }

  if (!this_player()->cast_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write("You cast Detect Magic!\n");
  say(TPN+" casts Detect Magic!\n");

  obs = all_inventory(environment(TP));
  for (i=0; i<sizeof(obs); i++) {
    if (living(obs[i])) {
      detect_living(obs[i], TP->query_level());
    } else {
      detect_thing(obs[i], TP->query_level());
    }
  }
  if (!counter) {
    write("No magical emanations detected.\n");
  } else {
    write(counter+" magical emanations.\n");
  }

  counter = 0;
  return 1;
}


// This function handles the detection in living objects...

int detect_living (object ob, int level) {
  int x;
  object *stuff, thing;

  thing = present("#ANTIMAGIC_SHELL#", ob);

  x = ob->query("magic_resist");
  if (x > random(100) ) 
     return 0;
  
  if (thing) 
     return 0;

  stuff = all_inventory(ob);

  for (x=0; x<sizeof(stuff); x++)
    detect_thing(stuff[x], level);

}


// This function handles the detection of non-living objects.

int detect_thing (object ob, int level) {
  int intensity, flag=0;
  string glow, *schools, name;
 
  if (!ob->query("enchantment") && !ob->query("magic") && !ob->query("bonus"))
    return 0;

  name = ob->query("short");
  if (!name) {
    if (living(environment(ob)))
      name = environment(ob)->query("cap_name");
    else
      name = "The room itself";
  } else {
    name = capitalize(name);
  }

  intensity = (this_player()->query_level() * 10);
  if (random(100) < intensity) flag = 1;

  intensity = (int)ob->query("enchantment");
 if (intensity == 0) intensity = (int)ob->query("bonus");

  switch (intensity) {
    case 0 : glow = "no"; break;
    case 1 : glow = "a faint"; break;
    case 2 : glow = "a dim"; break;
    case 3 : glow = "a moderate"; break;
    case 4 : glow = "a strong"; break;
    default : glow = "an overwhelming"; break;
  }                                                  

  schools = (string *)ob->query("schools"); 
  if (!schools || flag==0) 
    schools = ({ "enchantment" });

  if (name == (string)TP->query("cap_name"))
    write("You glow");
  else
    write(name+" glows");

  write (" with "+glow+" aura of ");
  for (flag=0;flag<sizeof(schools);flag++) {
    if ((sizeof(schools) > 1) && (flag == (sizeof(schools)-1))) {
      write(" and " + schools[flag]);
    } else {
      if ((sizeof(schools) > 2) && (flag < (sizeof(schools)-1))) {
        write(schools[flag] + ", ");
      } else {
        write(schools[flag]);
      }
    }
  }
  write(".\n");
  counter++;
  return 1;
}
string spellcraft() {
    return (@EndSpell
Detect Magic (Level I Wizard Spell - Universal)

Cost: 9 Spell Points

This spell detects magical emanations within the
area around the caster.
EndSpell
    );
}

/* EOF */

                                                                    
                                                             
