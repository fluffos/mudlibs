
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

int pre_show_msg();
void post_show_msg();
int check_wings();

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 1, "indoors" : 1, "mountain" : 1,
  ]) );
  set_short("a cave");
  set_long(
    "The wide floor through the cave ends abruptly here, dropping "
    "down a dizzying distance. The ceiling is a high dome that "
    "allows room for careful flight by the dragons. A glow comes from "
    "the west, far down at the bottom of the sudden drop."
  );
  set_items( ([
    "floor" : "It is very smooth and quite wide.",
    "cave" : "Rocky walls that form a tunnel through the mountain.",
    "ceiling" : "It is a rough dome shape far above.",
    "glow" : "A flickering glow that is probably fire, but it is "
      "too far away to tell.",
    "drop" : "The drop is quite far, but it looks like one could "
      "climb down carefully.",
  ]) );
  set_exits( ([
    "northeast" : DRAG_ROOMS+"bluepath3",
    "down" : DRAG_ROOMS+"bluepath1",
  ]) );
  add_pre_exit_function("down", "pre_show_msg");
  add_post_exit_function("down", "post_show_msg");
}

int pre_show_msg() {
  object tp = this_player();
  if (check_wings()) {
    message("info", "You fly down.", tp);
    if (!tp->query_invis())
      message("info", tp->query_cap_name()+" flies down.",
        environment(tp), tp);
  }
  else
    message("info", "You carefully climb down the wall.", tp);

  return 1;
}

void post_show_msg() {
  if (!check_wings())
    message("info", "Looking up, it would be impossible "
      "to climb back up that.", this_player());
}

int check_wings() {
  object tp = this_player();
  if (sizeof(regexp(tp->query_limbs(), "wing")) >= 2 ||
      tp->query_race() == "vampire")
        return 1;

  return 0;
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }
}

