// /d/wudang/shanlu2.c  山路

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",YEL"山路"NOR);
        set("long", @LONG
你走在一条偏僻的山路上，四周灌木丛丛，遍地奇花异草，人迹罕至，路
径几不可寻，只有采药的人才敢进入深山。你到处乱窜寻找出路，猛的一痛，
荆棘把你给划伤了!
LONG                           
        );

        set("exits", ([
                "west" : __DIR__"langmei",
                "southeast" : __DIR__"houshan/hsxl5",
        ]));

        set("outdoors","武当");
        set("objects",([
               CLASS_D("wudang")+"/caiyao" : 1,
        ]));

        setup();
}

void init()
{
	add_action("do_zuan","zuan");
}

int do_zuan(string arg)
{
	object me = this_player();
	
	if (! arg || arg != "guanmu")
	    return notify_fail("你没事乱钻什么啊？\n");
	
	if ( me->is_busy() || me->is_fighting())
	    return notify_fail("你正忙着呢。\n");
	
	message_vision("$N一猫腰钻进了灌木丛中。\n",me);
	me->move(__DIR__"shanlu3");
	tell_room(environment(me),me->query("name") + "弯曲着身子，钻了进来。\n",({ me }));
	return 1;
}
