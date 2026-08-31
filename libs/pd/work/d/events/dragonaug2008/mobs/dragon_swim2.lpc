
#include <std.h>
#include <dragonevent.h>

inherit MONSTER;

int phase;
int max_phase;
int counter;
int swim_time;

string start_room;
string swim_room;
string end_room;

void set_rooms(string, string, string);
void set_time(int);

void create() {
  ::create();
  set_property("passive", 1);
  set_property("no bump", 1);
  set_id( ({
    "dragon", "blue dragon", "little blue dragon",
    "young dragon", "swimming dragon"
  }) );
  set_name("little blue dragon");
  set_short("A little blue dragon");
  set_long(
    "This young dragon plays in the water. He looks like a strong swimmer and "
    "can carry people north to the beach if they %^BOLD%^<ride>%^RESET%^ him."
  );
  set_level(30);
  set_race("dragon");
  set_body_type("dragon");
  set_class("dragon");
  set_subclass("blue");
  set_gender("male");
  set_max_riders(1);
  set_rideable(1);
  set_rideallow(1);
  phase = 0;
  max_phase = 2;
  counter = 0;
  swim_time = 5;
  start_room = DRAG_ROOMS+"beach";
  swim_room = DRAG_ROOMS+"swimming";
  end_room = DRAG_ROOMS+"ogrebeach";
}

void set_rooms(string start, string middle, string end) {
  start_room = start;
  swim_room = middle;
  end_room = end;
}

void set_time(int time) {
  swim_time = time;
}

void heart_beat() {
  object *riders;
  object env;
  string envfile;

  ::heart_beat();
  if (!this_object()) return;

  env = environment();
  if (!env) return;

  envfile = base_name(env);
  riders = query_riders();

  if (counter == 0) {
    switch (phase) {
      case 0:
        if (envfile != start_room)
          move(start_room);
        else if (envfile == start_room && sizeof(riders)) {
          command("say Ok, let's go.");
          this_object()->move_player(swim_room, "into the water");
          riders->move(swim_room);
          riders->describe_current_room(1);
          counter = swim_time+1;
        }
        return;
      case 1:
        if (envfile == swim_room && sizeof(riders)) {
          this_object()->move_player(end_room, "onto the beach");
          riders->move(end_room);
          riders->describe_current_room(1);
          command("say Here we are!");
          counter = 1;
        }
        return;
      case 2:
        if (envfile == end_room) {
          this_object()->dismount_all("", "The dragon drops you off on the beach.");
          this_object()->move_player(start_room, "into the water");
          counter = 1;
        }
        return;
    }
  }

  else if (counter > 0 && --counter == 0)
    if (++phase > max_phase)
      phase = 0;
}

