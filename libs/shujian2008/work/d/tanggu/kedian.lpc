// /d/tanggu/kedian.c 喜发客栈
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "喜发客栈");
        set("long", @LONG
看见不少的外乡人进进出出的地方就是这里有名的“喜发客栈”。一楼的
乡里人在喝茶听着评书。店小二上上下下的忙呼，柜台后面老板在幽闲自在。
柜台上面有一个牌子。
LONG );
        set("no_sleep_room",1);
        set("no_fight",1);
        set("exits", ([
                "north" : __DIR__"stxijie1",
		"up" : __DIR__"kedian2"
	]));

	set("objects", ([
                __DIR__"npc/xiaoer" : 1,
      	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="喜发客栈" && dir == "up" )
		return notify_fail(CYN"店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n"NOR);
	if ((string)me->query_temp("rent_paid")=="喜发客栈" && dir == "north")
		return notify_fail(CYN"店小二跑到门边拦住：客官已经付了银子，怎麽不住店就走了呢！旁人还以为小店伺候不周呢！\n"NOR);
	return ::valid_leave(me, dir);
}
