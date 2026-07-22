// /u/dubei/miaojiang/mjqj

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY+"苗疆奇境"+NOR);
	set("long", @LONG
这里是山顶的一片空地，四周开满各种鲜花，抬头望去，能看到一片片飘
渺的浮云。不远处有几棵参天大树，下面长满各种植物。
LONG                           
        );
	set("xueteng_count",2);
        
	set("exits", ([
		"south" : __DIR__"gmcong14",
		"west" : __DIR__"shulin",
		"northeast" : __DIR__"mjqj1",
        ]));
	set("outdoors", "苗疆");
	setup();
}

void reset()
{
	set("xueteng_count", 2);
}

void init()
{
        add_action("do_wa", ({"wa","dig"}));
}

int do_wa(string arg)
{ 
        object xueteng;
        object me;
        me = this_player();

        if (!( present("xiao tiechan", this_player())))
		return notify_fail("你在地上刨了刨 ，惊起许多小动物！\n");

	if ( !arg || arg != "xue teng" )
		return notify_fail("你做什麽？\n");
        
	if ( (int)me->query("jingli") < 200) 
		return notify_fail("你太累了！\n");

	if(random(20)!=3) {
		me->add("jingli",-120);
		return notify_fail("你挖了半天，只看到一些野草。\n"); 
	}
 
	if (query("xueteng_count") > 0) {
		message_vision("$N忽然看到一株白色的小植物，赶快捡了起来。\n",me);
		add("xueteng_count", -1);
		xueteng=new(MEDICINE_D("xueteng"));
		xueteng->move(me);
		me->add("jingli", -200);
	}
        else
		message_vision("$N挖了半天，一无所获。\n", me);
	return 1;
}
