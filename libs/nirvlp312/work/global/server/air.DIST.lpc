/*
 * global/server/air.c -- returns for a given room which air room it
 *                        corresponds with.
 * Alfe for Tubmud 2001-Jul-23
 *
 * Distribution version by Coogan, 22-Sep-2009
 *
 */

#include <assert.h>
#include <regexps.h>

inherit "basic/create";

// in this mapping we keep those rooms which don't tell themselves
// what air room they belong to and which cannot be determined after
// their object name.
mapping room2air;

void create() {
  room2air = ([]);
  map(({ "room/shop","room/vill_green","room/vill_track","room/vill_road1",
         "room/vill_road2","room/vill_shore","room/crop","room/jetty",
         "room/nstreet1","room/nstreet2","room/nstreet3","room/nstreet4",
         "room/eastroad1","room/eastroad2","room/eastroad3","room/eastroad4",
         "room/eastroad5","room/inn","room/new_square",
         "room/storage","room/station",
         "room/adv_guild","room/narr_alley","room/bank","room/post",
         "room/mailing_lists" }),
      (: room2air[$1] = "air/village" :));
  create::create();
}

string get_air_room(object room) {
  string result,room_name;
  assert(objectp(room));
  // first: ask the object itself.
  if (result=room->query_air_room())
    return result;
  room_name = load_name(room);
  // second: is it a special room?
  if (result=room2air[room_name])
    return result;
  // third: heuristics
  if (IS_REGEXP(room_name,"room/church.*")              ||
      IS_REGEXP(room_name,"room/sunalley.*")
      )
    return "air/village";
  if (room_name == "room/plane7"                                ||
      IS_REGEXP(room_name,"room/big_tree.*")                    ||
      room_name == "room/hump_east" ||
      room_name == "room/hump"      ||
      room_name == "room/wild1"     ||
      room_name == "room/forest1"   ||
      room_name == "room/forest0"   ||
      room_name == "room/plane9"    ||
      room_name == "room/plane8_5"  ||
      room_name == "room/ruin"
      )
    return "air/west";
  if ( IS_REGEXP(room_name,"room/hill.*")          ||
      IS_REGEXP(room_name,"room/cliff.*")         ||
      room_name == "room/sea"    ||
      room_name == "room/jetty2" ||
      IS_REGEXP(room_name,"room/beach.*"))
    return "air/sea";
  if (IS_REGEXP(room_name,"room/orc_.*") ||
      room_name == "room/plane1"   ||
      room_name == "room/clearing" ||
      room_name == "room/forest2"  ||
      room_name == "room/forest3"  ||
      room_name == "room/slope"
      )
    return "air/orc_valley";
  if (IS_REGEXP(room_name,"room/south/.*")      ||
      IS_REGEXP(room_name,"room/forest.*")
      )
    return "air/south_forest";
  if (IS_REGEXP(room_name,"room/nstreet.*")
      )
    return "air/south_east";
  // fourth: nothing found?
  return 0;
}

