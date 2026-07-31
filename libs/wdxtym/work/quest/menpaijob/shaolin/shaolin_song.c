#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
     if (!duration) return 0;
  	 if( duration%2==0 
		 //&& 
		 //interactive(me) 
		 &&!environment(me)->query("no_fight")
		 && !me->is_fighting())
       {  me->start_busy(2);
          call_out("zuji", 0, me);    
     
	 }
        me->apply_condition("shaolin_song", duration - 1);
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
   	if(random(10)>6)
	{obj=new("/quest/menpaijob/huashan/xixia"+sprintf("%d",random(3)+1));
	 maxpot=maxpot+10+random(10);
         obj->set("combat_exp",maxexp);
        obj->set_skill("kuang-jian",maxskill);
        obj->set_skill("sword",maxskill);
        obj->set_skill("parry",maxskill);        
	 obj->set("title",HIR"Ð°ÅÉµÜ×Ó"NOR);
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
	obj->set("title",HIR"Ð°ÅÉµÜ×Ó"NOR);
	message_vision(HIR"\n$N¶Ô×Å$n´ó½ÐÒ»Éù£¬É±°¡!¡£\n"NOR,obj,me); 
	obj->kill_ob(me);
}

string query_type(object me)
{
	return "job";
}
