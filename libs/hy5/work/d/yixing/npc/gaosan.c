// /d/yixing/npc/gaosan.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("高三娘子", ({ "gao san", "gao"}));
	set("title", HIR "万马庄女庄主" NOR);
	set("long", "这女子颇有几分姿色，两幅罗裙外面系着绣花鸾带。
腰间整整齐齐插着两排短刀。\n");
	set("gender", "女性");
	set("age", 31);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_qi", 25000);
	set("max_jing", 23000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 100);
	set("combat_exp", 4000000);
	set("score", 600000);

		set_skill("zhuihun-biao", 220);
		set_skill("liuxing-biao", 220);
	set_skill("pili-biao",220);
	set_skill("force", 220);
	set_skill("biyun-xinfa", 220);
	set_skill("dodge", 220);
	set_skill("qiulinshiye", 220);
	set_skill("strike", 250);
	set_skill("unarmed",220);
	set_skill("biye-wu", 220);
	set_skill("parry", 280);
	set_skill("throwing", 220);
	set_skill("zimu-zhen", 220);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 220);
	set_skill("lansha-shou", 220);
	set_skill("hand", 220);
	set_skill("strike", 220);
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "dusha-zhang");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "biye-wu");
	map_skill("throwing", "zimu-zhen");
	map_skill("strike", "dusha-zhang");
	map_skill("hand", "lansha-shou");
	prepare_skill("strike", "dusha-zhang");
	prepare_skill("hand", "lansha-shou");
	
	set("class", "tangmen");

	set("chat_chance_combat", 98);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
	set("chat_chance", 3);
	set("chat_msg", ({
		"高三娘子怒道：丁不四这老贼，总有一天要找他算帐！\n",
	}) );

	set("inquiry",([
		"丁不四" : "下次再遇到这老贼，定在他身上插几把飞刀。",
		"长乐帮" : "我也正要到长乐帮拜山。",
		"司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
	]));

	setup();
	carry_object(__DIR__"obj/shortblade")->wield();
	carry_object("/clone/misc/cloth")->wear();
}



void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;


who->set_temp("book91122",1);
		
		

		
		
	::die();

}  