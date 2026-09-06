// a news board for the player houses
// would be a nice feature I think
// made by MagicTCS on 29/8/1994
// used the guildboard (cause the levelgroups - HLP)

#include <news.h>
#include <properties.h>

inherit "/obj/guild/guildboard";

create() {
  if (::create()) return 1;
  AddId("newsboard");
  AddId("board");
  SetShort("a newsboard");
  SetLong("A board for reading the newest notes from mostly all areas.\n");
  SetValue(24999);  // should be worth the value :)
  SetGroups(({"players","players.lorinia","d.avalon.players",
    "d.halfling.players","d.hell.players","d.ireland.players"}));  
  SetLevelGroups((["players.hlp":20]));
}

