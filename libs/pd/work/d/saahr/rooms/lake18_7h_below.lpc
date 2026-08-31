
#include <std.h>
#include <saahr.h>

inherit ROOM;
inherit SWIM_CODE;

int move_boulders(string);

void create() {
  room::create();
  set_properties((["water":1, "indoors":0, "light":0, "night light":-1]));
  set_short("underwater");
  set_day_long(
    "Very little light penetrates to the bottom of the lake. "
    "A large piling of boulders sits in the center here with smoothed "
    "out sand all around. A slow stream of bubbles comes from the boulders."
  );
  set_night_long(
    "The darkness below the lake is nearly absolute. "
    "A large piling of boulders sits in the center of the lakebed, "
    "but nothing else can be made out."
  );
  set_items( (query_items() || ([])) + ([
    "boulders" :
      "The boulders are piled together in the middle of the lakebed. "
      "Bubbles slowly escape from between them and float upward.",
    "bubbles" :
      "They slowly escape from between the boulders and float upward.",
  ]) );
  set_exits( ([
    "up" : VPROOMS+"lake18_7h",
  ]) );
  add_exit_alias("up", "surface");
  add_exit_alias("up", "above");

  // eventual plan is for this to lead to another area some day
  set_search("boulders", "The boulders look to be purposely piled together, "
    "but they also look extremely heavy.");
}

void init() {
  room::init();
  swim_code::init();
  add_action("move_boulders", ({ "move", "push", "shove" }) );
}

int move_boulders(string str) {
  object tp = this_player();
  object env = environment(tp);

  if (!str || str != "boulders")
    return notify_fail(capitalize(query_verb())+" what?");

  message("emote", "You try to "+query_verb()+" the boulders, "
    "but they are far too heavy.", tp);
  message("emote", tp->query_cap_name()+" tries to "+query_verb()+
    " the boulders, but they are far too heavy.", env, tp);

  return 1;
}

