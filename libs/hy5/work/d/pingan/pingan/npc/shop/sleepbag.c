// sleepbag.c

void wakeup(object,object);

inherit ITEM;

void create()
{
    set_name("睡袋", ({ "sleep bag","bag"}) );
        set_weight(1500);
        set_max_encumbrance(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
          set("unit", "只");
          set("long", "一个可以随时睡觉(sleephere)的睡袋。\n");
          set("value", 30000);
        }
}

int is_container()      {return 1;}

int init()
{
    add_action("do_sleephere", "sleephere");
}

int do_sleephere(object me, string arg)
{
        int rnd;
        object where;
        mapping fam;
        me = this_player();

        where = environment(me);
        
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");

        if( me->is_fighting() )
                return notify_fail("战斗中不能睡觉！\n");

        if (where->query("sleep_room")==1)
        {
                write("你往床上一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                me->set_temp("block_msg/all",1);
                message_vision("$N一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",me);
            rnd = random((60 - me->query_con()) / 3);
        }
//        if ( (where->query("no_fight")==1)||(where->query("no_sleep")==1)||(where->query("no_steal")==1))
//       {
//                return notify_fail("这里不能使用睡袋！\n");
//        }
        if (me->query("age") > 18) { 
                return notify_fail("你老大不小了还用睡袋，羞不羞！\n");
       }
        else { 
                write("你展开一个睡袋钻了进去，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                me->set_temp("block_msg/all",1);
                message_vision("$N展开一个睡袋钻了进去，不一会便鼾声大作，做起梦来。\n",me);
            rnd = 10 + random((100 - me->query_con()) / 3);
        }
        where->set("no_fight", 1);
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        me->set_temp("sleepbag", 1);
        if (!(where->query("hotel"))) 
                me->set_temp("sleeped",1);
        else
                me->delete_temp("rent_paid");

        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        
        return 1;
}

void wakeup(object me,object where)
{
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        me->add("neili", me->query("max_neili")/2 - me->query("neili")/2 );
        me->enable_player();
  
        message_vision("$N一觉醒来，精力充沛地活动了一下筋骨。\n",me);
        me->set_temp("block_msg/all", 0);
        write("你一觉醒来，只觉精力充沛。该活动一下了。\n");

        if (!where->query("sleep_room") && !where->query("hotel"))
                where->delete("no_fight");
     
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");
        me->set_temp("sleepbag", 0);      

}


