// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "A large library.") ;
  set("long", @ENDLONG
You stand in a large plush library with literally thousands of 
books lining the numerous shelves.  A fine tapestry covers the north
wall and a large oak desk stands in the center of the room.  Some plush
chairs are lined up a respectful distance from the desk.
ENDLONG
  );
  set("light", 1);
  set("item_desc", ([
   "books" : "Most of the books are in a language you don't understand.\n",
   "shelves" : "They're holding books.\n",
  "tapestry" : "This magnificient tapestry bears the the royal crest of Tormeid.\n",
   "desk" : "You see a candle, some papers, and a quill.\n",
   "candle" : "It's just a plain wax candle.\n",
  "papers" : "Boring documents regarding Castle business.\n",
   "crest" : "It's a large eagle.\n",
   "chairs" : "They look quite comfortable.\n",
    "wall" : "The north wall is covered with a tapestry.\nThe east and west walls are lined with books.\n",
  "north wall" : "A large tapestry covers it.\n",
  "east wall" : "It's lined with books.\n",
   "west wall" : "It's lined with books.\n",
  ]) ) ;
  set("exits", ([
  "south" : ROOMS(throne),
  ]) );
  set("objects", ([
   "king" : MON(king),
  "captain" : MON(guard_captain),
 ]) );
  ::create();
}

void init() {
  add_action("sit", "sit") ;
  add_action("search", "search") ;
}

int sit() {
  write("You sit in one of the plush chairs in front of the desk.\n") ;
  say(wrap(TPN+" sits in one of the plush chairs in front of the desk.")) ;
  return 1;
}

int search(string str) {
  if (!str || str != "tapestry") return 0 ;
  write("You search the tapestry thoroughly and find that there is secret passageway\nbehind it.\n");
  if (!TP->query("invisible"))
  say(TPN+" ducks behind the tapestry on the north wall and disappears.\n");
  TP->move_player(ROOMS(secret1), "SNEAK") ;
  say(TPN+" comes through the secret door.\n");
  return 1;
}
