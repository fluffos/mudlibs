#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit "/std/container";

int ring;

QueryIntLong() {
  if (!ring) return
"You see a pretty little splashing fountain.\n";
  return
"You see a pretty little splashing fountain. On its bottom you see "
"a key shimmering.\n";
}

create() {
  ::create();
  SetNoGet(1);
  SetIds(({"magicfountain","fountain"}));
  SetAds(({"little","pretty","splashing","a"}));
  SetShort(0);
  reset();
}

reset() {
  ::reset();
  ring=0;
}

MakeRing() {
  object ob;
  AddItem("/std/thing",REFRESH_NONE,
    ([P_SHORT:"A small golden ring",
      P_LONG:"This seems to be a valuable ring.\n",
      P_VALUE:3,
      P_WEIGHT:20,
      P_IDS:({"ring","goldring","goldquest"}),
      P_ADS:({"gold","a","small","little","valuable"})]));
  ring=1;
}
