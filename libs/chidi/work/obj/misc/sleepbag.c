// sleepbag.c

void wakeup(object,object,int);

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
          set("no_get", 1);
          set("no_put", 1);
          set("no_drop", "乱丢会污染环境的!^!^\n");
          set("no_sell",1);
          set("value", 5000);
        }
}

int is_container()      {return 1;}

int init()
{
    add_action("do_sleep", "sleep");
}

int do_sleep()
{

        mapping fam;
        object me,ob,where;
        int ttt,fight_room=1;
        me=this_player();
        ob=this_object();
        where = environment(me);
        
        if( environment(ob)!=me)
                return 0;
        
        if (me->is_busy())
                return notify_fail("你正忙着呢！\n");

        if( me->is_fighting() )
                return notify_fail("你找死啊！\n");
        
        if (me->query_temp("sleeped"))
                return notify_fail("别睡啦！多睡对身体有害无益! \n");

        if (where->query("sleep_room"))
        {
                write("你迷迷糊糊打了个盹，不觉睡着了。\n");
                write("不一会儿，你就进入了梦乡。\n");
                me->set_temp("block_msg/all",1);
                message_vision("$N打了个哈欠，头一歪就进入了梦乡。\n",me);
        }
        else { 
                write("你往地下角落一躺，开始睡觉。\n");
                me->set_temp("block_msg/all",1);
                message_vision("$N头一歪，不一会便鼾声大作，做起梦来。\n",me);
        }

        
        if(!where->query("no_fight"))
        {
                fight_room=0;
                where->set("no_fight",1);
        }
                        
        where->add_temp("sleeping_person", 1);

        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        
        if (!(where->query("hotel"))) 
                me->set_temp("sleeped",1);
        else
                me->delete_temp("rent_paid");

        me->disable_player("<睡梦中>");
        ttt= me->query_con() ;
        if(ttt>40) ttt=40 ;
        call_out("wakeup",random(45 - me->query("con")) + 15, me, where);
//      call_out("wakeup",random(50 - ttt) , me, where);        
        return 1;
        
}

void wakeup(object me,object where,int fight_room)

{

        me->set("kee",  me->query("eff_kee"));
        me->set("gin",  me->query("eff_gin"));
        me->set("sen",me->query("eff_sen"));
        if(me->query("force")<me->query("max_force")/2)
        me->add("force", me->query("max_force")/2 - me->query("force")/2 );
        me->enable_player();
  
        call_out("del_sleeped", random(30), me);

        message_vision("$N一觉醒来，也不知睡了多久。\n",me);
        me->set_temp("block_msg/all", 0);
        write("你一觉醒来，感觉好多了。\n");

        if (!where->query("sleep_room") && !where->query("hotel")&&!fight_room)
                where->delete("no_fight");
     
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      
 
}

void del_sleeped(object me)
{
        if (objectp(me) &&  me->query_temp("sleeped"))
                me->delete_temp("sleeped");
}

