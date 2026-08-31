#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/fallbase";

string swayDir, counterSwayDir;
int swaying;
int mistakes;

void create() {
  ::create();
  set_exits( ([
    "east" : DRAG_ROOMS"py/fall3",
    "west" : DRAG_ROOMS"py/fall3",
  ]) );
  add_pre_exit_function("east", "no_leave");
  add_pre_exit_function("west", "no_leave");
}

int no_leave() {
  SAY("The log is way too unstable for you to leave now.");
  return 0;
}

void new_player(object ob) {
  set_real_long("The inside of a hollow log. It is very cramped, the curved walls of the log press in all around.");
  swaying = 0;
  mistakes = 0;
}

void init() {
  ::init();
  add_action("sway_log", ({"lean", "push", "hide", "jump", "sway"}) );
  add_action("no_escape", ({ "climb", "run", "escape", "hop"}) );
}

int no_escape(string str) {
  SAY("You dare not to leave the safety of the log.");
  return 1;
}

int start_sway(string dir, string counter) {
  if (swaying) {
    SAY("The log has become unseated and begins to plummet!");
    player()->move(DRAG_ROOMS"py/fall4");
    all_inventory(this_object())->move(environment(player()));
    return 0;
  }
  swaying = 1;
  swayDir = dir;
  counterSwayDir = counter;
  SAY("The log begins to sway "+dir+".");
  return 1;
}

int sway_log(string str) {
  if(str == "n") str = "north";
  else if(str == "s") str = "south";
  else if(str == "e") str = "east";
  else if(str == "w") str = "west";
  else if(str == "nw") str = "northwest";
  else if(str == "ne") str = "northeast";
  else if(str == "se") str = "southeast";
  else if(str == "sw") str = "southwest";
  if(!str) {
    SAY(query_verb()+" in what direction?");
    return 1;
  }
  if(str != counterSwayDir && str != "to the "+counterSwayDir && str != "log to the "+counterSwayDir && str != "log "+counterSwayDir) {
    SAY("Your "+query_verb()+"ing "+str+" makes the branch more unstable.");
    mistakes++;
    if(mistakes > 6+random(10)) start_sway("down", "YOU'LL NEVER GUESS THIS");
    return 1;
  }
  SAY("You manage to stop the log from swaying.");
  swaying = 0;
  return 1;
}

void heart_beat() {
  ::heart_beat();
  if(!player()) return;

  //time triggers
  switch(beats()) {
    case 3:
      if(!start_sway("south", "north")) return;
      break;
    case 7:
      if(!start_sway("south", "north")) return;
      break;
    case 10:
      if(!start_sway("north", "south")) return;
      break;
    case 13:
      if(!start_sway("west", "east")) return;
      break;
    case 15:
      if(!start_sway("east", "west")) return;
      break;
    case 17:
      if(!start_sway("north", "south")) return;
      break;
    case 19:
      if(!start_sway("northwest", "southeast")) return;
      break;
    case 21:
      if(!start_sway("northeast", "southwest")) return;
      break;
    case 23:
      if(!start_sway("south", "north")) return;
      break;
    case 25:
      if(!start_sway("southwest", "northeast")) return;
      break;
    case 27:
      if(!start_sway("southeast", "northwest")) return;
      break;
    case 29:
      if(!start_sway("northwest", "southeast")) return;
      break;
    case 31:
      if(!start_sway("southeast", "northwest")) return;
      break;
    case 33:
      if(!start_sway("east", "west")) return;
      break;
    case 34:
      if(!start_sway("north", "south")) return;
      break;
    case 35:
      if(!start_sway("south", "north")) return;
      break;
    case 36:
      if(swaying) { start_sway("down", "TRY And gUESS"); return; }
      SAY("Things seem to have settled down a bit...");
      DRAG_D->set_data("cavelogsway:"+player()->query_name(), 0);
      player()->move(DRAG_ROOMS"py/fall5");
      all_inventory(this_object())->move(environment(player()));
      break;
  }
}
