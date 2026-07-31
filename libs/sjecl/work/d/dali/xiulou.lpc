// Room: /dali/xiulou.c
// bbb 1997/06/11
// Modify By River 98/12/

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIY"绣楼"NOR);
	set("long", @LONG
这家绣楼已开了几十年了，这里的老板娘祖上曾到中原学过刺绣织布回来
开了这家店，好多有钱人都到这来买布买服装，你可以在这里买卖布匹，和编
织自己的布匹。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"xijie2",
	]));

	set("objects", ([
		__DIR__"npc/women": 1,
		//"/d/zhiye/obj/zhibuji":1,
	]));
	set("no_zhiye", 1);
	set("incity", 1);
	set("no_fight", 1);
	setup(); 
}

void init()
{
	object me = this_player();
	if(me->query_temp("xuncheng"))
		me->set_temp("dali_xc/xiulou",1);
}
