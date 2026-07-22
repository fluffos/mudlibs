// Write By Yanyang@SJ 2001.10.1
// Room: /d/changan/southjie3.c

inherit ROOM;

void create()
{
	set("short", "南大街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。南边是南城门通向城外。北
边则是城中心的钟楼。西边是城中的镜湖，景色十分优美。东边是一条长长的
街，一眼望不到头，不知道通向哪里。
LONG
        );
	set("outdoors", "长安");
	set("exits", ([
		"east"   : __DIR__"changjie1",
		"south"  : __DIR__"southmen",
		"west"   : __DIR__"jinghu",
		"north"  : __DIR__"southjie2",
	]));
        set("objects", ([
                __DIR__"npc/gongzi" : 1,
        ]));
	set("incity",1);
	setup();
}

int valid_leave(object me,string dir)
{
	if( me->query("no_quest") &&  dir == "east"){
		return notify_fail("\n");
	}
	return ::valid_leave(me, dir);
}
