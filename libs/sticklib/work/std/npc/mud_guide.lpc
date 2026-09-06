#include "/sys/interactive_info.h"
#include "/sys/object_info.h"

#include <npc.h>
#include <mud_name.h>

string *route;
object follower;

void load_travel();
status move_follower(string s);
void remove_follower();
status stop_follow();

void
create_monster()
{
    set_name("guide");
    set_short("A tour guide");
    set_id(({"mud_guide", "tour guide"}));
    set_race("human");
    set_alignment(AL_NEUTRAL);
    set_gender(G_MALE);
    set_level(20);
    set_wc(10, 1);
    set_ac(0, 1);
    set_hp(30);
    set_ep(0); // No exp!
    set_long("Your local guide to "+MUD_NAME+".\n\
Type 'follow guide' for a guided tour to the village, and 'follow' to quit it.");
    load_travel();
}

void
init_monster()
{
    if (this_player() && object_info(this_player(), OI_ONCE_INTERACTIVE))
	add_action("follow","follow");
}

status
start_travel()
{
    remove_call_out("start_travel");
    call_out("travel",1,0);
    return 1;
}

status
travel(int nr)
{
    string message,action;
    int time_to_next;
    remove_call_out("travel");
    if (!follower || !interactive_info(follower, II_IP_NUMBER)) {
	// follower quitted or went ld
	this_object()->move_player("Vsighs and teleports to temple yard.",
	  "/room/church");
	follower = 0;
	return 1;
    }
    sscanf(route[nr],"%d#%s#%s", time_to_next, action, message);
    if (message && message != "")
	environment() -> tell_here("Guide says: "+message+".", this_object());
    if (action && action!="") {
	init_command(action);
	move_follower(action);
    }
    if (!time_to_next) {
	remove_follower();
	return 1;
    }
    call_out("travel", time_to_next, nr + 1);
}

status
move_follower(string dir)
{
    if (dir == "enter booth")
	dir = "and enters booth";
    follower -> move_player("Vfollows the guide "+dir, environment());
    follower -> tell_me("You follow the guide.");
    return 1;
}

void
remove_follower()
{
    follower -> tell_me("You stop following the guide.");
    follower = 0;
}

void
new_novice(object novice)
{
    // call_other from new_novice-object to report that a new utter has entered
    if (object_name(environment()) == "room/church") {
	environment() -> tell_here(
	  "Guide says: Welcome to "+MUD_NAME+", "+capitalize((string) novice->query_real_name()) + "!",
	  this_object());
	if (follower) novice -> tell_me(
	      "Guide tells you: I have a customer at the moment, but if you want a guided\
tour to the village, wait in the temple yard and type 'follow guide' when I\
arrive.\n\
Guide tells you: In the meanwhile, why not type 'help' to see what the game\
commands are?");
	else environment()->tell_here(
	      "Guide says: If you want a guided tour to the village, type: follow guide.\n\
Guide says: To get information about how to play the game, type: help.",
	      this_object());
    } else   // if not in temple yard.
	novice -> tell_me(
	  "Guide tells you: Welcome to "+MUD_NAME+", "+capitalize((string)
	    novice->query_real_name())+"!\n\
Guide tells you: I am on a tour at the moment, but if you want a guided tour to\
the village, wait at the temple yard and type 'follow guide' when I return\
there.\n\
Guide tells you: In the meanwhile, why not type 'help' to see what the game\
commands are?");
    return;
}

status
follow(string str)
{
    if (!str || str == "") {
	if (this_player() == follower) {
	    stop_follow();
	    return 1;
	}
	return notify_fail("Follow what (or who)?\n"), 0;
    }
    if (!id(str)) return notify_fail("Follow what (or who?)\n"), 0;
    if (follower == this_player()) {
	follower -> tell_me("Guide says: But you are following me\
already. If you want to end the tour, type 'follow'.");
	return 1;
    }
    if (follower) {
	this_player()->tell_me("Guide tells you: I have a customer\
at the moment, please wait for your turn.");
	return 1;
    }
    if (object_name(environment()) != "room/church") {
	this_player() -> tell_me("Guide says: Please go to the temple\
yard and wait for me there.");
	return 1;
    } 
    follower = this_player();
    // log_file("tour_guide",capitalize(follower->query_real_name())+"\n");
    // Urgh. Who needs these logs?!? -+ Doomdark +-
    this_player()->tell_me("You start to follow the guide.");
    call_out("start_travel", 1);
    return 1;
}

status
stop_follow()
{
    follower -> tell_me("You stop following the Guide.\n\
The Guide bows to you.");
    move_player("Vteleports to the temple yard", "/room/church");
    follower = 0;
    remove_call_out("travel");
    return 1;
}

void
load_travel()
{
    route = ({
      "3##Welcome to the guided tour to the village of "+MUD_NAME+". I'm your personal\
 guide on this tour and I hope you'll enjoy it",
      "3##If you want to leave the tour type 'follow'",
      "2##Now, let's start the tour",
      "8##This is the temple yard, where you start when you enter the game",
      "10#south#Ok, let's go south to see what we can find there",
      "8##On and around market square you'll find most of the most important\
 places in the village, so let's take a tour around it",
      "10#east#We'll continue east",
      "8##To the east we have the Adventurer's Guild, which is a very\
 important place for mudders. You can find boards in it on where you can read\
 important messages from your fellow mudders",
      "6##You can also raise your level and stats there, and find out what\
 quests you need to do",
      "6##To the northeast is the bank, where you can deposit your hard\
 earned money",
      "10##In this place is also the tool shop, where you can get some free\
 items. Type 'exa shop' and 'list' to see what you can get",
      "15##You can get the tools by typing 'get pointed stick', for instance",
      "8##The quicktyper is a tool for making aliases for commands and the\
 pointed stick is a weapon that you can wield",
      "10#southwest#If you didn't get the items now, you can return here later to\
 get them. Let's go southwest",
      "6##This is the central point of the village",
      "10##If you want to look at the map, type 'look at map' or 'exa map'",
      "8##To the southwest is the bench, where you can sit and chat with\
 your friends, and the enterance to the village pub",
      "10#northwest#We'll continue northwest",
      "8##In the Common Shop you can sell and buy all items, except armours\
 and weapons, which are sold and bought in the armoury and weaponery",
      "8##In the post office you can send letters to your friends in this mud",
      "8#east#Let's go back to the Temple Yard",
      "4#north##",
      "4##I hope you enjoyed this tour. For more information\
 the board in the adventurers' guild and the newspaper",
      "4##For information about game commands type 'help'",
      "4##If you ask other players politely, they will also help you",
      "0##I wish you happy mudding and hope you enjoy playing here"
    });
}
