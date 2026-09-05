// Room: /hangzhou/dongdajie1.c
// hubo 2008/4/19 

inherit "/d/hangzhou/song_room";
void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条贯穿东西从东青门通往钱塘门的临安城主要干道，西面是众安桥。
LONG);
        set("outdoors", "hangzhou");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		//"south" : __DIR__"qianzhuang",
		"west" : __DIR__"zhongan",
		"north" : __DIR__"beijie1",
	]));

	setup();
	replace_program(ROOM);
}

