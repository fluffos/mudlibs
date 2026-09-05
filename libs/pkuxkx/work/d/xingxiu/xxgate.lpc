// Room: /d/shaolin/hanshui1.c
// Date: YZC 96/01/19
#include <ansi.h>
inherit ROOM;


void create()
{
    set("short", YEL"巨岩"NOR);
    set("long", @LONG
这里是星宿派的势力范围了，站着几个星宿弟子，其中一个面色冷峻，太阳穴高高隆
起一看就是有一身不错的功夫，另外几人手拿乐器，好象在说着什么，此前是一片空地，
打扫的非常干净，空地两侧立着两根一丈高的旗杆，上面的彩旗被风吹的唰唰作响，上面
写着几个大字(zi),远处传来阵阵野兽的长啸声.
LONG
    );

    set("exits", ([
        "south" : __DIR__"tianroad1",
        "north" : __DIR__"tianroad2",
    ]));

    set("item_desc", ([
        "zi" : HIR"星宿老仙，举世无双\n"NOR,
    ]));
    set("objects", ([
         "/kungfu/class/xingxiu/tianlang": 1,
         __DIR__"npc/gushou": 1,
         __DIR__"npc/haoshou" : 1,
         __DIR__"npc/boshou" :1,
        __DIR__"npc/huangya" : random(3),
        ]));

    set("outdoors", "xingxiu");
    setup();
}

int valid_leave(object me,string dir)
{
    if (me->query("special_skill/sociability")) 
        return ::valid_leave(me, dir);  
    if (me->query("emnewbiejob_miejue_task")==1&&me->query("family/family_name")=="峨嵋派")//em新手任务交换生免疫
        return ::valid_leave(me, dir); 
    if( dir != "north" || (int)me->query("shen")< 5000 )
         return ::valid_leave(me,dir);
    if( objectp(present("tianlang zi",environment(me)))
        && living(present("tianlang zi",environment(me))))
        return notify_fail("天狼子伸手拦住了你的去路，说道“你们所谓白道人士到我们星宿干什么？\n");
    return ::valid_leave(me,dir);
}
