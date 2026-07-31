// Room: /d/suzhou/ymhting.c
//by dwolf
//97.11.4 

#include <ansi.h>         
#include <room.h>
inherit ROOM;

void create()
{
	set("short", MAG"衙门后厅"NOR);
        set("long", @LONG
	  这里是衙门后厅，厅内有几张椅子，一张桌子，还有一个书橱，知府夫人
穆念慈正和几位姑娘聊天。
LONG
	);

	set("exits", ([
		"south" : __DIR__"ymzting",
		"east" : __DIR__"shufang2",
	]));        
	
	set("objects", ([
		__DIR__"npc/surr" : 1,
		__DIR__"npc/ster" : 1,
		__DIR__"npc/lhxiu" : 1,
		/*__DIR__"npc/gsnan" : 1,*/
	]));

	setup();
}


