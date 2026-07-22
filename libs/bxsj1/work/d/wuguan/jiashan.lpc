// jiashan.c
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIM"假山"NOR);
         set ("long",@LONG
这里属于武馆的后花园，里面奇石嶙峋，平时很少有人到这里来。花花草
草有的也已经凋谢了。左首的一块假山上有一条缝隙（feng）大的可以藏下各
把人。南面小路就是通向竹林的，路前挂了一块牌子（paizi）。
LONG
   );
	 set("outdoors","武馆");

	 set("exits",([
             "north" : __DIR__"wxting",
	     "south" : __DIR__"zhulin1",
	 ]));

         set("item_desc", ([
             "feng" : BLU"一条黑乎乎的缝隙，好象可以钻（zuan）过去。\n"NOR,
             "paizi" : HIR"南面竹林危险，闲者莫入。\n"NOR,
	 ]));

	 setup();
}

void init()
{
    add_action("do_zuan", "zuan"); 
}

int do_zuan(string arg)
{
        object me;
        me = this_player();

        if (arg !="feng") 
            return notify_fail("你往哪里钻啊？\n");
        if( arg=="feng"){            
            write(HIG"你用力地往缝隙里钻，费力地穿过了缝隙。\n"NOR);
	    me->move(__DIR__"jiashan1");
            me->start_busy(2);
        }
        return 1;
}
