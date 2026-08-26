/*
** File: Strength_ob.c
** Purpose: Spell object for 2nd level alteration spell, strength.
** Cost: 12 SP
** Credits:
**    29 Sept 97   Cyanide rewrote the file.
*/

#include <mudlib.h>
#include <m_spells.h>

inherit OBJECT;

int str_change = 0;
string str;

void create() {
  set("id", ({ "#HOLYMIGHT_OB#" }) );
  set("extra_look", "$N is glowing with holy might!.\n");
}

void begin_spell (object ob, string str) {
  int str_curr;
  string c_str;


  str_change = (ob->query_level("priest")/5);
 
 if (str == "strength"){
   tell_object(ob, "You feel suddenly stronger!\n");
  tell_room(environment(ob), ob->query("cap_name")+" suddenly "+
    "grows in muscle mass!\n", ({ ob }) );
  str_curr = (int)ob->query("stat/strength");
  ob->add("stat/strength", str_change);
  }
 if (str == "dexterity"){
   tell_object(ob, "You feel suddenly more nimble!\n");
  tell_room(environment(ob), ob->query("cap_name")+" suddenly "+
    "seems more nimble!\n", ({ ob }) );
  str_curr = (int)ob->query("stat/dexterity");
  ob->add("stat/dexterity", str_change);
  }
 if (str == "constitution"){
   tell_object(ob, "You feel suddenly more hardy!\n");
  tell_room(environment(ob), ob->query("cap_name")+" suddenly "+
    "seems pumped!\n", ({ ob }) );
  str_curr = (int)ob->query("stat/constitution");
  ob->add("stat/constitution", str_change);
  }
 
call_out("remove", (ob->query_level("priest") * 30), str );
 
  return;
}

int remove(string str) {
  object caster = environment(this_object());

  if ((caster) && living(caster)) {

  if (str == "strength"){
    tell_object(caster, "You feel weaker.\n");
    caster->add("stat/strength", (-1 * str_change));  
  }

  if (str == "dexterity"){
    tell_object(caster, "You feel clumsy.\n");
    caster->add("stat/dexterity", (-1 * str_change));  
  }
  if (str == "constitution"){
    tell_object(caster, "You feel sick.\n");
    caster->add("stat/constitution", (-1 * str_change));  
  }
 caster->block_attack(60);
 caster->set("stunned", 60); 
}


::remove();  
  return 1;
}




/* EOF */
