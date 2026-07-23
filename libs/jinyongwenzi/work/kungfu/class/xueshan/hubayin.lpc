// hubayin.c 呼巴音
// by iceland

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("呼巴音", ({ "hu bayin", "hubayin" ,"hu","bayin"}));
	set("long",@LONG
他长得身材魁梧，脸上两道浓眉高高翘起，一双铜铃般的大眼。仿佛一座小山
似的站在那里。
LONG
	);
	set("title", HIY "大轮寺第十二代弟子" NOR);
	set("gender", "男性");
	set("age", 39);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 23);
	set("int", 18);
	set("con", 24);
	set("dex", 24);
	set("max_qi", 900);
	set("eff_jing", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 30000);
	set("unique", 1);

	set_skill("huanxi-chan", 80);
	set_skill("literate", 80);
	set_skill("force", 80);
	set_skill("longxiang-boruo", 80);
	set_skill("dodge", 80);
	set_skill("yuxue-dunxing", 80);
	set_skill("hand", 80);
	set_skill("dashou-yin", 80);
	set_skill("claw", 80);
	set_skill("tianwang-zhua", 80);
	set_skill("wushang-dali",80);
	set_skill("staff",80);
	set_skill("parry", 80 );

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "wushang-dali");
	map_skill("claw", "tianwang-zhua");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	create_family("大轮寺", 12, "弟子");
	set("class", "huanxi");

	setup();
	carry_object("/d/xueshan/npc/obj/qinxiu-jiasha")->wear();
	carry_object(BINGQI_D("jingangzuan"))->wield();
	add_money("silver",10);
}

void attempt_apprentice(object ob)
{
	if ((string)ob->query("family/family_name") != "大轮寺") {
		 command("say"+ RANK_D->query_respect(ob) +
			"不是本寺弟子，在这里捣什么乱？！");
		return;
	}

	if ((int)ob->query_skill("huanxi-chan", 1) < 50) {
	       command("say 欢喜禅是各项武功之本，你再勤加修炼吧。");
		command("say"+ RANK_D->query_respect(ob) +
			"再熬几个通宵，多多钻研钻研本门的心法吧。");
		return;
	}

	if ((string)ob->query("class") != "huanxi") {
		message_vision("呼巴音看了看你头顶，又摸了摸自己的光头。",this_player());
		command("say 你还没出家，不能表示你是真心侍奉欢喜佛，我不能收你。");
		command("say 这位" + RANK_D->query_respect(ob) +
			"如能早下决心，献身侍奉我佛再来找我吧。");
		return;
	}

	command("say 好吧，你以后就是我的弟子了，可要刻苦勤修，不能偷懒呀。");
	command("recruit " + ob->query("id"));
	ob->set("title", HIY "大轮寺第十三代弟子" NOR);
}
