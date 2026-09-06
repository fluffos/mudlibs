// a news board for the player houses
// would be a nice feature I think
// made by MagicTCS on 29/8/1994

#include <news.h>
#include <properties.h>

inherit "/std/board";

varargs void create() {
  (::create());
  AddId("board");
  SetShort("a board");
  SetLong("A board for reading the newest notes.\n");
  SetValue(4999);  // should be worth the value :)
  SetGroups( ({ "players", "ideas.\\.*", "ponder", "flames" }) );
}

