//xiangfang.c	农家厢房
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","厢房");
	set("long",@LONG 
这是一间宽敞明亮的厢房，屋子里摆了些桌子，椅子，
做工都很粗糙，墙上挂着一张财神爷，正乐呵呵地朝你笑
着，这家的主人正在摆弄农具。
LONG
	);
	set("exits", ([
		"south"	: __DIR__"xiaoyuan",
	]));
	set("objects",([
		__DIR__"npc/nongfu" : 1,
			]));
	setup();
}

