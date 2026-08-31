#include <std.h>

#define COL "%^ORANGE%^"
#define RES "%^RESET%^"

#define PRE COL+"(%)"+RES+" "

#define MOVEMENT_ARGS ({\
    "put", "get", "drop", "bury",\
    "wear", "wield", "remove", "ride", "mount",\
    "lock", "unlock", "open", "close",\
})
#define MOVEMENT_NOARGS ({\
    "search", "sit", "lay", "rest", "sleep",\
    "wake", "stand",\
})
#define MOVEMENT MOVEMENT_ARGS+MOVEMENT_NOARGS

inherit LIVING;

object owner;
int stopeavesdrop=0;

void setup(object tp);
int hear_movement(string str);
void stop_eavesdrop();

void create() {
  ::create();
  set_name("strange hallucination that should never be seen");
  set_id(({"eavesdrop_room_ob"}));
  set_long("");
  set_short("");
  set_property("passive", 1);
  // this should make other mobs keep their heart beats on while in the room
  set_property("keepheartbeat", 1);
  set_invis(1, "", "");

  // all the rest is to mitigate errors should anyone ever try to interact
  // with this object
  enable_commands();
  init_limb_data();
  set_base_stats( ([
    "strength" : 1, "dexterity" : 1, "constitution" : 1,
    "intelligence" : 1, "wisdom" : 1, "charisma" : 1
  ]) );
  add_limb("torso", "FATAL", 5000, 0, 0);
  set("race", "nothing");
}

void init() {
  ::init();
  add_action("hear_movement", MOVEMENT);
}

int is_invincible() { return 1; }

int is_living() { return 0; }

void setup(object tp) {
  if (!tp) return;
  owner=tp;
}

int hear_movement(string str) {

  if (stopeavesdrop) return 0;

  if (member_array(query_verb(), MOVEMENT_ARGS) != -1 &&
     (!str || !strlen(str))) return 0;

  if (owner->query_skill("perception") >= 140+random(90))
    message("info", PRE+"You hear some movement.", owner);

  return 0;
}

void stop_eavesdrop() { stopeavesdrop = 1; }

void receive_message(mixed cl, mixed msg) {

  if (stopeavesdrop) return;

  if (!stringp(cl) || !stringp(msg)) return;

  switch (cl) {

    case "say":
    case "whisper":
    case "emote":
    case "listen":
    msg = strip_color(msg);
    break;

    case "min":
    msg = "You hear someone enter.";
    break;

    case "mout":
    msg = "You hear someone leave.";
    break;

    case "combat":
    case "other_combat":
    msg = "You hear some fighting.";
    break;

    case "magic":
    msg = "You hear someone cast a spell.";
    break;

    default:
    return;
  }

  if (owner->query_skill("perception") >= 90+random(60))
    message("info", PRE+msg, owner);

}

// these are for when people use speak
int query_lang_prof(string lang) { return owner->query_lang_prof(lang); }
string query_primary_lang() { return owner->query_primary_lang(); }

