// Room: /city/kedian2.c

inherit ROOM;

void create()
{
	set("short", "天机楼");
	set("long", @LONG
这就是闻名万里的天机楼，据说每隔一段时间，天机老人就会来此一游。
LONG );
	set("exits", ([
		"north"  : __DIR__"kedian",
	]));

	set("no_fight", 1);
	set("objects", ([
		 "/d/city/npc/tianji"    : 1,

	]));


	setup();
}