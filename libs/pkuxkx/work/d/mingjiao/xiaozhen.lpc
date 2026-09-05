// Room: /d/mingjiao/xiaozhen.c

inherit ROOM;

void create()
{
	set("short", "小镇");
	set("long", @LONG
这是一个沙漠边缘的小镇。东面是个小木屋，门口有棵大树。
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"shamo7",
  "north" : __DIR__"shijie1",
  "west" : __DIR__"nongjia",
  "east" : __DIR__"house",
"southwest" : __DIR__"machehang",
]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
    set("objects",([
__DIR__"npc/madman" :1,
]));

	setup();
	replace_program(ROOM);
}
