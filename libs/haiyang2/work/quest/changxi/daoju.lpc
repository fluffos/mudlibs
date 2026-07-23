//daoju.c 唱戏用的道具
//海洋II（云起云落）
//星星lywin 2000/6/20

#include <ansi.h>
inherit ITEM;

void init()
{
	add_action("do_changxi", "changxi");
}

void create()
{
	set_name("唱戏道具", ({"changxi daoju", "daoju"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("no_drop","不要乱丢，要赔的！\n");
		set("no_put",1);
		set("long", "这是一套唱戏用的道具，你可以用它来唱戏（changxi）。\n");
		set("value", 0);
	}
	setup();
}

int do_changxi(string arg)
{
        object me=this_player();

    if (me->is_fighting()) 
        {
          tell_object(me,"你正打的热闹着呢!\n");
          return 1;
        }
    if(me->is_busy())
        {
          tell_object(me,"你正忙着呢!\n");
          return 1;
        }

        if (me->query_temp("obj/done") >= 1)
        {
          tell_object(me,"你已唱完戏了，回去报告吧。\n");
          return 1;
        }
        else
        if (me->query_temp("obj/changxi") < 1)
        {
          tell_object(me,"现在好像不该你唱戏吧？\n");
          return 1;
        }
        else
        if (!environment(me)->query("outdoors"))
        {
          tell_object(me,"你不该在这儿唱戏吧？\n");
          return 1;
        }
        else
        if (me->query_temp("obj/where") != environment(me)->query("outdoors"))
        {
          tell_object(me,"你不该在这儿唱戏吧？\n");
          return 1;
        }
        else
        if (environment(me)->query_temp("changxi") >= 1)
        {
          tell_object(me,"这儿不久前有人来唱过戏，现在再唱只怕没人会听了\n");
          return 1;
        }
        else          
        if ((me->query("jing") < 20))
        {  
          tell_object(me,"你的精力不能集中，不可以表演！\n");
          return 1;
        }
        else
        if ((me->query("qi") < 30 ))
        {
          tell_object(me,"你的身体状态太差，不能表演！\n");
          return 1;
        }
        else          
	if (environment(me)->query_temp("changxi") >= 1)
        {
        tell_object(me,"刚刚才有人来这儿唱过戏了，人们都不想再看戏。\n"NOR,me);
       	return 1;
      	}
      	else
        if (!arg || arg == "" )
        { 
          tell_object(me,"你要进行哪种表演？
          唱曲（changqu），碎砖（suizhuan），走绳索（zhou）？\n");
          return 1;
        }
        else
        if ( arg == "changqu" )
        {
          if ((me->query("neili") < 30))
            return notify_fail("唱曲讲究的是内息悠长，你的内力不足，唱不出好曲。\n");
           
          message_vision(HIW"$N清了清噪子，悠悠的唱起曲儿来。\n"NOR,me);          
          me->start_busy(8); 
          call_out("changqu",8,me);
          return 1;
       	}
       	else
        if ( arg == "suizhuan" )
        {
          if ((me->query_skill("unarmed") < 30))
            return notify_fail("你的拳脚功夫不足，哪里打得动大石？\n");
            
          message_vision(HIW"$N运功于臂，用力向一块砖头劈去。\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("changqu",8,me);
       	  return 1;
       	}
       	else
        if ( arg == "zhou" )
        {
          if ((me->query_skill("dodge") < 30))
            return notify_fail("以你这样的轻功也想去走绳？怕不一下子就掉了下来。\n");

          message_vision(HIW"$N跳上了一根横挂的绳索，从这头向那头走去。\n"NOR,me);          
          me->start_busy(8); 
       	  call_out("changqu",8,me);
       	  return 1;
       	}
}

int changqu(object me)
{
        message_vision(HIY"$N一曲唱毕，旁边的人鼓起了掌。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1);        
        return 1;
}

int suizhuan(object me)
{
        message_vision(HIY"$N只见好大的块砖头应声而碎，旁人看得张大口说不出话来。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
} 

int zhou(object me)
{
        message_vision(HIY"$N从绳索上轻轻的走了过去，晃也没晃一下，旁人都看得目瞪口呆。\n"NOR,me);
        me->set_temp("obj/done",1);
        environment(me)->set_temp("changxi",1); 
        return 1;
}          