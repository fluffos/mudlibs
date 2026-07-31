#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
		tell_object(me, HIY "你的巡山任务的时间结束了。\n" NOR);
                return 0;
	}
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
         {
          me->start_busy(1);
          call_out("zuji", 0, me);    
     
	 }
        me->apply_condition("huaxunshan", duration - 1);
        return 1;
}


void zuji(object me)
{   
	object obj; 
	int maxpot;
	int maxexp;
	int maxskill;
	maxskill=me->query_skill("force");
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp");
   	if(random(10)>7)
	{obj=new("/quest/menpaijob/huashan/xixia"+sprintf("%d",random(3)+1));
	 maxpot=maxpot+10+random(10);
         obj->set("combat_exp",maxexp);
        obj->set_skill("kuang-jian",maxskill);
        obj->set_skill("sword",maxskill);
        obj->set_skill("parry",maxskill);        
	 obj->set("title",HIR"华山剑宗大弟子"NOR);
	}
	else
	{
	 obj=new("/quest/menpaijob/huashan/xixia1");
        obj->set_skill("kuang-jian",maxskill);
        obj->set_skill("sword",maxskill);
        obj->set_skill("parry",maxskill);        
         obj->set("combat_exp",maxexp);
	  maxpot=maxpot-random(10);
	 }
	obj->do_copy(maxpot);
	obj->move(environment(me));
	obj->set("title",HIR"华山剑宗弟子"NOR);
	message_vision(HIR"\n$N对着$n大叫一声，杀啊!。\n"NOR,obj,me); 
	obj->kill_ob(me);
}

string query_type(object me)
{
	return "job";
}
