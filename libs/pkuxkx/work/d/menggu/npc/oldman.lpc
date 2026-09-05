// 制弓老汉
// create by zine 2012
#include <ansi.h>

inherit NPC;
#include "/d/menggu/shediao_bonus.h"
int ask_job();
int ask_trouble();
void create()
{
	set_name("老汉", ({"lao han","man","laohan","han"}));
	set("long", 
            HIW"他就是当年被草原骑兵夹裹至漠北的一个老汉，有点手艺。\n"NOR);
	set("gender", "男性");
	set("age", 50);
    set("combat_exp", 15000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	set("inquiry", ([
            "here" : "这里是桑昆的部落。",
			"帮助" : (: ask_job :),
            "help" : (: ask_job :),
			"麻烦" : (: ask_trouble :),
            "trouble" : (: ask_trouble :),
            
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth2")->wear();
	
    
}
	
int ask_trouble()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("mengguquest/arrow"))
	{
		command("thank "+me->query("id"));
		return 1;
	}
	if (me->query_temp("mengguquest/trouble"))
	{
		command("sigh");
		return 1;
	}
	command("sigh");
	command("say 桑昆想要和铁木真开战，每户要提供五扎利箭。");
	command("say 现在我年老体衰，这二十五支箭要削多久啊！");
	me->set_temp("mengguquest/trouble",1);
	return 1;
}
int ask_job()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("mengguquest/arrow"))
	{
		command("thank "+me->query("id"));
		return 1;
	}
	if (!me->query_temp("mengguquest/trouble"))
	{
		command("say 难是难了点，但也没有向陌生人开口的道理啊。");
		return 1;
	}
	if (me->query_temp("mengguquest/start"))
	{
		tell_object(me,"既然应承下来，再难也要帮人家完成。\n");
		return 1;
	}
    message_vision("$N道：“不如就让我来解决你的麻烦吧。”\n",me);
	tell_object(me,"当下，你暗中思索，按一路行来的观察，草原部落混战极为频繁。\n");
	tell_object(me,"尤其是按台山、不儿罕山口、谦利河南岸附近的牧民部落这些地方，近处还有南面的沙坡，细心搜索(zhao)应该不难发现遗落的利箭。\n");
	me->set_temp("mengguquest/start",1);
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
int dest2(object ob,object me)
{
	int e_reward;
	if (me)
	{
		if (ob->query("arrow_set"))
		{
			me->add("mengguquest/arrow_count",5);
		}
		if (ob->query("is_arrow"))
		{
			me->add("mengguquest/arrow_count",1);
		}
	}
	if (ob)
	{
		destruct(ob);
	}
	if (me->query("mengguquest/arrow_count")<25&&me->query("mengguquest/arrow_count")>0)
	{
		tell_object(me,"你总计给了老汉"+chinese_number(me->query("mengguquest/arrow_count"))+"支箭。\n");
	}
	if (me->query("mengguquest/arrow_count")>=25)
	{
		command("haha");
		message_vision("$N道：“这么快就完成了？其实我是想考验考验你。”\n",this_object());
		command("say 既然你帮了我，也不能白帮，我告诉你两个诀窍，zha <箭>可以把同类箭扎起来，方便携带。chai可以把一捆箭拆开使用。");
		e_reward=bonus(me,3000);
		me->add("potential",e_reward);
		user_record(me,e_reward,"jiejian");
		me->set("mengguquest/arrow",1);
		me->delete_temp("mengguquest");
		tell_object(me,HIW"完成蒙古支线任务【草原借箭】，你被奖励了"+chinese_number(e_reward)+"点潜能！\n"NOR);
		return 1;
	}
	return 1;
}
int accept_object(object me,object ob)
{
	object man=this_object();
	if (man->is_busy())
	{
		return notify_fail(man->name()+"正忙着呢。\n");
	}
	if (!ob->query("arrow_set")&&!ob->query("is_arrow"))
	{
		return notify_fail(this_object()->name()+"似乎没有心情理你。\n");
	}
	if (me->query("mengguquest/arrow"))
	{
		command("say 你瞧，我都不需要了，你还记得给我送箭来啊。");
		call_out("dest",1,ob);
		man->add_busy(1);
		return 1;
	}
	if (!me->query_temp("mengguquest/start"))
	{
		command("say 这个世界真是好人多啊！");
		call_out("dest",1,ob);
		man->add_busy(1);
		return 1;
	}
	if (me->query("mengguquest/arrow_count")<25)
	{
		call_out("dest2",1,ob,me);
		man->add_busy(1);
		message_vision("$N对着$n笑了笑。",this_object(),me);
		tell_object(me,"似乎这些箭还有些不够。\n");
		return 1;
	}
	if (me->query("mengguquest/arrow_count")>25)
	{
		command("say 你瞧，我都不需要了，你还记得给我送箭来啊。");
		call_out("dest",1,ob);
		man->add_busy(1);
		return 1;
	}
	return notify_fail(this_object()->name()+"对你的行为不置可否。\n");
}
