//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "西四北大街");
	set("long", @LONG
这里是西四北大街。南边通往西单。东边通向地安门，北面是一间书
院，不时传来阵阵朗朗的读书声。
LONG
);
	set("outdoors", "city2");
	set("exits", ([
		"south" : __DIR__"xisi",
		"east" : __DIR__"di_an4",
		"north" : __DIR__"shuyuan",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke": 1,
	]));
	setup();
	replace_program(ROOM);
}


