// Room: /d/mingjiao/xiaozhen.c

inherit ROOM;

void create()
{
	set("short", "小镇");
	set("long", @LONG
这是一个昆仑山脚下的小镇。东面是个小木屋，门口有棵大树。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "southwest" : "/d/road/kunlunshan",
  "north" : __DIR__"shijie1",
  "west" : __DIR__"nongjia",
  "east" : __DIR__"house",
]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
    set("objects",([
__DIR__"npc/madman" :1,
]));

	setup();
	replace_program(ROOM);
}
