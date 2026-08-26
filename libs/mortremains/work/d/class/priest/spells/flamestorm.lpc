/*
** ilz
** Cyanide fixed - July 14, 2000
*/

#define COST 80

inherit SPELL;

void do_storm(object target);

int invoke_flamestorm () {
    int i;
    object env, *monster, target;

    seteuid(getuid());

    if (!invoke_spell(TP, COST)) return 0;

    write(wrap("You summon a storm of fire! Liquid flame "+
          "begins to fall from the sky!"));

    say(wrap(TP->query("cap_name")+" summons a storm of fire! Liquid flame "+
          "begins to fall from the sky!"));
    env = environment(TP);
    monster = all_inventory(env);

    for (i=0;i<(sizeof(monster));i++){
	if (living(monster[i]) && monster[i]!=TP ){
	    do_storm(monster[i]);
	}
    }
}

void do_storm(object target){
    int rand;
    target->kill_ob(TP);

    rand = random(8)+random(8)+(TP->query_level("priest"))+2;
    say(target->query("cap_name")+" is burned by the droplets of liquid fire!\n");
    target->receive_damage(rand, "fire", TP);
    target->set("last_attacker", TP);
    return;
}

string spellcraft() {
    return (@EndSpellcraft
Flame Storm (Priest - Level VII - Fire)

Duration: instant 		Area of Effect: 1 Room
Cost: 80 TP

	This spell summons a storm of liquid fire to rain down on the 
entire room.
EndSpellcraft
    );
}
