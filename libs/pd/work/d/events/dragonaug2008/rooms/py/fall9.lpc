#include <std.h>
#include <dragonevent.h>
#include <rest.h>

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
      SAY("The log begins to slide down the metal bars.");
      break;
    case 4:
      SAY("The log picks up speed, hurtling towards the ground!");
      break;
    case 7:
      SAY("The log smashes into the ground, hurling you forward into the ground before shattering to splinters.");
      new(DRAG_ITEMS"splinters")->move(this_object());
      player()->move(DRAG_ROOMS"py/3");
      all_inventory(this_object())->move(environment(player()));
      if(!harm_player(player(), player()->query_max_hp()*0.35)) return;
      player()->set_rest_type(LAY);
      DRAG_D->set_data("cavestage:"+player()->query_name(), 7);
      break;
  }
}
