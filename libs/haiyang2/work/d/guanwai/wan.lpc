// yanji.c

inherit NPC;
inherit F_DEALER;
int ask_wu();
void create()
{
	set_name("万震山", ({ "wanzhenshan", "wan" }));
	set("title", "江西大侠");
	set("gender", "男性");
	set("long", "他是一个武师。自从得了连城剑法几页残篇后，武功大进。\n");
	set("age", 45);

	set("int", 20);
	set("con", 20);
	set("str", 20);
	set("dex", 20);
	set("per", 10);
	
	set("qi", 3000);
	set("max_qi", 3000);
	set("jing", 500);
	set("max_jing", 3500);
	set("neili", 23500);
	set("max_neili", 23500);
	set("shen_type", -1);

	set("combat_exp", 3500000);
	set("attitude", "heroism");

	set_skill("unarmed", 230);
	set_skill("dodge", 230);
	set_skill("parry", 260);
	set_skill("force", 260);
	set_skill("sword", 260);
       set("max_neili",20000);
        set("neili",20000);
        set("max_qi",9800);
        set("qi",9800);
	set_skill("liancheng-jian", 380);
	map_skill("sword", "liancheng-jian");
map_skill("parry", "liancheng-jian");	
        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 320);

	set("chat_chance", 40);
	set("chat_msg", ({
		(: random_move :),
	}));
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),                	                	                	
                (: perform_action, "sword.zhu" :),                	                	                	
		            (: random_move :),
        }) );


	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangjian")->wield();
}

