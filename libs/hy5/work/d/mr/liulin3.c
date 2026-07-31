// /u/beyond/mr/liulin3.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",GRN"柳树林"NOR);
         set("long",@long
这是一片碧绿的柳树林，草地中间有两棵大树(tree)，看上去枝叶茂盛，树上几
只小鸟唧唧喳喳的叫个不停。
long);
         set("exits",([
             "south" : __DIR__"liulin1",
]));
         set("item_desc", ([
"tree" : "树枝离地面不高，不知能不能跃(jump)上去。\n",
]));
set("objects",([
__DIR__"obj/xiao-shuzhi" : 2,
]));
setup();
}

void init()
{
        add_action("do_yue", "yue");
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{
	object me;
	me=this_player();
	write(RED"你纵身一跳...\n"
		       "结果你发现你的轻功难以跃上树枝。\n"NOR,
	);
	me->unconcious();
	return 1;
}

int do_yue(string arg)
{
                  object me;
             me = this_player();
             if (arg !="tree") 
             return notify_fail("你要到那去？\n");
             {
            
                    write("你纵身跳上了树枝。\n");
                    message("vision",
                             me->name() + "一纵身跳上了树枝。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"shuzhi");
                    message("vision",
                             me->name() + "从下面跳了上来。\n",
                             environment(me), ({me}) );
                }
                return 1;
            }




