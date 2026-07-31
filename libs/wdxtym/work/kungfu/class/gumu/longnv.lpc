inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

#include <ansi.h>
#include "gumu.h"

#define YINSUO    "/clone/weapon/yinsuo"

string ask_yunv();
string ask_me();
string ask_zhen();
mixed ask_yinsuo();

void create()
{
	set_name("小龙女", ({"long nv", "long"}));
	set("gender", "女性");
	set("age", 27);
	set("long",
		"她一生爱穿白衣，当真如风拂玉树，雪裹琼苞，兼之生性清冷，\n"
		"实当得起“冷浸溶溶月”的形容。\n");
	set("attitude", "friendly");

	set("str", 21);
	set("int", 30);
	set("con", 25);
	set("dex", 26);

	set("qi", 3800);
	set("max_qi", 3800);
	set("jing", 1900);
	set("max_jing", 1900);
	set("neili", 4400);
	set("max_neili", 4400);
	set("jiali", 50);

	set("combat_exp", 1600000);
	set("score", 0);

	set_skill("force", 1800);
	set_skill("yunv-xinfa", 1800);
	set_skill("sword", 1800);
	set_skill("yunv-jian", 1800);
	set_skill("quanzhen-jian", 1700);
	set_skill("whip", 1800);
	set_skill("yinsuo-jinling", 1800);
	set_skill("dodge", 1800);
	set_skill("yunv-shenfa", 1800);
	set_skill("parry", 1800);
	set_skill("unarmed", 1600);
	set_skill("meinv-quan", 1600);
	set_skill("strike", 1600);
	set_skill("fireice-strike", 1600);
	set_skill("tianluo-diwang", 1600);
	set_skill("literate", 130);
	set_skill("qufeng", 2100);
	set_skill("medical", 2000);
	set_skill("yunv-xinjing", 2000);
	set_skill("throwing", 2000);
	set_skill("yufeng-zhen", 2000);
	set_skill("zuoyou-hubo", 2500);

	map_skill("force", "yunv-xinfa");
	map_skill("whip", "yinsuo-jinling");
	map_skill("sword", "yunv-jian");
	map_skill("dodge", "yunv-shenfa");
	map_skill("parry", "meinv-quan");
	map_skill("unarmed", "meinv-quan");
	map_skill("strike", "tianluo-diwang");
	map_skill("throwing", "yufeng-zhen");

	prepare_skill("unarmed", "meinv-quan");
	prepare_skill("strike", "tianluo-diwang");

	create_family("古墓派", 3, "弟子");

	set("book_count", 1);
	set("count", 1);
	set("yfzhen_count", 3);

	set("inquiry", ([
		"过儿"     : "他就在正厅啊。",
		"杨过"     : "过儿他就在正厅啊。",
		"风神诀"   : "嗯…这个比较复杂，还是你自己去后厅下面的密室参悟(canwu)吧。",
		"剑"       : (: ask_me :),
		"玉女剑法" : "玉女剑法和全真剑法合壁，天下无敌！\n",
		"玉女心经" : (: ask_yunv :),
		"玉蜂针"   : (: ask_zhen :),
		"银索金铃" : (: ask_yinsuo :),
	]) );

	set_temp("apply/attack", 150);
	set_temp("apply/defense", 150);
	set_temp("apply/damage", 100);
	set_temp("apply/unarmed_damage", 100);
	set_temp("apply/armor", 200);

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
		(: perform_action, "strike.wang" :),
		(: perform_action, "sword.he" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "unarmed.you" :),
	}) );

	setup();

	carry_object("/d/gumu/npc/obj/shunvjian")->wield();
	carry_object("/clone/cloth/baipao")->wear();

}

void attempt_apprentice(object ob)
{
	if (! permit_recruit(ob) )
		return;

	if (ob->query("per") < 20)
	{
		command("say 尊容实在不敢恭维，我看你还是算了吧。\n");
		return;
	}

	command("say 好吧，我就收下你这个徒弟了。\n");
	command("recruit " + ob->query("id"));
}

int recognize_apprentice(object ob, string skill)
{
	return ob->query("family/family_name") == query("family/family_name");
}

string ask_yunv()
{
	object me;
	object ob;
	mapping fam;

	me = this_player();
	if (! (fam = me->query("family")) ||
	    fam["family_name"] != "古墓派")
		return RANK_D->query_respect(me) +
		"与本派毫无瓜葛，何以问起本派的心经？";

	if (this_player()->query_skill("yunv-xinfa", 1) < 15)
		return RANK_D->query_respect(me) +
			"的玉女心法火候太浅，我不能将玉女心经交给你。";

	if (query("book_count") < 1)
		return "你来晚了，本派的玉女心经已经被人取走了。";

	add("book_count", -1);
	ob = new("/clone/book/yunvjing1");
	ob->move(me, 1);
	return "好吧，这本「玉女心经」给你了，你要好好看看。";
}

string ask_me()
{
	object ob;

	if (query("count") < 1)
		return "现在我手头也没有了。";

	add("count", -1);
	ob = new("/d/gumu/npc/obj/junzijian");
	ob->move(this_player(), 1);
	return "这柄君子剑就送给你吧。";
}

string ask_zhen()
{
	object me;
	object ob;
	mapping fam;

	me = this_player();
	if (! (fam = me->query("family")) ||
	    fam["family_name"] != "古墓派")
		return RANK_D->query_respect(me) +
		"与本派毫无瓜葛，何以问起本派暗器？";

	if (me->query_skill("yufeng-zhen", 1) < 50)
		return RANK_D->query_respect(me) +
			"的玉蜂针手法火候还不到家，拿了玉蜂针也没有什么用。";

	if (query("yfzhen_count") < 1)
		return "你来晚了，我手头的玉蜂针已经发完了。";

	add("yfzhen_count", -1);
	ob = new("/d/gumu/obj/yfzhen");
	message_vision("$N拿出一些玉蜂针递给$n。\n", this_object(), me);
	ob->move(me, 1);
	return "好吧，这些玉蜂针你先拿去用吧。";
}

void reset()
{
	set("book_count", 1);
	set("yfzhen_count", 2 + random(2));
}

void unconcious()
{
	die();
}

mixed ask_yinsuo()
{
	object me;
	object ob;
	object owner;

	me = this_player();

	if (me->query("family/family_name") != "古墓派")
		return "银索金铃是我的武器，跟你有什么关系？";

	if (me->query("family/master_id") != query("id"))
		return "只有我的弟子才能用银索金铃，你还是请回吧。";

	if (me->query("gender") != "女性")
		return "我这银索金铃不适合你，你拿去没用。";

	if (me->query_skill("yinsuo-jinling", 1) < 150)
		return "你连银索金铃都没学好，用了也等于白用。";

	ob = find_object(YINSUO);
	if (! ob) ob = load_object(YINSUO);
	owner = environment(ob);
	while (owner)
	{
		if (owner->is_character() || ! environment(owner))
			break;
		owner = environment(owner);
	}

	if (owner == me)
		return "嗯？银索金铃不就你拿着在用吗？";

	if (objectp(owner) && owner != this_object())
	{
		if (! owner->is_character())
			return "我已经把银索金铃已经借出去了。";

		if (owner->query("family/master_id") == query("id"))
			return "银索金铃现在是你的同门" +
			       owner->query("name") + "在用，你要"
			       "想用就去找他吧。";
		else
			return "我正为此事发愁呢，银索金铃现在落在了"
			       + owner->query("name") + "手中，你去"
			       "把它找回来吧。";
	}

	ob->move(this_object());
	message_vision(HIC "$N" HIC "微微一笑，道：“既然这样，我这银"
		       "索金铃你就拿去吧，行走江湖时可要小心，别把它"
		       "弄丢了！”"NOR"\n",
		       this_object(), me);
	command("give yinsuo jinling to " + me->query("id"));
	return 1;
}
