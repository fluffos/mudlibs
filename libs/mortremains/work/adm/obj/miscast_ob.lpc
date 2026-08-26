/*
** File miscast object
** lvl 3 priest spell
*/

#include <magic.h>
#include <mudlib.h>
#include <uid.h>  

inherit OBJECT;


void create() {
 seteuid(ROOT_UID);
  set("id", ({ "#MISCAST_SPELL#" }) );
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

void init(){
add_action("invoke", "invoke");
add_action("cast", "cast");
}

int begin_spell(object caster, object target) {
  set("level", caster->query_level());

  set("enchantment", MODERATE);
  set("schools", ({ "enchantment" }) );

  call_out("remove", caster->query_level() * 20 );
  return 1;
}

int remove() {
  object caster = environment(this_object());

  if ((caster) && living(caster)) {
    tell_object(caster, "You feel the chaotic energies around you dissapate.\n");
     }
  ::remove();
  return 1;
}                                                  

int cast(string str){
object victim = environment(this_object());
string *spells, spell, newspell, target, arg1;
int i;
if (sscanf(str, "%s at %s", spell, target) !=2){
 if (sscanf(str, "%s at", spell) == 1) {
            write ("Cast "+spell+" at whom?\n");
            return 1;
        } else {
            if (sscanf(str, "%s %s", spell, arg1) != 2)
                spell = str;                            
                }
            }
if (random(2)){
	spells = victim->query("mage_spells");
	i = sizeof(spells);
	newspell = spells[random(i)];
if (arg1){
victim->force_me("cast "+newspell+" "+arg1);
		}else{
		if (!target){
victim->force_me("cast "+newspell);
		}else{
victim->force_me("cast "+newspell+" at "+target);
		}
		}
		return 1;
		}
		return 0;
		}


int invoke(string str){
object victim = environment(this_object());
string *spells, spell, newspell, target, arg1;
int i;
if (sscanf(str, "%s at %s", spell, target) !=2){
 if (sscanf(str, "%s at", spell) == 1) {
            write ("Invoke "+spell+" at whom?\n");
            return 1;
        } else {
            if (sscanf(str, "%s %s", spell, arg1) != 2)
                spell = str;                            
                }
}
 if (random(2)){
	spells = victim->query("priest_spells");
	i = sizeof(spells);
	newspell = spells[random(i)];
if (arg1){
victim->force_me("invoke "+newspell+" "+arg1);
		}else{
if (!target){
victim->force_me("invoke "+newspell);
		}else{

victim->force_me("invoke "+newspell+" at "+target);
		}
		}
		return 1;
		}
		return 0;
		}

/* EOF */
