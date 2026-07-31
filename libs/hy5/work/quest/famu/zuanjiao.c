// Room: /d/jindezheng/zuanjiao.c

inherit ROOM;

void create()
{
	set("short", "砖窑");
	set("long", @LONG
走出树林,就见到一座砖窑,前大后小,成直躺的鹅蛋形,后部砌成高 
约二米的薄壁烟囱,窑旁是一堆堆的松木.好几个工人正使劲拉着个大风 
箱,向窑中鼓风. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jindezheng");
	set("no_sleep", 1);
	set("no_dazuo", 1);

	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin2",
  "west" : __DIR__"songlin",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/gongjiang.c" : 2,
]));

	setup();
	replace_program(ROOM);
}
