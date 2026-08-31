
#include <std.h>
#include <dragonevent.h>

inherit BEACH;

int toggle = -1;
string long =
  "This cove is covered by a large jut of rock, making it appear to "
  "actually be inside the mountain. Jagged spines of rock split the "
  "waters just off the beach, and several wait on the beach to split "
  "the feet of careless travelers. The sand here is very coarse "
  "and clumped."
;

void check_cave();

void create() {
  ::create();
  set_properties( ([ "light" : 0, "night light" : 0, "no teleport" : 1,
    "indoors" : 1, "beach" : 1, ]) );
  set_short("a dark cove");
  set_long(long);
  set_items( ([
    "rock" : "The entire ceiling is rock.",
    "mountain" : "It is above you.",
    "spines" : "Thin, sharp pieces of rock that stick up at angles.",
    "beach" : "The beach sand is a dark and coarse grain mixed with dirt. "
      "Its small arc is covered by mountain rock.",
  ]) );
  set_letter("n");
  check_cave();
}

void init() {
  ::init();
  check_cave();
  if (DRAG_D->query_data("speechguidedragon") == 1 && !sizeof(children(DRAG_MOBS+"guidedragon")))
    load_object(DRAG_ROOMS+"guidedragon")->move(this_object());
}

void check_cave() {
  int ok = DRAG_D->query_data("eventstarted") || DRAG_D->query_data("eventfinished");
  if (DRAG_D->query_data("testing")) ok = 0;
  if (toggle == -1) toggle = !ok;
  if (!toggle && ok) {
    toggle = !toggle;
    set_item("cave", "It looks a little brighter inside.");
    set_long(long+" The beach ends abruptly at a cave opening.");
    add_exit(DRAG_ROOMS+"ogre69", "enter");
  }
  else if (toggle && !ok) {
    toggle = !toggle;
    remove_item("cave");
    set_long(long);
    remove_exit("enter");
  }
}

void reset() {
  object ob;
  ::reset();

  if (!sizeof(children(DRAG_MOBS+"dragon_swim2"))) {
    ob = new(DRAG_MOBS+"dragon_swim2");
    ob->set_rooms(DRAG_ROOMS+"ogrebeach", DRAG_ROOMS+"swimming", DRAG_ROOMS+"beach");
    ob->move(this_object());
  }

  if(0 && !present("microphone")) {

    ob = new("/wizards/pyro/personal/microphone");
    if(ob) {
      ob->set_microphone_name(path_file(file_name(this_object()))[1]);
      ob->set_owner(DRAG_D);
      ob->set_invincible(1);
      ob->move(this_object());
    }
  }
}
