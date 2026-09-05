// liangongfang.c 练功房
// Made By:pingpang

inherit ROOM;

void create()
{
	set("short", "练功房");
	set("long", @LONG
	这里是归云庄的练功房，地下凌乱地放着几个蒲团，几位桃花岛弟子正盘膝坐在上
面打坐。
LONG
	);
	set("exits", ([
		                "west" : __DIR__"liangongfang1",
		"east" : __DIR__"zoulang5",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 2]));

	set("no_fight", 1);
	
	setup();
	replace_program(ROOM);
}
