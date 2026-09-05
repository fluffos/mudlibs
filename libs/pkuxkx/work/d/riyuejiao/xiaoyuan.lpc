//xiaoyuan.c	农家小院
//by bing

#include <room.h>
inherit ROOM;

void create()
{
	set("short","农家小院");
	set("long",@LONG 
这是一处农家小院，院子里堆放着一些农具，房瓦上
晾晒着一些庄稼，黄澄澄的甚是好看。正中是大堂，左边
大概是间柴房，不见什么灯光，右边是间厢房。院子里有
几只小鸡在啄食吃，中央有口井，你可以在这喝点水(drink)
或是灌点水(fill)。
LONG
	);
        set("resource/water", 1);
	set("exits", ([
		"west"	: __DIR__"zhengfang",
		"east"	: __DIR__"yuanmen",
		"south"	: __DIR__"chaifang1",
		"north"	: __DIR__"xiangfang",
	]));
	set("objects",([
		__DIR__"obj/chick" : 3,
			]));
	set("outdoors", "riyuejiao");
	setup();
	create_door("east","院门","west",DOOR_CLOSED);
}

void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{
        int current_water;
	int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water<max_water) {
            me->set("water", current_water+30);
            message("vision", me->name()+"趴在井台上打了点水喝。\n"
            , environment(me), ({me}) );
            write("你喝了一口井中的水，清凉无比。\n");
        }
        else write("逮着不要钱的水就这么喝，至于吗?\n");

        return 1;
}
