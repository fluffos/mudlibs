// by advent
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "熊洞");
        set("long", 
"洞中有不少白熊残余食物，鱼肉鱼骨，甚是腥臭。\n"
"地上横躺着一段老树干，树皮(shupi)坚韧，看来可以
派些用场。\n"
        );
        set("item_desc", ([
               "shupi" : "这树皮倒是做绳子的好材料。\n",
       ]));
        set("exits", ([
                "south" : __DIR__"pyuan2",
        ]));
        set("objects",([        
                __DIR__"npc/xiong" : 2,
                ]));
        setup();
}
void init()
{
        add_action("do_bo", "bo");
}
int do_bo(string arg)
{
        object ob,rope;
        object me = this_player();
        if( !arg || arg!="shupi" ) 
        {
             if ( !arg ) return notify_fail("你要剥什么？\n");
             if ( arg!="shupi" )  return notify_fail("你要剥什么？\n"); 
        }
        if (arg=="shupi")
        {
          tell_object(me, HIR"你拔出兵刃剥下树皮，搓成了一条长长的绳索。\n"NOR);
          message("vision",me->name()+"得到了长绳。\n",environment(me),({me}));
          rope = new(__DIR__"obj/rope");
          rope->move(me);
          return 1;
        }
}

