int valid_leave(object me, string dir)
{
object fang;



	if ( objectp(present("qi wushi", environment(me))) )
		return notify_fail("棋武士拦住了你的去路。\n");




        if ((int)me->query_temp("marks/steps") == -10 && (int)me->query_temp("marks/step") == 16)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个玲珑棋局。\n");
         }  

        if ((int)me->query_temp("marks/steps") == -11 && (int)me->query_temp("marks/step") == 17)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个玲珑棋局。\n");
         }  

        if ((int)me->query_temp("marks/steps") == 10 && (int)me->query_temp("marks/step") == -16)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个玲珑棋局。\n");
         }  

        if ((int)me->query_temp("marks/steps") == 11 && (int)me->query_temp("marks/step") == -17)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个玲珑棋局。\n");
         }  


        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") <= -99)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个玲珑棋局。\n");
         } 
         
         


        if ((int)me->query_temp("marks/steps") >= 99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个玲珑棋局。\n");
         }          


        if ((int)me->query_temp("marks/steps") <= -99 && (int)me->query_temp("marks/step") >= 99)
         {
            me->move(__DIR__"fangjian1");
            me->delete_temp("marks/steps");
            me->delete_temp("marks/step");
            me->set_temp("qijuok",1);
             return notify_fail("你正在绝望时,走着走着，破了这个玲珑棋局。\n");
         }   

if (userp(me) && random(5)==0)
{
     	fang = load_object(__DIR__"npc/qiwushi");
	fang->move(environment(me));	
	fang->kill_ob(me);
		return notify_fail("突然出现一个棋武士拦住了你的去路。\n");	
	
}
 if ( (int)me->query_temp("marks/steps")> 11 )
 tell_object(me, "看来你向南走的超出范围了。\n");
 
 if ( (int)me->query_temp("marks/steps")< -11 )
 tell_object(me, "看来你向北走的超出范围了。\n");
                  
 if ((int)me->query_temp("marks/step")>17 )
 tell_object(me, "看来你向东走的超出范围了。\n");

 if ((int)me->query_temp("marks/step")<-17 )
 tell_object(me, "看来你向西走的超出范围了。\n");

 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "看来你向东走太多了。\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "看来你向西走太多了。\n");

 if ( (int)me->query_temp("marks/steps")> 0 && (int)me->query_temp("marks/step")>0 )
 tell_object(me, "看来你向南走太多了。\n");

if ( (int)me->query_temp("marks/steps")< 0 && (int)me->query_temp("marks/step")<0 )
 tell_object(me, "看来你向北走太多了。\n"); 



 
 //tell_object(me, "w" + me->query_temp("marks/step") + "。\n");
 //tell_object(me, "s" + me->query_temp("marks/steps") + "。\n");

                   if (dir == "west")
         me->add_temp("marks/step",1);

        if (dir == "south")
          me->add_temp("marks/steps",1);
        if (dir == "east")
          me->add_temp("marks/step",-1); 
        if (dir == "north")
          me->add_temp("marks/steps",-1);
        return ::valid_leave(me, dir);
}

