// Room: /d/heifeng/midao2.c

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
这里是一处密道，地上干干净净，可见经常有人过往，密道
边上的石壁挂着水珠。
LONG
	);

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"mishi1",
  "west" : __DIR__"midao1",
  "east" : __DIR__"midao3",
]));

	setup();
	//create_door("west", "铁门", "east", DOOR_CLOSED,LOCKED,__DIR__"obj/key1");
}
