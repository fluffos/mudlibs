// /u/beyond/mr/tingyuju.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",BLU"听雨居"NOR);
         set("long",
"「"WHT"听雨居"NOR"」三面环水, 从窗中望出去, 湖上烟波尽收眼底。屋正中摆着\n"
"一张大圆桌, 上面摆满了蔬果点心, 每一样都十分精致。 圆桌四周放了数\n"
"把椅子。墙边的小柜上放着一把「"BLU"琴"NOR"」。\n"
);        
         set("item_desc",([
             "floor" : "古琴旁边的地面不是十分平整。\n",
             "qin" : "这是一把古琴，弹一曲会使人心旷神怡。\n",
]));
         set("objects",([
             __DIR__"npc/azhu" : 1,
]));
         set("exits",([
"southeast" : __DIR__"xiaojing2",
])); 
         set("no_clean_up", 0);
}       
   
void init()
{
add_action("do_tan", "play");
add_action("do_tan", "press");
        add_action("do_tan", "tan");
}

int do_tan(string arg)
{
        object me;
     me = this_player();
        if (arg !="qin") 
return notify_fail("你要弹什么？\n");
        if( arg=="qin")
        {
            
             write("你弹了一下琴，突然脚下一空，掉了下去。\n");
                    message("vision",
             me->name() + "弹了一下琴，突然脚下一空，掉了下去。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"xiaozhou");
                    message("vision",
                  me->name() + "从上面的隔板中掉了下来,落到一条小舟上。\n",
                             environment(me), ({me}) );
                }
                return 1;
            }
