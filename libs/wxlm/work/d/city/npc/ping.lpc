

#include <medical.h>
inherit NPC;
inherit F_DEALER;

string ask_job();
int do_peiyao(string arg);
int working(object me);
int halt_working(object me);

void create()
{
	set_name("平易指", ({ "ping yizhi" }));
	set("title", "药铺老板");
	set("gender", "男性");
	set("long", "他就是医术高超的「杀人神医」平易指。可是他性格古怪，不是什么人都医的。\n");
	set("age", 65);
	set("int", 38);
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);
	set("combat_exp", 500000);
	set("attitude", "heroism");
	set("inquiry", ([
		"工作"   : (: ask_job :),
	]));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_peiyao", "peiyao");
}

string ask_job()
{
	object me;
	object *obs;

	me = this_player();
	if (me->query_temp("job/peiyao"))
		return "让你干的活你干完了么？";

	if (me->query("combat_exp") > 500000)
		return "让你干这活，也太屈就你了吧。";

	if (me->query("combat_exp") < 150)
		return "就这点经验，连一百五都没有，我看你来药臼都端不起来！";

	if (me->query("qi") < 5)
		return "你还是先歇歇吧，万一累出人命来我可负担不起。";

	if (! interactive(me))
		return "...";

	obs = filter_array(all_inventory(environment()),
			   (: interactive($1) &&
			      $1 != $(me) &&
			      $1->query_temp("job/peiyao") &&
			      query_ip_number($1) == query_ip_number($(me)) :));
	//if (sizeof(obs) > 50)
	//	return "我这已经有" + obs[0]->name() + "在干活了，你等等吧。";

	me->set_temp("job/peiyao", 1);
//	if(me->query("zjvip/level")&&me->query_temp("tuoguan/ping"))
		tell_object(me,ZJFORCECMD("peiyao"));
	// tell_object(me,ZJEXIT"northwest:"RED"中断"NOR":halt\n");
	return "好，你就帮我"ZJURL("cmds:peiyao")ZJSIZE(15)"配药"NOR"(peiyao)吧！喏，就这几味。";
}

int do_peiyao(string arg)
{
	object me;

	me = this_player();
	if (me->is_busy())
		return notify_fail("你正忙着呢，别着急。\n");

	if (! me->query_temp("job/peiyao"))
	{
		message_vision("$N刚想抓几味药配制，就听见$n怒喝道：给我放下，别乱动。\n",me, this_object());
		return 1;
	}
	me->set_temp("job/step", 1);
	me->start_busy(bind((: call_other, __FILE__, "working" :), me),bind((: call_other, __FILE__, "halt_working" :), me));
	tell_object(me, "你开始工作。\n");
	return 1;
}

int working(object me)
{
	object ob;
	string msg;
	int finish;
	int b;

	if (! me->query_temp("job/step"))
		me->set_temp("job/step", 1);

	if (! living(me))
	{
		me->delete_temp("job/peiyao");
		me->delete_temp("job/step");
		return 0;
	}

	finish = 0;
	me->receive_damage("qi", 1);
	switch (me->query_temp("job/step"))
	{
	case 1:
		msg = "$N东挑西拣，选好了一些药材。";
		break;
	case 2:
		msg = "$N把药材放进药臼，使劲捣了起来。";
		break;
	case 3:
		msg = "$N把药材翻了翻，继续使劲捣了起来。";
		break;
	case 4:
		msg = "$N把药材翻了翻，继续使劲捣了起来。";
		break;
	case 5:
		msg = "药材渐渐化作粉屑，混在一起。";
		break;
	case 6:
		msg = "粉屑在$N的捣弄下越来越细，逐渐变成了粉末。";
		break;
	default:
		msg = "$N把药材包好，递给$n。";
		finish = 1;
		break;
	}
	msg += "\n";

	if (finish)
	{
		msg += "$n看了$N配的药，点头道：不错，不错！这是给你的报酬！\n";
		me->delete_temp("job/peiyao");
		me->delete_temp("job/step");

		b = 10 + random(11);
		me->add("combat_exp", b);
		me->improve_potential(b/2);

		ob = new("/clone/money/coin");
		ob->set_amount(b/3);
		ob->move(me, 1);
	}
	msg = replace_string(msg, "$N", "你");
	msg = replace_string(msg, "$n", name());
	tell_object(me, msg);

	if (finish)
	{
		if (b > 0)
		{
			tell_object(me, HIC "\n你获得了" + chinese_number(b/3) + "个铜板、" + chinese_number(b) + "点经验和" + chinese_number(b/2) + "点潜能。"NOR"\n");
		}
		if (random(1000) == 1)
		{
			msg = "$n对$N嘿嘿一笑，道：干得不赖，有点意思，这个丹玉磨就算是我送给你的礼物吧。\n";
			message_vision(msg, me, this_object());
			ob = new("/clone/misc/dymo");
			ob->move(me, 1);
			tell_object(me, HIM "\n你获得了一个" + ob->name() + HIM "！"NOR"\n");
		}
//		if(me->query("zjvip/level")&&me->query_temp("tuoguan/ping"))
		if(!interactive(me)) return 0;
			tell_object(me,ZJFORCECMD("ask "+this_object()->query("id")+" about 工作"));
		return 0;
	}
	me->add_temp("job/step", 1);
	return 1;
}
int halt_working(object me)
{
	message_vision("$N把手中的活一甩，嚷嚷道：不干了，不干了！\n", me);
	me->delete_temp("job/peiyao");
	me->delete_temp("job/step");
	return 1;
}
