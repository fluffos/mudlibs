// Room: /d/zuojiacun/yuju.c

inherit ROOM;

void create()
{
	set("short", "渔具店");
	set("long", @LONG
这是一家渔具店，店里面出售一些鱼钩、鱼杆、丝线一类的
渔具。店的老板娘坐在柜台后面正在闲着，看到你进来，忙站了
起来向你走来。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu3",
]));
  	set("objects",([
	"/clone/npc/npc" : 1,
]));
	setup();
	replace_program(ROOM);
}
