// Room : /d/city/kedian.c

#include <ansi.h>
#include <room.h>

inherit CREATE_CHAT_ROOM;

void create()
{
	set("short", "精意客栈");
	set("long", @LONG       
这里是最近刚刚开业的精意客栈，老板生意非常兴隆。这里聚集着大
量的江湖中人，而且每天都有成百上千的各种各样的人赶来这里，但他们
的目的都是一样，都是为这里刚被发现的精意山庄而来。这里本来是遥无
人烟的地方，由于精意山庄的被发现，这里很快的形成了一座城市，这间
客栈也就是这样情况下开业的。你可以在这里打听到各地的风土人情。店
小二里里外外忙得团团转，接待着南腔北调的客人。当你走了进来，店小
二连忙迎上前去。客栈正面的墙上挂着一块醒目的牌子(paizi)。
LONG
	);

	set("valid_startroom", 1);
	set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "楼上雅房，每夜五两白银。\n",
	]));

	set("objects", ([
                __DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
                "west" : __DIR__"shanlu",
                "north" : __DIR__"majiu",
		"up" : __DIR__"kedian2",
	]));

	setup();
	"/clone/board/kedian_b"->foo();
}

void init()
{ 
        object me = this_player();
        add_all_action(); 
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
		return notify_fail("怎么着，想白住啊！\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("客官已经付了银子，怎么不住店就走了呢！旁人还以为小店伺候不周呢！\n");

	return ::valid_leave(me, dir);
}
