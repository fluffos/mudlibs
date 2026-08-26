/*
**ilz
** Cyanide cleans this up, 14 July 2000
*/

#include <p_spells.h>

#define COST 80

inherit SPELL;

void do_quake(object target);

int invoke_earthquake () {
    int i;
    object env, *monster, target;

    seteuid(getuid());

    if (!invoke_spell(TP, COST)) return 0;

    write("You summan an earthquake in the name of "+capitalize(TP->query("deity"))+"!!\n");
    say(TP->query("cap_name")+" shouts the name of "+
       capitalize(TP->query("deity"))+"!!\nThe earth begins to shake!\n");
    env = environment(TP);
    monster = all_inventory(env);

    for (i=0;i<(sizeof(monster));i++){
	if (living(monster[i]) && (monster[i]->query("deity") != TP->query("deity")) ){
	    do_quake(monster[i]);
	}
    }

    return 1;
}

void do_quake(object target){
    int rand;
    target->set("last_attacker", TP);
    target->kill_ob(TP);

    rand = (random(12)+random(12)+random(12)+random(12)+random(12)+
      random(12)+random(12)+random(12)+random(12)+random(12)+
      random(12)+random(12)+random(12)+random(12)+random(12)+15);

    say(target->query("cap_name")+" is hit by gouts of earthen debris!\n");
    write(target->query("cap_name")+" is hit by gouts of earthen debris!\n");

    target->receive_damage(rand, "bludgeoning", TP);
    target->block_attack(random(2)+1);
    return;
}

string spellcraft() {
    return (@EndSpellcraft
Earthquake (Priest - Level VII - Earth)

Duration: instant 		Area of Effect: Room
Cost: 80 TP

	This spell causes an earthquake in the room, damaging all 
bystanders, innocent or otherwise. Only followers of the same god are 
protected from the wrath of the quake.
EndSpellcraft
    );
}
