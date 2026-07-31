//ytyuan.c
// this is made by hotjc

#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",HIM"樱桃园"NOR);
         set("long",@long
这是一片樱桃园，树上开满了樱桃花。西边是小姐闺房，墙上有一个窗户，
一扇窗子(window)大敞着。
long);
         set("exits",([
"north" : __FILE__,
"south" : __FILE__,
"west" : __FILE__,
"east" : __DIR__"ytyuan2",
             "south" : __DIR__"huandong",
]));
        setup();
}

int init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
		object me;
        me = this_player();
        if (arg !="window") 
        return notify_fail("你要干什么？\n");
        if( arg=="window")
        {          
             write("你一纵身，从窗户外跳了进去。\n");
                    message("vision",
             me->name() + "从窗户跳了下去。\n",
                             environment(me), ({me}) );
                    me->move(__DIR__"guifang");
                    message("vision",
                  me->name() + "从墙上的窗户外跳了进来。\n",
                             environment(me), ({me}) );
                }
                return 1;
}


