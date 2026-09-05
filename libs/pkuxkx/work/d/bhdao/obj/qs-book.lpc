//test 7
//test 6
//test 5
//test 3
//test 2
//test
// by advent

#include <ansi.h>

inherit ITEM;

int to_zuanyan(string);
void create()
{
        set_name(HIW"七伤拳谱"NOR, ({ "book" }));
     set_weight(9000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "这是一本刀剑所刻的石书，笔画深陷\n"
                        "书写者无疑是个内功高手。\n");
                set("value", 1);
                set("no_get", 1);
                set("material", "stone");
                        
        }
}

void init()
{

 add_action("to_zuanyan","zuanyan");
}                           

int to_zuanyan(string arg)
{       object me;
        string book;
        int times,realtimes,max_level;
        
        me = this_player();

        if(!arg || (sscanf(arg, "%s %d",book,times) < 1 ) || book != "book")
             return notify_fail("指令格式：zuanyan book [次数]\n");
        if (times<1) return notify_fail("你至少要读一次！\n");


        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("你是个文盲，先学点文化(literate)吧。\n");
        if ( (int)me->query_skill("force", 1) < 500)
                return notify_fail("你的基本内功修为不够，不能学七伤拳。\n");

        if ( me->query_skill("qishang-quan",1) > 400)
                  if ( random((int)me->query_skill("qishang-quan", 1)*(int)me->query_skill("qishang-quan", 1)/100) > (235 + me->query("kar") + me->query("int")))
                {
                        tell_object(me,"你正读着七伤拳谱，突然感觉经脉运行不顺。\n");
                        me->add_temp("crazy",1);
                        if( (int)me->query_temp("crazy") > random(20) )
                        {
                                tell_object(me,HIR "你读得太快太急，七伤拳的负作用终于发作了！\n" NOR);
                                me->set("attitude","aggressive");
                                me->delete_temp("crazy");
								F_POISON->poison_attack(this_object(),me,"qishang", 900);
                                me->unconcious();
                        }
                        return 1;
                }       

        if ((int)me->query("jing")< 150)
          {
                 tell_object(me,"你已经很累了，歇歇再读吧,身体要紧.\n");
                 return 1;
          }
        message_vision("$N正专心研读拳谱。\n", me);
        realtimes = times;
         if ((me->query("jing")-100)/100 < times)
        {
                realtimes = me->query("jing")/100-1;
        }
        me->add("jing",-100*realtimes);
                max_level = (me->query("kar") + me->query("int") + me->query("spi") + 31)*10 / 2;
        if ( (int)me->query_skill("qishang-quan", 1) < max_level)
        {
                me->improve_skill("qishang-quan", me->query("int")*realtimes/2 ); //原来代码中为random(2)，这里/2代替
                write("你心中默念书中字句，对七伤拳有了更深一层的了解。\n");
        }
        else    write("你只觉气血翻涌，不能静下心来领悟拳谱要义。\n");
        if (realtimes < times)
                write("你已经很累了，歇歇再读吧,身体要紧.\n");
        return 1;
}



