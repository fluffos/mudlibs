// Room: /d/diaoyudao/shulin8.c 树林
// hongdou 98.09.20
// whuan to add jinwu-dao secret at 2008-5-3
#include <ansi.h>

inherit ROOM;
void init()
{
        object me=this_player();
        if (interactive(me) && me->query("jinwudao/phase1"))
        {
        this_object()->set("exits/enter",__DIR__"pingdi");
        tell_object(me,HIR"你突然发现树林中有一条小路。\n"NOR);
        }
        else
        {
        if (this_object()->query("exits/enter"))
         this_object()->delete("exits/enter");
        }
        add_action("do_climb", "climb");
}

void create()
{
        set("short", "树林");
        set("long", @LONG
你迷失了方向，仿佛走到了树林深处,你越来越感到恐惧，不知道怎么才
能走出这里。你的面前有一棵大树(tree)，直耸入天。
LONG
        );

        set("item_desc", ([
               "tree" : "一棵参天入云的大树，上去看看应该能找到出路。\n",
       ]));


        set("exits", ([
                 "east" : __DIR__"shulin7",
                "south" : __DIR__"shulin5",
                 "west" : __DIR__"shulin2",
                "north" : __DIR__"shulin4",
        ]));

        set("outdoors", "diaoyudao");
        setup();
//      replace_program(ROOM);
}

int do_climb(string arg)
{
        object me = this_player();
        if( !arg || arg!="tree" ) 
        {
             if ( !arg ) return notify_fail("你要往哪儿爬？\n");
             if ( arg!="tree" )  return notify_fail("那里不能爬！\n"); 
        }
        if (arg=="tree")
        {
           if((int)me->query_skill("dodge",1)<20)
               return notify_fail("你由于轻功欠佳，爬不上那么高的大树。\n");     
           else
             {  message("vision",me->name()+"灵活而轻便地爬上了大树。\n",environment(me),me);
                me->move(__DIR__"shuding");
                message("vision",me->name()+"也爬上了大树,出现在你的身旁.\n",environment(me),({me}));
                return 1;
             }
        }
}
