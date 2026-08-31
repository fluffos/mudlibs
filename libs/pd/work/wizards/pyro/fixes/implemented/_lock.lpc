#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

inherit DAEMON;

int lock_door(string);
int lock_bag(string);

int cmd_lock(string str) {
  object env = environment(this_player());
  int ret = 0;

  if(!str || str == "") return notify_fail("Lock what?\n");

  if(sizeof(env->query_doors())) ret = lock_door(str);
  if(!ret) ret = lock_bag(str);

  return (ret==1)?1:0;
}

int lock_door(string str) {
  string doorname, keyname;
  string *doors;
  object keyobj, tp = this_player(), env = environment(tp);

  if (sscanf(str, "%s with %s", doorname, keyname) != 2) {
    str = remove_article(str);
    if (!env->query_door_id(str))
      return notify_fail("There is no "+str+" here.\n");

    notify_fail("You cannot lock "+str+" without a key.\n");
    return 2;
  }

  doorname = remove_article(doorname);
  doors = env->query_doors_blocking_exit(doorname);
  if (!sizeof(doors)) doors = ({ env->query_door_id(doorname) });
  if (!sizeof(doors)) return notify_fail("There is no "+doorname+" here.\n");

  keyname = remove_article(keyname);
  keyobj = present(keyname, this_player());
  if(!keyobj) {
    notify_fail("You do not have "+keyname+".\n");
    return 2;
  }

  foreach (string id in doors)
    env->event_lock(tp, id, keyobj);

  return 1;
}

int lock_bag(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag, key;
  string bagstr, keystr, keyid;
  string bagshort, keyshort, with;

  if (!str || str == "")
    FAIL("Lock what?");

  if (sscanf(str, "%s with %s", bagstr, keystr) == 2) {
    key = present(keystr, tp);
    if (!key)
      FAIL("You do not have "+keystr+".");
    keyshort = " with "+key->query_short();
  }
  else
    bagstr = str;

  bag = present(bagstr, tp);
  if (!bag)
    bag = present(bagstr, env);
  if (!bag)
    FAIL("There is no "+bagstr+" here.");

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
    
    if (!key->id(keyid) && !key->id(DOOR_D->query_master_key())) {
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


void help() {
  message("help",
    "Syntax: <lock container (with [key])>\n"
    "        <lock door with [key]>\n\n"
    "Allows you to lets you lock containers and doors, if you can.\n"
    "Most containers and all doors will require you to specify which\n"
    "key you want to attempt to lock it with.",
    this_player() );
}
