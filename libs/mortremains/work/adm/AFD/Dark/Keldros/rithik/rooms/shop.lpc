#include <mudlib.h>
#include "../defs.h"

inherit SHOP;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Rithik Livery and General Goods.");
  set("long", @ENDLONG
This is a small establishment.  A plaque is mounted on the southern
wall, that looks like you should examine.  Dust rises from nearly
everything, including the store keeper.  Cramped shelves make movement
even for a dwarf restricting.  You see a small counter near the south
wall with a LARGE SIGN above it.
ENDLONG
  );
  set("light", 1);


  set("exits", ([
  "north" : ROOMS(street2),
  ]) );
  set("item_desc", ([
 "plaque" : "The sign reads: Rithik Livery and General Goods.\n",
 "sign" : "You can read it.\n",
 "counter" : "It appears that people are buying and selling goods there.\n",
"keeper" : "This is an elderly dwarf who is driving some hard bargains with his\ncustomers.\n",
"dust" : "The dust is a thick greyish brown.\n",
"shelves" : "The shelves are well organized, but quite numerous.\n",
  ]) );
 reset();
  stock("/obj/misc/bag");
  stock("/obj/weapons/dagger");
  stock("/obj/weapons/sword");
  stock("/obj/armor/shield");
}

void init() {
  add_action("read", "read");
  ::init();
}



int read(string str) {
  if (!str) return 0;
  if (str != "sign") return 0;
  write(@ENDSIGN
You read:
Welcome to the Rithik Livery and General Goods store!
You can [list] the items in stock, [buy] an item.
You can [sell] a single item or [all] you carry.
A free service provided by the smiths is determining the [value]
of a single item or [all] you carry.
You can also [browse] the wares for sale.

(To find out ALL the commands for the shop, type "help shop".)
ENDSIGN
 );
 return 1;
}