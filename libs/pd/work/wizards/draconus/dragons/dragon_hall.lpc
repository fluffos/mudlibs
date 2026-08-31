#include <std.h>
#include <rooms.h>
#include <council.h>
#include <daemons.h>
#define FAULT "A magical force holds you back."
#include <sindarii.h>
inherit ROOM;

int get_cost(string which, int lev);

void create() {
    object ob;
    ::create();
    set_property("no attack",1);
    set_property("no magic", 1);
    set_property("no teleport", 1);
    set_property("no bump", 1);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no gate", 1);
    set("short", "The top of a tower where Dragons roam.");
    set("long",
        "Welcome to the tower of the Dragons! "
        "Dragons come here to relax from the toils of the mortals.  "
        "The available commands are <cost>, <advance>, <list (number)>, "
        "<improve stat>, <train skill amount>, and <roll stats>.  Down "
        "through a passage "
        "guarded by a shimmering blue light is the "
        "entrance to the tower.  "
        "<help skills> will list all skills with their full, proper names."
        "  You must not show this place to mortal eyes.");
    set_exits(
              (["down" : "/d/standard/cemetary/building"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "dragon board", "bulletin board"}) );
    ob->set_board_id("dragon_board");
    ob->set_max_posts(25);
    ob->set_edit_ok(DRAGON_COUNCIL);
    ob->set_location(ROOMS "dragon_hall");
    ob->set("short", "the Ancient board of Dragons.");
    ob->set("long",
        "It is a huge scale from the biggest dragon of all. Used by "
        "the smaller to help in the battle against the mortals.\n");
}

void init() {
    ::init();
    add_action("train", "train");
    add_action("improve", "improve");
    add_action("advance","advance");
  }

int advance() { return (int)ADVANCE_D->advance(); }

int train(string str) {
    string which, which_tmp;
    int amount;

    if(!str) {
        notify_fail("Corract syntax: <train skill amount.\n");
        return 0;
    }
    if(sscanf(str, "%s %s %d", which, which_tmp, amount) == 3) which = which +"
"+ which_tmp;
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

    stats = ({ "strength", "intelligence", "wisdom", "dexterity",
"constitution", "charisma" });
    if(!str) {
        notify_fail("Improve what?\n");
        return 0;
    }
    str = lower_case(str);
    if(member_array(str, stats) == -1) {
        notify_fail("You have no such stat.\n");
        return 0;
    }

    stat_cost = get_cost(str, (int)this_player()->query_base_stats(str)+1);
    if ((int)this_player()->query_exp()-stat_cost < 1)
      {
       notify_fail("You are not experienced enough to improve yourself in that
way\n");
       return 0;
      }

    this_player()->set_stats(str, (int)this_player()->query_base_stats(str) +1);
    this_player()->add_exp(-stat_cost);
    message("no_wrap","You feel much ", this_player());
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
        case "intelligence": return (int)ADVANCE_D->get_stat_cost(1, lev,stat);
break;
        case "constitution": return (int)ADVANCE_D->get_stat_cost(1, lev,stat);
break;
        case "strength" : return (int)ADVANCE_D->get_stat_cost(1, lev,stat);
break;
        case "wisdom": return (int)ADVANCE_D->get_stat_cost(1, lev,stat);
break;
         case "dexterity" : return (int)ADVANCE_D->get_stat_cost(1, lev, stat);
break;
         case "charisma" : return (int)ADVANCE_D->get_stat_cost(1, lev, stat);
break;
        default: return (int)ADVANCE_D->get_stat_cost(2, lev, stat); break;
    }
}

int cost(string str) {
    int bing;

    write("Costs for advancement, training, and improvement:\n");
    bing = (int)ADVANCE_D->get_exp( (int)this_player()->query_level() + 1 );
    if(bing < 1) write("level:\t\tIt will cost you nothing to advance.");
    else write("level:\t\t"+bing+"\n");
    write("\nskills: You train by spending the amount of experience you
desire.\n");
    write("\n");
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
