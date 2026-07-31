// /kaifeng/tonanyang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "官道");
	set("long", @LONG
这是条连接开封府与汝州的官道，由于这条路治安较好
行人也不少。西面通向开封，东面通向汝州。
LONG
	);
	set("exits", ([
		"north" : __DIR__"tokaifeng",
		"east" : "/d/ruzhou/ximen",
	]));
	set("outdoors", "kaifeng");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
