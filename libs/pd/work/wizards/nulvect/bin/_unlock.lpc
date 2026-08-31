
#include <std.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

#define MASTER_KEY_ID "infmastakey"

int unlock_container(object tp, object env, object bag, object key);

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <unlock container [with key]>\n"
    "        <unlock door with key>\n\n"
    "This lets you unlock a locked container or door. "
    "Most will require a specific key.",
    this_player() );
}

int cmd_unlock(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag, key;
  string bagstr, keystr;
  int flag;

  if (!str || str == "")
    FAIL("Unlock what?");

  if (sscanf(str, "%s with %s", bagstr, keystr) == 2) {
    key = present(keystr, tp);
    if (!key)
      FAIL("You do not have "+keystr+".");
  }
  else
    bagstr = str;

  bag = present(bagstr, tp);
  if (!bag)
    bag = present(bagstr, env);
  if (!bag)
    if (!(flag = env->is_door(bagstr)))
      FAIL("Unlock what?");

  if (flag) {
    env->event_unlock(tp, bagstr, key);
    return 1;
  }

  else
    return unlock_container(tp, env, bag, key);

  return 1;
}

int unlock_container(object tp, object env, object bag, object key) {
  string bagshort, keyshort, with, keyid;

  bagshort = bag->query_short();

  if (!bag->query_can_lock())
    FAIL(CAP(bagshort)+" does not have a lock.");

  
  if (!bag->query_locked())
    FAIL(CAP(bagshort)+" is not locked.");

  if (keyid=bag->query_key()) {
    
    if (!key)
      FAIL("Unlock "+bagshort+" with what?");
    else
      keyshort = " with "+key->query_short();
    
    if (!key->id(keyid) && !key->id(MASTER_KEY_ID)) {
      message("cmd_unlock", "You try to unlock "+bagshort+
        keyshort+", but it doesn't fit.", tp);
      message("cmd_unlock", tp->query_cap_name()+" tries to unlock "+
        bagshort+keyshort+", but fails.", env, tp);
      return 1;
    }
    
  }

  bag->set_locked(0);

  message("cmd_unlock", "You unlock "+bagshort+keyshort+".", tp);
  message("cmd_unlock", tp->query_cap_name()+" unlocks "+bagshort+keyshort+".", env, tp);

  return 1;
}

