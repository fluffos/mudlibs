#include "where.h"


string ask_job()
{
  object  ob, me,gift,*team,obj;
  int exp,position,i;
  mapping target;
  string str;
  ob=this_player();
  me=this_object();
  exp=ob->query("combat_exp");
  if (interactive(ob) && (int)ob->query_condition("huang_mission"))
       return "你上一次的任务还没完成!";
  if (interactive(ob) && (int)ob->query_condition("huang_busy"))
       return "现在我可没有给你的任务，等会再来吧。\n";
  if (interactive(ob) && (int)ob->query_condition("guojob2_busy"))
       return "现在我可没有给你的任务，等会再来吧。\n";
       if ((int)ob->query_condition("gf_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("feitian2_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("gf_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("gumu_job"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("hu_song"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("huang_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("huaxunshan"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("husong_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("hxsd_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("lingjiu_song"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("lingxiao2_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("ljjob2"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("lyjob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("lyjob2"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("menggu_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("mingjiaojob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("mr_job"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("nonamejob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("quanzhenjob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("riyue_guard"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("riyuejob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("roomjob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("ry2_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("shaolin_song"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("taohuajob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("tz_job"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("wdj2_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("xsjob2"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("xsjob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("xh_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("wudangjob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("bt2_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("dali_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("emeijob"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("menpai_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("yl2_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("zzz_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";
       if ((int)ob->query_condition("yue_busy"))
       return "我看"+ob->query("name")+"需要休息一会！\n";


	if(exp<=100000)
    return "你的武功太差了,等练强了再来吧。\n";

	target = wheres[random(sizeof(wheres))];
    for(i=100;i*i*i/10<=exp;i++);//i=maxpot
	//obj=new(__DIR__"killer1");
	if(random(10)>7)
	{obj=new(__DIR__"skiller"+sprintf("%d",random(3)+1));
	 i=i+10+random(10);
	 obj->do_copy(ob,i);
	 obj->set("title",HIR"江南一霸"NOR);
	 ob->set_temp("huang_job_super",1);
	}
	else
	{ obj=new(__DIR__"killer");
	  i=i-random(10);
	  obj->do_copy(ob,i);
	}
	obj->move(target["weizhi"]);
	obj->set_temp("must_killby",ob->query("id"));
    ob->set_temp("huang_job_target", target["chinese"]);//where
    ob->apply_condition("huang_mission",10);
    ob->apply_condition("menpai_busy",5);
    ob->start_busy(2);
	command("nod");
	str="我掐指算出有人在『"+target["chinese"]+"』一带行凶作恶。";
	command("say "+str);
    return "你去巡视一下。";

}

int accept_object(object who, object ob,object me)
{
	/*
        if ( ob->query("id") != "tu fei corpse") {
                command("say 你给我这个干吗?");
                return 0;
        }*/
        if ( !who->query_temp("huang_job_target") ) {
                command("say 好啊！不过你得先申请任务。");
                return 0;
        }
	       	if (ob->query_temp("must_killby")!= who->query("id")
			||ob->query("victim_user")||who->query_temp("huang_given") )
		{       command("shake");
                command("say 你杀错人了。");
                return 0;
        }

  /*      if ( ob->query("kill_by") != who) {
                command("say 这个任务似乎不是你自己完成的吧？");
                return 0;
        }
*/      who->set_temp("huang_given",1);
        call_out("destroying", 1, ob);
        call_out("ok", 1, who);
        return 1;
}

void ok(object who)
{
        int exp,pot,count,i;
        if (!who) return;
        command("pat" + who->query("id"));
        command("say 做的好，加油干!");
        if(!who->query("huang_job_count"))
		who->set("huang_job_count",1);
        else
		who->add("huang_job_count",1);
		count=who->query("huang_job_count");
		for(i=0;i*i<count;i++);
		exp=500+random(200)+i*2;
        if(who->query_temp("huang_job_super"))
        {exp+=100;
		 who->delete_temp("huang_job_super");
		}
		pot=exp/2+random(100);
		who->add("potential",pot);
        who->add("combat_exp",exp);
        who->clear_condition("huang_mission");
		who->delete_temp("huang_job_target");
        who->delete_temp("huang_given");
		who->apply_condition("huang_busy",3+random(4));
        tell_object(who,HIW"你被奖励了：\n" +
        chinese_number(exp) + "点实战修为\n" +
        chinese_number(pot) + "点潜能\n"+
        NOR);
        return;
}


void destroying(object obj)
{
        destruct(obj);
        return;
}

string ask_fangqi()
{
         object me;
         me = this_player();
         if(!me->query_temp("huang_job_target"))
         return "你没有领任务,跑这里瞎嚷嚷什麽?";
         me->add("combat_exp",-80+random(20));
         me->apply_condition("huang_mission",6);
         me->delete_temp("huang_job_target");
	     return "没关系,下次继续努力 。";
}

string ask_gonglao(object who)
{
  object me;
  int i;

  me = this_player();
  if(!me->query("huang_job_count"))
  i=0;
  else
  i =(int)me->query("huang_job_count");
  message_vision(CYN"$N对$n说道:你已经完成了" + chinese_number(i) + "次任务。\n"NOR,who,me);
  return "继续努力吧！";
}
