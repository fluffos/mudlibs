//zhuquetang.c	朱雀堂
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","朱雀堂");
	set("long",@LONG 
这是日月神教所属的朱雀堂。堂中摆着几张太师椅，供桌
上供着历代日月神教教主和朱雀堂堂主的牌位。现任堂主正在
和教众议事。
LONG
	);

	set("exits", ([
		"east" : __DIR__"rukou",
		"north" : __DIR__"liwu",
		"south" : __DIR__"restroom",
	]));
	set("objects",([
               CLASS_D("riyuejiao") + "/bao" : 1,
		__DIR__"npc/jiaozhong2"	: 4,
		]));

	setup();

}







