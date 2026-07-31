// Room: /d/sandboy/zhulin.c

inherit ROOM;

void create()
{
	set("short", "竹林");
	set("long", @LONG
一片深邃的竹林，清翠的绿叶间隙洒下点点金色阳光。脚步踏在竹叶上
发出悉悉索索的声音。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"zhulin1",
  "east" : __DIR__"shandao2",
]));
set("outdoors","/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhangsan.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
