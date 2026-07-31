/************************
File:   Murtz.c
Create: Play
Time:   4/25/2002
************************/
inherit NPC;
#include <ansi.h>;
int ask_job();
#define JOB_G (__DIR__"mr_inherit/mr_jobs.c")
#define MR_JOB_MOVED (__DIR__"mr_inherit/mrjobd.c")

void create()
{
        seteuid(getuid());
	set_name("慕容拓哉",({ "murong tuozai", "murong", "tuozai", "guanjia" }) );
        set("gender", "男性" );
        set("title", "姑苏慕容大管家" );
        set("age", 47);
        set("long", "姑苏慕容世家的大管家。\n");
        set("per", 28);
        set("str", 34);
        set("dex", 25);
        set("con", 26);
        set("int", 25);
        set("attitude", "friendly");
	set("inquiry", ([
		"job"     : (: ask_job :),
		"work"    : (: ask_job :),
		"工作"    : (: ask_job :),
		"任务"    : (: ask_job :),
	]));

        setup();
        carry_object("/clone/armor/cloth")->wear();
}
void init()
{
        add_action("do_report", "report");
}

int ask_job()
{
	string msg;
	int list,i;
	mapping *jobs;
	object me = this_player();
	
        if(!me->query("family/family_name")||me->query("family/family_name")!="姑苏慕容")
                return 0;
 
        if(me->query_temp("Mrjob_over"))
        {
        	command("say 你的工作已经完成了，怎么不向我报告(report)呢！");
        	return 1;
        } 
        if(me->query_temp("Mrjob"))
        {
        	msg = sprintf("你现在%s%s%s还没有完成吧？",
        	               me->query_temp("Mrjob/type"),
        	               me->query_temp("Mrjob_city/name")?
        	               me->query_temp("Mrjob_city/name"):"",
        	               me->query_temp("Mrjob_name/name")?
        	               me->query_temp("Mrjob_name/name"):"",
        	               );
        	command("say "+msg);
        	command("say 输入 Yes 放弃当前的工作:");
        	input_to("get_unjob",me);
        	return 1;
        }
        if(me->query_temp("Mrjob_un")&&me->query_temp("Mrjob_un")>time())
        {
        	command("say 你累了，还是去休息休息吧。");
        	return 1;
        }
        command("say 选择你打算做的工作编号吧!");
        jobs = JOB_G->jobs();
        list = sizeof(jobs);
        for(msg="",i=0;i<list;i++)
        {
        msg += sprintf("  %d.%s \n",
                      i+1,
                      jobs[i]["type"],
                      );
        }
        write(msg);

        input_to("get_job",me,jobs);
        return 1;
}

int get_job(string arg, object me,mapping *jobs)
{
	int i, amu;
	string msg;
	mapping job,name,city;
	object obj,map;

        if( !arg || sscanf(arg, "%d", amu)!=1 ||!amu)
        {
        if(amu==0)
        {
        command("say 好吧，你想好以后再来。\n");
        return 1;
       	}
        write("请选择1-4的数字，选0为取消:");
        input_to("get_job",me,jobs);
        return 1;
        }
        if(amu<1 || amu > 4){
        write("请选择1-4的数字，选0为取消: ");
        input_to("get_job",me,jobs);
        return 1;
        }
        i = amu-1;
        job = jobs[i];
        if (undefinedp(job)) {write("系统错误。\n");return 1;}
	msg = JOB_G->msg(jobs[i]["content"]);
        switch(i)
        {
               case 0:
                      if(objectp(obj = present("shui hu", me))&&
                         obj->query("mrjob") )
                      break;	
		      obj=new(__DIR__"mr_obj/mr_shuihu.c");
		      obj->move(me);
		      command("say 这个水壶你收好。");
                      break;
               case 1:
                      if(objectp(obj = present("ling pai", me))&&
                         obj->query("mrjob") )
                         destruct(obj);
                      me->set_temp("Mrjob_patrol","start");
               	      obj=new(__DIR__"mr_obj/mr_lingpai.c");
		      obj->move(me);
		      command("say 这块令牌你拿好。");
		      break;
               case 2:
                      if(!objectp(obj = present("shijie zhang", me))||
                         !obj->query("mrjob") )
                     {
                      obj=new(__DIR__"mr_obj/mr_shuxin.c");
		      obj->move(me);
 		      command("say 这根使节杖你要保管好。");
 		      }
              default:
                      if(!mapp(name =JOB_G->query_name()))
                      {
                      	      command("say 慕容工作系统错误，请联系巫师。");
                      	      return 1;
                      }
                      if(!mapp(city =JOB_G->query_city()))
                      {
                      	      command("say 慕容工作系统错误，请联系巫师。");
                      	      return 1;
                      }
                      me->set_temp("Mrjob_name",name);
                      me->set_temp("Mrjob_city",city);
		      msg = sprintf(msg,city["name"],name["name"],name["id"]);
		      break;
	}
        if((amu==2||amu==3))
        {
        	if(!objectp(map = present("mr dituce", me)) )
        	{
        		map=new(__DIR__"mr_obj/mr_map.c");
        		map->move(me);
        	}
        	if(!query("jobmove"))
        	{
        		MR_JOB_MOVED->create();
        		set("jobmove",1);
        	}
        }
        me->set_temp("Mrjob_time",time()+job["time"]);
	command("say "+msg);
	me->set_temp("Mrjob",job);
	return 1;
}

int do_report(string arg)
{
	object me,obj;
	int exp, pot, sco, k=1, t, m=0, amu, bonus;
	mapping job;
	me = this_player();
	job = me->query_temp("Mrjob");
	if(!mapp(job))
	      return notify_fail("什么？\n");
        t=me->query_temp("Mrjob_time");
	if(!me->query_temp("Mrjob_over")&&t>time())
	      return notify_fail("你"+job["type"]+"的工作还没完成吧！\n");
        
	if(t>time())
	k+=(t-time())*10/job["time"];
	m=me->query_temp("Mrjob_hortation");
        switch(job["content"])
        {
        	case "water":
        	if(!m||m<1)
        	{
	        me->delete_temp("Mrjob_over");
	        me->delete_temp("Mrjob_hortation");
                me->delete_temp("Mrjob_time");
                me->delete_temp("Mrjob_amu");
		me->delete_temp("Mrjob");
		command("say "+me->name()+"浇灌这么简单的工作你也完不成！\n");
		return 1;
                }
        	bonus = __FILE__->get_bonus(me,"water");
                k += m;
                bonus +=k;
		command("say 很好，"+me->name()+"辛苦了！\n");
 		exp = job["exp_bonus"] + bonus+random(bonus/2);;
		pot = job["pot_bonus"] + bonus/2+random(bonus/3);
	        if(me->query("max_potential")<me->query("potential")+pot)
	        pot = me->query("max_potential") - me->query("potential");
        	me->add("combat_exp", exp);
	        me->add("potential", pot);
	        		
	        me->delete_temp("Mrjob_over");
		me->delete_temp("Mrjob");
	        me->delete_temp("Mrjob_hortation");
                me->delete_temp("Mrjob_time");
                me->save();
      	
        	break;
        	case "patrol":
                obj = present("ling pai", me);
 		amu = me->query_temp("Mrjob_amu");
        	if(me->query_temp("Mrjob_over")==2)
        	{
        		if(!amu||amu<3)
        		{
        		command("say 你不好好巡视山庄，再如此将给予处罚！");
         	        me->delete_temp("Mrjob_over");
        	        me->delete_temp("Mrjob_hortation");
                        me->delete_temp("Mrjob_time");
	                me->delete_temp("Mrjob_amu");
	                me->delete_temp("Mrjob_thief");
		        me->delete_temp("Mrjob");
         		if(obj)
	        	{
                         write("你将令牌交了回去。\n");
        	         destruct(obj);
                        }
                        me->save();
		        return 1;
 		        }
 		}
		command("say 不错，你完成的很出色！\n");
        	bonus = __FILE__->get_bonus(me,"patrol");
 	        k += m;
 	        bonus += k;
 		exp = job["exp_bonus"] + bonus+random(bonus/5);;
		pot = job["pot_bonus"] + bonus/6+random(k);;
	        if(me->query("max_potential")<me->query("potential")+pot)
	        pot = me->query("max_potential") - me->query("potential");
        	me->add("combat_exp", exp);
	        me->add("potential", pot);
		
	        me->delete_temp("Mrjob_over");
	        me->delete_temp("Mrjob_hortation");
                me->delete_temp("Mrjob_time");
	        me->delete_temp("Mrjob_amu");
	        me->delete_temp("Mrjob_thief");
		me->delete_temp("Mrjob");
		if(obj)
		{
                write("你将令牌交了回去。\n");
        	destruct(obj);
                }
                me->save();
        	break;
        	case "canvass":
        	if(m<1)
        	{
        		command("say 你这次征召"+me->query_temp("Mrjob_name/name")+"的结果太令我失望了！\n");
                	me->delete_temp("Mr_snoop");
	                me->delete_temp("Mrjob_over");
        	        me->delete_temp("Mr_canvass");
	                me->delete_temp("Mrjob_hortation");
                        me->delete_temp("Mrjob_time");
                        me->delete_temp("Mrjob_name");
                        me->delete_temp("Mrjob_type");
		        me->delete_temp("Mrjob");
		        me->save();
        	break;
        	}
        	k+=m;
                if(m>20)
                {
                	command("say 你请到"+me->query_temp("Mrjob_name/name")+"加盟慕容，为光复我大燕做得非常出色！\n");
                	k=k*2;
		}
		else
        	if(m>10)
        	{
        		command("say 你能为请到"+me->query_temp("Mrjob_name/name")+"以后我所用辛苦了！\n");
        		k=k*3/2;
        	}
                else
                command("say 你为慕容尽心尽力了，以后要再接再励。");		
        	bonus = __FILE__->get_bonus(me,"canvass");
        	bonus += k;
 		exp = job["exp_bonus"] + bonus+random(bonus/4);;
		pot = job["pot_bonus"] + bonus/6+random(k*2);
	        if(me->query("max_potential")<me->query("potential")+pot)
	        pot = me->query("max_potential") - me->query("potential");
        	me->add("combat_exp", exp);
	        me->add("potential", pot);
		
        	me->delete_temp("Mr_snoop");
	        me->delete_temp("Mrjob_over");
	        me->delete_temp("Mr_canvass");
	        me->delete_temp("Mrjob_hortation");
                me->delete_temp("Mrjob_time");
                me->delete_temp("Mrjob_name");
                me->delete_temp("Mrjob_type");
		me->delete_temp("Mrjob");
                me->save();
        	break;
        	case "revive":
        	if(!m||m<1)
        	{
        	me->delete_temp("Mr_ask");
	        me->delete_temp("Mrjob_over");
	        me->delete_temp("Mrjob_hortation");
		me->delete_temp("Mrjob");
                me->delete_temp("Mrjob_time");
                me->delete_temp("Mrjob_name");
                me->delete_temp("Mrjob_type");
		command("say "+me->name()+"如此简单的事情你都没做好，太令我失望了！\n");
                me->save();
		return 1;
        	}
		command("say 好啊，给那些鼠辈颜色看看，你做得不错！\n");
 	        k += m;
        	bonus = __FILE__->get_bonus(me,"revive");
        	bonus += k;
 		exp = job["exp_bonus"] + bonus+random(bonus/3);;
		pot = job["pot_bonus"] + bonus/6+random(k*3);;
	        if(me->query("max_potential")<me->query("potential")+pot)
	        pot = me->query("max_potential") - me->query("potential");
        	me->add("combat_exp", exp);
	        me->add("potential", pot);
		
        	me->delete_temp("Mr_ask");
	        me->delete_temp("Mrjob_over");
	        me->delete_temp("Mrjob_hortation");
                me->delete_temp("Mrjob_time");
                me->delete_temp("Mrjob_name");
                me->delete_temp("Mrjob_type");
		me->delete_temp("Mrjob");
                me->save();
        	break;
                default:
                write("慕容世家工作系统出现错误，请告之巫师。\n");
        	return 1;
        }
        	tell_object(me,HIC"你在完成"+job["type"]+"的工作中，获得了\n" +
		chinese_number(pot) + "点潜能的提升，领悟到" +
		chinese_number(exp) + "点实战经验。\n"NOR);
              return 1;
}

int get_bonus(object me, string str)
{
	int amu, Exp;
	Exp = me->query("combat_exp");

        switch(str)
        {
        	case "water":  //9万经验奖励到最低点
        	      	amu=Exp/3000; 	amu>30?amu=30:amu;   amu=30-amu;
        	break;
        	case "patrol": //150万经验奖励到峰值
                    	amu=Exp/6000;
                    	amu>=10?amu=amu+50:amu;
               	 	amu<30?amu=30:amu>300?amu=300:amu;
        	break;
        	case "canvass":  //462万经验奖励到峰值
                       	amu=Exp/11000;
                    	amu>=10?amu=amu+80:amu;
                       	amu<45?amu=45:amu>500?amu=500:amu;
        	break;
        	case "revive":  //1242万经验奖励到峰值
                       	amu=Exp/18000; 
                    	amu>=10?amu=amu+110:amu;
                       	amu<60?amu=60:amu>800?amu=800:amu;
        	break;
                default:
                amu=0;
                break;        	
        }
	return amu;
}

int get_unjob(string arg,object me)
{
	if(arg == "Yes"||arg[0]=='Y'||arg[0]=='y')
	{
        	me->delete_temp("Mr_snoop");
	        me->delete_temp("Mr_canvass");
	        me->delete_temp("Mrjob_hortation");
                me->delete_temp("Mrjob_time");
                me->delete_temp("Mrjob_name");
                me->delete_temp("Mrjob_type");
                me->delete_temp("Mrjob_amu");
                me->delete_temp("Mrjob_thief");
        	me->delete_temp("Mr_ask");
		me->delete_temp("Mrjob");
		command("say "+me->name()+"你的工作已经取消了。");
		me->set_temp("Mrjob_un",time()+600);
		me->save();
	}
	else
	command("say "+me->name()+"快去工作吧。");
	return 1;
}