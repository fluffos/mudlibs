
#include <std.h>
#include <daemons.h>
#include <dragonevent.h>

inherit OBJECT;

int remove();

void create() {
  ::create();
  set_name("gem");
  set_id( ({ "gem" }) );
  set_weight(1);
  set_heart_beat(10);
}

void init() {
  ::init();
}

void heart_beat() { if (!environment()) remove(); }

int get() {
  object env = environment();
  object room;
  object *placers;
  if (env && base_name(env) == DRAG_ITEMS+"pillar" && (room = environment(env)) ) {
    DRAG_D->set_data("gemsplaced", DRAG_D->query_data("gemsplaced")-1 );
    placers = DRAG_D->query_data("gemplacers");
    placers -= ({ this_object()->query_property("gem_placed_by") });
    DRAG_D->set_data("gemplacers", placers);
    if (DRAG_D->query_data("gemsplaced") == 0) {
      object tp = this_player();
      DOOR_D->set_door_status(DRAG_GEM_DOOR_ID, "default");
      DOOR_D->message_rooms_with_door(DRAG_GEM_DOOR_ID,
        "%^YELLOW%^The magical barrier suddenly vanishes.%^RESET%^", tp ? tp : 0);
      if (tp) message("info",
        "%^YELLOW%^As the gem is removed, the magical barrier vanishes.%^RESET%^", tp);
    }
  }
  return 1;
}

int remove() {
  object env = environment();
  if (env && base_name(env) == DRAG_ITEMS+"pillar" &&
  !sizeof(DRAG_D->query_data("winnersplacedgems"))) {
    DRAG_D->set_data("gemsplaced", DRAG_D->query_data("gemsplaced")-1 );
    if (DRAG_D->query_data("gemsplaced") == 0) {
      DOOR_D->set_door_status(DRAG_GEM_DOOR_ID, "default");
      DOOR_D->message_rooms_with_door(DRAG_GEM_DOOR_ID,
        "%^YELLOW%^The magical barrier suddenly vanishes.%^RESET%^");
    }
  }
  return ::remove();
}

