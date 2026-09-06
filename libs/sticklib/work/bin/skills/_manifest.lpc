/* Magic GENERAL skill- based on SK_M_ETHER
*/

#define SP_COST 5
#define MIN_EFFECT	SP_COST
// We need more than R 13, L 1 for this.
#define MAX_EFFECT	SP_COST * 4
#define SPELL_DELAY	1
#define BEGIN_PLYR_MESS	"You focus on the ether surrounding you."
#define BEGIN_ROOM_MESS(x)	sprintf("%s begins to concentrate.", x)

#include <cmd.h>
#include <eventqueue.h>
#include <skills_defs.h>
#include <spell_skills.h>
#include <attack.h>
#include <daemons.h>

void cancel_effect(int reason, mixed data);
void heal_effect(mixed data);
void attack_effect(mixed data);
void defend_effect(mixed data);
mixed defend_hook(mixed data);


int manifest_cmd(string arg) {
    string	targ,	// Name of target
    mode;	// Attack, Defend, or Heal?
    object	target;	// Who is going to be affected?


    if(to_int(this_player()->query_skill(SK_M_ETHER)) == SKILL_NO_EXIST)
	return 0;
    if(!this_player()->query_can_move()) {
	this_player()->tell_me("You can't move to do that!");
	return 1;
    }
    if(!this_player()->query_can_see()) {
	this_player()->tell_me("You can't see to do that!");
	return 1;
    }
    if(this_player()->query_sp() < SP_COST) {
	this_player()->tell_me("You're not focused enough to cast this spell.");
	return 1;
    }
    if(!arg || arg == "") {
	if(to_int(this_player()->query_skill(SK_M_DEFENSE)) ==
	  SKILL_NO_EXIST)
	    this_player()->tell_me("Usage: manifest [heal/attack <target>]");
	else
	    this_player()->tell_me("Usage: manifest [heal/defense/attack <target>]");
	return 1;
    }
    sscanf(arg, "%s %s", mode, targ);
    if(!mode) mode = arg;
    switch(mode) {
    case "attack":
	// Are we already fighting, or initiating one?
	if(!targ && !(target = this_player()->query_attack())) {
	    this_player()->tell_me(
	      "Usage: manifest attack <target>");
	    return 1;
	}
	else if(!target) { // We need to acquire a target
	    if(!(target = present(targ,
		  environment(this_player())))) {
		this_player()->tell_me(
		  "Target "+targ+" not found.");
		return 1;
	    }
	}	// We should have a target now
	if(target == this_player()) {
	    this_player()->tell_me(
	      "Despite your strong masochistic tendencies, \
you decide against it.");
	    return 1;
	}
	if(!COMBAT_D->is_valid_target(target)) {
	    this_player()->tell_me("Attacks usually \
work better against LIVING targets.");
	    return 1;
	}
	if(!target->attacked_by(this_player(), -1)) {
	    this_player()->tell_me(
	      "You......can't.......PK.....here. (Nice try, though.)");
	    return 1;
	}
	if(!this_player()->add_queued_event(
	    #'attack_effect, 1, #'cancel_effect,
	    ({ this_player(), target }))) {
	    this_player()->tell_me(
	      "You're too focused on something else."
	    );
	}
	// We can do the attack, now
	this_player()->tell_me(BEGIN_PLYR_MESS);
	environment(this_player())->tell_here(
	  BEGIN_ROOM_MESS(this_player()->query_name()),
	  this_player());
	return 1;
	break;
    case "defense":
	break;
    case "heal":
	if(targ && (targ != "me" && !this_player()->id(targ))) {
	    this_player()->tell_me("You can't heal others \
with this spell.");
	    return 1;
	}
	target = this_player();
	if(target->query_hp() == target->query_max_hp()) {
	    target->tell_me("You don't need that right now.");
	    return 1;
	}
	if(!this_player()->add_queued_event(
	    #'heal_effect, 1, #'cancel_effect, ({ target })))
	{
	    this_player()->tell_me(
	      "You're too focused on something else.");
	    return 1;
	}
	this_player()->tell_me(
	  BEGIN_PLYR_MESS
	);
	environment(this_player())->tell_here(
	  BEGIN_ROOM_MESS(this_player()->query_name()),
	  this_player());
	return 1;
	break;
    }
}

void heal_effect(mixed data) {
    int	ether,		// Our skill in ether
    life;		// Non trainable bonus
    object target;
    if(!data || !sizeof(data))	return;
    target = data[0];
    if(!objectp(target))	return; // target is this player
    // so this shouldn't happen
    if(target->query_sp() < SP_COST) {  // sp may have changed
	target->tell_me("You are not focused enough to \
complete the spell.");
	return;
    }
    if(!target->query_can_see() || !target->query_can_move()) {
	target->tell_me("You are unable to complete the spell.");
	return;
    }
    ether = to_int(target->use_skill(SK_M_ETHER, SK_TRAIN_STD, data));
    switch(ether) {
    case HOOK_RESOLVED_NT:
    case HOOK_RESOLVED:	// Someone took over our spell,
	// let's hope they know what they're
	// doing: we won't give any messages
	// or subtract sp
	return;
	break;
    case SKILL_NO_EXIST:	// forgot the skill mid spell
	// backlash would be nice, but we're
	// not that mean
	target->tell_me("Your mind becomes fuzzy as you forget \
what you're doing........");
	return;
	break;
    default:			// Passed hooks, we can continue
	break;
    }
    life = to_int(target->query_skill(SK_M_LIFE));
    // We wont trigger hooks this way, and we don't train.
    // However, manifest is a special newbieskill,
    // and we can permit this once in a while.
    life -= 3;	// Arbitrary hurdle to jump before we get a bonus
    if(life < 0) life = 0;	// No penalty for not clearing it
    ether *= target->query_skill_lev(SK_M_ETHER);
    ether += life;
    ether += MIN_EFFECT;
    if(ether > MAX_EFFECT)	// We're a 5 cent spell, nothing more
	ether = MAX_EFFECT;
    target->add_sp(-SP_COST);
    target->add_hp(ether);
    target->tell_me("As you complete the spell, a golden \
wave of ether washes over you, soothing your aches and pains.");
    environment(target)->tell_here(sprintf("A golden wave of light \
washes over %s.", target->query_name()), target);
}

void cancel_effect(int reason, mixed data) {
    object plr;
    string broke;
    plr = data[0];
    switch(reason) {
    case INTR_MOVED:	// We moved into a new room
	plr->tell_me("You moved and broke your concentration.");
	return;
	break;
    case INTR_CANCEL:	// We voluntarily cancelled the spell
	plr->tell_me("You cancel the spell.");
	return;
	break;
    case INTR_EXTERN:	// Something broke our concentration
	broke = data[1];
	plr->tell_me(sprintf("%s distracted you, breaking \
your concentration.", broke));
	return;
	break;
    default:		// This may become useful....maybe not
	plr->tell_me("DEBUG: Case slipped.");
	break;
    }
}

void attack_effect(mixed data) {
    int	ether,		// Our skill in ether
    combat;		// Non trainable bonus
    object	plr,		// The caster
    target;		// Our target

    plr	= data[0];
    target	= data[1];
    if(!objectp(plr) || !objectp(target))	return;
    // One of us got nuked
    if(environment(target) != environment(plr)) {
	plr->tell_me("Your target escaped.");
	return;
    }
    if(plr->query_sp() < SP_COST) {
	plr->tell_me("You are not focused enough to complete the \
spell.");
	return;
    }
    if(!plr->query_can_see() || !plr->query_can_move()) {
	plr->tell_me("You are unable to complete the spell.");
	return;
    }
    ether = to_int(plr->use_skill(SK_M_ETHER, SK_TRAIN_STD, data));
    switch(ether) {
    case HOOK_RESOLVED_NT:
    case HOOK_RESOLVED:
	return;		// As above
	break;
    case SKILL_NO_EXIST:
	plr->tell_me("Your mind becomes fuzzy as you forget \
what you're doing........");
	return;
	break;
    default:
	break;
    }
    ether *= plr->query_skill_lev(SK_M_ETHER);
    combat = to_int(plr->query_skill(SK_M_COMBAT));
    combat -= 3;
    if(combat < 0) combat = 0;
    ether += combat;
    if(ether < MIN_EFFECT) ether = MIN_EFFECT;
    if(ether > MAX_EFFECT) ether = MAX_EFFECT;
    plr->add_sp(-SP_COST);
    plr->tell_me(sprintf(
	"You complete the spell.\n%s's form ripples slightly, causing \
%s to cry out in pain!", target->query_name(), target->query_objective()));
    target->tell_me("Your entire body begins to tingle. Suddenly, \
every nerve in your body becomes a red hot needle of pain!");
    environment(target)->tell_here(sprintf(
	"%s's form ripples slightly, causing %s to cry out in pain!",
	target->query_name(), target->query_objective()), plr, target);
    target->attack_object(plr);
    plr->attack_object(target);
    target->hit_player(ether, DT_MAGIC, ether/6, plr);
}
