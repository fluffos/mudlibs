
#include <std.h>
#include <daemons.h>
#include <dragonevent.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit CONTAINER;

string color;

void do_pillar_win();
void check_gem(mixed *);

void set_color(string c) { color = c; }
string query_color() { return color; }

void create() {
  ::create();
  set_name("pillar");
  set_id( ({ "huge pillar", "carved pillar", "huge carved pillar", "hole" }) );
  set_short("a huge carved pillar");
  set_long("The pillar sits here in the middle of a large cavern, reaching "
    "from ceiling to floor. It is "
    "so massive that it would take a while to walk around it. Carved images "
    "of demons and gruesome visages cover it. There seems to be a small hole "
    "cut into the pillar.");
  set_weight(500000);
  set_prevent_get("It is far too heavy.");
  set_max_internal_encumbrance(1);
}

varargs int receive_objects(object ob) {
  object tp = this_player();
  object *placers;

  if (!ob || !color || !ob->id("dragon_event_gem_"+color) || DRAG_D->query_data("canplacegems") != 1)
    return 0;

  call_out("check_gem", 0, ({ tp, ob }) );

  message("info", "%^BOLD%^%^WHITE%^"
    "A strong force roots you to the ground "
    "as the gem approaches the pillar.%^RESET%^",
    tp);
  tp->set_paralyzed(4, "You are rooted to the ground!", "The gem seems to absorb the magic and release you.");

  placers = DRAG_D->query_data("gemplacers");
  if (sizeof(placers)) placers += ({ tp->query_name() });
  else placers = ({ tp->query_name() });
  DRAG_D->set_data("gemplacers", placers);
  ob->set_property("gem_placed_by", tp->query_name());

  return 1;
}

void check_gem(mixed *args) {
  object tp = args[0];
  object gem = args[1];
  object env;

  if (!tp || !gem || !(env = environment(tp))
      || env != environment(this_object()) || !color)
        return;

  if (color == "black" && !gem->query_charged()) {
    message("info", "The gem darkens and falls out of the hole.", env);
    gem->move(env);
    return;
  }

  message("info", "The gem glows brightly.", env);

  tp->remove_paralyzed();

  DRAG_D->set_data("gemsplaced", DRAG_D->query_data("gemsplaced")+1);
  if (DRAG_D->query_data("gemsplaced") >= 4) {
    do_pillar_win();
  }
  else if (DRAG_D->query_data("gemsplaced") == 1) {
    DOOR_D->set_door_status(DRAG_GEM_DOOR_ID, "active");
    DOOR_D->message_rooms_with_door(DRAG_GEM_DOOR_ID,
      "%^YELLOW%^A solid magical barrier suddenly blinks into place.%^RESET%^");
  }
}

void do_pillar_win() {
  string *winners = DRAG_D->query_data("gemplacers");
  object *players = map(winners, (: find_player($1) :) );

  DRAG_D->set_data("canplacegems", 0);
  DRAG_D->set_data("winnersplacedgems", winners);

  foreach(object pillar in children(base_name(this_object()))) {
    object gem;
    if (!clonep(pillar)) continue;
    if (gem = present("gem", pillar)) {
      message("magic", "%^BOLD%^%^BLUE%^The pillar glows brightly!%^RESET%^",
        environment(pillar));
      gem->remove();
    }
  }
  foreach (object player in players) {
    if (!player) continue;
    if (!present("carved pillar", environment(player))) continue;

    player->set_stats("wisdom", player->query_base_stats("wisdom")+4);
    player->set_stats("dexterity", player->query_base_stats("dexterity")+2);
    player->add_exp(500000);
  }
  // do prison-release code here
  DOOR_D->set_door_status(DRAG_GEM_DOOR_ID, "default");
  DRAG_D->remove_beams(4);
}

