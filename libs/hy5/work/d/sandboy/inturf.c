// Room: /d/sandboy/inturf.c

inherit ROOM;

void create()
{
	set("short", "草丛中");
	set("long", @LONG
眼前是一片长长的茅草,许多是淡绿色的,其中间杂着铁灰色的硬杆茂草.
弧月形的叶片边缘带着小小的锯齿,脚下是潮湿的泥土.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"turf",
  "north" : __DIR__"reed",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingwa.c" : 1,
]));

	setup();
	replace_program(ROOM);
}
