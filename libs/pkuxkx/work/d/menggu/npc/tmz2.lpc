// tmz
// create by zine 2012
#include <ansi.h>
inherit NPC;
#include "/d/menggu/shediao_bonus.h"
int ask_job();
int ask_hate();
int ask_finish();
int ask_leave();
void create()
{
	set_name("铁木真", ({"tie muzhen","tie","muzhen"}));
	set("long", 
            HIR"他就是大名鼎鼎铁木真。\n"NOR);
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
            
			"点兵" : (: ask_job :),
            "job" : (: ask_job :),
            "仇恨" : (: ask_hate :),
            "hate" : (: ask_hate :),
			"完成" : (: ask_finish :),
			"finish" : (: ask_finish :),
			"辞行" : (: ask_leave :),
            "leave" : (: ask_leave :),
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth4")->wear();
	
}

int bye_tie(object me,object ob)
{
	if (!me||!ob)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	if (environment(me)!=environment(ob))
	{
		return 1;
	}
	command("say 好，你就到南方去走一遭，把大金国六皇子完颜洪烈的脑袋给我提来。");
	command("say 义弟和我失和，枉自送了性命，全因这厮而起。");
	if (!me->query("shediaoquest/zjk"))
	{
		message_vision("说完，$N赠给$n十斤黄金作为盘缠。\n",ob,me);
		MONEY_D->pay_player(me,1000000);
		tell_object(me,"你想了想，还是把这些钱留给李萍吧。\n");
	}
	me->set("shediaoquest/zjk",1);
	return 1;
}
int ask_leave()
{
	object me=this_player();
	object ob=this_object();
	if (me->is_busy()||me->is_fighting())
	{
		tell_object(me,"你正忙着呢。\n");
		return 1;
	}
	if (!me->query_temp("shediaoquest/zjk/farewell"))
	{
		command("say "+me->query("name")+"，好好的怎么要走了？");
		return 1;
	}
	if (me->query_temp("shediaoquest/zjk/bye_tie"))
	{
		command("say 好孩子，出去闯闯也是好的。");
		return 1;
	}
	me->set_temp("shediaoquest/zjk/bye_tie",1);
	message_vision("$N向$n请示辞行的事宜。\n",me,ob);
	call_out("bye_tie",1,me,ob);
	return 1;
}
int cele3(object me)
{
	message("chat",HIC"【闲聊】哲别(Zhe bie)：这小子，真不错。\n"NOR,users());
	return 1;
}
int cele2(object me)
{
	if (!me)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	CHANNEL_D->do_channel(this_object(), "jh", "这次的胜利，"+me->query("name")+"的功劳最高，他是我的金刀驸马！");
	CHANNEL_D->do_channel(this_object(), "jh", "众人(Every one): 金刀驸马！金刀驸马！金刀驸马……马……马……马……(回音)", -1);
	CHANNEL_D->do_channel(this_object(), "jh", "华筝公主"+"看着"+me->query("name")+"，脸上洋溢着幸福的光彩。", -1);
	call_out("cele3",1,me);
	return 1;
}
int celebrate(object me)
{
	object tuo;
	object hua,zhe;
	if (!me)
	{
		return 1;
	}
	if (!living(me))
	{
		return 1;
	}
	tuo=new(__DIR__"tuolei");
	tuo->flatter();
	destruct(tuo);
	call_out("cele2",3,me);
	return 1;
}

int ask_finish()
{
	object me=this_player();
	int e_reward;
	if (!me->query("shediaoquest/jdfm"))
	{
		if (!me->query_temp("shediaoquest/jdfm/gogogo"))
		{
			command("hmm");
			return 1;
		}
		else if (!me->query_temp("shediaoquest/jdfm/jdfm"))
		{
			command("say 速去，这是军令，做不到要行军法的。");
			return 1;
		}
		else
		{
			command("yi "+me->query("id"));
			e_reward=bonus(me,3800);
			me->add("combat_exp",e_reward);
			user_record(me,e_reward,"jdfm");
			tell_object(me,HIC"完成射雕主线任务【金刀驸马】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
			me->set("shediaoquest/jdfm",2);
			return 1;
		}
	}
	if (me->query("shediaoquest/jdfm")>=2)
	{
		command("great "+me->query("id"));
		return 1;
	}
	else
	{
		e_reward=bonus(me,5800);
		me->add("combat_exp",e_reward);
		tell_object(me,HIC"完成射雕主线任务【金刀驸马】，你被奖励了"+chinese_number(e_reward)+"点经验！\n"NOR);
		me->set("shediaoquest/jdfm",2);
		call_out("celebrate",8,me);
		return 1;
	}
}
	
int ask_job()
{
    object me=this_player();
    if (me->query("shediaoquest/jdfm"))
    {
        command("say 你就是我的金刀驸马啊！");
        return 1;
    }
    if (me->query("shediaoquest/zhebie")<2)
    {
        command("say 你还太年轻了些，杀敌肯定是不行的！");
        return 1;
    }
    if (!me->query_temp("shediaoquest/jdfm/ask_hate"))
    {
        command("say 出兵？你知道为什么要出兵吗？冒冒失失，怎么成大事？");
        return 1;
    }
    if (me->query_temp("shediaoquest/jdfm/gogogo"))
    {
        command("say 你怎么还在这里？拖拖拉拉，要被执行军法的！");
        return 1;
    }
    command("say 好！我们就出兵，教训教训躲在和林的老贼、小贼。");
    command("say "+me->query("name")+"，为了不打草惊蛇，你翻过不儿罕山，从西麓穿越中央大草原后，从北向南直接杀入和林，不得有误！");
	tell_object(me,HIW+"你用心记下大汗定下的路线，生怕误了大汗的大事。\n"+NOR);
    me->set_temp("shediaoquest/jdfm/gogogo",1);
    return 1;
}
int ask_hate()
{
    object me=this_player();
	if (me->query("shediaoquest/jdfm"))
    {
        command("say 还有啥恨啊？啥恨都让给帮我给报了，呵呵。");
        return 1;
    }
    if (me->query("shediaoquest/zhebie")<2)
    {
        command("say 你还太年轻了些，杀敌肯定是不行的！");
        return 1;
    }
    command("say 桑坤老贼，偷了我家的铁锅，还不承认，该杀！");
    command("say 都史小贼，偷看华筝洗澡未遂，还大吵大闹，该杀！");
    me->set_temp("shediaoquest/jdfm/ask_hate",1);
    return 1;
}