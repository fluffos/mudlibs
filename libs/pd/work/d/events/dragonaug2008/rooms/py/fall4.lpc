#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/fallbase";

void create() {
  ::create();
  set_exits( ([
    "east" : DRAG_ROOMS"py/fall4",
    "west" : DRAG_ROOMS"py/fall4",
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
}

void heart_beat() {
  ::heart_beat();
  if(!player()) return;

  //time triggers
  switch(beats()) {
    case 1:
      SAY("The log is falling swiftly through the air.");
      break;
    case 4:
      if(DRAG_D->query_data("cavelogramp:"+player()->query_name())) {
        SAY("You hear a loud thud! Through the end of the log, you see that the log has fallen between two long metal rails.");
        player()->move(DRAG_ROOMS"py/fall9");
        all_inventory(this_object())->move(environment(player()));
      }
      SAY("The log begins to spiral wildly out of control!");
      break;
    case 6:
      SAY("The log twists end-side up, you can see the ground looming before you!");
      break;
    case 8:
      SAY("The log smashes against the ground!");
      if(!harm_player(player(), player()->query_max_hp()*0.9)) return;
      SAY("A large chunk of wood impales you in the torso!");
      if(!harm_player(player(), player()->query_max_hp()*6)) return;
      SAY("A large rock smashes your skull!");
      if(!harm_player(player(), player()->query_max_hp()*60)) return;
      SAY("A rabbid raccoon runs up and bites you in the groin!");
      if(!harm_player(player(), player()->query_max_hp()*600)) return;
      SAY("Your eyeballs explode!");
      if(!harm_player(player(), player()->query_max_hp()*6000)) return;
      break;
  }
}
