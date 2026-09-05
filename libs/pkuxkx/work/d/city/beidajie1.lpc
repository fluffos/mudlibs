// Room: /city/beidajie1.c
// YZC 1995/12/04

inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人都往
南边走去，那里有一个热闹的广场。东边是一家生意兴隆的客栈，来自各地的人
们进进出出，据说也是情人们的幽会地点。东南边新开了一个比武场，可以见到
各式各样的江湖人物走动。西边是一家钱庄，可以听到叮叮当当的金银声音。
LONG);
	set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"kedian",
		"south" : __DIR__"guangchang",
		"west" : __DIR__"qianzhuang",
		"north" : __DIR__"beidajie2",
                "southeast" : "/d/wizard/biwuchang", 
	]));
	set("objects", ([
	//	"/u/pingpang/npc/chen":1,
		__DIR__"npc/liumang" : 1,
		__DIR__"npc/liumangtou" : 1,
		"/kungfu/class/shaolin/xingzhe" : 1,
	]));
	setup();
}

/*  考虑到还有护镖的伙计有可能在bwc，而且有时候要杀人降道德 --by whuan
int valid_leave(object me, string dir)
{
	object* inv = deep_inventory(me);
	int i;

        if(dir != "southeast")
		return ::valid_leave(me, dir);
	for(i=sizeof(inv)-1; i>=0; i--)
		if(inv[i]->is_character())
			return notify_fail("你不能背着"+inv[i]->name()+"去比武场！\n");
	if(me->query_conditions_by_type("poison"))
		return notify_fail("你现在中毒未解，不能进比武场。\n");
	return ::valid_leave(me, dir);
}
*/
