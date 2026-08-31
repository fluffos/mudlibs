#include <std.h>
#include <daemons.h>
#include <rooms.h>

inherit ROOM;

void verify_advance(string input, object tp);
void do_advance(object tp);
void verify_roll(string input, object tp);
void do_roll(object tp);

string *HALL_CMDS = ({
  "start", "roll", "train", "improve", "advance", "list"
});

string type;

void create() {
  ::create();
  set_properties( ([
    "no attack" : 1,
    "no magic" : 1,
    "no teleport" : 1,
    "no bump" : 1,
    "no castle" : 1,
    "indoors" : 1,
    "light" : 2,
  ]) );
}

void init() {
  ::init();
  foreach (string str in HALL_CMDS)
    add_action("cmd_"+str, str);
}

// unused
void set_type(string str) { type = str; }
string query_type() { return type; }
// ---

int cmd_start(string str) {
  object tp = this_player();
  if (!str || str != "here")
    return notify_fail("Start where?");

  tp->set_primary_start(base_name(this_object()));
  message("info", "You are now set to start here.", tp);
  return 1;
}

int cmd_roll(string str) {
  object tp = this_player();
  mixed *tmp;

  if (!str || str != "stats")
    return 0;

  // if any stats are over 25, show a warning
  tmp = tp->query_all_stats();
  tmp = map(tmp, (: $2->query_stats($1) :), tp);
  tmp = filter(tmp, (: $1 >= 25 :) );
  if (sizeof(tmp)) {
    message("info",
      "This will reset all of your stats to beginning levels.\n"
      "The experience points spent on them will not be reimbursed.\n"
      "Are you sure you wish to reroll your stats? (y/n) ", tp);
    input_to("verify_roll", tp);
  }
  else
    do_roll(tp);
  return 1;
}

void verify_roll(string input, object tp) {
  input = strip_color(lower_case(input));
  switch (input) {
    case "y":
    case "yes":
      do_roll(tp);
    break;
    default:
      message("info", "You have chosen not to reroll your stats.", tp);
  }
}

void do_roll(object tp) {
  ADVANCE_D->roll_stats(tp);
}

int cmd_list(string str) {
  object tp = this_player();
  mixed num;
  
  if (!str)
    num = 0;
  else
    num = to_int(str);

  if (!intp(num) || num < 0)
    return notify_fail("Syntax: <list> or <list [number]>");

  ROOM_QUEST->list_quests(tp, num);

  return 1;
}

int cmd_advance(string str) {
  object tp = this_player();
  if (tp->getenv("ASK_ADVANCE")) {
    message("info",
      "Are you sure you wish to advance to the next level? (y/n) ", tp );
    input_to("verify_advance", tp);
  }
  else {
    do_advance(tp);
  }
  return 1;
}

void verify_advance(string input, object tp) {
  input = strip_color(lower_case(input));
  switch (input) {
    case "y":
    case "yes":
      do_advance(tp);
    break;
    default:
      message("info", "You have chosen not to advance.", tp);
  }
}

void do_advance(object tp) {
  ADVANCE_D->advance_level(tp);
}

int cmd_train(string str) {
  object tp = this_player();
  string skill, tmp;
  int exp;

  if (str) {
    if (sscanf(str, "%s %d", skill, exp) != 2)
      sscanf(str, "%s %s %d", skill, tmp, exp);
    if (tmp && sizeof(tmp) && skill && sizeof(skill))
      skill += " "+tmp;
  }

  if (!str || !sizeof(skill) || !exp)
    return notify_fail("Syntax: <train [skill] [amount]>");

  skill = strip_color(lower_case(skill));

  ADVANCE_D->train_skill(tp, skill, exp);

  return 1;
}

int cmd_improve(string str) {
  object tp = this_player();

  if (!str)
    return notify_fail("Syntax: <improve [stat]>");

  str = strip_color(lower_case(str));

  ADVANCE_D->improve_stat(tp, str);

  return 1;
}


