void init()
{
   call_out("destroying", 30, this_object());  
   add_action("do_eat", "eat");      
}

void destroying(object me)
{
   if(environment(me)->query("name") != "药篓"){
       message_vision("$N突然跌落在地上不见了。\n", me);       
       destruct(me);
       return;
       }
   else call_out("destroying", 30, this_object());
}

int do_eat(string arg)
{
        object me=this_player();

        if (!id(arg)) return notify_fail("你想吃什么？\n");

        if((int)me->query_condition("medicine") > 0){
            me->add("qi", -10);
            me->add("neili", 10);
            message_vision(HIR "$N吃下一株$n，只觉得头重脚轻，摇摇欲倒，原来服食太急太多，药效适得其反！\n"NOR, me, this_object());
            } 
        else{
            me->add("qi", 10);
            message_vision("$N吃下一株$n，只觉得浑身热气腾腾，身体变的好多了！\n", me, this_object());
            me->apply_condition("medicine", 10);
            }
        destruct(this_object());
        return 1;
}
