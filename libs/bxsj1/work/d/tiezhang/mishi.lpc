// Room: /d/tiezhang/mishi.c
//BY BOBO@sj 2000/1/27

inherit ROOM;
#include <ansi.h>
void init();
void create()
{
        set("short", HIY"密室"NOR);
        set("long", @LONG
这是瀑布后面的一间密室，地下尘土堆积，显是长时间无人到来，正中孤
零零的摆着一张石几(table)，几上有一只两尺见方的石盒(he)，盒口贴了封
条，此外再无别物。
LONG
        );

        set("exits", ([ 
        "out" : __DIR__"hhyuan-3",
        ]));

        set("item_desc", ([ 
        "he" : "一个四四方方的石盒，上面落满了尘土。\n",
        "table" : "这是一整块巨石雕成的石桌，上面积满了厚厚的灰尘。\n",
        ]));

        set("no_clean_up", 0);

        setup();
}

void init()
{
        
        object me = this_player();
        
        if((int)me->query_skill("dodge",1) <= 30) 
        {
                me->receive_damage("qi", 50);
                me->receive_wound("qi",  50);
                message_vision(HIR"$N只觉得被瀑布冲得左摇右晃，难以站稳，身体不由自主的摔出瀑布之外！\n"NOR, me);
                me->move(__DIR__"hhyuan-3");
                tell_object(me, HIR"你从瀑布中摔了出来，只觉得浑身无处不疼，还受了几处伤。\n"NOR);
                message("vision", HIR"只见" + me->query("name") + "从瀑布中摔了出来，躺在地上半天爬不起来！\n"NOR, environment(me), me);
        }

        add_action("do_open","open");
        add_action("do_study", ({"du", "study",}));
}

int do_open(string arg)
{
        object me = this_player();
        object ob;

       
    if (!arg || (arg != "he" && arg != "shi he"))
       {
        return notify_fail("你想打开什么？\n");
        return 1;
       }
    else
    {
    if (!present("tiezhang zhangpu",me))
       {
        write("你用力打开石盒，发现里面有一本落满尘土的书籍。你急忙把它捡起揣在怀中。\n");
        ob=new(__DIR__"obj/zhangpu");
        ob->move(me);
        return 1;
       }
        write("你用力打开石盒，发现里面空空的什么也没有。\n");
        return 1;
    }
}

int do_study(string arg)
{
        object me;
        int jing_cost;
        me = this_player();

        if ( !arg || ( arg != "table" ) )
                return notify_fail("你想读什么？\n");

        if ( (int)me->query_skill("guiyuan-tunafa", 1) < 1)
                return notify_fail("你试着理解石桌上的心法，可是没有归元吐纳法的基咄，无论怎么看也无法理解。\n");

        jing_cost = (-1) * random(20);
        if((int)me->query("jing") < jing_cost)
                return notify_fail("你现在精神无法集中！\n");
        if ( (int)me->query_skill("tiezhang-xinfa", 1) > 100)
                return notify_fail("你对着石桌琢磨了一回儿，发现上面所说的太过浅显，对你来说已毫无意义了。\n");
        
        me->improve_skill("tiezhang-xinfa", me->query("int"));
        write("你对着石桌琢磨了一回儿，似乎对铁掌心法有点心得。\n");
        message("vision",me->name() + "正专心研读石桌上的铁掌心法。\n", environment(me), ({me}));
        me->add("jing", jing_cost);
        return 1;
}


