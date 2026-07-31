// sleep.c

void wakeup(object,object);
void del_sleeped(object);
int main(object me, string arg)
{
    int rnd;
        object where = environment(me);
        
        seteuid(getuid());
        if (where->query("no_sleep_room")
        || ( ( me->query("family/family_name") != "丐帮") && (!(where->query("sleep_room")))) )
             return notify_fail("这里不是你能睡的地方！\n");

   
        if (me->is_busy())
                return notify_fail("你上一个动作未完成！\n");
        if( me->is_fighting() )
                return notify_fail("战斗中睡觉？挨宰呀？\n");
        
 
        if (me->query_temp("sleeped"))
                return notify_fail("你刚睡过一觉, 多睡对身体有害无益! \n");
        if (where->query("sleep_room"))
        {
                write("你往床上一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                message("vision",me->name()+"一歪身，倒在床上，不一会便鼾声大作，进入了梦乡。\n",environment(me),({me}));
          rnd=random(100/me->query_con()+3);
        }else{ 
                write("你往地下角落一躺，开始睡觉。\n");
                write("不一会儿，你就进入了梦乡。\n");
                message("vision",me->name()+"往地下角落屈身一躺，不一会便鼾声大作，做起梦来。\n",environment(me),({me}));
                rnd=random(100/me->query_con()+2);
        }
        where->add_temp("sleeping_person", 1);
        me->set("no_get", 1);   
        me->set("no_get_from", 1);      
        me->set_temp("block_msg/all", 1);

        me->set_temp("sleeped",1);
        me->disable_player("<睡梦中>");
        if ( rnd < 1 ) rnd = 0;
        call_out("wakeup", rnd + 10, me, where);
        
        return 1;
        
}
void wakeup(object me,object where)
{
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));
        me->enable_player();
    me->set_temp("block_msg/all",1);
    me->move(environment(me));
        me->delete_temp("block_msg");
        if ( userp(me) && (!me->query("food") || !me->query("water")) ){
                message("vision",me->name()+"一觉醒来，整个人懒洋洋的，没有半点精神。\n",environment(me),({me}));
                write("你一觉醒来，整个人懒洋洋的，没有半点精神。看来先要去找点吃的了！\n");
        }else{
        message("vision",me->name()+"一觉醒来，精力充沛地活动了一下筋骨。\n",environment(me),({me}));
        write("你一觉醒来，只觉精力充沛。该活动一下了。\n");
        me->set("qi",    me->query("eff_qi"));
        me->set("jing",  me->query("eff_jing"));
        }  
        call_out("del_sleeped", 5, me);
    if (where)
        where->add_temp("sleeping_person", -1);
        me->delete("no_get");   
        me->delete("no_get_from");      
 
}
void del_sleeped(object me)
{
        if (objectp(me) &&  me->query_temp("sleeped"))
                me->delete_temp("sleeped");
}

