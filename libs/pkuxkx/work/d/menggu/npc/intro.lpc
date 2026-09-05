//intro_menggu
//created by zine 2012

inherit NPC;
#include <ansi.h>
#include "/d/menggu/shediao_bonus.h"
int ask_job();
void create()
{
        set_name("汉人牧民", ({ "hanren mumin", "mumin", "min" }) );
        set("gender", "男性" );
		set("title", "蒙古百事通");
        set("age", 40+random(5));
		set("per",15);
        set("long", 
            "他是一个汉人牧民，偶尔也在蒙古放牧，关于蒙古的信息可以通过他来了解。\n");
        set("str", 30);
        set("dex", 10);
        set("con", 20);
        set("int", 10);
		set("shen_type", 1);
		set_skill("force", 25);
		set("combat_exp", 40000);
		set("max_qi", 800);
        set("max_jing", 500);
        set("neili", 100);
        set("max_neili", 100);
		set("attitude", "friendly");
        set("inquiry", ([
            "here" : "蒙古的事，没有我不知道的。",
			"介绍" : (: ask_job :),
            "jieshao" : (: ask_job :),
            
       	]) );
        setup();
		carry_object(__DIR__"items/pixue")->wear();
		carry_object(__DIR__"items/cloth22")->wear();
		
}

int intro2(object me)
{
	object ob=this_object();
	if (!me)
	{
		return 1;
	}
	if (environment(me)!=environment(ob))
	{
		return 1;
	}
	command("say 分隔蒙古几块区域的草原和沙漠地形瞬间多变。");
	command("say 不过也不用过于担心，进入之前问问老年牧人，他们会告诉你该怎么通行的。");
	command("say 天气最差的时候是无法通过草原和沙漠的，不过天气多变，很快就会转好。");
	command("say 蒙古包里都可以睡觉，在铁木真部落的东面和益兰州都有汉人商人可以帮助存钱取钱，铁木真的金帐和益兰州的广场可以存盘。");
	command("say 你现在还有什么不明白吗？如果准备好了，输入ready，我就提问了。");
	me->add_temp("mengguquest/getintro",1);
	return 1;
}

int intro(object me)
{
	object ob=this_object();
	if (!me)
	{
		return 1;
	}
	if (environment(me)!=environment(ob))
	{
		return 1;
	}
	command("say 射雕英雄有五个主线任务，分别是大漠风云，拜师哲别，射雕英雄，悬崖传功和金刀驸马。");
	command("say 他们对自身级别有一定的要求，特别是金刀驸马有一定的风险，需要慎重慎重。");
	command("say 大漠风云的起点是郭靖家，拜师哲别的起点是郭靖家门口，射雕英雄的起点是射箭场，悬崖传功的起点是一处悬崖前，金刀驸马的起点则是铁木真的金帐。");
	command("say 此外，蒙古地区尚有若干个支线任务，可以在不儿罕山的主峰通过look shi来查询。");
	message_vision("$N又喝了口水，又润了润嗓子，继续开讲……\n",ob);
	call_out("intro2",2,me);
	return 1;
}

int ask_job()
{
	object me=this_player();
	object ob=this_object();
	if (me->query("mengguquest/intro"))
	{
		command("say 基本上我知道的你都知道了。");
		return 1;
	}
	if (time()-ob->query("intro")<10)
	{
		command("say 我这会儿有些口干舌燥的，等会再说。");
		return 1;
	}
	if (me->query_temp("mengguquest/getintro")>3)
	{
		command("say 逗我玩吧？问了又问的。");
		return 1;
	}
	ob->set("intro",time());
	command("say 蒙古是一块很大的区域，被三片大草原和库布齐沙漠分隔开来。");
	command("say 蒙古东部由科尔沁草原连着张家口，是铁木真的地盘。");
	command("say 蒙古中部是桑昆的部落，虽然不如铁木真强盛，却占着最好的草场。");
	command("say 蒙古北部的益兰州最是神秘莫测，大泽深处有些什么，连我也不知道。");
	message_vision("$N喝了口水，润了润嗓子，继续开讲……\n",ob);
	call_out("intro",2,me);
	return 1;
}

int question_6(string arg,object me)
{
	int e_reward;
	object ob=this_object();
	if (arg=="D"||arg=="d"||arg=="金帐")
	{
		command("ah");
		command("say 全部答对了！");
		me->set("mengguquest/intro",1);
		e_reward=bonus(me,800);
		me->add("potential",e_reward);
		user_record(me,e_reward,"chushi");
		tell_object(me,HIW"完成蒙古支线任务【初识蒙古】，你被奖励了"+chinese_number(e_reward)+"点潜能！\n"NOR);
		ob->delete("asking");
		return 1;
	}
	else
	{
		write("答错了，这题正确答案是D，请用ready重新开始答题吧。\n");
		ob->delete("asking");
		me->delete_temp("mengguquest/answer");
		return 1;
	}
}

int question_5(string arg,object me)
{
	object ob=this_object();
	if (arg=="A"||arg=="a"||arg=="老年牧人")
	{
		write(ob->name()+"道：回答正确，下一题金刀驸马quest在哪开始？\nA,大泽 B,荒原 C,益兰州 D,金帐\n");
		input_to((:question_6:),me);
		return 1;
	}
	else
	{
		write("答错了，这题正确答案是A，请用ready重新开始答题吧。\n");
		ob->delete("asking");
		me->delete_temp("mengguquest/answer");
		return 1;
	}
}

int question_4(string arg,object me)
{
	object ob=this_object();
	if (arg=="D"||arg=="d"||arg=="不儿罕山")
	{
		write(ob->name()+"道：回答正确，下一题进入草原和沙漠之前应该先问谁？\nA,老年牧人 B,中年牧人 C,青年牧人 D,少年牧人\n");
		input_to((:question_5:),me);
		return 1;
	}
	else
	{
		write("答错了，这题正确答案是D，请用ready重新开始答题吧。\n");
		ob->delete("asking");
		me->delete_temp("mengguquest/answer");
		return 1;
	}
}

int question_3(string arg,object me)
{
	object ob=this_object();
	if (arg=="B"||arg=="b"||arg=="张家口")
	{
		write(ob->name()+"道：回答正确，下一题在哪里查看支线任务？\nA,金帐 B,蒙古包 C,科尔沁草原 D,不儿罕山\n");
		input_to((:question_4:),me);
		return 1;
	}
	else
	{
		write("答错了，这题正确答案是B，请用ready重新开始答题吧。\n");
		ob->delete("asking");
		me->delete_temp("mengguquest/answer");
		return 1;
	}
}

int question_2(string arg,object me)
{
	object ob=this_object();
	if (arg=="C"||arg=="c"||arg=="3")
	{
		write(ob->name()+"道：回答正确，下一题蒙古由科尔沁草原连着哪里？\nA,北京 B,张家口 C,晋阳 D,扬州\n");
		input_to((:question_3:),me);
		return 1;
	}
	else
	{
		write("答错了，这题正确答案是C，请用ready重新开始答题吧。\n");
		ob->delete("asking");
		me->delete_temp("mengguquest/answer");
		return 1;
	}
}

int question_1(string arg,object me)
{
	object ob=this_object();
	if (arg=="A"||arg=="a"||arg=="5")
	{
		write(ob->name()+"道：回答正确，下一题蒙古区域有几片草原？\nA,1 B,2 C,3 D,4\n");
		input_to((:question_2:),me);
		return 1;
	}
	else
	{
		write("答错了，这题正确答案是A，请用ready重新开始答题吧。\n");
		ob->delete("asking");
		me->delete_temp("mengguquest/answer");
		return 1;
	}
}

int answer(object me)
{
	object ob=this_object();
	if (!me)
	{
		return 1;
	}
	if (environment(me)!=environment(ob))
	{
		return 1;
	}
	write(ob->name()+"问道：射雕英雄在蒙古地区有几个主线任务？\nA,5 B,8 C,4 D,6\n");
    input_to((:question_1:),me);
	return 1;
}

int do_ready()
{
	object me=this_player();
	object ob=this_object();
	if (!me->query_temp("mengguquest/getintro"))
	{
		return 0;
	}
	if (me->query("mengguquest/intro"))
	{
		command("say 基本上我知道的你都知道了，不用再回答了。");
		return 1;
	}
	if (me->query_temp("mengguquest/answer"))
	{
		return 0;
	}
	if (ob->query("asking"))
	{
		command("等会再来，我还忙着呢。");
		return 1;
	}
	tell_object(me,ob->query("name")+"准备你问题了，请用A,B,C或D作答。\n");
	me->set_temp("mengguquest/answer",1);
	ob->set("asking",1);
	call_out("answer",1,me);
	return 1;
}

void init()
{
	add_action("do_ready","ready");
}