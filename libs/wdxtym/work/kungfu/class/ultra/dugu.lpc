// huang 黄裳

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_NOCLONE;

mixed ask_opinion();

#define ULTRA_OPINION   "宗师"
#define OPINION_TYPE    HIY "兵器功夫" NOR 
#define MY_OPINION      "weapon"

string  *my_opinions = ({ "sword", "blade", "staff", "hammer",
			  "club", "whip",  "dagger", });

// 该头文件必须在这里嵌入
#include "ultra.h"

void check_weapon();

void create()
{
	set_name("独孤求败", ({ "dugu qiubai", "dugu" }) );
	set("title", HIC "四大天王" NOR);
	set("gender", "男性");
	set("age", 48);
	set("long", "此人诚恳敦厚，眉目菱角分明，气宇轩昂。\n");
	set("attitude", "peaceful");
	set("str", 99);
	set("int", 99);
	set("con", 99);
	set("dex", 99);

	set("max_qi", 999999);
	set("max_jing", 999999);
	set("neili", 999999);
	set("max_neili", 999999);
	set("jiali", 999999);

	set("combat_exp", 999999999);

	set("inquiry", ([
		"独孤九剑" : "我把天下武功的变化归结在九剑之中，算不得是剑法，若拘泥于形势就无法理解其中奥妙。",
		"评价"     : (: ask_opinion :),
		"武学修养" : "武学修养(martial-cognize)乃武术大义，可谓是以一通通百通！",
	]));

	set_skill("unarmed", 9999);
	set_skill("sword", 9999);
	set_skill("blade", 9999);
	set_skill("staff", 9999);
	set_skill("hammer", 9999);
	set_skill("club", 9999);
	set_skill("whip", 9999);
	set_skill("dagger", 9999);
	set_skill("throwing", 9999);
	set_skill("parry", 9999);
	set_skill("dodge", 9999);
	set_skill("xinfa", 9999);
	set_skill("force", 9999);
	set_skill("never-defeated", 9999);
	set_skill("martial-cognize", 9999);

	map_skill("xinfa", "never-defeated");

	set("opinion/ultra",  1);
	set("opinion/master", 1);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: check_weapon :),
	}) );

	set("rank_info/self", "在下");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
	carry_object("/clone/weapon/zhujian")->wield();

	set("startroom", "/d/huashan/shandong");
	check_clone();
}

void init()
{
	object me;

	if (! interactive(me = this_player()))
		return;

	me->delete_temp("want_opinion");
	if (ultrap(me))
	{
		message_vision("$N微微一笑，对$n点了点头。\n", this_object(), me);
	}
}

void check_weapon()
{
	if (objectp(query_temp("weapon")))
		return;

	message_vision("$N长叹一口气道：我$N多年来兵器还从未离过手，罢！罢了！我去也！\n", this_object());
	destruct(this_object());
}

mixed ask_opinion()
{
	object me;
	object ob;

	me = this_player();

	if (me->query("combat_exp") < 5000000)
		return "呵呵，你这点武功还谈什么评价？";

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
		return "哈哈，你兵器方面的修为已经称得上是宗师了！咱们要不要过过招？";

	if (is_fighting(me))
		return "哈哈，废什么话，打赢了我，你自己给自己评价吧！";

	if (me->is_fighting())
		return "你等会儿吧！待我赶走他们。";

	if (objectp(ob = query_temp("opinion")))
	{
		if (ob == me)
		{
			command("say 你着什么急？不要烦我。");
			return 1;
		}

		message_vision("$N正在沉思，没有回答$n，只是摆了摆手。\n", this_object(), me);
		return 1;
	}

	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	message_vision("\n$N点点头道：“好了，你先等会儿，待我想想。”\n",this_object(), me);

	return 1;
}

int calc_level(object me, string skill)
{
	int lvl;
	string sp;
	mapping action;

	lvl = me->query_skill(skill, 1) / 2;
	sp = me->query_skill_mapped(skill);
	if (! sp) return lvl;

	lvl += me->query_skill(sp, 1);
	action = SKILL_D(sp)->query_action(me, me->query_temp("weapon")); 
	if (mapp(action))
		lvl += (action["force"] + action["parry"] + action["dodge"] - 250) / 10;
	return lvl;
}

void do_congration(object me)
{
	command("chat 这位" + RANK_D->query_respect(me) + "可要善自珍重，须知强中更有强中手。");
}

int accept_hit(object me)
{
	if (me->query_temp("want_hit/dugu") >= 2)
	{
		command("heng");
		command("say 事不过三，你要找死那就去死吧！");
		kill_ob(me);
		return 1;
	}

	command("shake");
	command("say 这位" + RANK_D->query_respect(me) + "，练武之人切忌贸然挑衅。");
	me->add_temp("want_hit/dugu", 1);
	return 0;
}

int accept_fight(object me)
{
	object weapon;

	if (me->query("opinion/" MY_OPINION) == ULTRA_OPINION)
	{
		message_vision("$N大喜，对$n道：“很好，近年我还没有和宗师高手过过招，来吧！”\n",
			       this_object(), me);
		return 1;
	}

	if (! me->query_temp("want_opinion/dugu"))
	{
		command("say 平白无故动什么手？");
		return 0;
	}

	if (! objectp(weapon = me->query_temp("weapon")))
	{
		command("say 没兵器你动什么手？");
		return 0;
	}

	if (me->query("qi") * 100 / me->query("max_qi") < 80||
	    me->query("jing") * 100 / me->query("max_jing") < 80)
	{
		command("say 你现在状态不佳，等休息好了再说吧！");
		return 0;
	}

	command("nod");
	COMBAT_D->do_attack(me, this_object(), weapon);
	COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));

	if (me->query("qi") <= 0)
	{
		message_vision("\n$N摇摇头对$n道：“你现在的武功还差得远，连我一招都接不住！”\n",this_object(), me);
		return notify_fail("看来要好好的修炼功夫了。\n");
	}

	call_out("check_opinion", 2, me);
	set_temp("opinion", me);
	me->delete_temp("want_opinion");
	message_vision("\n$N点点头道：“好了，你先等会儿，待我想想。”\n",this_object(), me);
	return notify_fail("看来不能心急，还得等一会儿。\n");
}

int accept_kill(object me)
{
	if (me->query("combat_exp") < 500000)
	{
		message_vision("$N大怒道：“无名小辈捣什么"
			       "乱？给我滚！”说罢一掌把$n劈倒在地。\n",
			       this_object(), me);
		me->unconcious();
		return -1;
	}
	command("sigh");
	command("say 很好！近年还真没有遇到什么敢和我较量的高手！");
	return 1;
}

int recognize_apprentice(object me, string skill)
{
	if (me->query("character") != "狡黠多变")
	{
		command("say 我看你的性格不够机智灵活，不适宜向我学习武功，还是算了吧！");
		return -1;
	}

	if (skill == "martial-cognize")
		return 1;

	if (! ultrap(me))
	{
		command("say 想学我的不败神功？你还不够资格，等你成了大宗师再说吧！");
		return -1;
	}

	if (me->query_skill(skill, 1) >= 180)
	{
		command("say 够了！我就教你到这里吧，武功还是要靠自己多研究才是！");
		return -1;
	}

	if (skill != "never-defeated")
		return 1;

	if (me->query_temp("can_learn/dugu/never-defeated"))
		return 1;

	me->set_temp("can_learn/dugu/never-defeated", 1);
	command("nod");
	command("say 我可以教你我多年领悟出来的不败神功，可是你能不能学，还要看你的机缘了！");
	return 1;
}

void unconcious()
{
	message("vision", "\n"HIR + name() + "脸色一变，吐了一口鲜"
		"血，身形一闪，消逝不见。"NOR"\n", environment());
	command("chat 罢！罢！罢！在下去也！");
	destruct(this_object());
}

void die()
{
	message("vision", "\n"HIR + name() + "大叫一声，狂吐了一口鲜"
		"血，身形一闪，就此不见。"NOR"\n", environment());
	command("chat 在下去也！");
	destruct(this_object());
}
