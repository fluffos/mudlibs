/* 01-Jun-94 Cadra */
inherit "std/thing";

#include "path.h"

create() {
  ::create();
  SetShort("a list of archwizards");
  SetLong(
"These are the current Archwizards of Nightfall and their jobs "
"(as long as the job is of interest for you players):\n\n"
"Department:     Archwizard:     Vice:\n"
"===========     ===========     =====\n"
"Combat:         Analena         Cormallon\n"
"Finance:        Sique           Thragor\n"
"Guilds:         Rover           Eilan\n"
"Magic:          Softbyte        <vacant>\n"
"Police:         Cadra           Grough\n"
"Quests:         Loco            Blackheart\n\n"
"Other Archwizards:\n"
"==================\n"
"      Hyp\n"
"Questions about your houses belong to:\n"
"======================================\n"
"      Sique\n"
  );
  SetIds(({"list","archlist"}) );
  SetAds( ({"a","an"}) );
  SetReadMsg(QueryLong());
  SetWeight(10);
  SetValue(10);
}
