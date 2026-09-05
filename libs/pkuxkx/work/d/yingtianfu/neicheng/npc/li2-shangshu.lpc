//礼部尚书

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_task();
int ask_finish();
void create()
{
    set_name("礼部尚书", ({"libu shangshu", "shangshu"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的礼部尚书。\n");
    set("attitude","heroism");
    set("generation",0);

    set("max_qi",800);
    set("eff_qi",800);
    set("qi",800);
    set("max_jing",300);
    set("jing",300);
    set("shen_type",1);
    set("no_clean_up",1);
    set("combat_exp",20000);
    set("mingpin",2);
    set("depart","libu2");
	set("inquiry", ([
	
     
	 "帮助": (: ask_task :),
     "help": (: ask_task :),
     "复命": (: ask_finish :),
     "finish": (: ask_finish :),
	]));

    setup();
    call_out("record_me",1);
    setup_player_name();
    carry_object("/d/yingtianfu/neicheng/obj/guanyin2");
}

int record_me()
{
    object ob=load_object("/d/yingtianfu/neicheng/qintian");
    ob->set("li",this_object());
    return 1;
}
int ask_finish()
{
    object me=this_player();
    object ob=this_object();
	int *rewards=({random(8)+4,4,6,5});
	int *rewards2=({-2,});
	string *finish_comments=({"这次考试尚算成功，大人果不负我所托，辛苦了。\n","修史的进度极佳，大人辛苦了。\n","官员已经来到礼部，有劳大人了。\n","天佑我大明啊，封禅居然如此顺利。\n"});
	string *finish_comments2=({"你搞什么呀？弄得考生怨声载道，已经上达天听了，还不快退下。\n",});
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/libu2/exam_degree")>0)
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query_temp("mingtasks/libu2/start")&&me->query("mingpin")!=1)
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    if (me->query_temp("mingtasks/libu2/exam")&&me->query_temp("mingtasks/libu2/exam_degree")<=0)
    {
        task_finish(me,rewards2[0],finish_comments2[0]);
        return 1;
    }
    if (me->query_temp("mingtasks/libu2/exam_degree")>0)
    {
        task_finish(me,rewards[0],finish_comments[0]);
        return 1;
    }
	if (me->query_temp("mingtasks/libu2/xiushi")=="finish")
    {
        task_finish(me,rewards[1],finish_comments[1]);
        return 1;
    }
	if (me->query_temp("mingtasks/libu2/fengchan")=="finish")
    {
        task_finish(me,rewards[3],finish_comments[3]);
        return 1;
    }
	if (me->query_temp("mingtasks/libu2/jinjian")=="finish")
    {
        task_finish(me,rewards[2],finish_comments[2]);
        return 1;
    }
	if (me->query_temp("ming_libu2_jinjian"))
	{
		if (time()-me->query_temp("ming_libu2_jinjian")<300)
		{
			me->add("ming/credit",1);
			command("say "+me->query("name")+"大人来了？太好了。");
			me->delete_temp("ming_libu2_jinjian");
			tell_object(me,HIC+"你获得了一点大明功勋。\n"+NOR);
		}
		else
		{
			command("say "+me->query("name")+"大人来迟了。");
			me->delete_temp("ming_libu2_jinjian");
		}
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
    object xinzha,*all,guan;
    string *taskname=({"贡院监考","修元史","通知觐见","封禅泰山"}),msg;
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/libu2/start"))
    {
        if (me->query_temp("mingtasks/libu2/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
		me->set_temp("mingtasks/libu2/task",n);
        if (n==0)
        {
            me->set_temp("mingtasks/libu2/exam",1);
            message_vision("$N看着$n，道：春闱马上就要进行了，我先派你去"+taskname[n]+"吧。\n",ob,me);
            message_vision("$N道：到了考官系，你就可以宣布开考(kaikao)了。\n",ob,me);
        }
        if (n==1)
        {
			message_vision("$N看着$n，道："+taskname[n]+"刻不容缓，你到礼部大厅去看看(xiushi)。\n",ob,me);
            me->set_temp("mingtasks/libu2/xiushi",1);
        }
        if (n!=1&&n!=0)
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
		me->set_temp("mingtasks/libu2/task",n+1);
        if (n==0)
        {
            me->set_temp("mingtasks/libu2/exam",1);
			if (me->query("mingpin")==1)
			{
				message_vision("$N看着$n，道：春闱马上就要进行了，本官决定前去"+taskname[n]+"。\n",me,ob);
			}
			else if (me->query("mingpin")<4)
			{
				command("say 春闱马上就要进行了，请大人前去"+taskname[n]+"。");
			}
			else
			{
				message_vision("$N看着$n，道：春闱马上就要进行了，我先派你去"+taskname[n]+"吧。\n",ob,me);
			}
			tell_object(me,"到了考官席，你就可以宣布开考(kaikao)了。\n");
        }
		if (n==1)
        {
            me->set_temp("mingtasks/libu2/xiushi",1);
			if (me->query("mingpin")==1)
			{
				message_vision("$N看着$n，道："+taskname[n]+"刻不容缓，本官到礼部大厅去看看。\n",me,ob);
			}
			else if (me->query("mingpin")<4)
			{
				command("say "+taskname[n]+"刻不容缓，大人得空去礼部大厅看看。");
			}
			else
			{
				message_vision("$N看着$n，道："+taskname[n]+"刻不容缓，你到礼部大厅去看看。\n",ob,me);
			}
			tell_object(me,"到了礼部大厅，你就可以开始修史(xiushi)了。\n");
        }
		if (n==2)
        {
			all = filter_array(children(USER_OB), (: userp :));
            all = filter_array(all, (: environment :));
            all = filter_array(all, (: $1->query("mingpin") :) );
			if (sizeof(all)<5)
			{
				command("say 暂时没事了，你退下吧。");
			}
			me->set_temp("mingtasks/libu2/jinjian",1);
			while (!guan||guan==me)
			guan= all[random(sizeof(all))];
			if (me->query("mingpin")==1)
			{
				message_vision("$N看着$n，道："+guan->query("name")+"很久没有上朝了，需要"+taskname[n]+"陛下，本官去通知他。\n",me,ob);
			}
			else if (me->query("mingpin")<4)
			{
				command("say "+guan->query("name")+"很久没有上朝了，需要"+taskname[n]+"陛下，大人请去通知他。");
			}
			else
			{
				message_vision("$N看着$n，道："+guan->query("name")+"很久没有上朝了，需要"+taskname[n]+"陛下，你去通知他。\n",ob,me);
			}
			me->set_temp("mingtasks/libu2/find_officer",guan->query("id"));
			tell_object(me,"找到"+guan->query("name")+"通知(tongzhi)他。\n");
        }
		if (n==3)
        {
			me->set_temp("mingtasks/libu2/fengchan",1);
			if (me->query("mingpin")==1)
			{
				message_vision("$N看着$n，道：年年风调雨顺，天佑我大明，应该"+taskname[n]+"了，本官自会去处理。\n",me,ob);
			}
			else if (me->query("mingpin")<4)
			{
				command("say 年年风调雨顺，天佑我大明，应该"+taskname[n]+"了，大人有暇请去处理一下。");
			}
			else
			{
				message_vision("$N看着$n，道：年年风调雨顺，天佑我大明，应该"+taskname[n]+"了，你去办好这件事。\n",ob,me);
			}
			tell_object(me,"在礼部大厅指定(zhiding)一名大明官员，有了帮手，你们一起去泰山封禅台封禅(fengshan)吧。\n");
			tell_object(me,HIR+"如果指定的助手是机器人，你就欲哭无泪了，所以指定之前，最好先和要指定的对象通个气。\n"+NOR);
        }
        if (me->query("mingpin")==1)
        pre_1pin(me);
        return 1;
    }
}

object create_npc()
{
    object npc=new(__DIR__"random_npc");
    npc->set_init_ability();
    return npc;
}

int add_list()
{
    object npc,ob=load_object("/d/yingtianfu/neicheng/shengzhi");
    int i,flag=0;
    string npc_save_path;
    ob->restore();
    npc=create_npc();
    for (i=0;i<1000;i++)
    {
        if (!ob->query("daming_backup_officer/"+i))
        {
            npc_save_path="daming_backup_officer/";
            npc->save_npc(npc_save_path,i);
            this_object()->set("new_officer",npc->query("name"));
            destruct(npc);
            return 1;
        }
    }
}

int add_lists()
{
    int i,officer=1+random(10);
    for (i=0;i<officer;i++)
    {
        add_list();
    }
    command("daming 大比之年，又增加了"+this_object()->query("new_officer")+"等"+chinese_number(officer)+"名年轻官员，国家之幸啊！");
    return 1;
}