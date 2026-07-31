// wan 万震山

inherit NPC;

void create()
{
	set_name("万震山", ({ "wan zhenshan", "wan" }));
	set("title", "万门大当家");
	set("gender", "男性");
	
	set("age", 50);
	set("str", 25);
	set("dex", 28);
	set("long", "他就是万震山，荆州万门的老大。\n");
	set("combat_exp", 35000);
	set("shen_type", 0);
	set("attitude", "heroism");

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
	carry_object(__DIR__"obj/gangjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	
}
