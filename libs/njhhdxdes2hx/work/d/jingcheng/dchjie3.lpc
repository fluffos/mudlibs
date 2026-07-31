// Room: /d/jingcheng/dchjie3.c
// Made by: ysgl

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "[32m十字路口[2;37;0m");
	set("long", @LONG
这里是东门大街和白虎大街的十字路口。一直向东走可以到京
城的东门。西边一直通到城中心，远远望去，钟楼依昔可见．
这里人来人往，倒也繁华。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/youxia" : 1,
]));
	set("outdoors", "city");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"baih1",
  "south" : __DIR__"baih4",
  "west" : __DIR__"dchjie2",
  "east" : __DIR__"dchjie4",
]));

	setup();
	replace_program(ROOM);
}
