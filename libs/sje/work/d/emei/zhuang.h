// zhuang.h

void init()
{
       add_action("do_jump", "jump");
       add_action("do_jump", "tiao");
}

int do_jump(string arg)
{
       object me;
       me = this_player();
       if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
        return notify_fail("你正忙着哪！\n");
       
       if( (int)me->query_skill("anying-fuxiang", 1) > 101)
        return notify_fail("这里已经不适合你练习轻功了。\n");

       if( !arg || arg!= "zhuang" || arg == "" )
       return notify_fail("什么?\n");

        if( arg =="zhuang" ) 
       {
               message_vision("$N在梅花桩上跳来跳去。\n", me);
               me->improve_skill("anying-fuxiang", (int)me->query_dex()*5);
               me->add("jingli", -15);
               return 1; 
       }
}




