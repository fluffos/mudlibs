#include "path.h"
#include <moving.h>
inherit "/std/thing";

create(){
  ::create();
  SetShort("Phish's Castle");
  SetLong(
"This is a beautiful old castle.  It looks like it has been "
"here for centuries.  Even the archwizards must have dwelt "
"within this structure back when they were adventuring. The "
"castle gate is open and inviting to all adventurers. Just ENTER CASTLE.\n");
  SetNoGet(1);
  AddId("castle");
  AddAdjective("phish's");
  AddAdjective("phishs");
  AddAdjective("Phish's");
 }

init(){
  ::init();
  add_action("enter","enter");
  }

enter(arg){
  if (!this_player()) return 0;
  if (arg != "castle") return 0;
  write("You enter the ancient structure.\n");
  this_player()->move(PHISH("entrance"),M_GO,"into the castle");
  return 1;
 }
