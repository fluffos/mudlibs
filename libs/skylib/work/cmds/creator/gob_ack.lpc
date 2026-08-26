/* goto command, trial out by Turrican for a commands daemon. */
#include <terrain.h>

inherit COMMAND_BASE;

mixed cmd(string str) {
  mixed dest;
  string tname;

  dest = this_player()->query_last_location();
  if(!dest)
    return notify_fail("No stored location.\n");
  if (stringp(dest)) {
    /* Player was in a normal room */
    dest = load_object(dest);
  } else if (arrayp(dest) && stringp(dest[0]) && arrayp(dest[1])) {
    /* Player was in a terrain */
    dest = TERRAIN_MAP->find_location(dest[0], dest[1]);
  } else {
    return notify_fail("I don't understand your stored location.\n");
  }
  tname = environment(this_player())->query_property("terrain name");
  if (tname) {
    /* Player is in a terrain.  Store terrain name and coords. */
    this_player()->set_last_location(
      ({ tname, environment(this_player())->query_co_ord() })
      );
  } else {
    /* Player was in a normal room.  Store file name. */
    this_player()->set_last_location(
      base_name(environment(this_player()))
      );
  }
  this_player()->move_with_look( dest,
                                 this_player()->query_mmsgin(),
                                 this_player()->query_mmsgout() );
  return 1;
}

