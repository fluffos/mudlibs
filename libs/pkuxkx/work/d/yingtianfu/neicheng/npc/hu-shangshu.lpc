//户部尚书

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"

int ask_task();
int ask_finish();
void create()
{
    set_name("户部尚书", ({"hubu shangshu", "shangshu"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的户部尚书。\n");
    set("attitude","heroism");
    set("generation",0);
    set("mingpin",2);
    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
	set("depart","hubu");
    
	set("inquiry", ([
	
     
	 "帮助": (: ask_task :),
     "help": (: ask_task :),
     "复命": (: ask_finish :),
     "finish": (: ask_finish :),
	]));

    setup();
    setup_player_name();
}
int ask_finish()
{
    object me=this_player();
    object ob=this_object();
	int n,*rewards=({5+random(8),2+random(2),10+random(3),});
	string *finish_comments=({"地图造册完成？看来你还真不简单啊。\n","内鬼抓到了？真的啊！\n",
		"居然整理得井井有条！\n"});
    if (me->query("mingjiaonewbiejob/damingstart")&& (me->query_temp("mingtasks/hubu/task3finish")||me->query_temp("mingtasks/hubu/task4finish")))
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query_temp("mingtasks/hubu/start")&&me->query("mingpin")!=1)
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    if (me->query_temp("mingtasks/hubu/task1finish"))
    {
		task_finish(me,rewards[0],finish_comments[0]);
        return 1;
    }
	if (me->query_temp("mingtasks/hubu/task3finish"))
    {
		task_finish(me,rewards[1],finish_comments[1]);
        return 1;
    }
	if (me->query_temp("mingtasks/hubu/task4finish"))
    {
		task_finish(me,rewards[2],finish_comments[2]);
        return 1;
    }
    else
    {
        task_pending(me,ob);
        return 1;
    }
}
int ask_task()
{
    object me=this_player();
    object ob=this_object();
    object xinzha;
    string *taskname=({"地图造册","编制户籍","户部库房","户部库房"}),msg;
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/hubu/start"))
    {
		if (me->query_temp("mingtasks/hubu/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
		if (n==1||n==0)
		{
			tell_object(me,"今天真是你的幸运日，"+this_object()->name()+"什么也没要你做就让你回明教复命了。\n");
			tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
			me->delete("mingjiaonewbiejob");
			me->set("mingjiaonewbiejob/lucky",1);
			me->set("mingjiaonewbiejob/damingfinish",1);
			return 1;
		}
		if (n==2)
        {
			message_vision("$N看着$n，道："+taskname[n]+"的宝钞最近总是失窃，我派你去看看吧。\n",ob,me);
            me->set_temp("mingtasks/hubu/huku",1);
        }
		if (n==3)
        {
			message_vision("$N看着$n，道："+taskname[n]+"的堆放的货品过于凌乱，你去整理(zhengli)一下吧。\n",ob,me);
            me->set_temp("mingtasks/hubu/hu_zhengli",1);
        }
		me->set_temp("mingtasks/hubu/task",1);
		return 1;
    }
    if (if_give_task(me)!="approve")
	{
		msg=if_give_task(me);
		write(msg);
		return 1;
	}
    else
    {
		me->set_temp("mingtasks/hubu/task",1);
        n=random(sizeof(taskname));
        if (n==0)
        {
            xinzha=new(__DIR__"obj/xinzha");
            xinzha->move(me);
			if (me->query("mingpin")==1)
			message_vision("$N对着$n道：江南历经兵乱，很多地区地图缺失，我去监督"+taskname[n]+"。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 江南历经兵乱，很多地区地图缺失，大人去监督"+taskname[n]+"。");
			else
			{
				message_vision("$N看着$n，道：江南历经兵乱，很多地区地图缺失，我先派你去"+taskname[n]+"吧。\n",ob,me);
				message_vision("$N给了$n一封信扎。\n",ob,me);
			}
        }
        if (n==1)
        {
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，道：户部侍郎听说最近工作不顺，我去指点他一下"+taskname[n]+"。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 户部侍郎最近很头疼，大人能否帮他"+taskname[n]+"？");
			else
            message_vision("$N看着$n，道：户部侍郎最近很头疼，我派你帮他"+taskname[n]+"吧。\n",ob,me);
            me->set_temp("mingtasks/hubu/hukou",1);
        }
        if (n==2)
        {
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，道："+taskname[n]+"的宝钞最近总是失窃，本官前去坐镇。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say "+taskname[n]+"的宝钞最近总是失窃，大人去监督一下。");
			else
			message_vision("$N看着$n，道："+taskname[n]+"的宝钞最近总是失窃，我派你去看看吧。\n",ob,me);
            me->set_temp("mingtasks/hubu/huku",1);
        }
		if (n==3)
        {
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，道："+taskname[n]+"的堆放的货品过于凌乱，本官去整理(zhengli)一下。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say "+taskname[n]+"的堆放的货品过于凌乱，大人能去整理(zhengli)一下吗？");
			else
			message_vision("$N看着$n，道："+taskname[n]+"的堆放的货品过于凌乱，你去整理(zhengli)一下吧。\n",ob,me);
			me->set_temp("mingtasks/hubu/hu_zhengli",1);
        }
		if (me->query("mingpin")==1)
        pre_1pin(me);
        return 1;
    }
}

