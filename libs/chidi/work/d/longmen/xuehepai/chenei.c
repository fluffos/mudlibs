#include <room.h>
inherit ROOM;

void create ()
{
        set ("short", "血河车内");
        set ("long", @LONG
忽然八马齐嘶，犹如神兵天降，血光大现，怒鼓金兵，翻涌而近血河
车。可以感觉到血车之中，有一股逼人的恐怖，一股逼人的阴寒之气，普
通人根本受不了。而血车外的鲜红色镂雕，映在雪地上，更有一种吞人的
气势车外血光隐动，车内黜暗一片，借着依稀的光亮，你发现车壁上似乎
有字(zi)。
LONG);
        set("item_desc", ([ /* sizeof() == 1 */
                "zi" : "这是千百年来血河派武学的精华，你不由一阵狂喜，赶忙凝神静气开始苦思(think)起来.\n",        
        ]));
  
        setup();
}

void init()
{
        add_action("do_study", "think");
        add_action("do_jump", "tiao");
}

int do_study(string arg)
{   
        object me=this_player();
        int jing_cost, qi_cost;
        if( !arg || (arg != "zi"))
                return notify_fail("你要学什么？\n");
        if( me->is_busy() )
                return notify_fail("你忙的很，哪有功夫去学习！\n");
        if( me->is_fighting() )
                return notify_fail("现学现卖已来不及了！\n");
        if( (int)me->query_skill("literate", 1) < 1000)
                return notify_fail("你看了半天也看不懂上面刻的是什么！\n");
        if( (int)me->query_skill("yiqiguan-riyue", 1) < 300)
                return notify_fail("你的内功心法还太低，不能钻研上面的武学！\n");
        if( (int)me->query_skill("taoism", 1) < 500)
                return notify_fail("你的道学心得还太低，不能钻研上面的武学！\n");
        if( ((int)me->query_skill("yiqiguan-riyue", 1) >= 1200) && (me->query_skill("taoism",1)>=2000))
                return notify_fail("你定睛看了会，你已经全部领悟到了。\n");
   
        jing_cost = 600 / (int)me->query_int(); 
//        jing_cost = 80 - (int)me->query_int();
        if( (int)me->query("jing") < jing_cost )
                return notify_fail("你现在头晕脑胀，该休息休息了。\n");

        qi_cost = 500 / (int)me->query_int();
//        qi_cost = 80 - (int)me->query_con();
        if( (int)me->query("qi") < qi_cost )
                return notify_fail("你现在浑身无力，该休息休息了。\n");

   
        me->receive_damage("jing", jing_cost);
        me->receive_damage("qi", qi_cost);
   
        if( (int)me->query_skill("yiqiguan-riyue", 1) < 1200)
                me->improve_skill("yiqiguan-riyue", 500);
        if ((random(10)<3) && (me->query_skill("taoism",1)<2000)) {
                me->improve_skill("taoism",5000);
        write("你的道学心得进步了！\n");
        }

        write("你冥思苦想，完全陶醉于车上的无上武学之中，你的一气贯日月进步了。\n");

        tell_room( environment(me), me->name() + "双手挥来挥去，不知在比划什么。\n", ({me}));

        return 1;
}

int do_jump(string arg)
{
        object me;
        object *obb;
        int i;

        me=this_player();
        if (!arg || arg!="out")
                return notify_fail("你要跳到哪里去？\n");
        message_vision("只见$N跳了出去！\n",me);
        obb=users();
        for(i=0; i<sizeof(obb); i++) {
        if (obb[i]->query_temp("xueheche"))
        {
                me->move(environment(obb[i]));
                message_vision("只见$N从血河车上跳了下来！\n",me);
                return 1;
        }
        }
        me->move("/d/longmen/xuehepai/xueheting");
        message_vision("只见$N从血河车上跳了下来！\n",me);
        return 1;
}

