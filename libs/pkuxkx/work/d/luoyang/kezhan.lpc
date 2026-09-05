//洛阳，扩展地图
//by kiden
//2006-9-8
// Modified by iszt@pkuxkx, 2007-04-26
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIW"白马客栈"NOR);
	set("long",
"这是洛阳城里最大的一家客栈，紧靠洛阳中心，以洛阳的名胜白马寺
来命名，曰「"+HIW"白马客栈"+NOR"」，由于价格公道，因此到这里来借宿的客人川流
不息，络绎不绝，生意极其兴隆，大堂内摆了七八张桌子，店小二跑来跑
去接待着从四面八方来的客人。客栈后面是客人休息的地方。柜台前摆着
一个牌子("+HIR"sign"+NOR")。\n");
	set("item_desc", ([
		"sign" : "本店客房每夜五两白银。\n",
	]) );

	set("no_fight",1);
	set("valid_startroom", 1);
	set("no_beg",1);
	set("no_steal",1);
	set("exits", ([
	       "east" : __DIR__"houyuan",  
	       "west" : __DIR__"nandajie1",            
	]));
	set("objects", ([
		__DIR__"npc/xiaoer-kz" : 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( !me->query_temp("rent_paid") && dir == "east" )
		return notify_fail("店小二一下挡在门前，白眼一翻：怎麽着，想白住啊！\n");
	if ( me->query_temp("rent_paid") && dir == "west" )
		return notify_fail("店小二满脸堆笑：「客官，客房在东边。」随即小声嘀咕：「真是个白痴。」\n");
	return ::valid_leave(me, dir);
}