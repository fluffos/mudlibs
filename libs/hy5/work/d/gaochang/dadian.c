// dadian 大殿
// by yuan

inherit ROOM;

void create()
{
	set("short", "高昌大殿");
	set("long", @LONG
	这里就是传说中埋藏着无数宝藏高昌迷宫的大殿，四壁供的都是泥塑木雕的佛像.
大殿之上有一个大大的龙椅，大堂之上透着一股威严，有一块大匾，上书：

                ****************
                *              * 
                *   文成武德   *
                *              *
                ****************

东西两面都是殿堂。
LONG
	);
	set("valid_startroom", 1);
	set("exits", ([
		"west" : __DIR__"wroom1",
		"east" : __DIR__"eroom1", 
	]));
//	set("objects", ([
//		CLASS_D("wudang") + "/guxu" : 1,
//		CLASS_D("wudang") + "/song" : 1]));
	setup();
//	replace_program(ROOM);
//	"/clone/board/wudang_b"->foo();
}

