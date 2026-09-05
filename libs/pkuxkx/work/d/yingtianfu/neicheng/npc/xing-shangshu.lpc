//刑部尚书

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"

int ask_task();
int ask_finish();
int ask_fail();
void create()
{
    set_name("刑部尚书", ({"xingbu shangshu", "shangshu"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的刑部尚书。\n");
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
	set("depart","xingbu");
    
	set("inquiry", ([
	
     
	 "帮助": (: ask_task :),
     "help": (: ask_task :),
     "复命": (: ask_finish :),
     "finish": (: ask_finish :),
     "失败": (: ask_fail :),
     "fail": (: ask_fail :),
	]));

    setup();
    setup_player_name();
}

int ask_fail()
{
    object me=this_player();
    if (!me->query_temp("mingtasks/xingbu/start"))
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
	if (me->query("mingpin")!=1)
	command("say 罢了罢了，你退下吧。\n");
	else
	command("say 恭送大人。");
	me->delete_temp("mingtasks");
	return 1;
}
int ask_finish()
{
    object me=this_player();
    object ob=this_object();
	int n,*rewards=({2+random(6),1+random(4),4+random(4),6+random(4),});
	string *finish_comments=({"不错不错，又是大功一件。\n","这么快就破了这宗无头案？又是大功一件。\n",
		"太湖缉凶那么快回来了？真是后生可畏啊。\n","听说钦犯已经被捉回来了，呵呵，不错不错。\n"});
    if (!me->query_temp("mingtasks/xingbu/start")&&me->query("mingpin")!=1)
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/xingbu/task1finish"))
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (me->query_temp("mingtasks/xingbu/task1finish"))
    {
		task_finish(me,rewards[0],finish_comments[0]);
        return 1;
    }
    if (me->query_temp("mingtasks/xingbu/task2finish"))
    {
		task_finish(me,rewards[1],finish_comments[1]);
        return 1;
    }
	if (me->query_temp("mingtasks/xingbu/task3finish"))
    {
		task_finish(me,rewards[2],finish_comments[2]);
        return 1;
    }
	if (me->query_temp("mingtasks/xingbu/task4finish"))
    {
		task_finish(me,rewards[3],finish_comments[3]);
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
    object where,xinzha,corpse;
	string destination,*place=({});
	string* local_path=({"/d/city/","/d/zhenjiang/","/d/hangzhou/","/d/suzhou/","/d/fuzhou/","/d/quanzhou2/","/d/nanchang/","/d/yueyang/","/d/jiangzhou/","/d/chengdu/","/d/yashan/"});
    string *taskname=({"运送物资","调查凶案","太湖缉凶","追查朝廷钦犯"}),msg;
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/xingbu/start"))
    {
        if (me->query_temp("mingtasks/xingbu/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
		me->set_temp("mingtasks/xingbu/task",n+1);
		message_vision("$N看着$n，道：刑部最近事务繁多，你先去"+taskname[n]+"吧。\n",ob,me);
        if (n==0)
        {
            message_vision("$N道：你先去找应天府尹要个批文吧。\n",ob,me);
        }
        if (n==1)
        {
			place=DAMING_D->ytf_task_place();
			if (!sizeof(place))
			{
				me->set_temp("mingtasks/xingbu/task2finish",1);
				tell_object(me,ob->name()+"似乎忘记了什么，你试试看他也许以为你是来领取任务奖励的。\n");
				return 1;
			}
			where=load_object(place[random(sizeof(place))]);
			corpse=new("/d/yingtianfu/neicheng/obj/corpse");
			corpse->set("owner",me);
			corpse->move(where);
			command("say "+where->query("short")+"最近出了一起凶杀案，你去查看(chakan)一下。。");
	
        }
        if (n>=2)
        {
			tell_object(me,"今天真是你的幸运日，"+this_object()->name()+"什么也没要你做就让你回明教复命了。\n");
			tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
			me->delete("mingjiaonewbiejob");
			me->set("mingjiaonewbiejob/lucky",1);
			me->set("mingjiaonewbiejob/damingfinish",1);
			return 1;
        }
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
        n=random(sizeof(taskname));
        me->set_temp("mingtasks/xingbu/task",n+1);
		if (me->query("mingpin")!=1)
		message_vision("$N看着$n，道：刑部最近事务繁多，你先去"+taskname[n]+"吧。\n",ob,me);
		else
		message_vision("$N看着$n，道：听说刑部最近有些忙不过来，我来"+taskname[n]+"吧。\n",me,ob);
        if (n==0)
        {
			if (me->query("mingpin")==1)
			message_vision("$N道：我先去找应天府尹拿个批文吧。\n",me);
			else if (me->query("mingpin")<4)
			command("say 大人先去找应天府尹拿个批文吧。");
			else
            message_vision("$N道：$n先去找应天府尹要个批文吧。\n",ob,me);
        }
        if (n==1)
        {
			place=DAMING_D->ytf_task_place();
			if (!sizeof(place))
			{
				me->set_temp("mingtasks/xingbu/task2finish",1);
				tell_object(me,ob->name()+"似乎忘记了什么，你试试看他也许以为你是来领取任务奖励的。\n");
				return 1;
			}
			where=load_object(place[random(sizeof(place))]);
			corpse=new("/d/yingtianfu/neicheng/obj/corpse");
			corpse->set("owner",me);
			corpse->move(where);
			if (me->query("mingpin")==1)
			message_vision("$N道：听说"+where->query("short")+"最近出了一起凶杀案，我去查看(chakan)一下。\n",me);
			else if (me->query("mingpin")<4)
			command("say "+where->query("short")+"最近出了一起凶杀案，请大人去查看(chakan)一下。");
			else
			command("say "+where->query("short")+"最近出了一起凶杀案，你去查看(chakan)一下。");
        }
        if (n==2)
        {
			if (me->query("mingpin")==1)
			message_vision("$N道：听说最近有一名朝廷重犯在太湖上出没，我去把他捉回来\n",me);
			else if (me->query("mingpin")<4)
			command("whisper "+me->query("id")+" 最近有一名朝廷重犯在太湖上出没，请大人去把他捉回来，如遇反抗，可就地正法。");
			else
			command("whisper "+me->query("id")+" 最近有一名朝廷重犯在太湖上出没，你去把他捉回来，如遇反抗，可就地正法。");
			tell_object(me,HIC+"太湖共有四处码头，分布在归云庄、嘉兴、慕容和苏州，你可以征用随便任何一处的船只，在码头enter即可。\n"+NOR);
        }
		if (n==3)
		{
			while (!objectp(where) || 
			!where->isroom()||
			TASK_D->place_belong(where)=="不明区域"||
			base_name(where) == "/adm/daemons/taskd")
			{where=TASK_D->random_room(local_path[random(11)]);}
			corpse=new(__DIR__"taofan");
			corpse->set("uni_target",me);
			corpse->set("owner",me);
			corpse->move(where);
			if (!living(corpse))
			{
				tell_object(me,"你惊讶的发现，"+ob->name()+"似乎记错了，以为你是来交卸任务的，试试复命吧。\n");
				me->set_temp("mingtasks/xingbu/task4finish",1);
				return 1;
			}
			if (me->query("mingpin")==1)
			message_vision("$N翻了一下宗卷，道："+TASK_D->place_belong(where)+"的"+where->query("short")+"的巨盗？我去把他抓回来。\n",me);
			else if (me->query("mingpin")<4)
			command("whisper "+me->query("id")+" 最近有一名朝廷钦犯在"+TASK_D->place_belong(where)+"的"+where->query("short")+"留下行踪，请大人去把他抓回来。");
			else
			command("whisper "+me->query("id")+" 最近有一名朝廷钦犯在"+TASK_D->place_belong(where)+"的"+where->query("short")+"留下行踪，你去把他抓回来。");
			corpse->info_spread();
		}
		if (me->query("mingpin")==1)
        pre_1pin(me);
        return 1;
    }
}

