/*
**ilz
*/
#include <mudlib.h>
#include <config.h>
#define COST 100

inherit SPELL;

void do_word(object target);


int invoke_word () {
	int i;
   object env, *monster, target;

   seteuid(getuid());
 
      if (!TP->invoke_spell(COST)) return 1;
   
write("You call forth the Holy Word of "+capitalize(TP->query("deity"))+"!!\n");

say(TP->query("cap_name")+" calls forth the Holy Word of "+capitalize(TP->query("deity"))+"!!\n");
 env = environment(TP);
monster = all_inventory(env);

for (i=0;i<(sizeof(monster));i++){

if (living(monster[i]) && (monster[i]->query("deity") != TP->query("deity")) ){
	do_word(monster[i]);
	}
	}
 }



 void do_word(object target){
int rand;
target->set("last_attacker", TP);
target->kill_ob(TP);


if (target->query("summoned")){
say(target->query("cap_name")+" is sent back to it's home!\n");
write(target->query("cap_name")+" is sent back to it's home!\n");
target->move(VOID);
target->set("hit_points", -1);
return;
}

 if ((target->query_level())<5){
say(target->query("cap_name")+" dies from hearing the holy word!\n");
write(target->query("cap_name")+" dies from hearing the holy word!\n");
target->set("hit_points", -1);
return;
}
 if ((target->query_level())<8){
say(target->query("cap_name")+" is paralyzed from hearing the holy word!\n");
write(target->query("cap_name")+" is paralyzed from hearing the holy word!\n");
rand = random(4)+1;
target->block_attack(rand);
target->set("no_move", rand);
return;
}
 if ((target->query_level())<12){
say(target->query("cap_name")+" falls to thier knees from hearing the holy word!\n");
write(target->query("cap_name")+" falls to thier knees from hearing the holy word!\n");
rand = random(4)+random(4)+2;
target->set("no_move", rand);
return;
}

 if ((target->query_level())>11){
say(target->query("cap_name")+" is blinded from divine light!\n");
write(target->query("cap_name")+" is blinded from divine light!\n");
rand = random(4)+1;
target->set("blind", rand);
return;
}

return;
}
string spellcraft() {
    return (@EndSpellcraft
Holy Word (Priest - Level VII - Combat)

Duration: instant 		Area of Effect: Room
Cost: 100 TP

	This spell can blind, paralyze, stun and/or
kill all surrounding the priest. It also sends
summoned creatures back to thier home plane
automatically.
EndSpellcraft
    );
}