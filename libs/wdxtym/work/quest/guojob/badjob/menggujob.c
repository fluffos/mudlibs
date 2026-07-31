#include <ansi.h>

mixed names = ({
        ({
        "朱雀外门","青龙外门","白虎外门","玄武外门",
        }),
        ({
         "宋兵","流氓","偏将","佐将","小贩","男孩","郭芙","老先生",
         "小孩","书店老板","武三通","穷汉","铁匠","朱子柳","店小二","宋兵",
	 "樊一翁","郭芙","郭襄","简捷","史伯威","史季强","史孟捷","史叔刚",
	 "史仲猛","武敦儒","武修文","耶律齐","程英",
        }),
        });

string ask_job()
{ 
  object  ob, me,newob;
  int exp,position;
  string target,myfam,obfam,job_type;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if (interactive(ob) && ob->query_temp("menggu_job_target")
      && (int)ob->query_condition("menggu_mission"))  
       return "你上一次的任务还没完成!";
  if (interactive(ob) && !ob->query_temp("menggu_job_target")
      && (int)ob->query_condition("menggu_mission"))  
       return "你办事不力，先等会吧。";
   
    if (interactive(ob) &&
       (int)ob->query_condition("menggu_busy"))  
       return "现在我可没有给你的任务，等会再来吧。\n";

if (ob->query_skill("force",1)<100)
       return "我看你的武功还不够啊。\n";

if (ob->query("shen")>0)
       return "我看你到像是一个奸细。\n";
	
	if(exp<=100000)     
    return "你的武功太差了,等练强了再来吧。\n";
    job_type="刺杀";
   	ob->set_temp("menggu_job_type",job_type);
        
	if(job_type=="刺杀")
	{target = names[1][random(sizeof(names[1]))];
        ob->apply_condition("menggu_mission",30);    
	ob->set_temp("menggu_job_target", target);
	ob->set_temp("mgjob", 1);
        newob = new(__DIR__"ling");
        newob->set("long", "
        刺杀令
" + target + "必死。
        大元\n");
        newob->move(ob);

    message_vision(HIW"$N，对$n说道:有消息又有武林人士来增援襄阳,他好像要到"+target+"，这里，你把他和"+target+"一起干掉!\n"NOR , me,ob);
     if( (string)this_player()->query("family/family_name")=="神龙教" ) 
{     
        newob = new(__DIR__"item1");
        newob->move(ob);
    message_vision(HIW"$N，对$n说道：听说神龙教对用石灰对敌有心德，这包石灰粉就给你了!\n"NOR , me,ob);
}
     if( (string)this_player()->query("family/family_name")=="星宿派" ) 
{     
        newob = new(__DIR__"item2");
        newob->move(ob);
    message_vision(HIW"$N，对$n说道：听说星宿派对用蒙汗药对敌有心德，这包蒙汗药就给你了!\n"NOR , me,ob);
}
     if( (string)this_player()->query("family/family_name")=="雪山寺" ) 
{     
        newob = new(__DIR__"item3");
        newob->move(ob);
    message_vision(HIW"$N，对$n说道：听说雪山寺对用阴阳和合散对敌有心德，这包阴阳和合散就给你了!\n"NOR , me,ob);
}

	return "如果失败了，我要你的命!";
	}
}


string ask_fangqi()
{
         object me;
         me = this_player();
         if(me->query_condition("menggu_mission")<=1)
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->clear_condition("menggu_mission");
me->apply_condition("menggu_busy",8);    
destruct(present("hehe san",me));
destruct(present("meng hanyao",me));
destruct(present("shi huifeng",me));
me->clear_condition("menggu_mission");
me->delete_temp("menggu_job_target");
me->delete_temp("menggu_job_type");
me->delete_temp("mgjob");
		 me->delete_temp("menggu_job_type");
         return "下次不允许失败!! 。";
}

int accept_object(object who, object ob,object me)
{
        if ( ob->query("id") != "corpse") {
                command("say 你给我这个干吗?");
                return 0;
        }
        if ( !who->query_temp("menggu_job_target") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }

        if( who->query_temp("mgjob")!=3){
                command("say 你没有把武林侠士干掉还来要赏?");
                return 0;
        }

        if( who->query_temp("menggu_job_type")=="保护")
		if (ob->query_temp("must_killby")!= who->query("id")
			||ob->query("victim_user") )
		{       command("shake");
                command("say 你杀错人了。");
                return 0;
        } 
command("say 做的好!!为我们大汉立了大功。");
who->add("combat_exp",220+random(100));
who->add("shen",-50);
who->add("potential",150+random(100));
who->clear_condition("menggu_mission");
who->delete_temp("menggu_job_target");
who->delete_temp("menggu_job_type");
who->delete_temp("mgjob");
destruct(present("hehe san",who));
destruct(present("meng hanyao",who));
destruct(present("shi huifeng",who));
call_out("destroying", 1, ob);
        return 1;
}



void destroying(object ob)
{
        destruct(ob);
        return;
}