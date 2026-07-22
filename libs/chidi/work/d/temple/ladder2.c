#pragma save_binary
// Room: /d/temple/ladder2.c
#include <roadbusy.h>

inherit ROOM;

void create()
{
	set("coor",({1250,4920,30}));
	set("short", "石英岩石阶");
	set("long",
"你正走在一道长长的石英岩阶梯上,阶梯的两侧种植著一排高耸\n"
"的松树。抬头望望东北边那座高耸挺拔的山峰,在云雾飘渺的山\n"
"顶上,矗立著一座雄伟的白色楼阁。\n"
);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest" : 1,
]));
	set("outdoors", "temple");
	set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"ladder1",
  "northdown" : __DIR__"ladder3",
]));
	set("no_clean_up", 0);

	setup();
//        replace_program(ROOM);
}
