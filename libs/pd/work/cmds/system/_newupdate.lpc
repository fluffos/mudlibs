//      /bin/system/_update.c
//      from the Nightmare Mudlib
//      destructs an old version of a file and loads a new one
//      created by Sulam 911219
//      security changes by Descartes of Borg 930810
//
//      rewritten completely by Nulvect 2010-04-22

#include <std.h>
#include <rooms.h>
#include <security.h>
#include <move.h>
#include <daemons.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <update [-a] [file]>\n\n"
    "Destructs the base object of the file named and then attempts "
    "to load a new version of it.\n"
    "The -a flag causes all inherited objects to also be reloaded.\n\n"
    "See also: call, clone, cref, dest, dref, load, renew",
    this_player()
  );
}

int cmd_newupdate(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *obs = ({ 0 });
  string *files = ({ 0 });
  string msg = "";
  int deep;

  IMSTAT_D->add_stat(tp->query_name(), "update", time());

  if (!str) {
    obs[0] = env;
    files[0] = file_name(env);
  }
  else if (sscanf(str, "-a %s", str))
    deep = 1;

  if (!obs[0]) {
    files[0] = resolv_path(tp->get_path(), str);
    obs[0] = load_object(files[0]);
  }

  if (!obs[0]) {
    message("info", "Couldn't update "+str+".", tp);
    return 1;
  }

  if (deep) {
    files += deep_inherit_list(obs[0]);
    obs += map(files[1..<1], (: find_object($1) :) );
    msg += "Performing deep update on "+ (str ? str : files[0]) + "\n";
  }

  foreach (object ob in obs) {
    string file;
    object *inv;
    string err;
    int master_flag;

    if (!ob) continue;

    file = file_name(ob);
    inv = filter(all_inventory(ob), (: $1->is_player() :) );
    if (ob == master()) master_flag = 1;

    // move players out
    foreach (object pl in inv)
      pl->move(ROOM_VOID);

    // try really hard to destroy this object
    err = catch(ob->remove());
    if (err) {
      msg += file+": error in remove(): "+err+"\n";
      // security: make sure the player updating has permission to
      //   destruct the object
      seteuid(getuid(previous_object()));
      destruct(ob);
      if (ob) {
        msg += file+": couldn't destruct\n";
      }
      // no clue why we have to delay this seteuid()
      //   for the master object only...
      if (!master_flag)
        seteuid(UID_SYSTEM);
    }

    if (!ob) {
      // try to load a new version
      err = catch(call_other(file, "???"));
      if (err) {
        msg += file+": error loading: "+err+"\n";
      }
      else {
        if (master_flag)
          seteuid(UID_SYSTEM);
        // if all went well, move all those players back in
        foreach (object pl in inv)
          pl->move(find_object(file));
        msg += file+": updated and loaded\n";
      }
    }
  }

  message("system", msg, tp);

  return 1;
}

