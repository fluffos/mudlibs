#include "../defs.h"
inherit CHATTING_ROOM;

void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "In the Golden Skull.");
set("long", @ENDLONG
The Golden Skull stands before you in opulent splendor.
Lords and ladies of all races meander from location to
location gambling away the money for which someone must
have once worked very well to obtain.  The Golden Skull
offers many different varieties of games in which to spend
your hard earned currency.  From here, you see slot machines
to the west, a row of blackjack tables to the east and
roulette tables to the north.
ENDLONG
   );
  set("item_desc", ([
    "lords" : "Men of all races and levels of wealth sip drinks and move from game to game.\n",
    "ladies" : "Ladies dressed in beautiful gowns accompany their lords and act as token \"good luck charms\".\n",
     "money" : "Thousands of coins move from hand to hand while people gamble it away, or make it big.\n",
     "games" : "The patrons of this establishment can be seen playing roulette, blackjack, and slot machines.\n",
     "slot machines" : "From here, they are plated in gold, with a wooden handle.\n",
     "blackjack" : "The blackjack tables look quite profitable....\n",
     "roulette" : "The roulette wheels spin cheerfully every few minutes.\n",      
   ]) );
  set("smell", ([
    "default" : "White wine and perfumes permeates the air here, a decadent smell which entices you to make it rich.\n",
  ]) );
  set("listen", ([
   "default" : "Sounds of laughter and wails of disappointment fill the Golden skull, with and occasional cheer of joy.\n",

  ]) );

  set("exits", ([
    "north" : ROOMS(skull2),
    "east" : ROOMS(skull1),
    "west" : ROOMS(skull3),


  ]) );
  ::create();
}