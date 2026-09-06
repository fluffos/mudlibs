// Modified 26-Jan-98, Kieve
//   The calculation for tumble_success() was god damned aweful.
//   I completely re-did it.  Also a few changes in the query_guild_ac_rate
//   function because of a few silly mistakes (ie unreachable code)
//   I also fixed the rate at which the damage is reduced. It was almost
//   90% every time... now it is more reasonable.
// Modified 01-Feb-98, Kieve
//   Added SOME tumble when a miss occurs just because they are dying way
//   way way too fast.
// Modified 04-Feb-98, Kieve
//   I changed the dwarf tumble train delay to be the same as a hobbit
//   Graah had made dwarves have an advantage as a thief, but could have
//   missed this one.
// 19-May-98 / Graah: query_guild_ac_rate() now checks if the hitter is
//		      living and not ourself: only if so, we can tumble.
//		      However, it is nice to be able to tumble some traps;
//		      so DT_CRUSH can still be tumbled.

#ifndef TMARK_C
#include <living_defs.h>
object owner, target;
mapping skills;
int guildmaster, advantage, tumbtime, flg_tumble, pk;
#define TUMBLE_COST             1
#define TUMBSEC                 2
inherit "/guilds/thieves/skills/criticals";
#include "../thief.h"
#endif

#include <tune.h>

#define ENV(xx) environment(xx)
#define KDEBUG(xx)  if(ENV(TO) && ENV(TO) == find_player("kieve")) \
                        find_player("kieve")->tell_me(xx);
#define BDEBUG(xx)  if(ENV(TO) && ENV(TO) == find_player("testkieve")) \
                        find_player("kieve")->tell_me(xx);

int
tumble_success()
{
    /*   -1 = botched tumble.
	  0 = failed to tumble.
	  1 = tumbled succesfully.
	  2 = avoid stun.
	  3 = tumble behind him and restab.
    */
    // tumble success depends on a percentage of the total weight carried...
    // the smaller it is, the better you'll do
    // if you have more than 20% of the weight you can carry, then you're
    // going to never make the good tumbles.
    // At level 5000 (1/2 ultimate) half of the tumbles will fail. after ultimate
    // a failed tumble is extremely rare. As it should be. Unless you're carrying
    // a lot of equipment.
    // If you are a low level, you should fail a great deal of the time
    // so... failure is dictated by level... but you can still fail after that.
    int fail_chance, weight_perc, sk, max_weight, crit;

    sk = (skills[SK_TUMBLING]);
    fail_chance = sk / 100;   // /10000.0 * 100;
    // up it a bit, to take into account the fact that we'll be doing some
    // more random fail checks later.
    fail_chance += 10;
    if(random(101) > fail_chance) {
	// Failed a tumble.
	// Now, did we fail badly?
	// Before it was simply a 4% chance of a bad fail
	// Our skill has been shown to be low... massive fail should
	// happen more often.  Say 15 percent of the time.
	// It's 25% because now a 0 tumble tumbles a small amount of the
	// damage.
	if(random(101) < 25)
	    return -1;
	return 0;
    }
    // We still may have failed... We didn't take into account any
    // racial bonuses yet...
    // So we've passed by our skill... 
    if(ENV(TO) != owner) return 0;
    // this is basically from /obj/living.c add_weight()
    max_weight = owner->query_race_stat(RACE_CARRY_RATE) *
    (owner->query_stat(ST_STR) + 10) / 111;
    weight_perc = (int)(owner->query_weight() / (float)max_weight * 100);

    // advantage goes from -3 to 4 -- 8 range
    // Now, how much do I want this to affect the percentage here..
    // We've already failed... if the weight is more than 40%, we have
    // a chance to fail once more, but not badly.
    if(weight_perc > 40) {
	if(random(101) > ( (int)(thief_dex()*1.5686) + 4*(advantage + 1))) {
	    // 1.5686 was calculated from 51y + 20 = 100
	    //    (100 - 20) / 51
	    // 40% troll:    20x - 8  =  23 =  23 % fail
	    // 40% hobbit:   51x + 20 =  99 =   1 % fail
	    // 100% troll:   12x - 8  =  10 =  90 % fail
	    // 100% hobbit:  32x + 20 =  70 =  30 % fail
	    // I like these numbers... let's see for human:
	    // 40% human:    47x + 0  =  73 =  27 % fail
	    // 100% human:   30x + 0  =  47 =  53 % fail
	    // Good good.. now what if there was no advantage for hobbits
	    // 40% hobbit:   51x + 0  =  79 =  21 % fail
	    // 100% hobbit:  32x + 0  =  50 =  50 % fail
	    // Poifect
	    // While the calculation is based on current numbers,
	    // it will still hold if the numbers change.

	    // could we massivly fail here? No... we've passed 
	    // the skill check.. we're fairly skilled... just weighted down
	    // Well, on the other hand... Ultimate levels would never get
	    // the massive fail message... so let's say 4% of the time
	    // This is up to 9% because 0 tumble tumbles some damage
	    if(random(101) < 9)
		return -1;
	    return 0; // failed tumble
	}
    }

    if(weight_perc > 33)
	// They're carrying too much to do a REALLY nice tumble.
	return 1;
    // So, we've covered skill, how much we're carrying (using advantage)
    // Now let's check our crits....
    crit = critical(sk, guildmaster, advantage);
    if (crit > 1) return 3;
    if ((crit == 1) && (random(101) < 40)) return 2;

    return 1;
}

int
query_guild_ac_rate(int dmg, int dtype, int hc, object att)
{
    int success, rate, hs;
    int t_time;
    string how, how2, r;
    int max_weight, weight_perc;

    // This check is important. /Graah
    if ((dtype != DT_CRUSH) && (!living(att) || (att == owner)))
	return dmg;

    if (!still_thief(1))
	return dmg;

    /* forced dmg..don't tumble..*/
    if (member(({
	  DT_FORCE, DT_POISON, DT_TIME, DT_MAGICAL, DT_NEGATIVE,
	  DT_POSITIVE, DT_LIGHT, DT_DARK, DT_STAB }), dtype) != -1) {
	write_file(GDIR+"FORCED_DAM",
	  sprintf("Skipped tumbling %d damage from %s\n",
	    dtype,(att ? (string)att->query_real_name() : "???")));
	return dmg;
    }

    /* Too tired to tumble? */
    if (owner->query_fp() < TUMBLE_COST)
	return dmg;

    success = tumble_success();
    /* Let's make tumble cost a little */
    owner->add_fp(-TUMBLE_COST);

    if (success < 1) {
	if(success < 0) {
	    TM("You botch your tumble, blundering into the worst possible "+
	      "position for defending yourself.");
	    environment(owner)->tell_here(owner->query_name() +
	      " botches " + owner->query_possessive() +
	      " tumble, blundering into the worst possible position "+
	      "for defense.",owner);
	}

	r = (string)owner->query_race();

	t_time = tumbtime + TUMBSEC;
	if (r == "half-orc") t_time += 60;
	if (r == "troll") t_time += 120;

	if (t_time < time() && random(100) < 20 && ((skills[SK_TUMBLING] / 2000) < dmg) &&
	  ( (int)owner->query(LIV_CARRY_RATE) > random(100) )) {
	    // Ultimate tumble trains way to fast... this should fix that a bit... -Chao
	    // Actually, every tumble trained too fast... It's just that smart
	    // thieves had ultimate tumble --Kieve
	    //		if(skills[SK_TUMBLING] < 10000 || random(skills[SK_TUMBLING]) < random(4000) ) {
	    max_weight = owner->query_race_stat(RACE_CARRY_RATE) *
	    (owner->query_stat(ST_STR) + 10) / 111;
	    weight_perc = (int)(owner->query_weight() / (float)max_weight * 100);

	    if(weight_perc < 50  ||  random(100-weight_perc) > 30) {
		tumbtime = time();
		skills[SK_TUMBLING]++;
		if(success == -1  &&  weight_perc < 30)
		    skills[SK_TUMBLING]++;
	    }
	}

	if (success == 0) {
	    TM("You fail to tumble, bearing the full impact of the damage. ");
	    environment(owner)->tell_here(
	      owner->query_name()+" fails to tumble, bearing the full "+
	      "impact of the damage. ", owner);
	    // Now We'll reduce the damage if their skills are good enough.
	    // This is only being reduced because they DIE way too fast when
	    // they fail a tumble...  I will move up the chance of a total
	    // blunder to compensate for taking off damage for this...
	    //
	    // We'll take the skill, half it...
	    rate = BALANCE->defence(skills[SK_TUMBLING]/10,GN_THIEF,120);

	    rate = (int)( (int)(((float)(rate-27) / 53.0) * 45.0) + random(6));
	    //rate = rate/2 - 5 + random(11);
	    if(rate < 0)
		rate = 0;
	    if(rate > 50)
		rate = 50;
	    return (int)(dmg*(1.0 - (float)rate/100.0));
	    //return dmg;
	}
	else {
	    // This only happens when success == -1
	    rate =  (((100 - success * (5+random(30)-advantage)) * dmg) / 100);
	    return rate;
	}
    }

    /* Todo: better messages, pose the maneuver to others too. */
    /* Done! --Colt  */

    switch (random(5)) {
    case 0: how = "dodge"; break;
    case 1: how = "tumble"; break;
    case 2: how = "fumble"; break;
    case 3: how = "dash"; break;
    case 4: how = "duck"; break;
    }
    switch (random(4)) {
    case 0: case 1: how2 = ""; break;
    case 2: how2 = " out of the way"; break;
    case 3: how2 = " head over heels"; break;
    }

    TM(sprintf("You %s%s and avoid some damage.", how, how2));
    environment(owner)->tell_here(sprintf("%s %ss%s and avoids some damage.",
	(string)owner->query_name(), how, how2), owner);

    // High skill bonus
    if ((hs = (((skills[SK_TUMBLING] - 8000) / HIGH_SKILL_DIV) / 10)) < 0)
	hs = 0;

    if (success == 3 && (skills[SK_TUMBLING] > (4000 + random(10000)))) {
	//switch (random(2))  {  // random(2) never gives '2' --Kieve
	switch (random(3)) {
	case 0:
	    TM("An AWESOME tumble! You pop up behind your enemy and "+
	      "take another STAB at it.");
	    environment(owner)->tell_here(owner->query_name() +
	      " performs an AWESOME tumble and pops up behind " +
	      owner->query_possessive() + " opponent for another "+
	      "shot at a stab!",({ owner, att }));
	    att->tell_me(owner->query_name() + " astounds you with an "+
	      "AWESOME tumble and pops up behind you!");
	    tumble_stab(att);
	    /*here goes nothing. 153 was success = 2; before. -Cognac*/
	    // Way to go Cognac, you broke their other tumble bonus
	    // Back to 2 (was 4) --Kieve
	    success = 2;
	    break;
	case 1:
	    TM("An AWESOME tumble! You tumble behind your enemy, "+
	      "catching "+ att->query_possessive() +" legs in the "+
	      "process.  " + att->query_name() + " trips and fumbles "+
	      "around trying to get up.");
	    environment(owner)->tell_here(owner->query_name() + " trips "+
	      att->query_name() + " with an AWESOME tumble!",
	      ({ owner, att }));
	    att->tell_me(owner->query_name() +" catches your legs "+
	      "with an AWESOME tumble! Your sumble around trying "+
	      "to recover.");
	    att->set_condition(C_STUNNED,random(3)); 
	    success = 2;
	    break;
	case 2:
	    TM("An AWESOME tumble! You tumble out of the way, throwing "+
	      "dirt up in the face of your enemy in the process.");
	    environment(owner)->tell_here(owner->query_name() +" kicks "+
	      "some dirt up into the face of " + att->query_name() +
	      " with an AWESOME tumble!", ({ owner, att }));
	    att->tell_me(owner->query_name() + " kicks dirt up into "+
	      "your face with an AWESOME tumble!");
	    att->set_condition(C_BLIND,random(4));
	    success = 2;
	    break;
	} // SWITCH

    } // IF

    if (success == 2 && (skills[SK_TUMBLING] > (4500 + random(8000)))) {
	TM("Your deft footwork avoids nearly all possible damage!");
	environment(owner)->tell_here(owner->query_name() +
	  "'s deft foot work avoids a lot of damage!",owner);
	owner->set_condition(RESISTANCE(C_STUNNED),random(3));
	owner->set_condition(RESISTANCE(C_UNCONSCIOUS),random(3));
	if (dtype > DT_FALL) {
	    TM("You feel Skert's warm embrace and the magical attack "+
	      "doesn't seem to harm you as much.");
	    return ((100-(skills[SK_TUMBLING]/100 + hs)) * dmg)/100;
	}
    }

    if (dtype > DT_FALL)
	rate = ((100 - (skills[SK_TUMBLING] / 100 + hs)) * dmg) / 100;
    else {
	rate = BALANCE->defence(skills[SK_TUMBLING]/10,GN_THIEF,120);
	//rate = 10 + random(rate - 10) + hs;
	// Someone with low skill could easily get the same rate as
	// somenoe with high skill level.
	//rate = rate - 10 + random(11) + hs;
	// absolute low of 17%, high of 90
	rate = (int)(rate * 0.6) - 10 + random((int)(rate*0.4)) + hs;
    }

    if (rate < 3) rate = 3;
    else if (rate > 90) rate = 90;

    // rate is the percentage by which the dmg is reduced... not
    // by how much is taken!!  ie if dmg is 100, and rate is 90,
    // the damage given is 10.  if rate is 15, the damage is 85.
    return (int)(dmg*(1.0 - (float)rate/100.0));
}

// Tumble stab damage.
status tumble_stab(object victim)
{
    int dam,perc_dec;

    if(!victim) {
	return 0;
    }
    /* Make sure we aren't fleeing at the time */

    if(owner->query(LIV_IS_FLEEING)) {
	return 0;
    }
    if(!present(victim,environment(owner))) {
	TM("Your victim has fled.");
	return 1;
    }

    dam = 30 + skills[SK_STAB]/150 + random(skills[SK_STAB]/100);
    if (dam > 100)
	dam = 100; /* for now. */
    perc_dec = (skills[SK_TUMBLING] / 100);
    if (perc_dec < 100)
	dam = (dam * perc_dec) / 100;
    /* At least SOME damage. This is so rare. //Graah */
    if (dam < 30) dam = 30;

    TM("Your deftly pop up and stab your victim.");
    victim->tell_me("OUCH! Your opponent quickly stabs you from behind.");
    environment(owner)->tell_here(owner->query_name()+" ducks behind "+
      owner->Possessive()+" opponent and stabs quickly.",({owner,victim}));

    if((string)victim->query_guild() == GN_THIEF) {
	flg_tumble = 0;
	return 0;
    }

    victim->hit_player(TUNE_THIEF_DAMAGE(dam),DT_STAB,0,owner);
    return 1;
}
