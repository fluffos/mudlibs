// room for vmaster objects
// created by Magictcs

#include <properties.h>
#include <sykorath.h>

inherit BASEROOM;

mixed Query(string p,int sc) {
  if (p==P_INT_WIZMSG) return
    "It is located at: (see map of sykorath - outer.map)\n"+
    "\t"+::Query("X")+","+::Query("Y")+"\n"
    "It's an virtual room up to now.\n"
    "If you have some ideas for this room - feel free to contact a "
    "responsible wizard or create it yourself.\n";
  return ::Query(p,sc);
}

create() {
  ::create();
  SetIntShort("A not finished room");
  SetIntLong("This room is not finished presently.\n");
}

