

#include <magic.h>
#include <mudlib.h>


inherit SPELL;
inherit OBJECT;

int ray();

void create() {
  
  seteuid(getuid());
  set("enchantment", DIM);
  set("schools", ({ "invocation" }) );
  set("id", ({ "#SUNRAY#" }) );
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

int begin_spell(object caster) {
 int dmg, sv;
 object subject;
 
 
  subject = environment(TO);
  if (!subject) {
    destruct(TO);
    return 0;
  }

 ray();
  call_out("remove", (random(4)+2));
 
  return 1;
}

int remove() {
object subject;
  if (environment() && living(environment())) {    
    subject = environment(this_object());
    tell_object(subject, "You are no longer bathed in light.\n");
  }
  ::remove();
  return 1;
}


int ray(){
 int dmg, sv;
 object subject;
 
  
  subject = environment(TO);
  if (!subject) {
    destruct(TO);
    return 0;
  }
 dmg = random(6)+random(6)+random(6)+random(6)+random(6)+random(6)+random(6)+random(6)+8;

sv = subject->save_throw();
if (sv) dmg /= 2;
if (!sv){
 subject->set("blind", random(3)+1);
say(subject->query("cap_name")+" is blinded by the glowing rays!\n");
}
if (subject->query("undead")){
 subject->receive_damage(dmg, "fire", subject);
say(subject->query("cap_name")+" is burned by the searing rays!\n");
}

 subject->set("last_attacker", subject);

 call_out("ray" , 1);
 return 1;
 }