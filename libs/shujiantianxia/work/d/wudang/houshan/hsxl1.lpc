#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "小路");
	set("long", @LONG
这里是山路的尽头，前面是一座险峻的山峰。峭壁上长着许多松树，在山
壁上打了一些一尺来长的木桩，似乎可以踩着木桩爬(pa)上去。
LONG	);
	set("exits", ([ 
                 "northdown" : __DIR__"hsxl2",
        ]));
	set("objects",([
                CLASS_D("wudang") + "/chenggao" : 1,
        ]));
        
        set("outdoors", "武当");
        setup();
}

void init()
{
        add_action("do_pa","pa");
}

int do_pa(string arg)
{
        object me;
        me=this_player();
        
        if ((int)me->query_skill("dodge", 1) < 20)
            return notify_fail("你的轻功不够，无法爬上去。\n");
        if (arg =="up"){
           write("你踩着木桩，小心翼翼的向上爬去。\n");
           message("vision",me->name() + "向上一纵突然不见了。\n",environment(me), ({me}) );
           message("vision", me->name() + "爬了上来。\n",environment(me), ({me}) );
           me->move(__DIR__"taoyuan1");
           return 1;
        }
       return notify_fail("你要往哪儿爬？\n");
}
