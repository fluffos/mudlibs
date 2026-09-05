#include <ansi.h>


int time_period(int timep, object me,object obj);
int give_quest();
int dest(object ob);

/*
void init()
{
        add_action("give_quest", "quest");
} 
*/


int give_quest()
{
        mapping quest ;
        object me,obj;
        int j, combatexp, timep,num;
        string tag = "1000000";
        string pai ; 
        int score;
        string *menpai = ({
              "峨嵋派",
              "少林派",
              "武当派",
              "丐帮",
              "华山派",	
              "明教",
              "星宿派", 
              "桃花岛",
              "全真派",
              "白驼山",
"天龙寺",
"古墓派",
"日月神教",
             });
        string *dirfile = ({
              "emei",
              "shaolin",
              "wudang",
              "gaibang",
              "huashan",
	      "mingjiao",
              "xingxiu",
              "taohua",
              "quanzhen",
              "baituo",
"dali",
"gumu",
"riyuejiao",
              });
              
	string *levels = ({    
		        "0",
                        "5000",
                        "50000",
			"500000",
           });
        me = this_player(); 
        obj= this_object();
               
if(me->query("family/family_name")!=obj->query("family/family_name"))
          {command("? "+me->query("id"));
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

       	if((quest =  me->query("quest")))
        {                                   
        if( me->query_temp("quest_finish"))
           if (((int) me->query("task_time")) > time() )
            {tell_object(me,obj->query("name")+"说道：恭喜你！你又完成了一项任务！\n");
             score=quest["score"]+random(quest["score"]);
             tell_object(me,"你对"+me->query("family/family_name")+"的忠诚度提高了"+chinese_number(score)+"点。\n");     
             if(!me->query("score"))
               me->set("score",0);
             me->add("score",score);  
             me->delete("quest");
             me->delete_temp("quest_finish"); 
             return 1;
            }  
           else 
            {tell_object(me,obj->query("name")+"说道：真可惜！你没有在指定的时间内完成！\n");         
             me->delete("quest");
             me->delete_temp("quest_finish");
             return 1;
            }   
     	if( ((int) me->query("task_time")) >  time() )
               return 0;              
	else {
                message_vision(obj->query("name")+"向$N叹了口气，说道：算了，看来我不应该让你去做这件事。\n", me);
                score=1+random(quest["score"]/2); 
        tell_object(me,"你对"+me->query("family/family_name")+"的忠诚度降低了"+chinese_number(score)+"点。\n");     
        if(!me->query("score"))
               me->set("score",0);
        me->add("score",-score); 
        }
        }
        if( ((int) me->query("task_time")) > time() )
           {
            message_vision(obj->query("name")+"向$N挥了挥手，说道：暂时没有什么事要做了，你先下去吧。\n", me);  
            return 1; 
           }      
        combatexp = (int) me->query("combat_exp");
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
                if( atoi(levels[j])  <= combatexp )
                        {
	                         num=j;
                                 break;
                        }
        }
        pai=me->query("family/family_name");
        for(j= 0;j<sizeof(menpai);j++)
        {
             if(pai == menpai[j])
                  break;
        }    
        pai=dirfile[j];  
        tag=levels[num];
	quest = ((string)"/quest/"+pai+"/qlist"+num)->query_quest();
        timep = quest["time"];
        time_period(timep, me,obj);
        if (quest["quest_type"] == "寻")
        {
        tell_object(me,"找回『"+quest["quest"]+"』给我。\n" NOR);
        }
                if (quest["quest_type"] == "杀")
        {
        tell_object(me,"替我杀了『"+quest["quest"]+"』。\n" NOR);
        }
        quest["score"]=quest["score"];

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

        tell_object(me,HIW" "+obj->query("name")+"沉思了一会儿，说道：\n请在" + time + "内");
        return 1;
}
 int accept_object(object who, object ob)
{
        int score;
        string test;
        mapping quest;
        object obj=this_object();
   
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
remove_call_out("dest");
call_out("dest",1,ob);
        if ((int) who->query("task_time") < time() )
        {
        tell_object(who,obj->query("name")+"说道：真可惜！你没有在指定的时间内完成！\n");
         
        who->delete("quest");
                        return 1;
        }
        else
        {
        tell_object(who,obj->query("name")+"说道：恭喜你！你又完成了一项任务！\n");
        score=quest["score"]+random(quest["score"]);
        tell_object(who,"你对"+who->query("family/family_name")+"的忠诚度提高了"+chinese_number(score)+"点。\n");     
        if(!who->query("score"))
               who->set("score",0);
        who->add("score",score);  
        who->delete("quest");
        return 1;
        }
}

int dest(object ob)
{
destruct(ob);
return 1;
}

