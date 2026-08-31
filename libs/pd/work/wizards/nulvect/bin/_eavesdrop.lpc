
#include <std.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n")

#define EAVESDROP_PROP "eavesdrop_abil_data"

#define EAVESDROP_ROOM_OB DIR_CLASS_CMDS+"/obj/eavesdrop_room_ob"
#define COMMAND_OB DIR_CLASS_CMDS+"/obj/command"

inherit DAEMON;

int eavesdrop_check(string);
int eavesdrop_died(object, object);
void eavesdrop_remove(object);


int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "thief" &&
      tp->query_skill("perception") >= 25*5)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <eavesdrop [direction]>\n\n"
    "Thieves can listen in on adjacent rooms.",
    this_player() );
}

int can_cast(object tp, string dir) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (sizeof((object *)tp->query(EAVESDROP_PROP)))
    FAIL("You are already eavesdropping!");

  if (!strlen(dir))
    FAIL("Listen in which direction?");

  if (member_array(dir, environment(tp)->query_exits()) == -1)
    FAIL("There is no exit that way.");

  return 1;
}

int cmd_eavesdrop(string str) {
  object tp = this_player();
  object env = environment(tp);
  object room;
  object myob, roomob;
  mixed tmp;

  if (!abil()) return 0;

  if (!can_cast(tp, str)) return 0;

  message("info", "You listen intently to the "+str+".", tp);

  room = load_object(env->query_exit(str));
  roomob = new(EAVESDROP_ROOM_OB);
  roomob->setup(tp);
  roomob->move(room);
  myob = new(COMMAND_OB);
  myob->set_catchall(1);
  myob->set_function(this_object(), "eavesdrop_check");
  myob->set_notify("eavesdrop_died");
  myob->move(tp);

  tp->set(EAVESDROP_PROP, ({ roomob, myob }) );

  return 1;
}

int eavesdrop_check(string str) {
  object tp = this_player();
  string verb = query_verb();
  mixed *prop = tp->query(EAVESDROP_PROP);

  if (!sizeof(prop)) return 0;

  switch (verb) {

    case "look": case "sit": case "stand":
    case "lay": case "rest": case "inventory":
    case "skills": case "score": case "stats":
    case "cost": case "spells": case "abilities":
    case "body": case "money": case "armour":
    case "hp": case "status": case "age":
    case "time": case "calendar": case "party":
    case "tell": case "reply": case "say":
    case "speak": case "emote": case "emoteto":
    case "yell": case "shout": case "whisper":
    case "message": case "title": case "pretitle":
    case "peer": case "listen": case "touch":
    case "smell": case "read": case "taste":
    return 0;

    default:
    if (wizardp(tp) && verb != "stop") return 0;
    if (sscanf(verb, "%s:%*s", str) >= 1) verb = str;
    else if (sscanf(verb, "%semote%*s", str) >= 1) verb = str;
    if (member_array(verb, tp->query_channels()) != -1) return 0;

    message("info", "You stop eavesdropping.", tp);
    // sometimes the call_out takes a heartbeat to finish and you'd
    // see messages still after you stop... this fixes that
    prop[0]->stop_eavesdrop();
    call_out("eavesdrop_remove", 0, tp );
    if (verb == "stop" && (str == "eavesdrop" || str == "eavesdropping"))
      return 1;
    return 0;

  }
  
  // never gets here
  return 1;  
}

int eavesdrop_died(object killer, object victim) {
  eavesdrop_remove(victim);
  return 0;
}

void eavesdrop_remove(object tp) {
  object *obs;
  if (!tp) return;
  obs = (object *)tp->query(EAVESDROP_PROP);
  if (!sizeof(obs)) return;
  tp->set(EAVESDROP_PROP, ({}) );
  obs->remove();
}
