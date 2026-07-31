// zhu.c 朱熹

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

string ask_buy();
string ask_job();
int  do_copy(string arg);
int do_answer();
int  working(object me);
int  halt_working(object me);

void create()
{
	set_name("朱熹", ({ "zhu xi" }));
	set("long", "朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
	set("age", 65);
	set("no_get", 1);
	set_skill("literate", 500);
	 set("teacher",1);
	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	set("inquiry", ([
	    "买书" : (: do_answer :),
	    "抄书" : (: ask_job :),
	    "借书" : "借？你不还我到哪里找你？哼！",
	]));
	set("vendor_goods", ({
		"/clone/book/lbook1",
		"/clone/book/lbook2",
		"/clone/book/lbook3"
	}));
	setup();

	set("chat_chance", 1);
	set("chat_msg", ({
		"朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
}

void init()
{
	add_action("do_copy", "copy");
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

int do_answer()
{
	::do_list();
	write(name() + HIR"在你耳边轻声说道：我这可真是货真价实，童叟无欺啊！"NOR"\n");
	return 1;
}

int recognize_apprentice(object ob)
{
	if (ob->query_temp("mark/朱") < 1)
		return 0;

	ob->add_temp("mark/朱", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (! who->query_temp("mark/朱"))
		who->set_temp("mark/朱", 0);

	if (ob->query("money_id") && ob->value() >= 2000)
	{
		message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
		    destruct(ob);
		return 1;
	}

	command("say 看清楚学规，请教学问至少要二十两白银！");
	return 0;
}

void auto_copy(object me)
{
	if(!interactive(me)) return;
	if(!me->query_temp("pending/auto_copy"))
		return;
	if(me->is_busy())
		call_out("auto_copy",1,me);
	else if( (int)me->query("qi") < 50||(int)me->query("jing") < 50 )
	{
		tell_object(me,"体力不足，休息中。。。\n");
		call_out("auto_copy",10,me);
	}
	else
	{
		tell_object(me,"托管中，继续抄书。。。。。。\n");
		tell_object(me,ZJFORCECMD("ask "+this_object()->query("id")+" about 抄书"));
	}
}

string ask_job()
{
	object me;
	object *obs;

	me = this_player();
	if (me->query_temp("job/copy"))
		return "让你抄的书你抄完了？";

	if (me->query("combat_exp") < 1)
		return "虽然我这里只是抄抄书，可是你战斗修为这么差，要是有小流氓捣乱你怎么办？";

	if (me->query("combat_exp") > 500000)
		return "大侠你也来抄书？真是屈就您了，慢走啊！";

	if (me->query("qi") < 20)
		return "我看你脸色不行啊，先歇会儿吧，我可不想抄书抄出人命来。";

	if (me->query("jing") < 10)
		return "我看你精神不行啊，能抄得了书么？";

	if (me->query_int() < 25 && me->query_skill("literate", 1) < 1)
		return "我说你脑子这么笨！也来抄书？";

	if (! interactive(me))
		return "...";

	obs = filter_array(all_inventory(environment()),
			   (: interactive($1) && $1 != $(me) && $1->query_temp("job/copy") && query_ip_number($1) == query_ip_number($(me)) :));
	//if (sizeof(obs) > 0)
	//	return "我这已经有" + obs[0]->name() + "在干活了，你等等吧。";

	me->set_temp("job/copy", 1);
	tell_object(me,ZJFORCECMD("copy"));
	tell_object(me,ZJEXIT"northwest:"RED"中断抄书"NOR":halt\n");
	return "好，你就帮我"ZJURL("cmds:copy")ZJSIZE(15)"抄书"NOR"(copy)吧！笔墨纸砚在这儿。";
}

int do_copy(string arg)
{
	object me;

	me = this_player();
	if (me->is_busy())
		return notify_fail("你正忙着呢，别着急。\n");

	if (! me->query_temp("job/copy"))
	{
		message_vision("$N摸起毛笔，刚想蘸墨，就听见$n大喝道：给我放下，别乱动文房四宝。\n",me, this_object());
		return 1;
	}

	me->set_temp("job/step", 1);
	me->set_temp("pending/auto_copy", 1);
	me->start_busy(bind((: call_other, __FILE__, "working" :), me),
		       bind((: call_other, __FILE__, "halt_working" :), me));
	tell_object(me, "你开始工作。\n");
	return 1;
}

int working(object me)
{
	string msg;
	int finish;
	int b;

	if (! me->query_temp("job/step"))
		me->set_temp("job/step", 1);

	if (! living(me))
	{
		me->delete_temp("job/copy");
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("jing", 1);
	me->receive_damage("qi", 2);
	switch (me->query_temp("job/step"))
	{
	case 1:
		msg = "$N拿过砚台，慢慢地研墨。";
		break;
	case 2:
		msg = "$N看看墨磨得差不多了，摸起毛笔，轻轻哈了两口气。";
		break;
	case 3:
		msg = "$N饱蘸墨汁，翻开四书，摊开纸张，开始誊写。";
		break;
	case 4:
	case 6:
		msg = "$N聚精会神的抄写书籍。";
		break;
	case 5:
		msg = "$N蘸了蘸墨，继续仔细地抄写。";
	case 7:
		msg = "$N不断翻动着书籍，纸张越来越厚。";
		break;
	default:
		msg = "$N把书籍抄好，将纸上墨吹干，装订成册，递给$n。";
		finish = 1;
		break;
	}
	msg += "\n";

	if (finish)
	{
		object ob;
		msg += "$n看了$N抄写的书，满意道：还行，儒子可教！"
		       "这是给你的报酬！你可以在我这里学点文化。\n";
		me->delete_temp("job/copy");
		me->delete_temp("job/step");

		b = 10 + random(11);
		me->add_temp("mark/朱", 20);
		me->add("combat_exp", b);
		me->improve_potential((b * 1) / 3);

		if (me->query_skill("literate", 1) < 100)
			me->improve_skill("literate", (b + 1) / 2);

		ob = new("/clone/money/coin");
		ob->set_amount(5);
		ob->move(me, 1);
	}

	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

	if (finish)
	{
		if (b > 0)
		{
			tell_object(me, HIC "\n你获得了5个铜板、" + chinese_number(b) + "点修为和" + chinese_number((b * 1) / 3) + "点潜能。"NOR"\n");
		}
//		if(me->query("zjvip/level")&&me->query_temp("tuoguan/zhu"))
			call_out("auto_copy",1,me);
		return 0;
	}

	me->add_temp("job/step", 1);
	return 1;
}

int halt_working(object me)
{
	message_vision("$N把手中的笔墨纸砚丢到一旁，牢骚道：什么呀，根本就不是人干的活！\n", me);
	me->delete_temp("job/copy");
	me->delete_temp("pending/auto_copy");
	me->delete_temp("job/step");
	return 1;
}
