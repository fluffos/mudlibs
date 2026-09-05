// Room: /d/diaoyudao/hzhang1.c 营帐
// hongdou 98.09.20

#include <ansi.h>

inherit ROOM;

void create()
{
	object room;
	set("short", "营帐");
	set("long", @LONG
你掀开帐廉，走进一座营帐，帐周围被密密的铁丝网围着，帐中
只有一张破桌子，旁边地上铺着厚厚的稻草，一个年轻姑娘正被一个
东瀛武士撕光了衣服按在草铺上，一边哭喊一边挣扎!
LONG
	);
	
	set("exits", ([
              "out": __DIR__"zhanghou",
	]));
	set("objects", ([
                __DIR__"npc/yunv" : 1,
                __DIR__"npc/dywushi" : 1,
        ]));
	setup();
}

/*
void init()
{
	tell_object(this_player(),BLK"\n八格亚路，什么的干活？竟敢破坏我的好事！！！\n"NOR);
	tell_object(this_player(),BLK"\n东瀛武士拿起武士刀，放下帐廉，堵住了出口，冲你
恶狠狠地喊道：“你的死了死了的。”\n\n"NOR);
}
*/

int valid_leave(object me, string dir)
{
	object npc;
        if(objectp(present("wu shi", environment(me)))) 
        {
               if (dir == "out" )
               {
                       return notify_fail(HIY"\n倭寇还没有被消灭，你怎么能临阵脱逃呢？\n"NOR);
               }
        }
	if (!(me->query_temp("marks/救"))) 
	{
      if (objectp(npc=present("shao nv", environment(me))))
	   {  
		message_vision(HIY
"\n少女不堪污辱，拾起地上的武士刀抹脖自尽了！你看了一眼血污的
尸体，叹了口气，离开了营帐。\n"NOR,me);
		npc->die();
	   }
	}
       return ::valid_leave(me, dir);

}
