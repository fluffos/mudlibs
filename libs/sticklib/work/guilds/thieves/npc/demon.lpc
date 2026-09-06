/* Demon of Skert */

#include <conditions.h>
#include <npc.h>

void
create_monster()
{
    set_name("nasty-looking demon");
    set_short("Nasty-looking Demon");
    set_id(({ "demon", "nasty", "nasty-looking" }));
    set_long(
      "This large demon is a horned, winged humanoid with oily dark red skin.\n"+
      "Every inch of its body is covered by scales, spikes and warts. It has\n"+
      "three eyes and it giggles, mumbles and grins all the time. Its smell is\n"+
      "nauseous, resembling rotten fish.\n");
    set_level(20);
    // set(NPC_NOT_AGGRESSIVE);
    set_alignment(AL_NASTY);
    set_dead_ob(this_object());

    set_ep(400000);
    set_ac(15);
    set_wc(20);
    set_hp(340);
    set_sp(100);
}

void
init_monster()
{
    call_out("check_situation", 1);
}

check_situation()
{
    object ob, att;

    remove_call_out("check_situation"); /* Just to be sure */

    if (!environment()) return;

    ob = present("priestess", environment());

    if (!ob ||
      !(att = (ob->query_attack()))) {
	tell_room(environment(),
	  "Demon decides to return into Abyss in a puff of black smoke.\n");

	destruct(this_object());
	return;
    }

    if (ob && att && !query_attack())
	attack_object(att);
}

heart_beat()
{
    ::heart_beat();

    check_situation();
    return;
}

#define ATT query_attack()

attack() {
    string n,tmp;
    int loss,i;
    object ob;

    if (!::attack()) return 0;
    if (!ATT || !present(ATT, environment())) return 0;

    n = ATT->query_name(); if (!n) n = "Someone";

    /* Casting spells? */
    if (!random(6)) {
	switch(random(4)) {
	case 0: /* Missile */
	    say(query_name() + " points at " + n +
	      ", which is hit by a fiery magic missile!\n", ATT);
	    tell_object(ATT, query_name() +
	      " points at you and grins. A fiery magic missile hits you!\n");
	    loss = random(20) + 5;
	    ATT->hit_player(loss);
	    break;
	case 1: /* Paralysing ray (One of the funniest!) */
	    say(
	      query_name() +
	      " sends a ray of evil magic from its fingertips.\n"+
	      "The ray hits " + n + ".\n", ATT);
	    tell_object(ATT, query_name() +
	      " hits you with an evil magic ray from its fingertips.\n");
	    if (ATT->query_npc() || ATT->query_level() > random(35) ||
	      ATT->query_condition(C_STUNNED)) {
		say(n + " is not affected.\n", ATT);
		tell_object(ATT,"You are not affected this time.\n");
		break;
	    }
	    say(n + " is stunned!\n", ATT);
	    tell_object(ATT, "You are stunned and disoriented!\n");
	    ATT->set_condition(C_STUNNED, 2 + random(5));
	    break;
	case 2: /* Curse */
	    say(query_name() + " points at " + n +
	      " and roars: \"A curse upon thee!\"\n",ATT);
	    tell_object(ATT,query_name() +
	      " points a clawed finger at you and hisses: \"A curse upon thee!\"\n");

	    ob = ATT->query_weapon();

	    if (ATT->query_level() < random(40)) {
		if (ob) {
		    tell_object(ATT,
		      "Your weapon is surrounded by an evil black glow!\n");
		    say(n +
		      "'s weapon is surrounded by an evil black glow!\n",ATT);
		    ob->set_cursed(ob->query_cursed() + (1 + random(3)));
		    ATT->recount_wc();
		} else {
		    /* Drain the bastard's strength! */
		    tell_object(ATT,"You feel weaker!\n");
		    say(n + " looks pale and weak.\n");
		    ATT->add_str(-1);
		}
	    }
	    break;

	default: /* Cause disease */
	    say(query_name() +
	      " burps loudly! A small cloud of foul green smoke surrounds " +
	      n + "!\n",ATT);
	    tell_object(ATT,query_name() +
	      " burps loudly! You are surrounded by a small cloud of foul green smoke!\n");
	    if (ATT->query_level() > random(40) ||
	      present("disease",ATT)) {
		tell_object(ATT, "You gag and almost throw up.\n");
		break;
	    }
	    ob = clone_object("/obj/disease");
	    move_object(ob, ATT);
	    ob->set_disease(0); /* Random one */
	    tell_object(ATT, "You feel momentarily dizzy.\n");
	    break;
	} /* end switch */
	return 1;
    }

    return 1;
}
