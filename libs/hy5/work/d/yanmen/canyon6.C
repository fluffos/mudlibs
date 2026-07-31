// Room: /d/canyon/canyon6.c
//#include <roadbusy.h>

inherit ROOM;

void create()
{
	set("coor",({-300,4150,0}));
	set("short", "雁门关谷地");
	set("long",
"高耸的悬崖立在雁门关两侧，中间是并不开阔的谷地，真是易守难攻的好地方，这么多年来\n"
"与异族的关系一直非常缓和，因此大门又重新打开。铁门的后面有个很大的机械装置(machi\n"
"ne)，向南是通往京城的路，往北就出了雁门关。\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"canyon7",
  "north" : __DIR__"canyon5",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "mechine" : "这是个很大的绞盘，可能是开关铁门用的。\n",
]));

        set("outdoors","yanmen");
	setup();
//        replace_program(ROOM);
}
