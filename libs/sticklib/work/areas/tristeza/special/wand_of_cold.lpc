#include <treasure.h>

#include <room_defs.h>
#include <attack.h>
#include <player_defs.h>

int counter, speed_kill;
object victim;

#define TP this_player()
#define MK_MAX_DMG_BASE 20
#define PK_MAX_DMG_BASE 10
#define MK_MAX_DMG_RANDOM 41
#define PK_MAX_DMG_RANDOM 21

void start_cold(object x);
status end_cold(object x);

mixed action;

void
create_treasure()
{
    counter = 8 + random(5);	// Was always 10!
    set_name("wand of cold");
    set_short("Wand of Cold");
    set_long(
      "It seems to be a wand of casting Coldness.\n\
Usage: 'cold <victim>'.");
    set_id(({ "wand" }));
    set_value(2000);
    set_weight(1);
    set_size(({ 50, 2, 2 }));
    action = ({ #'start_cold, #'end_cold });
}

void
init()
{
    //++Tron
    if(environment(this_object()) == this_player())
    {
	add_action("cold","cold");
	//	add_action("do_drop", "drop");
	// Commented out 03-jul-96 by Doomdark. Why was it there in first place?
    }
}

void
start_cold(object plr)
{
    string a, b;
    if (!plr || environment() != plr) return;
    if (!victim || !present(victim, environment(plr))) {
	plr->tell_me("Your victim seems to have fled...");
    } else {
	victim->tell_me(sprintf("%s points a wand at you!",
	    (a = (string) plr->query_name(0, victim))));
	plr->tell_me(sprintf("You point your wand of cold at %s!",
	    (b = (string) victim->query_name(0, plr))));
	environment(plr)->tell_here(sprintf("%s points a wand at %s!",
	    a, b), ({ victim, plr }));
    }
}

status
end_cold(object plr)
{
    string a, b;
    speed_kill = 0;
    if (environment() != plr)
	return 1;
    if (!victim || !present(victim, environment(plr))) {
	plr->tell_me("Your victim seems to have fled...");
	return 0;
	// When we return 0, this does _NOT_ take 1 combat round!
    }
    // Now... If attacked_by 'fails', it means we can't do this sort of
    // attack. However, we did test for this earlier. Meaning that if
    // it now fails, something has changed; probably players have gone
    // to a non-Pk room or something alike... Thus let's spend the combat
    // round. *grin*
    if (!victim->attacked_by(plr)) {
	plr->tell_me(
	  "For some reason, your wand of coldness fails to work now!");
    } else {
	a = (string) plr->query_name(0, victim);
	b = (string) victim->query_name(0, plr);
	victim->tell_me(sprintf("A cone of cold surrounds you from\
 the wand held by %s!", a));
	plr->tell_me(sprintf("A cone of cold from your wand of cold\
 surrounds poor %s!", b));
	environment(plr)->tell_here(sprintf("A cone of cold from the\
 wand held by %s surrounds %s!", a, b), ({ plr, victim }));
	// Remember to use damage types!!!
	if(!victim->query_npc() && !plr->query_npc())
	    victim->hit_player(PK_MAX_DMG_BASE + random(PK_MAX_DMG_RANDOM), DT_COLD, 0, plr);
	else
	    victim->hit_player(MK_MAX_DMG_BASE + random(MK_MAX_DMG_RANDOM), DT_COLD, 0, plr);
	// Was random(40)
    }
    if (--counter <= 0) {
	plr->tell_me("The wand suddenly disintegrates!");
	destruct(this_object());
    }
    return 1;
}

status
cold(string str)
{
    if (this_player() != environment())
	return 0;
    if (!str) {
	notify_fail("Cold whom?\n");
	return 0;
    }
    if (speed_kill) {
	this_player()->tell_me("You are already aiming with\
 your wand.");
	return 1;
    }
    victim = present(lower_case(str), environment(TP));
    if (victim == TP) {
	this_player()->tell_me("Umh, you better not cast coldness on\
 yourself!");
	return 1;
    }
    if (!victim) {
	this_player()->tell_me(sprintf("You can't see any \"%s\" here.", str));
	return 1;
    }
    if (!living(victim)) {
	this_player()->tell_me("Uhh. Better just cast coldness on\
 living things instead...");
	return 1;
    }
    if (!victim->attacked_by(this_player(), -1)) {
	this_player()->tell_me("You can't do that here; possibly\
 because of PK-restrictions.");
	return 1;
    }

    if ((int) this_player()->set(PLR_COMBAT_QUEUE, action) == 1)
	start_cold(this_player());

    return (speed_kill = 1);
}

// No more multiple wands in a bag. --Val
int prevent_insert()
{
    this_player()->tell_me(
      "The wand starts to sputter ice droplets as you try that.\n\
You think it is safer to keep it out of it.");
    return 1;
}
