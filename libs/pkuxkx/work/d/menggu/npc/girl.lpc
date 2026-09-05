//小姑娘
//created by zine 2012

inherit NPC;
#include <ansi.h>
#include "/d/menggu/shediao_bonus.h"
int ask_job();
int ask_job2();
void create()
{
        set_name("年轻姑娘", ({ "nianqing guniang", "guniang", "girl" }) );
        set("gender", "女性" );
		set("title", "草原一枝花");
        set("age", 15+random(5));
		set("per",25);
        set("long", 
            "她是益兰州最漂亮的姑娘，最近似乎有了什么心事。\n");
        set("str", 30);
        set("dex", 10);
        set("con", 20);
        set("int", 10);
		set("shen_type", 1);
		set_skill("force", 5);
		set("combat_exp", 15000);
		set("max_qi", 500);
        set("max_jing", 100);
        set("neili", 1);
        set("max_neili", 1);
		set("attitude", "friendly");
        set("inquiry", ([
            "name" : "我不告诉你。",
			"心事" : (: ask_job :),
            "xinshi" : (: ask_job :),
			"口信" : (: ask_job2 :),
            "kouxin" : (: ask_job2 :),
            
       	]) );
        setup();
		carry_object(__DIR__"items/pixue")->wear();
		carry_object(__DIR__"items/cloth21")->wear();
		
}

int ask_job2()
{
	object me=this_player();
	int e_reward;
	if (me->query("mengguquest/xinshi"))
	{
		command("thank "+me->query("id"));
		return 1;
	}
	if (!me->query_temp("mengguquest/xinshi_f")&&me->query_temp("mengguquest/xinshi_1"))
	{
		command("say 我就知道你是骗我的，你一定没见到札儿赤兀惕大哥，男人没一个好东西。");
		return 1;
	}
	if (me->query_temp("mengguquest/xinshi_f"))
	{
		message_vision("$N把札儿赤兀惕即将回来的消息告诉了$n。\n",me,this_object());
		command("jump");
		me->delete_temp("mengguquest/xinshi_f");
		me->set("mengguquest/xinshi",1);
		e_reward=bonus(me,2000);
		me->add("potential",e_reward);
		user_record(me,e_reward,"yizhihua");
		tell_object(me,HIW"完成蒙古支线任务【一枝花的心事】，你被奖励了"+chinese_number(e_reward)+"点潜能！\n"NOR);
		return 1;
	}
}

int ask_job()
{
	object me=this_player();
	if (me->query("mengguquest/xinshi"))
	{
		command("thank "+me->query("id"));
		return 1;
	}
	if (!me->query_temp("mengguquest/xinshi_start"))
	{
		command("say 我们素不相识的，问人家心事合适吗？");
		me->add_temp("mengguquest/xinshi_start",1);
		return 1;
	}
	if (me->query_temp("mengguquest/xinshi_start")<2)
	{
		command("say 你虽然人挺好的，可是……");
		me->add_temp("mengguquest/xinshi_start",1);
		return 1;
	}
	if (me->query_temp("mengguquest/xinshi_1"))
	{
		command("say 不是告诉过你了吗，但你又不能帮忙。");
		command("angry");
		return 1;
	}
	else
	{
		message_vision("$N道：“不知姑娘因何事发愁，在下或可效劳。”\n",me,this_object());
		command("say 札儿赤兀惕大哥最近去了也儿的石河，很久都没有音讯了。");
		command("sigh");
		me->set_temp("mengguquest/xinshi_1",1);
		tell_object(me,"你心里暗想，这么漂亮的姑娘也挺可怜的，如果能帮她带信过去，也算功德一件。\n");
		return 1;
	}
}

