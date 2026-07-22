inherit ROOM;

void create()
{
	set("short", "右仓");
	set("long", @LONG
这是蒙古大军的囤粮之所，所谓兵马未动，粮草先行，这里的粮食和草料
堆积如山。一队队巡逻兵来回守卫，戒备森严。
LONG);
	set("outdoors","黄河");

	set("exits", ([
		"east" : __DIR__"liangcang2",
        ]));
	set("objects", ([
		__DIR__"obj/liangdun" : 1,
		__DIR__"npc/yuanbing" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	ob = present("yuan bing",environment(this_player()) );
	if(ob)
		return notify_fail("元兵一把将你拦住：哪里跑！\n" );

	return ::valid_leave(me, dir);
}