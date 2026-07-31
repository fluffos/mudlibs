inherit ROOM;

void create()
{
	set("short", "东长安街");
	set("long", @LONG
这里是东长安街，宽阔的街道上车水马龙，人来人往。向西走就是
天安门了。北边是京城最有名的“千金楼”，达官显贵、宫廷侍卫都爱
去。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "beijing");
	set("exits", ([
		"east" : __DIR__"dongcha2",
		"west" : __DIR__"tian_anm",
		"north" : "/d/qianjin/qianjin",
		"south" : "quest/skills2/wunon/jiujia",
		//"south" : __DIR__"fuweibiaoju",
	]));

	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
