#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
object obj,gift;
    object *team;
        int j,maxskill;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int k,a,b,c,d,e,f,temp;
	
int maxpot,maxexp,minexp;      
     int i=0,count=0;
maxexp=me->query("combat_exp");
team=me->query_team();
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
//for(i=100;i*i*i/10<=maxexp;i++);
//maxpot=i;

if(environment(me)->query("short")!=me->query_temp("tjob")
&& duration<17)
{
tell_object(me, HIY "\n奸细偷偷溜出了城，你任务失败！\n" NOR); 
me->delete_temp("tjob");
me->apply_condition("mptjob",0);
return 0;	
}
else     if (!duration)
{
message_vision(HIR"\n$N敌人的头领杀到了!!\n"NOR,me); 
	     obj=new("/quest/menpai/boss"); 
	maxskill=(int)me->query_skill("force",1)+20;
	if (!me->query("zhuanshen") && me->query("combat_exp",1) <=6000000) maxskill=maxskill*2/3;
	obj->initlvl(maxskill);
	
        obj->set("combat_exp",me->query("combat_exp",1));
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (!i) i=1;
        obj->set("qi",obj->query("max_qi")*i);
        obj->set("eff_qi",obj->query("max_qi")*i);
        obj->set("max_qi",obj->query("max_qi")*i);

        obj->set("jing",obj->query("max_jing")*i);
        obj->set("eff_jing",obj->query("max_jing")*i);
       obj->set("max_jing",obj->query("max_jing")*i);

        obj->set("neili",obj->query("max_neili")*i);
        obj->set("max_neili",obj->query("max_neili")*i);
        
   	     obj->set("title",HIR"敌派奸细"NOR);
  	     obj->move(environment(me));

	     message_vision(HIY"$N狂笑不已：就凭你们几个也想挡住我的去路?\n"NOR, obj);
	     obj->kill_ob(me);me->kill(this_object());
  	     me->delete_temp("tjob");
  	     gift=new("/quest/menpai/mijian2");
  	     gift->set_temp("host",me->query("id"));
  	     gift->set("okname",me->query("id"));
  	     
  	     gift->move(obj);
      return 0;
}
else  	 if( duration%3==0 && duration <17
		 &&!environment(me)->query("no_fight")
		 )
       {  me->start_busy(1);
          call_out("zuji", 0, me);    
     
	 }
if (!environment(me)->query("no_fight"))
{
        me->apply_condition("mptjob", duration - 1);
tell_object(me, RED "\n任务紧急，请快速细致！\n" NOR); 
}
        return 1;
}


void zuji(object me)
{   
    object *team,obj,gift;
int maxpot,maxexp,minexp;      
	int maxskill;

        int j;
	mapping npc,mp;
	mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;
	string sex;
	object ob, weapon;
	int k,a,b,c,d,e,f,temp;
     int i=0,count=0;
maxexp=me->query("combat_exp");
team=me->query_team();
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
//for(i=100;i*i*i/10<=maxexp;i++);
//maxpot=i;
        if (!me) return;
if (!me->query_temp("tjob")) return;

me->start_busy(2);
	maxskill=me->query_skill("force",1);
	//maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<150)
        maxskill=150;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;
        obj=new("/quest/menpai/kill");

	obj->move(environment(me));
if (!me->query("zhuanshen") && me->query("combat_exp",1) <=6000000) maxskill=maxskill*2/3;	
	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);
	
	message_vision(HIG"\n$N对着$n大叫一声，你们全去死吧，杀啊!。\n"NOR,obj,me); 
	obj->kill_ob(me);
	obj->set_leader(me);  

   if (random(10)>= 8 && me->query("combat_exp",1)>= 20000000 )
	{
       obj->set_temp("apply/defense", 200);
        obj->set_temp("apply/armor", 500);
        obj->set_temp("apply/damage", 200);
        obj->set_temp("apply/attack", 200);		
	}


}

string query_type(object me)
{
	return "job";
}


