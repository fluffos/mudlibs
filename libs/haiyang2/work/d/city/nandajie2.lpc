// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2

inherit ROOM;

void create()
{
	set("short", "十里长街");
	set("long", @LONG
这里就是张佑诗中写的「十里长街市井连，月明桥上望神仙」的十
里长街。长街宽达三十丈，青砖铺地，东边一道泄水沟。街中心种有槐
树，分行人以左右而行。西边是官河，岸边相间种有绿柳碧桃，倒影水
面，摇曳风中。北边通往市中心，西边是一家顾客众多的茶馆，三教九
流人士都在那里谈天说地。东边一座两层的楼房传来阵阵浪笑，那就是
天下闻名的丽春院。
LONG );
        set("outdoors", "city");
//	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"lichunyuan",
		"south" : __DIR__"nanmendajie",
		"west"  : __DIR__"chaguan",
		"north" : __DIR__"nandajie1",
	]));
        set("objects", ([
                CLASS_D("shaolin") + "/tuoboseng" : 1,
                "/d/dali/npc/duanyu": 1,
        ]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 18 && !wizardp(me))
		return notify_fail("小朋友不要到那种地方去！！\n");
	return 1;
}
