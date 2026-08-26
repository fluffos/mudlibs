#include <mudlib.h>

inherit PRIVATE_ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light",1);
    set("short","Uliver's Vault");
    set("long",@EndLong
    This room is rather vacant, with a desk in the far corner,
and benches lining the remaining walls.  A table lies in the
center of the room, with scattered parts on top of it.  The
floor is cold, gray concrete, swept meticulously.  A large
vault lies to the south.
EndLong
    );
    set("exits",([
    ]));
    set("item_desc",([
      "desk" : "It has a few papers on it.\n",
      "papers" : "That's private!\n",
      "benches" : "The benches are made of a dark marble.\n",
      "table" : "This table appears to be where Uliver does his work.\n",
      "floor" : "The floor is spotless.\n",
      "vault" : "It bars the south exit.\n"
    ]));
}
