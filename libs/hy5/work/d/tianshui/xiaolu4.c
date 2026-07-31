// Room: /d/tianshui/xiaolu4.c

inherit ROOM;

void create()
{
	set("short", "青草地");
	set("long", @LONG
这是一片青青的草地，在这附近是很难得的，所以周围的牧
人都来这里放牧，往西走就是关外小镇天水镇了，往东是一望无际
的黄土路。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaolu3",
        "east" : "/d/mayi/huangtu2",
]));
	set("no_clean_up", 0);
	set("outdoors", "tianshui");
	set("objects",([
	__DIR__"npc/moggy" : 3,
	__DIR__"npc/yak" : 1,
	__DIR__"npc/cowboy" : 1,
]));
	setup();
	replace_program(ROOM);
}
