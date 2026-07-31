inherit NPC;
void create()
{
   set_name("哲别",({"zhe bie"}));
   set("gender","男性");
   set("long","铁木真手下猛将之一,是郭靖的箭术师傅!\n");
   set("shen",25000);
   set("combat_exp",160000);
   set("title","神箭手");
   
set("age",35);
  set("max_qi", 55000);
	set("max_jing", 53000);
	set("neili", 80000);
	set("max_neili", 80000);
	set("jiali", 100);
	set("combat_exp", 8000000);
	set("score", 600000);

		set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	
	set_skill("dusha-zhang", 380);
	set_skill("lansha-shou", 380);
	set_skill("hand", 380);
	set_skill("strike", 380);
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

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);


   setup();
   add_money("silver",20);
carry_object("/d/tangmen/obj/zimuzhen")->wield();
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tieqiang");
}


void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book591",1);
		


	::die();
}
