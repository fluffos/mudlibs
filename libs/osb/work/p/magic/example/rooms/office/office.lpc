#include "/d/archwiz/common/path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("aw_office");

void create() {
  (::create());
  SetOfficeName("Magic");
  SetOfficeDesc(
"This is the Magic-Office. Everything around you is shimmering or "
"fuming strongly. On a wall you read a sign \"Enter at own risk\". "
"There is a large table standing on one wall, covered with all kinds "
"of books and a lot of different papers. This seems to be the planning "
"table of the magic department.\n"
"From everywhere you here the song \"It`s a kind of Magic\".\n");
  SetArchwiz(({"Softbyte"}));
  SetIntNoise("From everywhere you here the song \"It`s a kind of Magic\".\n");
  AddDetail(({"table","desk","planing table"}),
"The table is covered with books, papers and a small picture.\n");
  AddDetail(({"book","books"}),
"All books seem to be about magic. You can read a few titles: "
"'Tome of magic','AS&S Book of Magic', 'Das Buch der 11*11 Zauber', "
"'Spells and magic items' and 'The Offical Magic Policy'\n");
  AddDetail(({"paper","papers"}),"Many papers cover the table.\n");
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT:"The Magic Board",
      P_LONG:"It carries 'magic' (default) and all subgroups.\n",
      "Groups":(({ "magic", "magic.\\."}))]));
  AddExit("south",TOWER("first/east_corr"));
  AddExit("down","../d_hallway");
}
