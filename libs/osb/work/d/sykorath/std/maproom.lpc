/*
 * A room that adds a short map to the room
 * can be used in any room as master room, as long as you don't overload
 * QueryIntLong() or IntLong() !
 *
 * introduced by Magictcs - 18 jan 98
 * ------------------------------------------------------------------------
 * [tcs] 18 jan 98 - first version
 */

#include <properties.h>

#define TP this_player()
#define NOT_SHOW_SHORT_MAP "show_short_map"
#define MAPSPACE 10

// if this 'non-builtin' property is set - the map isn't displayed
#define P_NOT_SHOW_MAP "NotShowMap"

inherit "/std/room";
inherit "/lib/string";

//******************************************
// add the map to the given long description
//******************************************
private string add_map_to_long(string l) {
  string *exp,*map;
  string *exits;
  int size,i;

  // wrap the long and split it into single strings
  l=wrap(l,75-MAPSPACE);
  exp=explode(l,"\n");

  map=({
    "         ",
    "         ",
    "         ",
    "   *     ",
    "         ",
    "         ",
    "         "
  });

  // get all visible exits:
  exits=ExitList()[0];

  // create the map:
  for (i=0;i<sizeof(exits);i++) {
    switch (exits[i]) {
      case "north":
           map[0][3]='+';
           map[1][3]='|';
           map[2][3]='|';
           break;
      case "south":
           map[4][3]='|';
           map[5][3]='|';
           map[6][3]='+';
           break;
      case "east":
           map[3][4..6]="--+";
           break;
      case "west":
           map[3][0..2]="+--";
           break;
      case "northwest":
           map[0][0]='+';
           map[1][1]='\\';
           map[2][2]='\\';
           break;
      case "northeast":
           map[0][6]='+';
           map[1][5]='/';
           map[2][4]='/';
           break;
      case "southwest":
           map[6][0]='+';
           map[5][1]='/';
           map[4][2]='/';
           break;
      case "southeast":
           map[6][6]='+';
           map[5][5]='\\';
           map[4][4]='\\';
           break;
    }
  }

  // remove empty map-lines: (can be made faster by using:
  // if (member(map,"         ")) map-=({"         "});
  map-=({"         "});

  // map-linenumber > long-lineneumber? --> extend the long
  if (sizeof(exp)<sizeof(map)) {
    for (i=sizeof(exp);i<7;i++) exp+=({""});
  }

  // add the map at the beginning of the first 7 lines
  for (i=0;i<sizeof(map);i++) {
    exp[i] = map[i] + exp[i];
  }

  // wrapped long is longer than 7 lines? okay, add the other lines
  for (i=sizeof(map);i<sizeof(exp);i++) {
    exp[i] = "         " + exp[i];
  }

  // make one string out of the array:
  l=implode(exp,"\n");
  if (l[<1..] != "\n") l+="\n";
  return l;
}


//*******************
// overloaded IntLong
//*******************
// handles the adding of the map
public varargs string IntLong(string what)  {
  string long;
  
  long = ::IntLong(what);

  if (!long) return long;

  // if player switched off ma, don't draw it!
  if (TP->QueryAttr(NOT_SHOW_SHORT_MAP))
    return long;                             // no map is shown

  // if property is set to any value, map is discarded
  if (Query(P_NOT_SHOW_MAP)) return long;    // no map is shown

  // add the map to the room:
  return add_map_to_long(long);
}

//************************************
// allows switch off/on for any player
//************************************
int showmap(string str) {
  int shown;
  shown=TP->QueryAttr(NOT_SHOW_SHORT_MAP);
  if (!str) {
    if (!shown)
      write("Map is shown.\n");
    else
      write("Map isn't shown.\n");
    return 1;
  }
  str=norm_id(str);
  if (str=="on") {
    if (!shown) {
      write("Map is already drawn.\n");
      return 1;
    }
    TP->SetAttr(NOT_SHOW_SHORT_MAP,0);
    write("Map will be switched on.\n");
    return 1;
  }
  if (str=="off") {
    if (shown) {
      write("Map isn't shown.\n");
      return 1;
    }
    TP->SetAttr(NOT_SHOW_SHORT_MAP,1);
    write("Map will be switched off.\n");
    return 1;
  }
  notify_fail("Use: showmap (on | off)\n");
  return 0;
}

//************************
// create to add a command
//************************
create() {
  ::create();
  AddRoomCmd("showmap",#'showmap);
}

