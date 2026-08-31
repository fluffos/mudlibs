#include <config.h>
#include <std.h>
#include <radyne.h>
#include <daemons.h>
#include <rooms.h>

inherit ROOM;

int get_exp(int lev);
int train_player(object tp, string which, int amount);
int get_cost(string which, int lev);
int get_stat_cost(int x, int lev);

void create() {
  object ob;
  
  ::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
                    "indoors"     : 1,
                    "no steal"    : 1 ]) );
  set_short("Adventurer's Hall");
  set_long( 
        "%^CYAN%^Tirun adventurer's hall.%^RESET%^\n"
        "People that are not a member of a class meet here to discuss "
        "their adventuring, train their stats and skills, and to level.  "
        "The Colleseum entrance is to the south.  Against the "
        "east wall is a staircase leading up."  );
    set_exits( ([
                   "down" : ROOMS"ombud_hall",
                     "up" : ROOMS"booth",
                  "west" : ROOMS"adv_enter",
                  "south" : "/d/arena/bet",
             ]) );
  set_items( ([
        "hall" : "One of the exits leading out of this place.",
        "stairs" : "Cut from marble, they lead up.",
        "staircase" : "Cut from marble, they lead up."
           ]) );

  ob = new("std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "bulletin board", "adventure board" }) );
  ob->set_board_id("adv_board");
  ob->set("short", "The Adventure Board");
  ob->set("long", "An old cork board where the adventurers "
          "who pass through Tirun post information on the "
          "things they have discovered.\n");
  ob->set_max_posts(99);
  ob->set_location(ROOMS"adv_hall");

}

void init() {
    ::init();
    add_action("roll","roll");
    add_action("train", "train");
    add_action("improve", "improve");
    add_action("advance","advance");
    add_action("list","list");
}
int go_down() {
  if(!wizardp(this_player())) {
    write("%^BLUE%^%^BOLD%^You cannot penetrate the force of the blue light.");
    say(this_player()->query_cap_name()+" tries to get through the "
        "passage, but fails.", this_player());
    return 0;
  }
  return 1;
}

int get_exp(int lev) {
    int val;

    switch(lev) {
        case 0: val = 0; break;
        case 1: val = 1014; break;
        case 2: val = 2028; break;
        case 3: val = 3056; break;
        case 4: val = 4800; break;
        case 5: val = 6200; break;
        case 6: val = 9100; break;
        case 7: val = 12500; break;
        case 8: val = 15000; break;
        case 9: val = 20000; break;
        case 10: val = 28000; break;
        case 11: val = 40000; break;
        case 12: val = 55000; break;
        case 13: val = 72000; break;
        case 14: val = 104000; break;
        case 15: val = 150000; break;
        default: val = (lev-12)*(lev-15)*28000 + 150000;
    }
    return val;
}
int roll(string str) {
    if(str != "stats") return 0;
    ROOM_SETTER->do_rolls();
    return 1;
}

int advance() { return (int)ADVANCE_D->advance(); }

int train(string str) {
    string which, which_tmp;
    int amount;

    if(!str) {
        notify_fail("Correct syntax: <train skill amount>\n");
        return 0;
    }
    if(sscanf(str, "%s %s %d", which, which_tmp, amount) == 3) which = which+ " "+ which_tmp;
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
    string adj;
    int stat_cost;

    if (!str)
      {
       notify_fail("Improve what?\n");
       return 0;
      }
    stats = ({ "strength", "intelligence", "wisdom", "dexterity", "constitution", "charisma" });
    str = lower_case(str);
    if(member_array(str, stats) == -1) {
        notify_fail("You have no such stat.\n");
        return 0;
    }
    stat_cost = get_cost(str, (int)this_player()->query_base_stats(str)+1);
    if( (int)this_player()->query_exp()-stat_cost < 0 ) {
        notify_fail("You are not experienced enough to improve yourself in that way.\n");
        return 0;
    }
    this_player()->set_stats(str, (int)this_player()->query_base_stats(str) + 1);
    this_player()->add_exp(-stat_cost);
    adj = (str == "strength" ? "stronger" : (str == "intelligence" ? "more intelligent" :
      (str == "wisdom" ? "wiser" : (str == "dexterity" ? "more nimble" :
      (str == "constitution" ? "sturdier" : "more attractive")))));
    message("my_action", sprintf("You look %s.", adj), this_player());
    message("other_action", sprintf("%s looks much %s",
      (string)this_player()->query_cap_name(), adj), environment(this_player()),
      ({ this_player() }));
    return 1;
}

int get_cost(string blah, int lev) 
{ 
return (int)ADVANCE_D->get_stat_cost(2, lev, blah);
return get_stat_cost(1, lev); 
}
int get_stat_cost(int x, int lev) {
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

