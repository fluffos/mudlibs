// Room: /city/duchang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "淮扬赌场");
	set("long", @LONG
这里是淮扬赌场的大院，烟花三月的扬州，怎么能少了这个？院子
四周是通往各个房间的通道。隐隐可以听到传出来吆五喝六的声音。你
摇头一笑，想要的正是这个调调儿。南面搏饼厅，也是本潭的网友联谊
会，联谊会四周是搏饼屋。
LONG );
	set("item_desc", ([
		"paizi" : "二楼的拱猪房正处于测试阶段。\n",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
	]));
	set("exits", ([
//		"west" : __DIR__"daxiao",
		"up"   : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
		"south": __DIR__"bobingting",
		"west" : __DIR__"zoulang1",
		"north" : __DIR__"shaiziting",	
	]));
	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "west" && this_player()->query("age")<18)
                return notify_fail("小毛孩子往这儿瞎凑合什么?!\n");
        return ::valid_leave(me, dir);
}

