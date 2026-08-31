#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(strip_color(s)+"\n")
#define CAP(s) capitalize(strip_color(s))

inherit DAEMON;

int unlock_bag(string);
int unlock_door(string);

int cmd_unlock(string str) {
  object env = environment(this_player());
  int ret = 0;

  if(!str || str == "") return notify_fail("Unlock what?\n");

  if(sizeof(env->query_doors())) ret = unlock_door(str);
  if(!ret) ret = unlock_bag(str);

  return (ret==1)?1:0;
}

int unlock_door(string str) {
  string doorname, keyname;
  string *doors;
  object keyobj, tp = this_player(), env = environment(tp);

  if (sscanf(str, "%s with %s", doorname, keyname) != 2) {
    str = remove_article(str);
    if (!env->query_door_id(str))
      return notify_fail("There is no "+str+" here.\n");

    notify_fail("You cannot unlock "+str+" without a key.\n");
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
    env->event_unlock(tp, id, keyobj);

  return 1;
}

int unlock_bag(string str) {
  object tp=this_player();
  object env=environment(tp);
  object bag, key;
  string bagstr, keystr, keyid;
  string bagshort, keyshort, with;

  if (!str || str == "")
    FAIL("Unlock what?");

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
  
  if (!bag->query_locked())
    FAIL(CAP(bagshort)+" is not locked.");

  if (keyid=bag->query_key()) {
    
    if (!key)
      FAIL("Unlock "+bagshort+" with what?");
    
    if (!key->id(keyid) && !key->id(DOOR_D->query_master_key())) {
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


void help() {
  message("help",
    "Syntax: <unlock container (with [key])>\n"
    "        <unlock door with [key]>\n\n"
    "Allows you to lets you unlock locked containers and doors.\n"
    "Most containers and all doors will require you to specify which\n"
    "key you want to attempt to unlock it with.",
    this_player() );
}
