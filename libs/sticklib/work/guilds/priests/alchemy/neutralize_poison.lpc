#include <attack.h>
#include <conditions.h>
#include "priest_potion.h"

/*
 * NEUTRALIZE POISON
 *
 * This potion neutralizes poison (C_POISONED and thief poison) and adds
 * resistance against poisons and poison attacks.
 * - 22-april-1997 First version by Chopin
 */ 

#define POISON_D "/guilds/thieves/poison_d"
#define RES_POISON_AMOUNT 300 // 30% resistance against poison attacks
#define MAX_POISON_RESISTANCE 600
// a 100% resistance would not be fair, we have invulnerability for that

void
neutralize_poison(int t)
{
    object ob, pl;
    int duration, amount, cur_resist;

    pl = this_player();
    // if player is poisoned, neutralize the poison, otherwise add resistance
    if(pl->query_condition(C_POISONED)) {
	pl->set_condition(C_POISONED,0);
	return;
    }
    ob = find_object(POISON_D);
    if(!ob) {
	// in case the poison daemon will be moved somewhere
	write_file(ERRORLOG,
	  "ERROR: thief poison daemon not found\n");
	return;
    }
    if(ob->is_poisoned(pl)) {
	ob->remove_poisoned_living(pl,0);
	return;
    }

    duration = 20 + t/3 + random(t/4);

    // resistance against condition "C_POISONER"
    pl->add_condition(RESISTANCE(C_POISONED),duration/2); // in heart_beats

    // resistance against attacks of type "DT_POISON"
    amount = RES_POISON_AMOUNT;
    cur_resist = pl->query_resistance(DT_POISON);
    if(amount + cur_resist > MAX_POISON_RESISTANCE)
	amount = MAX_POISON_RESISTANCE - cur_resist;
    pl->add_resistance(DT_POISON, amount);

    // someone write a better message
    pl->tell_me("You feel safer.");
    call_out("end_poison_resistance", duration, pl, amount);
}


void
end_poison_resistance(object pl, int amount)
{
    pl->add_resistance(DT_POISON, -amount);
}


void
create_potion() {
    funs = #'neutralize_poison;
    lvl = 10;
    cost = 25;
    dif = 0;
    ingredients = ({
      ({"wyvern_sample", "dragon_sample"}),
      "spring water",
    });
    color = "fuzzy";
    drinker_mess = "";
    pot_name = "neutralize poison";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_NEUTRL_POISON});
    skill_p = ({10,30,60});
}
