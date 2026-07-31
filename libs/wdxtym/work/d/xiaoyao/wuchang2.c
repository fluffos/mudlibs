// wuchang2.c

inherit ROOM;

void create()
{
	set("short", "逍遥场");
	set("long", @LONG
这是里没有什么多余的摆设，只是立了一些制作精巧的练功用的木人，
看来这里是供给逍遥派弟子练功用的场所。
LONG
	);
	set("exits", ([
		"north" : __DIR__"xiaodao1",
	]));

 	set("objects", ([
		"/clone/npc/mu-ren" : 4,
	]));

	set("outdoors", "xiaoyao");
	set("for_family", "逍遥派");
	setup();
}
