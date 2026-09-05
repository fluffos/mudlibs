/*
 * global/server/air.c -- returns for a given room which air room it
 *                        corresponds with.
 * Alfe for Tubmud 2001-Jul-23
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
         "players/frazor/room/path4","players/frazor/obj/tools/imp/imp_room",
         "domains/peerage/room/entrance","domains/peerage/room/peerentry",
         "domains/peerage/room/trade","domains/peerage/room/peercarp",
         "players/ugh/room/library","room/storage","room/station",
         "room/adv_guild","room/narr_alley","room/bank","room/post",
         "room/mailing_lists","players/chrisp/room/market1",
         "players/chrisp/room/market2","players/chrisp/room/balance",
         "players/chrisp/room/dump","players/chrisp/room/dump_inner",
         "players/chrisp/room/dump_lair","players/chrisp/room/escort",
         "players/chrisp/room/armoury","players/chrisp/room/weaponry",
         "players/chrisp/room/smithy","players/chrisp/room/fork",
         "players/chrisp/room/castle_road",
         "players/chrisp/room/castle_entrance",
         "players/chrisp/room/castle_yard",
         "room/brook/brook_8", "room/brook/brook_9", "room/brook/brook_10" }),
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
  if (IS_REGEXP(room_name,"players/angmar/fairyland/.*"))  // no air-room here.
    return 0;                                   // Coogan, 14-Aug-2002
  // third: heuristics
  if (IS_REGEXP(room_name,"room/church.*")              ||
      IS_REGEXP(room_name,"room/sunalley.*")            ||
      IS_REGEXP(room_name,"domains/banking/.*")         ||
      IS_REGEXP(room_name,"players/ereborn/park/.*")    ||
      IS_REGEXP(room_name,"players/ereborn/park/.*")    ||
      room_name == "players/ereborn/rc_level1/rc_1"     ||
      room_name == "players/ereborn/rooms/path1"        ||
      room_name == "players/ereborn/rooms/path2"        ||
      IS_REGEXP(room_name,"players/padrone/deposit/.*") ||
      IS_REGEXP(room_name,"players/angmar/room/.*")     ||
      IS_REGEXP(room_name,"domains/mordor/dol_guldur/.*") ||
      IS_REGEXP(room_name,"players/littlenemo/.*")      ||
      IS_REGEXP(room_name,"domains/escoryn/room/area/coach_stop") ||
      IS_REGEXP(room_name,"players/puff/.*")            ||
      IS_REGEXP(room_name,"players/flash/rooms/.*")     ||
      IS_REGEXP(room_name,"players/amylaar/.*")         ||
      room_name == "players/chameloid/room/meadow"
      )
    return "air/village";
  // air/ranabar must come before air/glandon, as DC is a subdir of Glandon.
  // (the same for xio, see air/sea)
  if ((IS_REGEXP(room_name,"domains/glandon/DC/.*") &&
       !IS_REGEXP(room_name,"domains/glandon/DC/room/capa.*"))  ||
      IS_REGEXP(room_name,"players/kantele/.*")                 ||
      room_name == "room/plane7"                                ||
      IS_REGEXP(room_name,"room/big_tree.*")                    ||
      IS_REGEXP(room_name,"domains/deathbat/rooms/wikkaton/.*") ||
      IS_REGEXP(room_name,"players/xio/room/wales/.*"))
    return "air/ranabar";
  if ((IS_REGEXP(room_name,"domains/glandon/.*") &&
        !IS_REGEXP(room_name,"domains/glandon/DC/room/capa.*")) ||
      IS_REGEXP(room_name,"players/some/bdream/.*"))
    return "air/glandon";
  if (IS_REGEXP(room_name,"domains/peerage/clans/noldor/room/.*") ||
      IS_REGEXP(room_name,"domains/peerage/clans/bb/room/.*")     ||
      IS_REGEXP(room_name,"players/hans/room/.*")                 ||
      IS_REGEXP(room_name,"players/surak/wurk/room/hans/.*")      ||
      IS_REGEXP(room_name,"room/grove/.*")                        ||
      IS_REGEXP(room_name,"room/brook/.*")                        ||
      IS_REGEXP(room_name,"players/morath/room/.*")               ||
      IS_REGEXP(room_name,"players/flash/q/room/.*")              ||
      IS_REGEXP(room_name,"players/ereborn/rooms/.*")             ||
      IS_REGEXP(room_name,"domains/deathbat/oldrealm/outside/.*") ||
      IS_REGEXP(room_name,"domains/moon/.*")                      ||
      room_name == "room/hump_east" ||
      room_name == "room/hump"      ||
      room_name == "room/wild1"     ||
      room_name == "room/forest1"   ||
      room_name == "room/forest0"   ||
      room_name == "room/plane9"    ||
      room_name == "room/plane8_5"  ||
      room_name == "room/ruin"
      )
    return "air/grove";
  if (IS_REGEXP(room_name,"domains/snowdonia/.*") ||
      IS_REGEXP(room_name,"room/hill.*")          ||
      IS_REGEXP(room_name,"room/cliff.*")         ||
      room_name == "players/blackmoon/rooms/base" ||
      IS_REGEXP(room_name,"players/dozy/miyu/.*") ||
      IS_REGEXP(room_name,"players/carador/b/.*"))
    return "air/snowdonia";
  if (IS_REGEXP(room_name,"players/monst/.*")    ||
      IS_REGEXP(room_name,"players/darkstar/.*") ||
      IS_REGEXP(room_name,"players/xio/.*")      ||
      room_name == "room/sea"    ||
      room_name == "room/jetty2" ||
      IS_REGEXP(room_name,"room/beach.*"))
    return "air/sea";
  if (IS_REGEXP(room_name,"domains/dragonland/.*")      ||
      IS_REGEXP(room_name,"players/tody/moongaard/.*")  ||
      room_name == "domains/deathbat/rooms/tale_03/isle"
      )
    return "air/dragonland";
  if (IS_REGEXP(room_name,"players/leonardo/.*") ||
      IS_REGEXP(room_name,"domains/peerage/clans/silverfox/.*") ||
      IS_REGEXP(room_name,"domains/martial_art/.*") ||
      room_name == "room/plane6" ||
      room_name == "room/plane8" ||
      room_name == "room/ravine" || // Dozy
      (room_name != "room/plane1" && IS_REGEXP(room_name,"room/plane1.")) ||
      IS_REGEXP(room_name,"room/mount_.*") ||
      IS_REGEXP(room_name,"players/mllynwrlch/.*"))
    return "air/north";
  if (IS_REGEXP(room_name,"domains/deathbat/oldrealm/wikkaton/.*") ||
      IS_REGEXP(room_name,"domains/deathbat/lila/.*") ||
      (IS_REGEXP(room_name,"domains/deathbat/rooms/tale_02/.*") &&
       room_name != "domains/deathbat/rooms/tale_02/forest11") ||
      IS_REGEXP(room_name,"players/endor/.*"))
    return "air/northwest";
  if (IS_REGEXP(room_name,"room/orc_.*") ||
      IS_REGEXP(room_name,"players/walchy/tobac/.*") ||
      room_name == "room/plane1"   ||
      room_name == "room/clearing" ||
      room_name == "room/forest2"  ||
      room_name == "room/forest3"  ||
      room_name == "room/slope"    ||
      IS_REGEXP(room_name,"players/foxsly/tower/rooms/.*")  ||
      IS_REGEXP(room_name,"domains/glandon/DC/room/capa.*") ||
      // these Escoryn rooms here must come before air/west
      room_name == "domains/escoryn/room/area/road1" ||
      room_name == "domains/escoryn/room/area/road2" ||
      room_name == "domains/escoryn/room/area/road3" ||
      room_name == "domains/escoryn/room/area/bushes"||
      IS_REGEXP(room_name,"players/bumblebee/inn/room/.*")
      )
    return "air/orc_valley";
  if (IS_REGEXP(room_name,"domains/escoryn/.*") ||
      IS_REGEXP(room_name,"domains/deathbat/akroliz/.*"))
    return "air/west";
  if (IS_REGEXP(room_name,"players/kingkong/.*") ||
      IS_REGEXP(room_name,"players/quantos/.*") ||
      // path0* must come before air/south_forest
      IS_REGEXP(room_name,"room/south/path0.")
      )
    return "air/south";
  if (IS_REGEXP(room_name,"room/south/.*")      ||
      IS_REGEXP(room_name,"room/forest.*")      ||
      IS_REGEXP(room_name,"players/padrone/outside/.*") ||
      IS_REGEXP(room_name,"players/myxectbo/room/.*"))
    return "air/south_forest";
  if (IS_REGEXP(room_name,"domains/deathbat/oldrealm/mansion/.*") ||
      IS_REGEXP(room_name,"players/chrisp/room/.*")     ||
      IS_REGEXP(room_name,"room/nstreet.*")             ||
      room_name == "domains/deathbat/rooms/tale_01/scholar_hut"
      )
    return "air/south_east";
  // fourth: nothing found?
  return 0;
}

