// Room: /hangzhou/dongdajie1.c
// hubo 2008/4/19 

inherit "/d/hangzhou/song_room";
void create()
{
	set("short", "北大街");
	set("long", @LONG
北大街沿着大河建造，虽然不如御街北段繁华，却是胜在清幽。
LONG);
        set("outdoors", "hangzhou");

	set("exits", ([
		"south" : __DIR__"beijie1",
		//"south" : __DIR__"qianzhuang",
		"west" : __DIR__"xianlinsi",
		"north" : __DIR__"beijie3",
	]));

	setup();
	replace_program(ROOM);
}

