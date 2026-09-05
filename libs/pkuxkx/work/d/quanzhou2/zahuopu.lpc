// Room: /d/quanzhou/zahuopu.c
// Date: May 7, 96   Jay

inherit ROOM;

void create()
{
	set("short", "杂货铺");
	set("long", @LONG
这里是一家专卖女人用的东西的小铺子。
LONG
	);

	set("exits", ([
                "east" : __DIR__"xijie",
	]));
	set("hsz_no_task",1);
    set("objects", ([
                 __DIR__"npc/chen" : 1,
    ]) );


	setup();
}

void init()
{
    object me=this_player();
    if (!userp(me)&&me->query("name")!="陈阿婆")
    {
        me->move(__DIR__"xijie");
    }
}

