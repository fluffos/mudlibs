//工部尚书

#include <ansi.h>
inherit NPC;
#include <title.h>
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
#include "huilu.h"
int ask_room();
int ask_task();
int ask_finish();
int askforhelp();
void create()
{
    set_name("工部尚书", ({"gongbu shangshu", "shangshu"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 50);
    set("long", "他就是当今朝廷的工部尚书。\n");
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
    set("chat_chance", 5);
        set("chat_msg", ({
                
                (:askforhelp:),
        }) );
	set("depart","gongbu");
	set("inquiry", ([
	
     "额外空间": (: ask_room :),
     "space": (: ask_room :),
	 "帮助": (: ask_task :),
     "help": (: ask_task :),
     "复命": (: ask_finish :),
     "finish": (: ask_finish :),
	]));

    setup();
    carry_object("/d/yingtianfu/neicheng/obj/guanyin2");
    setup_player_name();
}

int askforhelp()
{
    if (random(100)>95&&time()-query("adv_time")>600)
    {
		set("adv_time",time());
        command("daming 朝廷资助官员扩充自己房间的空间，有需要的四品及以上官员可以来找本官。\n");
    }
        
}

int ask_finish()
{
    object me=this_player();
    object ob=this_object();
	int n,*rewards=({3+random(2),12+random(8),1+random(4),4+random(4),});
	string *finish_comments=({"真是干吏啊，修缮完成，皇城一新啊。\n","真是干吏啊，虞衡司事务复杂，给你料理的井井有条。\n",
		"屯田完成，京城的粮食更有保障了。\n","治水完成，长江希望再无水患。\n"});
    if (me->query("mingjiaonewbiejob/damingstart")&& (me->query_temp("mingtasks/gongbu/task1finish")||me->query_temp("mingtasks/gongbu/task2finish")||me->query_temp("mingtasks/gongbu/task4finish")))
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query_temp("mingtasks/gongbu/start")&&me->query("mingpin")!=1)
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
	if (me->query_temp("mingtasks/gongbu/task4finish"))
    {
		task_finish(me,rewards[0],finish_comments[0]);
        return 1;
    }
	if (me->query_temp("mingtasks/gongbu/task3finish"))
    {
		task_finish(me,rewards[1],finish_comments[1]);
        return 1;
    }
	if (me->query_temp("mingtasks/gongbu/task2finish"))
    {
		task_finish(me,rewards[2],finish_comments[2]);
        return 1;
    }
    if (me->query_temp("mingtasks/gongbu/task1finish"))
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
    string *taskname=({"长江治水","正阳门外屯田","虞衡司似乎有些事务，你且去问问两位侍郎吧","营缮司有些任务，你且去问问两位侍郎吧"}),msg;
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/gongbu/start"))
    {
        if (me->query_temp("mingtasks/gongbu/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
		if (n==2)
		{
			tell_object(me,"今天真是你的幸运日，"+this_object()->name()+"什么也没要你做就让你回明教复命了。\n");
			tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
			me->delete("mingjiaonewbiejob");
			me->set("mingjiaonewbiejob/lucky",1);
			me->set("mingjiaonewbiejob/damingfinish",1);
			return 1;
		}
		else if (n==3)
		{
			message_vision("$N看着$n，道："+taskname[n]+"。\n",ob,me);
		}
		else
		{
			message_vision("$N看着$n，道：工部事物繁多，我先派你去"+taskname[n]+"吧。\n",ob,me);
		}
        me->set_temp("mingtasks/gongbu/task",n+1);
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
		me->set_temp("mingtasks/gongbu/task",n+1);
		if (n!=2&&n!=3)
		{
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，道：工部最近有些忙不过来？我去帮助"+taskname[n]+"一下。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 工部事物繁杂，大人可以帮我去"+taskname[n]+"吗？");
			else
			message_vision("$N看着$n，道：工部事物繁多，我先派你去"+taskname[n]+"吧。\n",ob,me);
		}
		else
		{
			if (me->query("mingpin")==1)
			{
				msg=replace_string(taskname[n], "你", "我" );
				message_vision("$N道：听说"+msg+"。\n",me);
			}
			else if (me->query("mingpin")<4)
			command("say 多谢大人帮忙，"+taskname[n]+"。");
			else
			message_vision("$N看着$n，道："+taskname[n]+"。\n",ob,me);
		}
		if (me->query("mingpin")==1)
        pre_1pin(me);
        return 1;
    }
}

int ask_room()
{
    object me=this_player();
    object ob=this_object();
    if (!me->query("mingpin"))
    {
        command("say 老夫在朝二十余年，大明官员都见过，怎么不认识你？\n");
        return 1;
    }
    if (me->is_busy() || me->is_fighting())
    {
		return notify_fail("你正忙着哪！\n");
    }
    me->add_busy(1);
    if (me->query("mingpin")==5||me->query("mingpin")==6)
    {
        command("say 朝廷现在也不宽裕，过过再说吧。\n");
        return 1;
    }
    if (me->query("mingpin")==4)
    {
        if (me->query("ming/extraroom")==2)
        {
            command("say 大人不是已经问过了？\n");
            return 1;
        }
        me->set("ming/extraroom",2);
        command("say 朝廷的四品大员？不能失了朝廷体统，已经派人给你增加了一些储物空间。\n");
        return 1;
    }
    if (me->query("mingpin")==3)
    {
        if (me->query("ming/extraroom")==4)
        {
            command("say 大人不是已经问过了？\n");
            return 1;
        }
        me->set("ming/extraroom",4);
        command("say 大人乃朝廷重臣，已经给大人添加了一些储物空间。\n");
        return 1;
    }
    if (me->query("mingpin")==2)
    {
        if (me->query("ming/extraroom")==7)
        {
            command("say 大人不是已经问过了？\n");
            return 1;
        }
        me->set("ming/extraroom",7);
        command("say 大人乃国之栋梁，已经给大人扩建了一些储物空间。\n");
        return 1;
    }
    if (me->query("mingpin")==1)
    {
        if (me->query("ming/extraroom")==10)
        {
            command("say 大人不是已经问过了？\n");
            return 1;
        }
        me->set("ming/extraroom",10);
        command("say 老大人乃国之柱石，下官能为大人增加储物空间不胜荣幸。\n");
        return 1;
    }
    else
    {
        command("say 你用的什么bug？老实交代！\n");
        return 1;
    }
}