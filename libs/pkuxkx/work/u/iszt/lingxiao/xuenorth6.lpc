//吴起
//xuenorth6.c
//03-7-14

#include <room.h>;
#include <ansi.h>;

inherit ROOM;

void create()
{
	set("short", "寿板铺"NOR);
	set("long", @LONG
所谓寿板铺，其实就是棺材铺。看看这副对联就明白了：
                   梦且得官原瑞物
                   呼之为寿亦佳名
店主煞费苦心，讨了买主这么一个好，一来当然是为减轻死者家属的痛苦，
二也能给小店多招点生意。
LONG);
	
	set("indoors", "凌霄城");
	set("exits", ([
		"south" : __DIR__"xuejie6",
	]));
	set("objects", ([
		__DIR__"npc/skguan" : 1,
	]));

	setup();
}

