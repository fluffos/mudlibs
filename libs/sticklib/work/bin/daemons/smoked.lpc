/* SMOKE DAEMON - Coded by MacLeod. Additional coding by Colt.
 *
 * 22.10.96: Optimized the code a bit. Bugfixes << MacLeod >>
 */

#include <pipe_defs.h>
#include <conditions.h>
#include <npc_defs.h>

#define TELLM(x)        who->tell_me(x)
#define TELLH(x)        environment(who)->tell_here(x,who)
#define MY_NAME         capitalize((string)who->query_name())
#define HIS             who->query_possessive()

mapping smokers;

string *pipe_out_msg;

status check_smokers();
void create_monster(object who);

void create() {
    pipe_out_msg = ({ "Your pipe goes out!", "Your pipe suddenly gets cold.",
      "The pipe is not lit anymore.", "Suddenly your pipe feels cold." });

    if (!smokers) smokers = ([]);    /* If not initialized... Do it! --Colt */

    check_smokers();
}

void reset_smokers() { smokers=([]); }

/* QUERY FUNCTIONS */

int     query_addiction(object who) { return smokers[who, ADDICTION]; }
int     query_strength(object who) { return smokers[who, STRENGTH]; }
int     query_fuel(object who) { return smokers[who, FUEL]; }

status  query_filled(object who) { return smokers[who, FILLED]; }
int     query_chewing(object who) { return smokers[who, CHEWING]; }
status  query_smoking(object who) { return smokers[who, SMOKING]; }
status  set(object who,int what,int value) {
    smokers[who,what] = value;
    return 1;
}

int     query_fit(object who) { return smokers[who, FIT]; }
int     query_sweat(object who) { return smokers[who, SWEAT]; }
object  *query_smokers() { return m_indices(smokers); }

status add_smoker(object who, int addiction, int sweat) {
    /* This function is called whenever a new smoker enters the game, or when we
       get a new victim :) */

    if (!smokers) smokers = ([ who: addiction; 0; 0; 0; 0; 0; 0; sweat ]);
    else smokers += ([ who : addiction; 0; 0; 0; 0; 0; 0; sweat ]);
    return 1;
}

void remove_smoker(object who) { m_delete(smokers, who); }
/* This function is called by this daemon when it notices that the player is
   either link dead or quitted. (Or when someone stops smoking for good) */

void fill_pipe(object who, int strength, int fuel) {
    /* This function is called when the player actually fills his pipe. */

    smokers[who, STRENGTH] = strength;
    smokers[who, FUEL] = fuel;
    smokers[who, FILLED] = YES;
}

void light_pipe(object who) {
    /* This function is called when the player decides to light his pipe. */

    smokers[who, SMOKING] = YES;
}

void add_addiction(object who, int amount) {
    /* This function is called when adding more addiction to the smoker. */

    smokers[who, ADDICTION] += amount;
}

void reduce(object who, int amount) {
    /* This function is called when we reduce hp/sp/fp. */

    if(!interactive(who)) return;
    if ((int)who->query_hp() > ((int)who->query_max_hp() * 20 / 100) + amount)
	who->add_hp(-amount);
    if ((int)who->query_sp() > (amount / 2)) who->add_sp(-(amount/2));
    if ((int)who->query_fp() > (amount / 4)) who->add_fp(-(amount/4));

    smokers[who, ADDICTION] -= (10 * amount);
}

void stop_chewing(object who) {
    /* This function is called when the player spits the gum out or when it
       becomes tasteless. */

    smokers[who, CHEWING] = NO;
    TELLM("Grimacing, you finally spit the tasteless lump out.");
    TELLH(MY_NAME+" spit out "+HIS+" chewing gum and grimaces.");
}

void chew(object who) {
    /* This function is called when the player keeps on chewing. */

    smokers[who, CHEWING] -= 1;
    if(smokers[who, SWEAT] > 10) reduce(who,1);
    if (!random(5)) {
	switch(random(3)) {
	case 0: TELLM("You masticate your gum with perverse gusto.");
	    TELLH(sprintf("%s masticates %s gum with perverse gusto.",
		MY_NAME, HIS));
	    break;
	case 1: TELLM("You blow a huge bubble. It pops loudly and sticks to your\
 wind cleaver.");
	    TELLH(sprintf("%s blows a huge bubble. It pops loudly and sticks\
 to %s wind cleaver.", MY_NAME, HIS));
	    break;
	default:TELLM("You squash the chewing gum between your upper lip and teeth\
 and suck loudly.");
	    TELLH(sprintf("%s squash the chewing gum between %s upper lip and\
 teeth and sucks loudly.", MY_NAME, HIS));
	    break;
	}
    }
    if(smokers[who, CHEWING] < 1) {
	stop_chewing(who);
    }
}

void start_chewing(object who) {
    /* This function is called when the player tries to quit smoking and decides
       to chew a gum. */

    smokers[who, CHEWING] = 20;
}

void smoker_died(object who) {
    /* This function is called when the player dies in cancer. */

    smokers[who, ADDICTION]     = 0;
    smokers[who, STRENGTH]      = 0;
    smokers[who, FUEL]          = 0;
    smokers[who, FILLED]        = NO;
    smokers[who, SMOKING]       = NO;
    smokers[who, CHEWING]       = 0;
    smokers[who, FIT]           = 0;
    smokers[who, SWEAT]         = 0;
}

void empty_pipe(object who) {
    /* This function is called when the player empties his pipe */

    smokers[who, STRENGTH]      = 0;
    smokers[who, FUEL]          = 0;
    smokers[who, FILLED]        = NO;
    smokers[who, SMOKING]       = NO;
}

void pipe_out(object who) {
    /* This function is called when the pipe goes out (tobacco runs out) */

    TELLM(pipe_out_msg[random(sizeof(pipe_out_msg))]);
    smokers[who, SMOKING] = NO;
    smokers[who, FUEL] == 0;
}

void increase(object who, int amount) {
    /* This function is called when we want to increase hp/sp/fp. */

    who->add_hp(amount);
    who->add_sp((amount*2)/3);
    who->add_fp(amount/2);
}

void cough(mixed who,int fmsg) {
    // Temporary fix by Doomdark.
    /* This function is called in fit */

    object fit_stun;
    if(smokers == 0 || sizeof(smokers) == 0) return;
    //fit_stun = m_indices(smokers)[who];
    fit_stun = who;
    if(smokers[who, FIT] < 1) {
	TELLM("The fit passes. You draw a shaky breath.");
	TELLH(sprintf("%s draws a shaky breath. The fit passes.", MY_NAME));
	who->set_condition(C_STUNNED, 0, fit_stun);
	return;
    }
    if(smokers[who, FIT] > 0) {
	who->set_condition(C_STUNNED, -1, fit_stun);
	smokers[who, FIT] --;
	fmsg++;
	switch(fmsg) {
	case 0:
	    TELLM("You cough.");
	    TELLH(sprintf("%s coughs.", MY_NAME));
	    break;
	case 1:
	    TELLM("You are racked by a sudden violent cough!");
	    TELLH(sprintf("%s is racked by a sudden violent cough!", MY_NAME));
	    break;
	case 2:
	    TELLM("You draw a deep breath, ignoring the pain.");
	    TELLH(sprintf("%s draws a deep breath.", MY_NAME));
	    break;
	case 3:
	    TELLM("You are siezed by another fit of coughing.");
	    TELLH(sprintf("%s coughs again, a tearing, unhealthy sound.", MY_NAME));
	    break;
	case 4:
	    TELLM("Your breath rattles unhealthily in your lungs.");
	    TELLH(sprintf("%s draws a painful rattling breath and winces.", MY_NAME));
	    break;
	case 5:
	    TELLM("You double over, overcome by the pain. Inexcorably, yet another\
 cough forces its way through your gritted teeth.");
	    TELLH(sprintf("%s doubles over, unable to bear the pain as yet another\
 cough comes tearing through %s gritted teeth.", MY_NAME, HIS));
	    break;
	case 6:
	    TELLM("There is a sickening taste of blood in your mouth.");
	    TELLH(sprintf("%s licks blood from %s lips.", MY_NAME, HIS));
	    break;
	case 7:
	    TELLM("You force your tortured lungs to take a small gulb of air and\
 almost gag from the pain. A red haze covers your sight...");
	    TELLH(sprintf("%s takes a small agonized breath and almost gags from the\
 pain.", MY_NAME));
	    break;
	case 8:
	    TELLM("Oh, ye gods! Is this it? You're not ready to die...");
	    TELLH(sprintf("%s shudders. There is fear in %s eyes.", MY_NAME, HIS));
	    break;
	default:
	    TELLM("Once more your wreck of a body gathers itself in a hopeless\
 attempt to expunge a disease that has been gnawing your lungs for a long\
 time. Too long. As your breath starts its headlong rush up your windpipe you\
 feel something tear. Something wells up inside your breast, filling you with\
 a comfortable warmth. Your mouth opens to release the blast of air and it\
 explodes outwards, closely pursued by a fountain of red liquid. Dumbly, you\
 realize that it must be your blood. Just before drifting away, you have time\
 to wonder how beatiful it is, reaching up like an early spring blossom,\
 eager for the bright, warm sunlight...");
	    TELLH(sprintf("%s tenses, as once more %s wreck of a body gathers itself\
 in a hopeless attempt to expunge a disease that has been gnawing at %s lungs\
 for a long time. Too long. The final explosion of breath is closely pursued\
 by a fountain of blood, nauseating in its frail beauty. Averting your eyes,\
 you do not see the odd expression of peace settling on %s face, just before\
 the moment of death.", MY_NAME, HIS, HIS, HIS));
	    if (!who->query_coder_level()) {
		log_file("pipe_log", ctime(time()) + "\t" + MY_NAME + " died.\n");
		smoker_died(who);
	    }
	    who->hit_player(10000);
	    break;
	}
    }
    if (who) {   
	reduce(who,10);
	call_out("cough",3,who,fmsg);
    }
}

void smoke(object who) {     /* This function is called when player smokes. */
    int heal,i;
    if(who->query_ghost()) return;
    if(smokers[who, FUEL] < 1) {
	pipe_out(who);
	return;
    }

    if(smokers[who, SMOKING] = YES) {
	smokers[who, FUEL] -= 1;
	heal = smokers[who, STRENGTH] + random(smokers[who, STRENGTH]);

	if ((string)who->query_race() == "hobbit") heal += random(heal);
	if (heal < 3) heal = 3;

	if ((int)who->query_hp() < 1 || who->query_condition(C_SICK) ||
	  who->query_condition(C_POISONED)) heal = 0;

	increase(who, heal);

	smokers[who, ADDICTION] += 20;

	if (smokers[who,SWEAT] > 2) smokers[who,SWEAT] -= 3;

	if (!random(10)) {
	    TELLM("You puff your pipe contendely.");
	    TELLH(MY_NAME+" puffs "+HIS+" pipe contendely.");
	}

	if (!random(10)) {
	    for(i=0;i < (smokers[who, ADDICTION] - 7680) / 1000; i++)
		smokers[who, FIT] += random(2);
	    if(smokers[who, FIT] > 0) {
		TELLM("You become aware of a strange itch in your chest.");
		TELLH(MY_NAME+" hesitates, wearing a strangely bemused expression.");
		cough(who, 0);
	    }
	}

	if (smokers[who, STRENGTH] > 6) {
	    if (!random(5)) {
		switch(random(4)) {
		case 0: TELLM("You start to giggle incoherently.");
		    TELLH(MY_NAME+" giggles incoherently.");
		    break;

		case 1: TELLM("Your nose sprouts a leafy plant!");
		    TELLH(MY_NAME+" goes all cross-eyed and gapes.");
		    break;

		case 2: TELLM("You suddenly feel like flying!");
		    TELLH(MY_NAME+" hops around and flaps "+HIS+" arms.");
		    break;

		default: TELLM("You recall a bad experiance.");
		    TELLH(MY_NAME+" whispers fearfully: Oh no, no...\
 No... Please, NOOOO!!!!");
		    break;
		}
	    }

	    else if (!random(40)) {
		TELLM("You feel scared!");
		who->run_away();
	    }

	    else if (!random(120)) {
		create_monster(who);
	    }
	}
    }
    else if(smokers[who, SMOKING] == NO) pipe_out(who);
    else if(smokers[who, FUEL] < 0) pipe_out(who);
}

void sweat(object who) {
    /* This function is called when we are not smoking :) */

    int sweat;
    if(who->query_ghost()) return;
    if(!interactive(who)) return;
    smokers[who, SWEAT] ++;
    smokers[who, ADDICTION] --;
    if (smokers[who, CHEWING] > 0) {
	chew(who);
    }
    else {
	sweat = (int) smokers[who,SWEAT];
	if (!random(3)) {
	    if(sweat > 50) TELLM("You could kill for a smoke!");
	    else if(sweat > 30) TELLM("You need a smoke quite badly now.");
	    else if(sweat > 10) TELLM("You could use a good smoke.");
	    else TELLM("You feel fantastic!");
	    TELLH(sprintf("%s coughs wetly and spits on the ground.", MY_NAME));
	    if(sweat > 200) reduce(who, 5+ random(15));
	    else reduce(who,random(sweat/10));
	}
    }
}

status check_smokers() {
    /* This is the main routine of smoking. It checks players situation, heals
       them a bit if they are in the right condition and so on. Check out more
       detailed commaents in the function. */

    int i, *stats;
    object *we;
    we = m_indices(smokers);
    for(i=0;i < sizeof(we); i++) {
	if (query_fit(we[i]) > 0) cough(we[i],0);
	if (query_smoking(we[i]) == YES) smoke(we[i]);
	else if(query_addiction(we[i]) > 0) sweat(we[i]);
    }
    call_out("check_smokers", 15);
}

void create_monster(object who) {

    /* This function is called when we want a imaginary monster. */

    object ob;
    TELLM("You are attacked by an imaginary monster!");
    ob = clone_object(NPC_FILE);
    ob->set_name("imaginary monster");
    ob->set_level(1);
    ob->set_ep(0);
    ob->set_if("monster");
    ob->set_short("Imaginary monster");
    ob->set_long("It's too horrible to look upon!");
    ob->set_wc(1);
    ob->set_ac(15);
    move_object(ob,environment(who));
    ob->attack_object(who,1);
}
