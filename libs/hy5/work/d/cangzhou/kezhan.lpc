// Room: /d/cangzhou/kezhan.c

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "大客栈");
        set("long", @LONG
这里是就是沧州客栈。传说这家客栈是直隶最大的客店的老板原来是一名
江湖上的高人，自从退隐江湖后，开了这家客栈，江湖中人路过这里都会在这
个客栈投宿一晚，既是给这位高人一个面子，表示我来探望过你了，也顺便照
顾生意。客栈的一楼是个酒楼，很多人在打尖吃饭，二楼就是住宿的地方了。
门上的横匾上写了四个金字“沧州大客栈”。
LONG );
        set("exits", ([
        	"north" : __DIR__"beijie3",
		"south" : __DIR__"nanjie1",
		"up" : __DIR__"kezhan2",
	]));
	
	set("objects", ([
                __DIR__"npc/xiaoer" : 1,
		__DIR__"npc/miao" : 1,
        ]));
	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail(CYN"店小二一下挡在楼梯前，白眼一翻：怎麽着，想白住啊！\n"NOR);

	if ( me->query_temp("rent_paid") && dir != "up" )
		return notify_fail(CYN"店小二急忙拦住：客官已经付了银子，怎麽不住店就走了呢！旁人还以为小店伺候不周呢！\n"NOR);

	return ::valid_leave(me, dir);
}
