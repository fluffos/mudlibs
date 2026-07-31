 // spy.c
inherit NPC; 
void create()
{
        object ob; 
        set_name("黑衣人", ({ "spy" }) );
        set("gender", "男性");
        set("age", 24);
        set("long",
                "这个男人看起来鬼鬼祟祟的，想必不是什麽好东西。\n");
        set("combat_exp", 900000);
        set("score", 400);
        set("bellicosity", 2000);
	set("max_qi", 5000);
	set("max_jing", 3000);
	set("neili", 10000);
	set("max_neili", 10000);
	set("jiali", 100);
	set("combat_exp", 2000000);
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

        setup();
        carry_object(__DIR__"obj/throwing_knife")->wield();
        carry_object(__DIR__"obj/black_suit")->wear();

}  
void killed_enemy(object who)
{
        command("say 哈哈哈哈哈哈。");
        call_out("dissolve", 1);
} 
void dissolve()
{
        command("dissolve corpse");
}       
