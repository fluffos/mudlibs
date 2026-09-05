// liwanshan.c
// iszt@pkuxkx, 2007-01-25

#include "setdizi.h"

#define FACTOR_FT 1.0

string ask_ganliang();
string ask_mijiu();
string ask_job();
string ask_finish();

void create()
{
	setcreate(2);
	set_name("李万山", ({ "li wanshan", "li", "wanshan" }) );
	set("gender", "男性" );
	set("age", 36);
	set("long", "这是一个肥肥矮矮的雪山弟子，一身白袍，在这里巡查饭堂。\n");

	add("inquiry", ([
		"rumors" : "听说有人在饭堂捣乱，不知是也不是？",
		"here" : "这里是凌霄城的饭堂，雪山派弟子平日在此饮食，也可以找我要干粮米酒。",
		"饭堂" : "这里是凌霄城的饭堂，雪山派弟子平日在此饮食，也可以找我要干粮米酒。",
		"捣乱" : "好啊，原来是你小子在捣乱！",
		"干粮" : (: ask_ganliang :),
		"米酒" : (: ask_mijiu :),
		"肥肥" : "你找死啊？！",
		"偷吃" : "我决不允许有人偷吃！",
		"玄冰碧火酒" : "那只是一个传说……",
		"北侠" : "我北大侠客行千秋万载，一统江湖！",
		"帮忙" : (: ask_job :),
		"干活" : (: ask_job :),
		"工作" : (: ask_job :),
		"完成" : (: ask_finish :),
	]) );
	setfamily(6);

	//干粮和米酒的计数
	set("ganliang_count", 10);
	set("mijiu_count", 10);

	//最多允许同时帮忙的人数
	set("job1", 3);
	set("job2", 3);
	set("job3", 4);
	set("job4", 4);
	set("job5", 2);
	set("job6", 2);

	setup();
	setequip();
}

void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void attempt_apprentice(object ob)
{
	setapp(ob);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() )
		return;

	if(ob->query("family/family_name") != "雪山派")
		message_vision(CYN"李万山盯着$N，上下打量了一番。\n"NOR, ob);
	else if(ob->query("combat_exp") < 140000 && !ob->query_temp("lingxiao/fantang_job"))
	{
		message_vision(CYN"李万山拍了拍$N的头道：「小兄弟来帮忙干点活罢！」\n"NOR, ob);
		if(!ob->query_temp("lingxiao/notify_ask_fantang"))
			tell_object(ob, WHT"\t你可以用"HIR"ask li about 帮忙"NOR+WHT"来领取工作。\n"NOR);
		ob->set_temp("lingxiao/notify_ask_fantang", 1);
	}
	else if(ob->query_temp("lingxiao/fantang_ok"))
	{
		message_vision(CYN"李万山拍了拍$N的头道：「小兄弟干的不错，来向我覆命么？」\n"NOR, ob);
		if(!ob->query_temp("lingxiao/notify_finish_fantang"))
			tell_object(ob, WHT"\t你可以用"HIR"ask li about 完成"NOR+WHT"来覆命。\n"NOR);
		ob->set_temp("lingxiao/notify_finish_fantang", 1);
	}
	else if(!ob->query_temp("lingxiao/fantang_job"))
		message_vision(CYN"李万山笑道：「快请坐，饿了罢？」\n"NOR, ob);
}

string ask_ganliang()
{
	object me = this_player();
	object ob;
	if( me->query("family/family_name") != "雪山派" )
		return "你非雪山派弟子，不能找我要干粮。";
	if(query("ganliang_count") <= 0)
		return "干粮已经没有了，你在这里随便吃些别的罢。";
	add("ganliang_count", -1);
	ob = new("/clone/food/ganliang");
	ob->move(me);
	message_vision("$n交给$N一大块干粮。\n", me, this_object());
	return "好，给你，拿着罢。";
}

string ask_mijiu()
{
	object me = this_player();
	object ob;
	if( me->query("family/family_name") != "雪山派" )
		return "你非雪山派弟子，不能找我要米酒。";
	if(query("mijiu_count") <= 0)
		return "米酒已经没有了，你在这里随便喝些别的罢。";
	add("mijiu_count", -1);
	ob = new("/d/city/npc/obj/jiudai");
	ob->move(me);
	message_vision("$n交给$N一个牛皮酒袋。\n", me, this_object());
	return "好，给你，拿着罢。";
}

string ask_job()
{
	object me = this_player();
	object ob;
	int exp = me->query("combat_exp");
	string msg;

	//player标记说明：
	//query("lingxiao/last_job")标记本门派中上一个任务
	//query_temp("lingxiao/fantang_job")标记饭堂任务名
	//query_temp("lingxiao/fantang_tool")标记工具名
	//query_temp("lingxiao/fantang_times")标记特定任务需完成的次数（如收拾碗筷10次）
	//query_temp("lingxiao/fantang_ok")标记饭堂任务是否完成
	//query("lingxiao/fantang/times")标记饭堂任务完成次数

	if( me->query("family/family_name") != "雪山派" )
		return RANK_D->query_respect(me) + "不是我雪山派弟子，不敢劳动您大驾。";
	if( me->query("lingxiao/last_job") == "fantang")
		return "你刚帮过忙，先去别处看看罢。";
	if( me->query_temp("lingxiao/fantang_job") )
		return "不是叫你去"+me->query_temp("lingxiao/fantang_job")+"了么？";
	if(exp > 140000 && exp < 1000000)
		return "你的武功已经有根底了，不必来这里帮忙了。";
	if(exp >= 1000000)
		return "你的武功如此高强，饭堂没什么需要帮忙的。";
	exp = exp - 20000 + random(40000);
	if(exp < 30000 && random(2) == 1 && query("job1") > 0)
	{
		me->set_temp("lingxiao/fantang_job", "收拾碗筷");
		me->set_temp("lingxiao/fantang_times", 4+random(4));
		msg = CYN"$n想了想，对$N道：「你就在饭堂帮忙"HIW"收拾碗筷"HIR"(shoushi 碗筷)"NOR
			+CYN"罢，收拾完了送到伙房去。」\n"NOR;
		add("job1", -1);
	}
	else if(exp < 30000 && query("job2") > 0)
	{
		me->set_temp("lingxiao/fantang_job", "整理桌椅");
		me->set_temp("lingxiao/fantang_times", 6+random(4));
		msg = CYN"$n想了想，对$N道：「你就在饭堂帮忙"HIW"整理桌椅"HIR"(zhengli 桌椅)"NOR
			+CYN"罢，整理完了找我覆命。」\n"NOR;
		add("job2", -1);
	}
	else if(exp < 60000 && query("job3") > 0)
	{
		me->set_temp("lingxiao/fantang_job", "烧火");
		me->set_temp("lingxiao/fantang_times", 6+random(4));
		msg = CYN"$n想了想，对$N道：「你去伙房帮忙"HIW"烧火"HIR"(shao 火)"NOR+CYN"罢。」\n"NOR;
		add("job3", -1);
	}
	else if(exp < 90000 && query("job4") > 0)
	{
		me->set_temp("lingxiao/fantang_job", "劈柴");
		me->set_temp("lingxiao/fantang_times", 6+random(5));
		msg = CYN"$n想了想，对$N道：「你拿着这柄柴刀，去伙房帮忙"HIW"劈柴"HIR"(pi 柴)"NOR+CYN"罢。」\n"NOR;
		ob = new(__DIR__"obj/chaidao");
		ob->move(me);
		msg += YEL"$n交给$N一柄柴刀。\n"NOR;
		me->set_temp("lingxiao/fantang_tool", "chai dao");
		add("job4", -1);
	}
	else if(exp < 120000 && query("job5") > 0)
	{
		me->set_temp("lingxiao/fantang_job", "运柴火");
		msg = CYN"$n想了想，对$N道：「你去柴火店帮忙"HIW"运柴火"NOR+CYN"来罢。向柴火店掌柜的打听\n"
			HIR"(ask zhanggui about 柴火)"NOR+CYN"，他就会给你一辆小车，赶"HIR"(gan)"NOR+CYN"过来就行了。」\n"NOR;
		add("job5", -1);
	}
	else if(query("job6") > 0)
	{
		me->set_temp("lingxiao/fantang_job", "取水");
		msg = CYN"$n想了想，对$N道：「你拿着这个水瓢"HIW"取水"NOR
			+CYN"罢，找干净的雪舀"HIR"(yao 雪)"NOR+CYN"一些回来就行。」\n"NOR;
		ob = new(__DIR__"obj/shuipiao");
		ob->move(me);
		msg += YEL"$n交给$N一把水瓢。\n"NOR;
		me->set_temp("lingxiao/fantang_tool", "shui piao");
		add("job6", -1);
	}
	else
		msg = CYN"$n想了想，对$N道：「我这里暂时没什么需要帮忙的，多谢你了。」\n"NOR;
	message_vision(msg, me, this_object());

	return "小兄弟快去罢！";
}

string ask_finish()
{
	object me = this_player();
	int exp_reward;
	int pot_reward;
	int score_reward;
	string msg;

	if(!me->query_temp("lingxiao/fantang_job"))
		return "你又没有任务，来完成什么？";
	if(!me->query_temp("lingxiao/fantang_ok"))
		return "你还没干完活，别想偷懒。";
	if(me->query_temp("lingxiao/fantang_tool"))
		return "你先把工具还回来。";

	message_vision(HIY"$n满意的拍了拍$N的肩，道：「干得好！」\n"NOR, me, this_object());

	//奖励设计：连续做的话每分钟500~1k exp，增加1 score
	//总体受FACTOR_FT调控
	switch(me->query_temp("lingxiao/fantang_job"))
	{
	case "收拾碗筷":
		exp_reward = 100 + random(100);
		pot_reward = 15 + random(40);
		score_reward = (random(4)==1);
		add("job1", 1);
		break;
	case "整理桌椅":
		exp_reward = 100 + random(100);
		pot_reward = 15 + random(40);
		score_reward = (random(4)==1);
		add("job2", 1);
		break;
	case "烧火":
		exp_reward = 200 + random(100);
		pot_reward = 50 + random(40);
		score_reward = (random(2)==1);
		add("job3", 1);
		break;
	case "劈柴":
		exp_reward = 350 + random(300);
		pot_reward = 100 + random(80);
		score_reward = (random(2)==1);
		add("job4", 1);
		break;
	case "运柴火":
		exp_reward = 500 + random(1000);
		pot_reward = 200 + random(100);
		score_reward = random(3);
		add("job5", 1);
		break;
	case "取水":
		exp_reward = 1000 + random(1000);
		pot_reward = 200 + random(400);
		score_reward = 1+random(2);
		add("job6", 1);
		break;
	default:
		break;
	}
	exp_reward = FACTOR_FT * exp_reward;
	pot_reward = FACTOR_FT * pot_reward;

	me->add("combat_exp", exp_reward);
	me->add("exp/lingxiao/fantang", exp_reward);
	me->add("potential", pot_reward);
	me->add("pot/lingxiao/fantang", pot_reward);
	me->add("score", score_reward);

	me->set("lingxiao/last_job", "fantang");
	me->add("lingxiao/fantang/times", 1);
	me->delete_temp("lingxiao/fantang_ok");
	me->delete_temp("lingxiao/fantang_job");
	me->delete_temp("lingxiao/fantang_times");

	msg = HIW"你被奖励了：\n";
	msg += chinese_number(exp_reward) + "点经验；\n";
	msg += chinese_number(pot_reward) + "点潜能";
	if(score_reward)
		msg += "；\n" + chinese_number(score_reward) + "点师门忠诚";
	msg += "。\n";
	msg += "你已经在饭堂帮忙" + chinese_number(me->query("lingxiao/fantang/times")) + "次。\n"NOR;

	tell_object(me, msg);

	return "辛苦你了，下去休息罢！";
}

int accept_object(object me,object ob)
{
	if(ob->query("id") == "chai dao")
	{
		me->delete_temp("lingxiao/fantang_tool");
		return 1;
	}
	if(ob->query("id") == "shui piao")
	{
		if(!ob->query("snow_got"))
			return notify_fail("你还这个空瓢做什么？\n");
		me->delete_temp("lingxiao/fantang_tool");
		return 1;
	}
	return 0;
}