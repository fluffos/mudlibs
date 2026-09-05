// alucar，感谢alucar完成最为复杂的蒙古地图，特设立quest一项以资感谢
// create by zine 2012
#include <ansi.h>

inherit NPC;
#include "/d/menggu/shediao_bonus.h"
int ask_job();
int ask_leave();
void create()
{
	set_name("大隐士", ({"da yinshi","yinshi","shi"}));
	set("title",HIW+"仙风道骨"+NOR);
	set("long", 
            HIW"他是隐居在不儿罕山中的一个大隐士。\n"NOR);
	set("gender", "男性");
	set("age", 101);
    set("combat_exp", 100000000);
    set_skill("unarmed", 2000);
    set_skill("force", 2500);
    set_skill("dodge", 2500);
    set_temp("apply/attack", 300);
    set_temp("apply/defense", 400);
	set("max_qi",600000);
	set("qi",600000);
	set("max_jing",600000);
	set("jing",600000);
	set("shen_type", 1);
	set("inquiry", ([
			"兴趣" : (: ask_job :),
            "interest" : (: ask_job :),
			"离开" : (: ask_leave :),
            "leave" : (: ask_leave :),
            
       	]) );
	setup();
	carry_object(__DIR__"items/pixue2")->wear();
	carry_object(__DIR__"items/cloth23")->wear();
	
    
}
int ask_leave()
{
	object me=this_player();
	if (time()-me->query("menggu_yinzhe_askleave")<5)
	{
		message_vision("$N转过身去，不再理睬你。\n",this_object());
		return 1;
	}
	me->query("menggu_yinzhe_askleave",time());
	command("say 想走了？出了这屋子直接向上爬(climb up)就是了。");
	return 1;
}
int ask_job()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("mengguquest/yinzhe_finish"))
	{
		command("say 有空的时候就来和老哥我聚聚。");
		return 1;
	}
	if (me->query_temp("mengguquest/yinzhe_start"))
	{
		command("say 你行吗？");
		return 1;
	}
	me->set_temp("mengguquest/yinzhe_start",time());
	tell_object(me,ob->name()+"道：“我在这住了几十年了，别的没啥嗜好，就像尝一下镇江的"+HIR+"清炖蟹粉狮子头"+NOR+"。”\n");
	command("whisper "+me->query("id")+" 拜托拜托啦。");
	return 1;
}

int dest(object ob)
{
	if (ob)
	{
		destruct(ob);
	}
	return 1;
}

int accept_object(object me,object ob)
{
	int e_reward;
	if (me->query("mengguquest/yinzhe_finish"))
	{
		return notify_fail(this_object()->name()+"道：“有空时候多来看看老哥。”\n");
	}
	if (!me->query_temp("mengguquest/yinzhe_start"))
	{
		return notify_fail(this_object()->name()+"对这个毫无兴趣。\n");
	}
	if (!ob->query("yinzhe_prefer"))
	{
		return notify_fail(this_object()->name()+"对这个毫无兴趣。\n");
	}
	else
	{
		if (ob->query("init_time")<me->query_temp("mengguquest/yinzhe_start"))
		{
			return notify_fail(this_object()->name()+"道：“可惜，放置的时间太久了，全无一点鲜味了。”\n");
		}
		else
		{
			message_vision("看着$N拿出的"+ob->query("name")+"，$n笑得合不拢嘴了。\n",me,this_object());
			me->delete_temp("mengguquest/yinzhe_start");
			me->delete_temp("mengguquest/yinzhe/clue");
			call_out("dest",1,ob);
			e_reward=bonus(me,1200);
			me->add("potential",e_reward);
			user_record(me,e_reward,"yinzhe");
			me->set("mengguquest/yinzhe_finish",1);
			tell_object(me,HIW"完成蒙古支线任务【寻隐者不遇】，你被奖励了"+chinese_number(e_reward)+"点潜能！\n"NOR);
			return 1;
		}
	}
	return notify_fail(this_object()->name()+"对这个毫无兴趣。\n");
}
