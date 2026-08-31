
#include <std.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

#define MASTER_KEY_ID "infmastakey"

inherit DAEMON;

int lock_container(object tp, object env, object bag, object key);

void help() {
  message("help",
    "Syntax: <lock container [with key]>\n"
    "        <lock door with key>\n\n"
    "This lets you lock a container such as a treasure chest,"
    "or a door, if it has a lock. Most locks will require specific "
    "keys to work.",
    this_player() );
}

int cmd_lock(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag, key;
  string bagstr, keystr;
  int flag;

  if (!str || str == "")
    FAIL("Lock what?");

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
      FAIL("There is no "+bagstr+" here.");

  if (flag) {
    env->event_lock(tp, bagstr, key);
    return 1;
  }

  else
    return lock_container(tp, env, bag, key);
  
  return 1;
}

int lock_container(object tp, object env, object bag, object key) {
  string bagshort, keyshort, with, keyid;

  bagshort = bag->query_short();

  if (!bag->query_can_lock())
    FAIL(CAP(bagshort)+" does not have a lock.");
  
  if (bag->query_locked())
    FAIL(CAP(bagshort)+" is already locked.");

  if (!bag->query_closed())
    FAIL("It must be closed before it can be locked.");

  if (keyid=bag->query_key()) {
    
    if (!key)
      FAIL("Lock "+bagshort+" with what?");
    else
      keyshort = " with "+key->query_short();
    
    if (!key->id(keyid) && !key->id(MASTER_KEY_ID)) {
      message("cmd_lock", "You try to lock "+bagshort+
        keyshort+", but it doesn't fit.", tp);
      message("cmd_lock", tp->query_cap_name()+" tries to lock "+
        bagshort+keyshort+", but fails.", env, tp);
      return 1;
    }
    
  }

  bag->set_locked(1);

  message("cmd_lock", "You lock "+bagshort+keyshort+".", tp);
  message("cmd_lock", tp->query_cap_name()+" locks "+bagshort+keyshort+".", env, tp);

  return 1;
}

