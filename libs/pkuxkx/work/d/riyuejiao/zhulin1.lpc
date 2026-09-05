//竹林

#include <ansi.h>
inherit ROOM;
#include "bamboo.h"
void create()
{
	set("short",HIG"竹林"NOR);
	set("long",@LONG 
这里是一大片竹林，竹林间偶尔有小动物穿行。
LONG
	);

	set("exits", ([
		"south" : __DIR__"zhulin",
		
	]));
	/*set("objects",([
               CLASS_D("riyuejiao") + "/tong" : 1,
		__DIR__"npc/jiaozhong1"	: 4,
		]));*/
	set("outdoors", "riyuejiao");
	setup();

}

void init()
{
    add_action("do_pi", ({ "pi","chop" }));
}

/*int valid_leave(object me, string dir)
{
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
        if (dir == "north" && me->query("family/family_name") != "日月神教" 
        && objectp(present("tong baixiong",environment(me)))
        && living(present("tong baixiong",environment(me))))
			return notify_fail("童百熊说道：「你不是我日月神教弟子，来我教干什么？速速离开！」\n");
        return ::valid_leave(me, dir);
}*/






