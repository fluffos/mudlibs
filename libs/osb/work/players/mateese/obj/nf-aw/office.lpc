#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit STD("aw_office");

void create() {
  ::create();
  SetOfficeName("LPC research and development");
  SetOfficeDesc(
"It's a plain naked room since the magic done here doesn't bear much "
"distraction. However, there is an incomplete gallery of pictures on "
"the wall, and a statue in one corner.\n"
"To the east is a storage room for useful tools, to the west the library. "
"Down are some rooms filled with complex LPC examples and other stuff.\n"
                     );
  SetArchwiz(({"Mateese", "<vacant>"}));
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT:"The LPC board",
      P_LONG:"This is the (new) board of LPC research and development. "
"It carries 'lpc' (default) and all subgroups.\n",
      "Groups":(({"lpc","lpc.\\."}))]));

//  AddExit("north", "/d/archwiz/common/lpc/admin_office"); 
  AddExit("south",TOWER("first/west_corr"));
  AddExit("east","./toolstorage");
  AddExit("west","./library");
  AddExit("down","./entrance");
  AddDetail (({ "pictures", "gallery" }),
 "The pictures show some of the former Arches of LPC. As you look closer, "
 "you identify Orb, Uranus, Hyp and Mateese.\n"
            );
  AddDetail ("statue",
 "The statue shows a man in fierce combat with a red dragon. "
 "The nameplate of the statue reads 'Lars Pensjo'.\n"
            );
  /* The statue is an reference to the standard book about compiler
   * construction, nicknamed 'the dragon book' because its title cover
   * shows a knight (the programmer) fighting against a red dragon.
   * Lars Pensjo is of course the original author of LPMud :-)
   */
}





