/* a voting table
 * (c) 1993/12/13 - 1993/12/13 by taube
 */

inherit "/std/thing";

#include <moving.h>
#include <properties.h>
#include "/d/archwiz/common/room/tower/first/voting.h"

create()
{
  seteuid(getuid());
  (::create());
  SetIds(({"table"}));
  SetAds(({"voting"}));
  SetShort("a voting table");
  SetLong(
"This is an official voting table.\n"
"You can 'sit at [the] table' and then read or write votes.\n");
  SetNoGet(1);
  SetNoise("The voting table humms in expectation of you opinion.\n");
  SetSmell("The voting table smells like old ink and old papers.\n");
}

init()
{
  (::init());
  add_action("SitDown", "sit");
}

SitDown(str)
{
  /* is the command really for us? */
  if(str!="at table" && str!="at the table" &&
     str!="down" &&
     str!="at voting table" && str!="at the voting table")
    return 0;   /* it wasn't */
  /* yes, this_player() wants to sit down */
  if(VOTING_ROOM->QueryOccupied()) {
    write(
"You try to sit down at the voting table, but the table won't let you! "
"It says: 'Sorry, I am currently busy with another player. "
"Please try again later (in a minute).'\n");
    say(this_player()->QueryName()+" wants to sit down at the voting table, "
"but the table is currently occupied with another player.\n");
    return 0;
  }
  call_other(VOTING_ROOM, "???");
  write("You sit down at the table.\n"+(VOTING_ROOM->QueryIntLong()));
  say(this_player()->QueryName()+" sits down an the voting table.\n");
  return this_player()->move(VOTING_ROOM, M_SILENT, this_object());
}
