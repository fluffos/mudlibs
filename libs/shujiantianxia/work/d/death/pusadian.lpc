// Room: /d/death/gateway.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU"地藏王菩萨殿"NOR);
	set("long", @LONG
你现在来到一座阴森的大殿前，新来的鬼魂们都必须在此接受阎王
恍惚间，你来到一座雄伟的大殿前，此处光线缓和，将那些鬼哭狼嚎之
声都挡拒在外。殿内正中坐有一尊菩萨，面带宝象，头顶紫冠，是地藏
王菩萨。
LONG);
	set("exits", ([ 
		"out" : "/d/death/gate",
	]));
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/pusa": 1,
                __DIR__"npc/shami": 2,
	]) );
	setup();
}

int valid_leave(object me, string dir)
{
	if( wizardp(me) || !userp(me) ) return 1;
	if( dir == "out") 
	     return notify_fail("一阵阿弥陀佛在你耳边响起。。。使你不由自主地盘膝坐了下来。\n");
	else return 1;
}
