
#include <std.h>
#include <dragonevent.h>
#include <daemons.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 1, "indoors" : 1, "mountain" : 1,
  ]) );
  set_short("a cave");
  set_long(
    "Several torches line the walls here. The cave extends off to the "
    "west. The ceiling is impossibly high overhead, and a wall of "
    "rough rock stands almost as high to the east. Most of the surfaces "
    "have been smoothed down."
  );
  set_items( ([
    "torches" : "Basic oil torches that are set into holes "
      "bored into the walls.",
    "walls" : "Smooth rock with an occaisonal vein of color.",
    "cave" : "A tunnel through the mountain.",
    "ceiling" : "Looking up that high makes you dizzy.",
    "wall" : "The wall to the east is incredibly high, rough rock.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "up" : DRAG_ROOMS+"bluepath2",
    "west" : DRAG_ROOMS+"entryblue",
  ]) );
  add_invis_exit("up");
  add_pre_exit_function("up", "check_wings");
}

int check_wings() {
  object tp = this_player();
  if (sizeof(regexp(tp->query_limbs(), "wing")) >= 2 ||
      tp->query_race() == "vampire") {
        message("info", "You fly up.", tp);
        if (!tp->query_invis())
          message("info", tp->query_cap_name()+" flies up.",
            environment(tp), tp);
        return 1;
  }

  if (tp->is_player() &&
      sizeof(regexp(RACE_D->query_limbs(tp->query_race()), "wing")) >= 2)
        message("info", "You try to fly up, but you are missing a wing.", tp);
  else
    message("info", "You can't climb back up, you would have to have wings.", tp);

  return 0;
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

