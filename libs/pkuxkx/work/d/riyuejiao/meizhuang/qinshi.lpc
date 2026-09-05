//qinshi.c   琴室
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","琴室");
	set("long",@LONG 你一进屋门，便闻到一股檀香。只见这里铺设得甚为高雅。桌上放着一张
古琴，墙上挂着一支玉箫，一看便知都是价值连城的古物。门额上写着「琴心」
两字，以蓝色琉璃砌成，笔致苍劲。
LONG
	);

	set("exits", ([
		"south"	: __DIR__"yuanzi",
		"north" : __DIR__"neishi",
	]));
	set("objects",([
		__DIR__"npc/huangzhong":1,
		]));

	setup();

}

int valid_leave(object me, string dir)
{
        if (dir == "north")
	{
		if (!present("huangzhong gong",environment(me)))
			return notify_fail("主人不在，你怎么可以进去呢？\n");
		if (!me->query_temp("riyue/黄ok"))
			return notify_fail("黄钟公说道：「里间是我休息之地，贵客请勿进去。」\n");
		if (!me->query_temp("riyue/黑ok"))
			return notify_fail("黄钟公说道：「我二弟还没有应允，你还是去问一下他吧！」\n");
		if (!me->query_temp("riyue/秃ok"))
			return notify_fail("黄钟公说道：「我三弟还没有应允，你还是去问一下他吧！」\n");
		if (!me->query_temp("riyue/丹ok"))
			return notify_fail("黄钟公说道：「我四弟还没有应允，你还是去问一下他吧！」\n");
        if ( me->query_encumbrance() * 100 / me->query_max_encumbrance() > 30)
                return notify_fail("你身上背那么多东西进去干吗呀？\n");

          if (present("huangzhong gong",environment(me)))
	message_vision("黄钟公闪在一旁，说道：「" + RANK_D->query_respect(me) + "请进。」\n",me);
      }
        return ::valid_leave(me, dir);
}






