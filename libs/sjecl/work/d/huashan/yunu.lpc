// Room: /d/huashan/yunu.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "玉女峰");
	set("long", @LONG
这里是华山的中峰，玉女峰。玉女峰地势略为平缓，不似其它四峰那般险
峻，江湖上赫赫有名的华山剑派就在此处。西边有所小小的庙宇，那就是玉女
祠了。南面稀稀落落有十几间房子，那里是华山派的地方，闲杂游客最好别往
那去。
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"zhenyue",
		"northwest" : __DIR__"xiaolu1",
		"east" : __DIR__"yunuci",
		"south" : __DIR__"shanlu1",
		"west" : __DIR__"pubu",
	]));
	set("objects", ([
		NPC_D("youke") : 1,
		NPC_D("caiyaoren") : 1,
	]));
	set("outdoors", "华山" );
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir=="south" ){
        if(me->query("can_ride")) {  return 0;  }

	if(me->query_temp("ride_horse"))
		return notify_fail("这位" + RANK_D->query_respect(me) + "还是请先下马，再进去吧！\n");
        }
        return ::valid_leave(me, dir);
}


