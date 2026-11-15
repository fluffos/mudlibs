// zhuo.c 卓步凡



inherit NPC;

mixed ask_me();

void create()
{
	set_name("卓步凡", ({ "zhuo bufan", "zhuo", "bufan"}));
	set("gender", "男性");
	set("title", "一字慧剑门门主");
	set("nickname", HIY "剑神" NOR);
	set("age", 37);
	set("long", @LONG
三十三年前，一字慧剑门满门师徒给童姥杀得精光，当时卓不
凡不在福建，幸免于难，从此再也不敢回去，逃到长白山中荒僻极
寒之地苦研剑法，无意中得了前辈高手遗下来的一部剑经，勤练三
十年，终于剑术大成，自信天下无敌。
LONG );
	set("attitude", "peaceful");
	set("str", 32);
	set("int", 31);
	set("con", 33);
	set("dex", 31);
    
	set("qi", 4500);
	set("max_qi", 4500);
	set("jing", 2200);
	set("max_jing", 2200);
	set("neili", 4800);
	set("max_neili", 4800);
	set("jiali", 120);
	set("combat_exp", 2200000);

	set_skill("force", 220);
	set_skill("hunyuan-yiqi", 220);
	set_skill("sword", 230);
	set_skill("zhougong-jian", 230);
	set_skill("dodge", 210);
	set_skill("feiyan-zoubi", 210);
	set_skill("strike", 225);
	set_skill("liuyang-zhang", 225);
	set_skill("parry", 230);

	map_skill("force", "hunyuan-yiqi");
	map_skill("sword", "zhougong-jian");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("parry", "zhougong-jian");
	map_skill("strike", "liuyang-zhang");

	prepare_skill("strike", "liuyang-zhang");

	set("inquiry", ([
		"剑芒"     : (: ask_me :),
		"绝招"     : (: ask_me :),
		"天山宫主" : "她杀尽我一字慧剑门满门师徒，幸亏她死得早？",
		"虚竺"     : "他是我们灵鹫宫新的门主，我们全部听他号令。",
		"虚竺子"   : "他是我们灵鹫宫新的门主，我们全部听他号令。",
		"剑法"     : "我的周公剑天下无双，除了门主，没第二人能够敌过。",
	]));

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mang" :),
		(: exert_function, "recover" :),
	}) );

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
	if (interactive(ob) && (!ob->query("family") ||
	   ob->query("family")["master_name"] != "虚竺"))
	{
		command("heng");
		command("say 你是什么东西？竟想习我精妙的剑法！\n");
		return -1; 

	}
	if (skill != "zhougong-jian" && skill != "sword")
	{
		command("shake");
		command("say 我号称剑神，也只能传授你一些剑法。");
		return -1;
	}
	if (! ob->query_temp("can_learn/zhuobufan"))
	{
		command("say 好！你既然感兴趣，又是主公的弟子，我就教你这套周公剑！");
		ob->set_temp("can_learn/zhuobufan", 1);
	}
	return 1;
}

mixed ask_me()
{
	object me;

	me = this_player();
	if (me->query("can_perform/zhougong-jian/mang"))
		return "自己好好多练习吧！";

	if (me->query("family/master_name") != "虚竺" ||
	    me->query("family/master_id") != "xu zhu")
		return "你这话是什么意思？";

	if (me->query_skill("zhougong-jian", 1) < 120)
		return "你的周公剑还不到家，要多练练！";

	if ((int)me->query("max_neili", 1) < 1500)
		return "你内力修为太弱了，还是练习高点再来吧。\n";

	message_vision(HIY "$n" HIY "点了点头，拔出腰间佩剑，长剑一"
		       "挺，剑尖上突然生出半尺吞吐不定的青芒。\n当真"
		       "气势如虹，一展王者风范。$N" HIY
		       "目光一亮，似乎明白了什么。"NOR"\n",
		       me, this_object());

	command("haha");
	command("say 看清楚了？这就是御剑的最高境界——剑芒，自己下去多研究研究吧。");
	tell_object(me, HIC "你学会了使用剑芒。"NOR"\n");
	if (me->can_improve_skill("sword"))
		me->improve_skill("sword", 160000);
	me->set("can_perform/zhougong-jian/mang", 1);
	return 1;
}

