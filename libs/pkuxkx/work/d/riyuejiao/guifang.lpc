//guifang.c	闺房
//by bing
#include <room.h>
inherit ROOM;

void create()
{
	set("short","闺房");
	set("long",@LONG 
房内花团锦簇，脂粉浓香扑鼻，东首一张梳妆台畔坐着一人，身穿粉红衣衫，
左手拿着一个绣花绷架，右手持着一枚绣花针，抬起头来，看了看你。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xiaoshe",
	]));
	set("objects",([
               CLASS_D("riyuejiao") + "/dongfang" : 1,
		]));
        set("no_task",1);
	setup();
}

