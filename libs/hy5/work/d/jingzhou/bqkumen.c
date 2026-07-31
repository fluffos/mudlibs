// Room: bqkumen.c
// congw  890830
inherit ROOM;

void create()
{
	set("short", "兵器库大门");
	set("long", @LONG
你正站在荆州兵器库的门口，可以看到两个穿着制服的官兵正在巡逻，不时
地传来呐喊声。老百姓是不允许在此观看的，你最好赶快走开。
LONG
	);

	set("exits", ([
		"west" : __DIR__"bqku",
		"east" : __DIR__"nandajie2",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "south")
		return notify_fail("官兵拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}

