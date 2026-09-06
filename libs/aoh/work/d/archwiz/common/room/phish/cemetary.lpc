#include "path.h"
inherit "/std/room";

DoGrave(){
  if (!this_player()) return 0;
  show(this_player()->QueryName()+" looks at the grave.\n",this_player());
  return
"As you look at the grave, you notice this inscription:\n "
"\tHere lies "+capitalize(this_player()->QueryRealName())+".\n"
"\tKilled in this very\n"
"\tcemetary by an evil\n"
"\tghost.  Rest In Peace\n"
"\n";
}

create(){
  ::create();
  SetIntShort("A Cemetary");
  SetIntLong("\
This is the old cemetary of the castle.  Many of Phish's relatives "
"have been buried here. Some of the graves are centuries old.  There is one "
"grave that seems recent.\n");
  AddDetail("grave",#'DoGrave);
  AddDetail( ({"cemetary","graves"}),
"It is mossy everywhere. Nearly all graves are covered with ivy or moss. But "
"there is one grave that isn't...\n");
  AddDetail(({"moss","ivy"}),
"It covers nearly all graves. Only one is spared.\n");
  AddExit("west","./hall");
 }
