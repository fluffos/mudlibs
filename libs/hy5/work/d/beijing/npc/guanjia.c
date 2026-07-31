// luguanji.c 女管家

inherit NPC;

void create()
{
	set_name("女管家", ({ "guan jia", "guan" }));
	set("gender", "女性");
	set("age", 45);

set("max_qi", 25000);
	set("max_jing", 25000);
	set("neili", 25000);
	set("max_neili", 25000);
	set("combat_exp", 3825000);

	
	set("jiali", 100);


		set_skill("zhuihun-biao", 220);
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
	


	set("chat_chance_combat", 88);
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
        set_temp("apply/attack", 130);
        set_temp("apply/defense", 140);
	set("shen_type", -1);
	setup();
	carry_object("/d/tangmen/obj/zimuzhen")->wield();
	carry_object("/d/beijing/obj/diaopi")->wear();
	add_money("silver", 10);

}

