/*
 * /obj/daemons/closed/readwrite.c
 * Daemon object for valid_write and valid_read
 * Rumplemintz - 09/25/2014
 */

#include <security.h> /* Defines for wizard levels */

nomask mixed read_check(string str, object player);
nomask mixed write_check(string str, object player);


/* read_check() - Return 1 for allow, 0 for not */
nomask mixed read_check(string str, object player) {
  string name, junk;

  /* If they have write access, by default they have read access */
  if (write_check(str, player))
    return 1;

  /* Anyone should be allowed to read in these directories, so allow it before
     starting the level checks */
  if (   str[0..2] == "log"  || str[0..3] == "/log"
      || str[0..2] == "obj"  || str[0..3] == "/obj"
      || str[0..2] == "sys"  || str[0..3] == "/sys"
      || str[0..3] == "open" || str[0..4] == "/open"
      || str[0..3] == "room" || str[0..4] == "/room")
    return 1;

  /* Start with the lowest level that has complete read access - Elders
     Obviosuly, Arches and Gods fall into this group as well, as they are
     higher level than Elders */
  if ((int)player->query_level() >= ELDER)
    return 1;

  /* Next, Stat level wizards have access to /players */
  if ((int)player->query_level() >= STAT) {
    if (str[0..6] == "players" || str[0..7] == "/players")
      return 1;
  }

  /* Next, allow wizards to read their own directory */
  if ((int)player->query_level() >= CREATE &&
      if (sscanf(str, "/players/%s/%s", name, junk) == 2)) {
        if (name = (string)player->query_real_name()) 
          return 1;
  }
  return 0;
}

