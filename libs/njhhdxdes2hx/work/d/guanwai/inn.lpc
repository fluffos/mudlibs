// inn.c

#include <room.h>

inherit ROOM;

string look_sign(object me);

void create()
{
	set("short", "迎梅客栈");
	set("long", @LONG
这是布达拉宫中最大的一家客栈。据说这家店主是一个痴情的年青人。他
在这里开客栈就是希望他当年在中原失散的情人能够知道他在这里，而来与他
相会。可是店开多年，中原客人来人往，还是没有他昔年情人的一点消息。
一块大匾(sign)悬于堂内。
LONG
	);

	// This enables players to save this room as their startroom.
	set("valid_startroom", 1);

	set("item_desc", ([
		"sign": (: look_sign :),
	]) );
	
	set("exits", ([
		"west"   : __DIR__"octo1",]) );


	set("objects", ([
		__DIR__"npc/waiter" : 1 ]) );


	setup();
        // To "load" the board, don't ever "clone" a bulletin board.
        call_other( "/obj/board/lasa_b", "???" );

}

string look_sign(object me)
{
	if( wizardp(me) )
		return "招牌写著：情为何物！ 旁边一排小字：俞铁题。\n";
	else
		return "招牌写著：情为何物！\n";
}
