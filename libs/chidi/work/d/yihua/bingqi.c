inherit ROOM;

void create()
{
	set("short", "雨花阁");
	set("long", @LONG
这里是移花宫的兵器房，四周放这几个兵器架，上面是移花宫各
弟子平时练剑用的剑。
LONG
	);
	set("exits", ([
		"west" : __DIR__"changlang",
	]));
	set("objects", ([
		"/clone/weapon/changjian.c" : 5]));

	set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}