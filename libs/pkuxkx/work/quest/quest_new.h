#include <ansi.h>


int time_period(int timep, object me,object obj);
int give_quest();
int report_quest();
int dest(object ob);

void init()
{
        add_action("give_quest", "quest");
        add_action("report_quest","report");
} 
int report_quest()
{
	mapping quest;
	object me,obj;
	int quest_lianxu,reward,score,num_online; 
	object *players_online = users(); 
	num_online = sizeof(players_online);
        me = this_player(); 	
	obj = this_object();
	if(me->query("family/family_name")!=obj->query("family/family_name"))
          {
          	command("? "+me->query("id"));
           	command("say "+RANK_D->query_respect(me)+"与本派素无来往，此话从何说起？");
           	return 1; 
           }  
        if((quest =  me->query("quest")))
        {                                   
        if( me->query_temp("quest_finish"))
           if (((int) me->query("task_time")) > time() )
            {tell_object(me,obj->query("name")+"说道：恭喜你！你又完成了一项任务！\n");
             score=1+random(3);
             tell_object(me,"你对"+me->query("family/family_name")+"的忠诚度提高了"+chinese_number(score)+"点。\n");     
             if(!me->query("score"))
               me->set("score",0);
             if(!me->query("quest_lianxu"))
               me->set("quest_lianxu",0);
             if(me->query("quest_lianxu") >= 7)
               me->set("quest_lianxu",7);
             quest_lianxu = me->query("quest_lianxu");  
             me->set("quest_lianxu",++quest_lianxu);
             reward = quest_lianxu*(int) me->query("quest/score")*(num_online/10+2);  
             me->add("score",score);  
             reward = reward+random(reward/2);
             me->add("combat_exp",reward);
             me->add("potential",reward/10);
             if((int)me->query("potential") - (int)me->query("learned_points") >= 600)
               me->add("potential",(600-(int) me->query("potential")+(int)me->query("learned_points")));
             me->delete("quest");
             me->delete("task_time");
             me->delete_temp("quest_finish"); 
             tell_object(me,"你的经验增加了"+chinese_number(reward)+"点。\n");     
             tell_object(me,"你的潜能增加了"+chinese_number(reward/10)+"点。\n");     
             return 1;
            }  
           else 
            {tell_object(me,obj->query("name")+"说道：真可惜！你没有在指定的时间内完成！\n");         
             me->delete("quest");
             me->delete("task_time");
             me->set("quest_lianxu",0);
             me->delete_temp("quest_finish");
             return 1;
            }   
     	if( ((int) me->query("task_time")) >  time() )
     	{
     		if(!quest) tell_object(me,"你没有任务可报告!\n"); 
	 	else tell_object(me,"你任务还没有完成,还不快去?\n");
	 	return 1;              
	}
	else {
                message_vision(obj->query("name")+"向$N叹了口气，说道：算了，看来我不应该让你去做这件事。\n", me);
        	tell_object(me,"你对"+me->query("family/family_name")+"的忠诚度降低了一点。\n");     
        	if(!me->query("score"))
                  me->set("score",0);
        	me->add("score",-1); 
        	me->set("quest_lianxu",0);
        	me->delete("quest");
        	me->delete("task_time");
        	return 1;
        	}
	}
	
}


int give_quest()
{
        mapping quest ;
        object me,obj,xin;
        int j,timep,num;
        int score,dork;
        int rnd = random(100);            
	string *levels = ({    
		        "0",
                        "10000",
                        "100000",
                        "200000",
			"5000000",
			"1000000",
			"3500000",
           });
        me = this_player(); 
        obj= this_object();
               
	if(me->query("family/family_name")!=obj->query("family/family_name"))
          {
          	command("? "+me->query("id"));
           	command("say "+RANK_D->query_respect(me)+"与本派素无来往，此话从何说起？");
           	return 1; 
           }         
           
        if( me->query("score") * me->query("score") >= 
                me->query("combat_exp") * 10 )
        {
                command("sigh " + me->query("id"));
                command("say " + RANK_D->query_respect(me) + 
                        "还是先练好武艺再为本派出力吧！\n");
                return 1;
        }
	if( ((int) (me->query("task_time")) > time() ))
           {
                    tell_object(me ,"你任务还没有完成,还不快去?\n"); 
            	    return 1; 
           } 
        if(me->query("quest"))
        {
        	tell_object(me ,"你已经请了任务,还来请?\n");
        	return 1;
        }     	   
        for(j= sizeof(levels)-1; j>=0; j--)
        {
                if( atoi(levels[j]) < (int)me->query("combat_exp") )
                        {
	                         num=j+1;
                                 break;
                        }
                num = 0;        
        }
        if (rnd >= 95 && num!=6) num++;
        else if (rnd >= 90 && num!=0 && num!=1) num--;
        else if (rnd >= 85) num = 0;
        do
        {
           quest = ((string)"/quest/new_quest/q"+num)->query_quest();
        }while(obj->query("name") == quest["quest"]);
	if(num == 0) num = 7;
        timep = quest["time"];
        tell_object(me ,HIW" "+obj->query("name")+"沉思了一会儿，说道：\n"); 
        if (!undefinedp(quest["reason"])) 
              tell_object(me ,HIW" "+quest["reason"]);
        if (!undefinedp(quest["shen"]))
        	dork = -1000*num;
        	else dork =quest["shen"];	      
        time_period(timep, me , obj);
        if (quest["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+quest["quest"]+"』给我。\n" NOR);
        }
        else if (quest["quest_type"] == "杀" && me->query("shen") >= dork)
        {
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
        }
	else if (quest["quest_type"] == "杀" && me->query("shen") < dork)
	{
	tell_object(me,"替我战胜『"+quest["quest"]+"』。\n" NOR); 
	quest["quest_type"] = "胜"; 
	}
	else if (quest["quest_type"] == "胜" && me->query("shen") < dork)
        {
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
        quest["quest_type"] = "杀";
	}
	else if (quest["quest_type"] == "胜" && me->query("shen") >= dork)
        {
        tell_object(me,"替我战胜『"+quest["quest"]+"』。\n" NOR);
        }		
        else if (quest["quest_type"] == "送")
        {
        tell_object(me,"把这封信送给『"+quest["quest"]+"』吧。\n" NOR);
        xin=new("/u/kuer/xin");
        xin->move(me);  
        } 
        me->set("quest", quest);
        me->set("task_time", (int) time()+(int) quest["time"]);
	return 1;
}

int time_period(int timep, object me,object obj)
{
        int t, d, h, m, s;
        string time;
        t = timep;
        s = t % 60;             t /= 60;
        m = t % 60;             t /= 60;
        h = t % 24;             t /= 24;
        d = t;

        if(d) time = chinese_number(d) + "天";
        else time = "";

        if(h) time += chinese_number(h) + "小时";
        if(m) time += chinese_number(m) + "分";
        time += chinese_number(s) + "秒";
  
        tell_object(me,HIW" "+"请在" + time + "内");

        return 1;
}
 int accept_object(object who, object ob)
{
        int score;
        string test;
        mapping quest;
        object obj=this_object();
        if(obj->query("family/family_name")!=who->query("family/family_name"))
          {
          	command("? "+who->query("id"));
           	command("say "+RANK_D->query_respect(who)+"的厚意我心领了,不过东西我是不能要.\n");
           	return 1; 
           }  
   
        if( ob->is_character())
        {
        tell_object(who,obj->query("name")+"说道：这不是我想要的。\n");
        return 0;
        }
        if(userp(ob) || !(quest =  who->query("quest")))
        {
        tell_object(who,obj->query("name")+"说道：这不是我想要的。\n");
        return 0;
        }
        if( ob->name(1) != quest["quest"])
        {
        tell_object(who,obj->query("name")+"说道：这不是我想要的。\n");
        return 0;
	}
	who->start_busy(2);
	who->set_temp("quest_finish",1);
	remove_call_out("report_quest");
	remove_call_out("dest");
	call_out("report_quest",0);
	call_out("dest",0,ob);
	return 1;
}

int dest(object ob)
{
destruct(ob);
return 1;
}