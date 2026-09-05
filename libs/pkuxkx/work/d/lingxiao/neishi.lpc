// File		: neishi.c
// Created By	: iszt@pkuxkx, 2007-01-22

inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这是白自在的寝室，家具屋饰，极尽豪华，谓金碧辉煌，桂
殿兰宫。但现在白自在已不知去向，只剩他的一个妾室，还在这
里抽抽噎噎地哭。
LONG);

	set("indoors", "凌霄城");
	set("exits", ([
		"east" : __DIR__"huating",
	]));

        set("objects", ([  
                __DIR__"npc/yaoniang" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
