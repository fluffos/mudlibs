//兵部尚书 Zine 

#include <ansi.h>
inherit NPC;
#include "huilu.h"
#include "/d/yingtianfu/neicheng/npc/daming_npc_officer.h"
int ask_task();
int ask_finish();
void create()
{
    set_name("兵部尚书", ({"bingbu shangshu", "shangshu"}));
    set("title", HIW"大明"NOR);
    set("gender", "男性");
    set("age", 40);
    set("long", "他就是当今朝廷的兵部尚书。\n");
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
	set("depart","bingbu");
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
	int n,*rewards=({6,5+random(5),4+random(5),5+random(5),});
	string *finish_comments=({"不错不错，新军连成，我大明必添一强镇。\n","不错不错，军械造成，我大明都城必固若金汤。\n",
		"你的评价很中肯。\n","不错不错，这么快清点完军粮，我大明都城必固若金汤。\n",});
	string *desc=({"可堪大任","不堪造就","能力平平","天人之资"});
    if (me->query("mingjiaonewbiejob/damingstart")&& (me->query_temp("mingtasks/bingbu/bing_degree")>85 
        && me->query_temp("mingtasks/bingbu/bing_degree")<=100 || me->query_temp("mingtasks/bingbu/xie_degree")>50
        || me->query_temp("mingtasks/bingbu/liang_degree")>50|| me->query_temp("mingtasks/bingbu/wg_degree")>20))
    {
        tell_object(me,"完成了大明任务，你可以回杨逍处复命了。\n");
        me->delete("mingjiaonewbiejob");
        me->set("mingjiaonewbiejob/damingfinish",1);
        return 1;
    }
    if (!me->query_temp("mingtasks/bingbu/start")&&me->query("mingpin")!=1)
    {
        command("say 你有在这里要过任务吗？\n");
        return 1;
    }
    if (me->query_temp("mingtasks/bingbu/bing_degree")>85 && me->query_temp("mingtasks/bingbu/bing_degree")<=100)
    {
		task_finish(me,rewards[0],finish_comments[0]);
		return 1;
    }
    if (me->query_temp("mingtasks/bingbu/xie_degree")>50)
    {
		task_finish(me,rewards[1],finish_comments[1]);
        return 1;
    }
	if (me->query_temp("mingtasks/bingbu/wg_degree")>20)
    {
		message_vision("$N向$n汇报："+me->query_temp("mingtasks/bingbu/wg_name")+"“"+desc[random(sizeof(desc))]+"”。\n",me,ob);
		task_finish(me,rewards[2],finish_comments[2]);
        return 1;
    }
    if (me->query_temp("mingtasks/bingbu/liang_degree")>50)
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
    object ob=this_object(),wg;
    string *taskname=({"操练新军","督造军械","清点军粮","有武职官在兵部大厅述职，你去问问(ask)他吧"}),msg;
    int n;
    if (me->query("mingjiaonewbiejob/damingstart")&& me->query_temp("mingtasks/bingbu/start"))
    {
        if (me->query_temp("mingtasks/bingbu/task"))
        {
            command("say 你领了任务，就赶紧去做吧。\n");
            return 1;
        }
        n=random(sizeof(taskname));
		if (n==3)
		{
			message_vision("$N看着$n，朗声道："+taskname[n]+"。\n",ob,me);
			wg=new(__DIR__"wu_guan");
			wg->set("owner",me);
			wg->move("/d/yingtianfu/neicheng/bing_big_room");
			message_vision("$N又道：他的名字叫作"+wg->name()+"什么的。一定要事无巨细，多问几次，知道了解清楚再来回报。\n",ob);
		}
		else
		{
			message_vision("$N看着$n，朗声道：我朝卫所凋敝，女真人入侵在即，你且去"+taskname[n]+"吧。\n",ob,me);
		}
        me->set_temp("mingtasks/bingbu/task",n+1);
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
		me->set_temp("mingtasks/bingbu/task",n+1);
		if (n==3)
		{
			wg=new(__DIR__"wu_guan");
			wg->set("owner",me);
			wg->move("/d/yingtianfu/neicheng/bing_big_room");
			if (me->query("mingpin")==1)
			message_vision("$N对$n道：听说来了个武官叫做"+wg->name()+"在等候述职，我去问问(ask)他。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 来了个武官叫做"+wg->name()+"在等候述职，大人可以代我去问问(ask)他吗？");
			else
			{
				message_vision("$N看着$n，朗声道："+taskname[n]+"。\n",ob,me);
				message_vision("$N又道：他的名字叫作"+wg->name()+"什么的。一定要事无巨细，多问几次，知道了解清楚再来回报。\n",ob);
			}
		}
		else
		{
			if (me->query("mingpin")==1)
			message_vision("$N看着$n，朗声道：我朝卫所凋敝，女真人入侵在即，我去看看"+taskname[n]+"的情况。\n",me,ob);
			else if (me->query("mingpin")<4)
			command("say 我朝卫所凋敝，女真人入侵在即，大人有空去看看"+taskname[n]+"的情况。");
			else
			message_vision("$N看着$n，朗声道：我朝卫所凋敝，女真人入侵在即，你且去"+taskname[n]+"吧。\n",ob,me);
		}
        if (me->query("mingpin")==1)
        pre_1pin(me);
        return 1;
    }
}



