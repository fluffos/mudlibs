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
		"east" : "/d/guiyunzhuang/zoulang5",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 2]));
       set("research_room",1);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("valid_startroom", 1);
	
	setup();
	replace_program(ROOM);
}
