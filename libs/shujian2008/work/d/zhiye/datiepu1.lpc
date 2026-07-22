// 打铁铺
// datiepu1.c
// augx@sj 9/4/2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",RED"打铁铺"NOR);
	set("long",
"这是一间很朴实的屋子，里面只放了一张桌子和几张椅子，还有就是终
日炉火不熄的打铁炉了，和呼呼作响的风箱。在这里你可以买卖矿石，也可
以自己尝试一下打铁的乐趣。
"); 

	set("objects",([
		__DIR__"npc/tiejiang" : 1,
		//__DIR__"obj/datielu" : 1,
	]));
	
	set("exits",([
		"south" : "/d/city/dongdajie0",
	]));
	
	set("indoors", "扬州城");
	set("incity",1);
	set("no_fight", 1);
	setup();
}
