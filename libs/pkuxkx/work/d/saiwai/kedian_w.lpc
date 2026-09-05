// Room: /city/kedian.c
// YZC 1995/12/04 
#include <title.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "客店");
	set("long",
"这是一家价钱低廉的客栈，生意非常兴隆。外地游客多选择这里落脚，你可\n"
"以在这里打听到各地的风土人情。店小二里里外外忙得团团转，接待着南腔北调\n"
"的客人。客店的主人从不露面，他究竟是谁，有各种各样的猜测。墙上挂着一个\n"
"牌子" + RED "(paizi)" NOR "。\n");

	set("valid_startroom", 1);
    set("no_sleep_room",1);

	set("item_desc", ([
                "paizi" : "张家口客栈，每晚二两。\n",
	]));

	set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"southstreet",
		"enter" : __DIR__"kedianw2",
	]));
	set("kedian","天字号房");
	setup();
}
int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "enter" )
		return notify_fail("店小二一下挡在门前，白眼一翻：怎麽着，想白住啊！\n");

	return ::valid_leave(me, dir);
}