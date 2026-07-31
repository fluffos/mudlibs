// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "掌棒龙头");
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
		"因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
        set("beggarlvl",9);
        set("class", "beggar");
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

	set("qi", 3900);
	set("max_qi", 3900);
	set("jing", 3100);
	set("max_jing", 3100);
	set("neili", 6200);
	set("max_neili", 6200);
	set("jiali", 100);
	
	set("combat_exp", 600000);
	set("score", 20000);
	
	set_skill("force", 190); // 基本内功
	set_skill("huntian-qigong", 190); // 混天气功
	set_skill("unarmed", 195); // 基本拳脚
	set_skill("xianglong-zhang", 190); // 降龙十八掌
	set_skill("dodge", 190); // 基本躲闪
	set_skill("xiaoyaoyou", 190); // 逍遥游
	set_skill("parry", 190); // 基本招架
	set_skill("staff", 185); // 基本棍杖
	set_skill("begging", 160);
		set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 18, "九袋长老");
	setup();
	carry_object(__DIR__"obj/jiaohuaji")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 ) {
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
		return;
	}
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
}
#include "/kungfu/class/gaibang/gaibang.h"
