// wuzhirong.c
inherit NPC;

void create()
{
	set_name("吴之荣", ({ "wu zhi rong", "wu" ,"rong"}) );
	set("gender", "男性" );
	set("age", 40);
	set("int", 28);
	set("long",
		"他原是归安县的知县，因贪赃枉法，百姓恨之切齿，终被告发革职。\n"
               +"他长得尖嘴猴腮，一看就知不是好人 。\n");
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 15000);
	set("max_jing", 15000);
	set("neili", 15000);
	set("max_neili", 15000);
	set("combat_exp", 15000);

	set("max_neili", 800000);
	set("jiali", 100);


		set_skill("zhuihun-biao", 180);
		set_skill("liuxing-biao", 180);
	set_skill("pili-biao",180);
	set_skill("force", 180);
	set_skill("biyun-xinfa", 180);
	set_skill("dodge", 180);
	set_skill("qiulinshiye", 180);
	set_skill("strike", 150);
	set_skill("unarmed",180);
	set_skill("biye-wu", 180);
	set_skill("parry", 180);
	set_skill("throwing", 180);
	set_skill("zimu-zhen", 180);
	set_skill("literate", 150);
	
	set_skill("dusha-zhang", 180);
	set_skill("lansha-shou", 180);
	set_skill("hand", 180);
	set_skill("strike", 180);
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
	


	set("chat_chance_combat", 28);
	set("chat_msg_combat", ({

		(: perform_action, "parry.wandu" :),
		(: perform_action, "parry.meng" :),
		(: perform_action, "strike.tianxie" :),
		(: perform_action, "strike.hantian" :),
		(: perform_action, "hand.canglong" :),
		(: perform_action, "hand.xiangyi" :),
		(: perform_action, "hand.luanpo" :),									
						
	}) );
	set("score", 5000);
        set_skill("literate", 100);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/d/beijing/obj/goldleaf");
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	who->add_temp("book731",1);
	::die();
}