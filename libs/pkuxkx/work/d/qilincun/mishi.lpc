// Rewrote by iszt@pkuxkx, 2007-02-11

#include "dong.h"
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"密室"NOR);
	set("long", @LONG
这是土匪窝中的密室，和外面一样都是一片黑暗。一个少年正护着一个少妇
靠在密室一角，少年英气逼人，那少妇却是瑟瑟发抖。看到你进来，他们的眼中
都不禁闪动着喜悦的光芒。
LONG);
	set("exits", ([
		"out" : __DIR__"dong99",
		"south" : __DIR__"shanlu10"
	]));
    set("no_task",1);
	set("objects", ([
		__DIR__"npc/lev8" : 1,
		__DIR__"npc/lev"+random(9) : 1,
		__DIR__"npc/lev"+random(9) : 1,
		__DIR__"npc/cuigu" : 1,
		__DIR__"npc/yuefei" : 1,
	]));

	setup();
	
}


int valid_leave(object me,string dir)
{  
	if (dir=="out")
    {
        if (!userp(me))
        {
            return notify_fail("你老兄哪能出去呀？\n");
        }
        
    }
	return ::valid_leave(me, dir);
}