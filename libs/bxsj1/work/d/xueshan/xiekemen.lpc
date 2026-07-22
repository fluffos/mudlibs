// Room: xiekemen.c

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "谢客亭");
	set("long", @LONG
前面一溜细青石覆檐砖墙，中间一扇黑漆木门，门额上有流云、仙鹤、行
龙、双凤等深浮雕图案，雕工细致，构思巧妙。正中匾额书“谢客亭”三字。
门旁立着个小牌子(sign)。
LONG
	);

	set("exits", ([
		"southup" : __DIR__"zhudubadian",
		"enter" : __DIR__"rimulundian",
	]));
	set("item_desc",([ "sign" : "		进香客步止于此。\n",
	]));
	set("objects", ([CLASS_D("xueshan") + "/sangjie" : 1,
		__DIR__"npc/fanseng" : 2,]));
	setup();
        create_door("enter", "黑漆木门", "out", DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{        
        /*
        if ((string)me->query("family/family_name") != "大轮寺" 
           && dir == "enter"  
           && present("sang jie", environment(me)))
	return notify_fail(
"桑结伸手拦住了你，一指门旁的牌子道：“没看到牌子么？施主还是请回吧。”\n");
	*/
        if ((string)me->query("family/family_name") != "大轮寺" 
           && dir == "enter"  
           && present("hufa lama", environment(me)))
	return notify_fail(
"护法喇嘛拦住你道：“里面是本寺方丈及弟子居所，施主如欲礼佛还请去前面大殿。”\n");

	return ::valid_leave(me, dir);
}
