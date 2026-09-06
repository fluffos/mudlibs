#include <room.h>
#include <skills_defs.h>
#include <generic_rooms.h>
#include <generic_items.h>
#include <daemons.h>
#include "/guilds/thieves/thief.h"
#include <guild.h>

#ifdef OPEN_FOR_BUSINESS
// We're testing now.....we'll set a real time later
#define TIME_TO_CONVERT time() + 1
#define T_SKILLS ({ SK_STAB, SK_SNEAK, SK_TTH, SK_PICK, SK_STEAL, \
SK_APPRAISE, SK_POISON, SK_TUMBLING })
#define THIEF_DIFF	({ DIFF_STAB, DIFF_SNEAK, DIFF_THROW, DIFF_PICK, \
DIFF_STEAL, DIFF_APPRAISE, DIFF_POISON, DIFF_TUMBLING })
#define STD_THIEF_DIVISOR 10000000
#define STD_PRIEST_DIVISOR 10000
#define PT_CONV_VAL	50

void convert_guild(string str);
int find_thief_skill(int i);


int cmd_retrain(string str) {
    if(!str) {
	this_player()->tell_me("Retrain which skill?");
	return 1;
    }
    if(to_int(this_player()->query_skill(str)) == SKILL_NO_EXIST) {
	this_player()->tell_me("You don't know that skill.");
	return 1;
    }
    if(to_int(this_player()->query_skill(str)) < TOP_RANK) {
	this_player()->tell_me("You still have more to learn in that skill.");
	return 1;
    }
    this_player()->set_skill_lev(str, this_player()->query_skill_lev(str) + 1);
    this_player()->set_skill(str, 0.0);
    this_player()->tell_me("You begin training anew.");
    return 1;
}

int cmd_forget(string str) {
    if(time() < TIME_TO_CONVERT) {
	this_player()->tell_me("Use convert for now.");
	return 1;
    }
    if(to_int(this_player()->query_skill(str)) == SKILL_NO_EXIST) {
	this_player()->tell_me("You didn't know that one anyways.");
	return 1;
    }
    this_player()->remove_skill(str);
    return 1;
}

int cmd_convert(string str) {
    float skill;
    int pts;
    if(str == "guild") {
	this_player()->tell_me("This will cause you to become \
guildless. There will be no experience penalty for leaving. Are you sure you \
wish to do this at this time? [y/N]");
	input_to("convert_guild");
	return 1;
    }
    if(time() > TIME_TO_CONVERT) {
	this_player()->tell_me("It's too late for conversion. \
You must forget the skill, now.");
	return 1;
    }
    skill = this_player()->query_skill(str);
    if(to_int(skill) == SKILL_NO_EXIST) {
	this_player()->tell_me("You have to know the skill before \
you can convert it.");
	return 1;
    }
    // Penalty for conversion.
    skill = exp(skill);
    skill /= SKILL_TRAIN_RATE;
    skill /= (1.75 * PT_CONV_VAL);
    pts = to_int(skill);
    pts >= 0 || pts = 0;
    this_player()->remove_skill(str);
    this_player()->add_skill_mod(pts);
    this_player()->tell_me(sprintf("%s converted for %d points.",
	capitalize(str), pts));
    return 1;
}

void convert_guild(string str) {
    int *skills, size, total;
    status priest; // If we're not a priest, we're a thief
    object guild;

    switch(str) {
    case "Y":
    case "y":
    case "Yes":
    case "yes":
	break;
    default:
	this_player()->tell_me("You decide not to convert your \
guild skills over for now.");
	return;
    }
    if(this_player()->query_guild() != GN_THIEF &&
      this_player()->query_guild() != GN_PRIEST) {
	this_player()->tell_me("You don't have a guild.");
	return;
    }
    guild = this_player()->query_guild_object();
    priest = (this_player()->query_guild() == GN_PRIEST);
    if(!priest) { // We're a thief
	skills = map_array(T_SKILLS, #'find_thief_skill);
	size = sizeof(skills);
	while (size--) {
	    skills[size] *= THIEF_DIFF[size];
	    skills[size] /= STD_THIEF_DIVISOR;
	    total += skills[size];
	}
	if(guild->query_sneak()) this_player()->vis();
	CHANNEL_D->remove_from_channel("thief", this_player());
	CHANNEL_D->remove_from_channel("thiefdmn", this_player());
	CHANNEL_D->remove_from_channel("thiefgmc", this_player());
	guild->chant(capitalize(this_player()->query_real_name()) +
	  " has undergone skills conversion.", 3);
	this_player()->set_guild(0);
	destruct(guild);
	if(guild = present("skert_bless"))
	    destruct(guild);
    }
    else { // We're a priest
	total = this_player()->query_guild_object()->query_coef();
	total /= STD_PRIEST_DIVISOR;
	"/guilds/priests/daemons/informer"->resign(this_player(), 1);
    }
    this_player()->add_skill_mod(total);
    this_player()->tell_me(sprintf("Your guild was converted for \
%d points.", total));
    this_player()->save_me();
}
#endif /* OPEN_FOR_BUSINESS */


status cmd_evaluate(string str) {
    string res;
    int ind;
    float skill, cval, fval;

    if(!str) {
	this_player()->tell_me("Evaluate [skill]");
	return 1;
    }
    res = "--------------------";
    if(to_int(skill = this_player()->query_skill(str)) == SKILL_NO_EXIST) {
	this_player()->tell_me("It might work better \
if you evaluated a skill that you actually know.");
	return 1;
    }
    if(this_player()->query_money() < 50) {
	this_player()->tell_me("You don't have enough gold for\
 an evaluation.");
	return 1;
    }
    if(to_int(skill) == TOP_RANK) {
	this_player()->tell_me("You have mastered this skill and \
need to retrain it to progress any further in it.");
	return 1;
    }
    this_player()->add_money(-50);
    cval = to_float(to_int(skill) + 1);
    fval = to_float(to_int(skill));
    // Kludge because floats are a pain in the ass
    if(to_int(100 * skill))
	skill = exp(skill);
    else skill = 1.0; // would have been exp(0.0) which doesn't
    // want to work
    cval = exp(cval);
    fval = exp(fval);
    cval -= fval;
    skill = skill - fval;
    ind = to_int((skill * 20) / cval);
    while(ind--)
	res[19-(19-ind)] = '%';
    this_player()->tell_me(capitalize(str)+": <"+res+">");
    return 1;
}
#ifdef OPEN_FOR_BUSINESS
status cmd_spend(string str) {
    float sk;
    int amt;
    string skill;
    if(!str || sscanf(str, "%d on %s", amt, skill) != 2) {
	this_player()->tell_me("Spend [amt] on [skill]");
	return 1;
    }
    if(to_int(sk = this_player()->query_skill(skill)) >= TOP_RANK) {
	this_player()->tell_me("You cannot spend any more \
points on that skill.");
	return 1;
    }
    if(amt > this_player()->query_skill_mod()) {
	this_player()->tell_me("You don't have that many points \
to spend.");
	return 1;
    }
    if(to_int(sk) == SKILL_NO_EXIST) {
	this_player()->tell_me("You must know the skill on \
which you wish to spend your points.");
	return 1;
    }
    sk = exp(sk);
    sk += (amt * PT_CONV_VAL * SKILL_TRAIN_RATE);
    sk = log(sk);
    if(to_int(sk) > TOP_RANK)
	sk = to_float(TOP_RANK);
    this_player()->add_skill_mod( - amt);
    this_player()->set_skill(skill, sk);
}

status cmd_ptotal(string str) {
    this_player()->tell_me("You have "+this_player()->query_skill_mod()+
      " points to spend on skills.");
    return 1;
}
int find_thief_skill(int i) {
    return this_player()->query_guild_object()->query_skills(i);
}
#endif /* OPEN_FOR_BUSINESS */

void create_room() {
    set_short("skill services");
    set(ROOM_WD, WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_long(
      "This section of the tower has been renovated, and the skill service \
people have moved in. A small desk occupies the center of the room. \
Over the desk hangs a sign which reads:\n\
\
=================================================================\n\
\n\
Evaluate [skill]: Evaluates your training progress: 50 gp\n"+
#ifdef OPEN_FOR_BUSINESS
      "Convert <guild|[skill]>: Converts either your guild or a\n\
			  skill* into conversion points.\n\
Spend [amount] on [skill]: Spends conversion points on a skill**\n\
Forget [skill]: Completely forget a skill you learned***\n\
Retrain [skill]: Advance a mastered skill to the next level****\n\
\n\
	*	For a limited time only\n\
	**	Customer is responsible for learning skill before\n\
		spending points on it\n\
	***	Forgotten skills are lost forever, and must be\n\
		retrained from scratch\n\
	****	Offer available to Gurus only\n"+
#endif /* OPEN_FOR_BUSINESS */
      "\n\
=================================================================\n\
	");
    set_exits(([
	"up" : AREA_TRISTEZA+"tower/tower2",
	"down" : GENERIC_ROOM_ADV_GUILD,
      ]));
    add_object(({ GENERIC_BBOARD, ({
	  "set_board", 100, 0, "skills_discussion_board", 0 }),
      }), 0, 1);
    set_commands(([
	"evaluate" : #'cmd_evaluate,
#ifdef OPEN_FOR_BUSINESS
	"cmd_spend" : "spend",
	"cmd_forget" : "forget",
	"cmd_convert" : "convert",
	"cmd_retrain" : "retrain",
#endif /* OPEN_FOR_BUSINESS */
      ]));
}
