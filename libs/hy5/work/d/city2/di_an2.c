inherit ROOM;

void create()
{
	set("short", "地安门东大街");
	set("long", @LONG
这是一条东西走向的大道。西边通往地安门。东边通往王府井。
LONG );
        set("outdoors", "city2");

	set("exits", ([
		"east" : __DIR__"di_an1",
		"west" : __DIR__"di_anmen",
	]));
	set("objects", ([
		__DIR__"npc/flowerg" :  2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


