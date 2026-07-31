// Room: /u/qingyun/jyzj/cuigu.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"洞天福地"NOR);
	set("long", @LONG
出得洞来，突然间阳光耀眼，你闭着眼定一定神，再睁开眼来，面前竟是
个花团锦簇的翠谷，红花绿树，交相掩映。山洞离地竟然不过丈许。你轻轻一
跃，便已着地，脚步下踏着的是柔软细草，鼻中闻到的是清幽花香，耳中听到
的是鸣禽间关，眼前呈现的是鲜果悬枝，你怎么也不会想到经过黑黝黝的洞穴
之后，竟会有这样一个洞天福地。
LONG	);
	set("exits",([
                "north" :   __DIR__"shanlu5",
                "south" :   __DIR__"cuigu3",
		"eastup" : __DIR__"shanbi",
                "west" :  __DIR__"shanlu3",
	]));
	set("objects", ([
		__DIR__"obj/rock" : 1,
	]));

	set("outdoors", "昆仑翠谷");
	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action("do_zuan", "zuan");
}

int do_zuan(string arg)
{
	object me = this_player();
        object *ob = deep_inventory(me);
        int i = sizeof(ob);
	if (arg == "dong"){
            while (i--)
            if(ob[i]->id("jiuyang zhenjing"))
                return notify_fail("你转念一想，携带如此重要的武学秘籍出去，岂不危险，不如藏在此处更为安全。\n");
	    message("vision", me->name() + "一个溜身，钻进了山洞。\n", environment(me), ({me}));
            write("你强吸一口气，从狭窄的山洞中穿过，来到一个大平台上。\n");
            me->move(__DIR__"dapingtai");
            message("vision", me->name() + "从山洞中钻了出来。\n", environment(me), ({me}));
	    return 1;
	}
	return 0;
}
