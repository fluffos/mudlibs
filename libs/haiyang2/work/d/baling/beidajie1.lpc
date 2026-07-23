
inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许
多人都往南边走去，那里有一个热闹的广场。东边是一家生意兴隆的药
铺，一位老板在作诊。西边是一家钱庄，可以听到叮叮当当的金
银声音。
LONG
	);
        set("outdoors", "baling");

	set("exits", ([
		"south" : __DIR__"guangchang",
		"west" : __DIR__"qianzhuang",
		"north" : __DIR__"beimen",
		"east" : __DIR__"yaopu",
	]));
	set("objects",([
	 __DIR__"npc/xiaonvzi":1,
	 ]));
	setup();
	replace_program(ROOM);
}

