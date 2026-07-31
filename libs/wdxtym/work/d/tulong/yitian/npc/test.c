#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	object ling1;
	set_name("流云使", ({ "liuyun shi", "liuyun", "shi" }));
	set("long", "一个四十多岁的中年男子，装束奇异，不像\n"
		    "普通的中土人士。这便是波斯明教总教教主\n"
		    "座下排名三百七十四的流云使。\n");
	set("title", HIB "波斯总教教主座下" NOR);
	set("nickname", HIY "云风月三使" NOR);
	set("gender", "男性");
	set("age", 47);
	set("attitude", "friendly");
	set("shen_type", 1);

	set("per", 23);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 4000);
	set("max_jing", 1800);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 200);
	set("combat_exp", 1200000);

	set("chat_chance_combat", 200);
	set("chat_msg_combat", ({
		(: perform_action, "sword.xiyan" :),
		(: perform_action, "sword.guanghua" :),
		(: perform_action, "sword.lianxin" :),
		(: perform_action, "sword.canxue" :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :),
	}) );

	set_skill("literate", 100);
	set_skill("sanscrit", 300);
	set_skill("force", 230);
	set_skill("dodge", 230);
	set_skill("unarmed", 230);
	set_skill("parry", 230);
	set_skill("finger", 230);
	set_skill("strike", 230);
	set_skill("sword", 230);
	set_skill("shenghuo-ling", 250);
	set_skill("tougu-zhen", 250);
	set_skill("yinfeng-dao", 250);
	set_skill("shenghuo-xinfa", 250);
	set_skill("qiankun-danuoyi", 250);
	set_skill("sanscrit", 200);

	map_skill("dodge", "qiankun-danuoyi");
	map_skill("force", "shenghuo-xinfa");
	map_skill("finger", "tougu-zhen");
	map_skill("strike", "yinfeng-dao");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("sword", "shenghuo-ling");

	prepare_skill("strike", "yinfeng-dao");
	prepare_skill("finger", "tougu-zhen");

	create_family("波斯明教总舵", 32, "弟子");

	setup();

	if (clonep())
	{
		ling1 = find_object("/clone/book/ling1");
		if (! ling1) ling1 = load_object("/clone/book/ling1");
		if (! environment(ling1))
			ling1->move(this_object());
			ling1->wield();
	}

	carry_object(__DIR__"obj/jiaofu")->wear();
}

void init()
{
	object me;

	me = this_player();

	if (! interactive(me))
		return;

	if (living(this_object()) && present("yitian sword", me))
	{
		command("say 咦？倚天剑怎么会在你手里，看来这次中原之行没白跑了！");
		kill_ob(me);
		return;
	}

	if (living(this_object()) && present("tulong blade", me))
	{
		command("say 哼，把屠龙刀交出来，我们已经守侯多时了！");
		kill_ob(me);
		return;
	}

	if (living(this_object()) && present("shenghuo ling", me))
	{
		command("say 咦？你怎么会拿着我教的圣火令，快还给我！");
		return;
	}
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("shen") > 1000)
	{
		command("say 叽哩古拉，花不鲁鲁，你这人看上去不象是好人，开滚。");
		return -1;
	}

	if (skill != "sanscrit")
	{
		command("say 教你点我在印度学的一点东西，你还不知足啊？");
		return -1;
	}
	return 1;
}

int accept_object(object who, object ob)
{
	if (ob->query("id") == "shenghuo ling")
	{
		destruct(ob);
		if (! who->query("can_perform/shenghuo-ling/canxue"))
		{
			if (! who->query_skill("shenghuo-ling", 1))
			{
				command("say 多谢，多谢。");
				command("say 看来你并没练过这令上的东西，要不我倒是可"
					"以传授点东西给你。");
				return 1;
			} else
			if (who->query("character") != "阴险奸诈" &&
			    who->query("character") != "狡黠多变")
			{
				command("say 多谢，多谢。");
				command("say 唉，看来你的天性不适，要不我倒是可以把这"
					"令法的绝招传授与你。");
				return 1;
			} else
			if (who->query("int") < 32)
			{
				command("say 多谢，多谢。");
				command("say 唉，要不是你的悟性太低，领悟不了，我倒是"
					"可以把这令法的绝招传授与你。");
				return 1;
			} else
			if (who->query_skill("shenghuo-ling", 1) < 250)
			{
				command("say 多谢，多谢。");
				command("say 看来你并没练好这令上的武功，要不我倒是可"
					"以把这令法的绝招传授与你。");
				return 1;
			} else
			if (who->query_skill("force") < 350)
			{
				command("say 多谢，多谢。");
				command("say 唉，要不是你的内功火候不怎么足，我倒是可"
					"以把这令法的绝招传授与你。");
				return 1;
			} else
			if (who->query("max_neili") < 5000)
			{
				command("say 多谢，多谢。");
				command("say 唉，可惜你的内力修为有限，不然我倒是可以"
					"把这令法的绝招传授与你。");
				return 1;
			} else
			{
				command("say 多谢，多谢。");
				command("say 阁下武功高强，对这套令法又颇有研究，我们"
					"真是有缘。");
				command("say 倘若阁下不嫌弃，我这倒是可以教你这套令法"
					"的绝招。");
				message_vision(HIC "$N" HIC "将$n" HIC "招到身边，在"
					"耳畔悄悄嘀咕了几句，$n" HIC "听后会心的一笑"
					"，看来领悟到了什么。"NOR"\n", this_object(),
					who);
				who->set("can_perform/shenghuo-ling/canxue", 1);
				tell_object(who, HIC "你学会了圣火令法之「" NOR + HIR
					    "残血令" NOR + HIC "」。"NOR"\n");
				if (who->can_improve_skill("sword"))
					who->improve_skill("sword", 160000);
				if (who->can_improve_skill("shenghuo-ling"))
					who->improve_skill("shenghuo-ling", 160000);
				return 1;
			}
		}
		message_vision(CYN "$N" CYN "满脸欢喜的对$n" CYN "道：再次多谢将本"
			       "教的圣物还我。"NOR"\n", this_object(), who);
		return 1;
	}
	return 0;
}

