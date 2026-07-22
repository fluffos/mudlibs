// 交流室
// jiaoliushi1.c
// augx@sj 9/24/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","陈列室");
	set("long",
"这里是寄卖店掌柜的陈列室，陈列了掌柜多年来的收藏。此处到处摆满了
兵器防具，以及珍奇的药草。此处也成为工匠们交流经验，推荐产品的场所。
"); 
        
	set("exits",([
		"east"  : __DIR__"jimaidian1",
	]));
	
	set("indoors", "扬州城");
	set("incity",1);
	setup();
	
	call_other( "/clone/board/worker1_b", "???" );
}
