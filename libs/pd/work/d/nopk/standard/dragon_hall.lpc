#include <std.h>
#include <sindarii.h>
#include <config.h>
#include <council.h>
#include <daemons.h>
inherit ROOM;

string get_new_title(object tp);
string get_male(int lev);
string get_female(int lev);
string previous_title(object tp);
int get_cost(string which, int lev);


void create() {
    object ob;

    ::create();
    set_property("no attack",1);
    set_property("light", 1);
    set_property("indoors", 1);
    set("short", "The Dragon Guild Hall");
    set_long("Welcome to the chamber of the Wyrm-Lords!\n"
        "This hideout has been dug into the "
        "surrounding rock by dragon claws. The available commands are "
        "<cost>, <advance>, <list [number]>, <train [skill] [amount]>, "
        "<improve [stat]>, and <roll stats>. A tunnel leads back up, "
        "out of the hall.");
    set_smell("default", "A dank and musty smell fills the air.");
    set_exits( 
	      (["up" : ROOMS"square",
		"east" : ROOMS"dragon_vote"]));
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "dragon board" }) );
    ob->set_board_id("dragon_board");
    ob->set_max_posts(50);
    ob->set_edit_ok("inferno");
    ob->set_location(ROOMS"dragon_hall");
    ob->set("short", "%^RESET%^%^GREEN%^The Dragon Guild Board");
    ob->set("long", "An old wooden board for dragons to post "
            "their messages and news on.");
}

void init() {
    ::init();
/*    add_action("cost","cost");
    add_action("murder", "murder"); */
    add_action("roll","roll");
    add_action("train", "train");
    add_action("improve", "improve");
    add_action("advance","advance");
    add_action("list","list");
  }

int roll(string str) {
    if(str != "stats") return 0;
    call_other(ROOMS"setter", "do_rolls");
    return 1;
}

string get_new_title(object tp)
{
    int lev;
    string gen, title;

    lev = (int)this_player()->query_level();
    gen = (string)this_player()->query_gender();
    if(this_player()->query_guild()) {
	if(present((string)tp->query_guild()+"_ob", tp)) {
	    if(lev > 19) title = "High mortal";
	    else title = (string)present((string)tp->query_guild()+"_ob", tp)->query_title(tp);
	    title += " $N";
	}
	else {
	    if(lev > 19) title = "High mortal $N";
	    else title = "$N";
	}
    }
    else {
	if(lev > 20) title = "High mortal $N";
	else title = "$N";
    }
    if(lev > 20) title += previous_title(tp);
    else if(gen == "male") title += " "+get_male(lev);
    else title += " "+get_female(lev);
    return title;
}

string get_male(int lev) {
    switch(lev) {
        case 1:  return "the new born dragon";       break;
        case 2:  return "the minor hatchling";       break;
        case 3:  return "the little hatchling";      break;
        case 4:  return "the hatchling";             break;
        case 5:  return "the trouble-maker";         break;
        case 6:  return "the tiny wyrm";             break;
        case 7:  return "the mischivous wyrm";       break;
        case 8:  return "the booger factory";        break;
        case 9:  return "the fire spitter";          break;
        case 10: return "the flame dancer";          break;
        case 11: return "the minor pyro";            break;
        case 12: return "the pseudodragon";          break;
        case 13: return "the flight attemptee";      break;
        case 14: return "the little dragon";         break;
        case 15: return "the cattle chewer";         break;
        case 16: return "the farm ravager";          break;
        case 17: return "the devestator";            break;
        case 18: return "the city-scourge";          break;
        case 19: return "the flaming hellkite";      break;
        case 20: return "the great wyrm";            break;
	default: return "";                          break;
    }
}

string get_female(int lev) {
    switch(lev) {
//	case 8: return "the man eater"; break;
	default: return get_male(lev); break;
    }
}

int advance() { return (int)ADVANCE_D->advance(); }

int train(string str) {
    string which, which_tmp;
    int amount;

    if(sscanf(str, "%s %s %d", which, which_tmp, amount) ==3) which = which + " "+ which_tmp;
    else if(sscanf(str, "%s %d", which, amount) !=2) {
	notify_fail("Correct syntax: <train skill amount>\n");
	return 0;
    }
    which = lower_case(which);
    if(!this_player()->skill_exists(which)) {
	notify_fail("No such skill.\n");
	return 0;
    }
    return (int)ADVANCE_D->train_player(this_player(), which, amount);
}

int improve(string str) {
    string *stats;
    int stat_cost;

    stats = ({ "strength", "intelligence", "wisdom", "dexterity", "constitution", "charisma" });
    str = lower_case(str);
    if(member_array(str, stats) == -1) {
	notify_fail("You have no such stat.\n");
	return 0;
    }
    stat_cost = get_cost(str, (int)this_player()->query_base_stats(str));
    if( (int)this_player()->query_exp()-stat_cost < (int)ADVANCE_D->get_exp( (int)this_player()->query_level() ) ) {
	notify_fail("You are not experienced enough to improve yourself in that way.\n");
	return 0;
    }
    this_player()->set_stats(str, (int)this_player()->query_base_stats(str) + 1);
    this_player()->add_exp(-stat_cost);
    write("You feel much ");
    say(this_player()->query_cap_name()+" looks much ");
    if(str == "strength") tell_room(this_object(), "stronger.\n");
    else if(str == "intelligence") tell_room(this_object(), "more intelligent.\n");
    else if(str == "wisdom") tell_room(this_object(), "wiser.\n");
    else if(str == "dexterity") tell_room(this_object(), "more nimble.\n");
    else if(str == "constitution") tell_room(this_object(), "sturdier.\n");
    else tell_room(this_object(), "more attractive.\n");
    return 1;
}

int get_cost(string stat, int lev) {
    switch(stat) {
  	case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
	case "dexterity": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
	case "charisma": return (int)ADVANCE_D->get_stat_cost(1, lev,stat); break;
  	default: return (int)ADVANCE_D->get_stat_cost(2, lev,stat); break;
    }
}

int cost(string str) {
    int bing;
 
    write("Costs for advancement, training, and improvement:\n");
    bing = (int)ADVANCE_D->get_exp( (int)this_player()->query_level() + 1 );
    if(bing < 1) write("level:\t\tIt will cost you nothing to advance.");
    else write("level:\t\t"+bing+"\n");
    write("skills: You train by spending the amount of experience you
desire.\n");
    write("strength:\t\t" + get_cost("strength",
(int)this_player()->query_base_stats("strength")) +
"\t\tconstitution:\t\t" + get_cost("constitution",
(int)this_player()->query_base_stats("constitution")) );
    write("intelligence:\t\t" + get_cost("intelligence",
(int)this_player()->query_base_stats("intelligence")) +
"\t\tdexterity:\t\t" + get_cost("dexterity",
(int)this_player()->query_base_stats("dexterity")) );
    write("wisdom:\t\t" + get_cost("wisdom",
(int)this_player()->query_base_stats("wisdom")) +
"\t\tcharisma:\t\t" + get_cost("charisma",
(int)this_player()->query_base_stats("charisma")) );
    return 1;
}
string previous_title(object tp) {

    string pre, post, str;

    str = (string)tp->getenv("TITLE");
    sscanf(str, "%s $N %s", pre, post);
    return post;
}

int list(string str) {
    int x;

    if(!str) ROOMS"quest_room"->list_quests(this_player(), 0);
    else {
	if(sscanf(str, "%d", x) != 1) {
	     notify_fail("You must give the number of the quest you want listed.\n");
	    return 0;
	}
	if(x<1) {
	    notify_fail("No such quest.\n");
	    return 0;
	}
	ROOMS"quest_room"->list_quests(this_player(), x);
    }
    return 1;
}

int murder() {
    if(this_player()->query_skill("murder")) return 0;
    this_player()->add_skill("murder", 3, 100);
    write("Done.\n");
    return 1;
}

