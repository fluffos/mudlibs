// yanji.c

inherit NPC;
inherit F_DEALER;
int ask_wu();
void create()
{
	set_name("阎基", ({ "yan ji", "yan" }));
	set("title", "江湖医生");
	set("gender", "男性");
	set("long", "他是一个没落江湖医生。自从得了胡家刀谱几页残篇后，武功大进。\n");
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
	set("max_neili", 23500);
	set("shen_type", -1);

	set("combat_exp", 2500000);
	set("attitude", "heroism");
       set("max_neili",20000);
        set("neili",20000);
        set("max_qi",9800);
        set("qi",9800);
	set_skill("unarmed", 230);
	set_skill("dodge", 230);
	set_skill("parry", 260);
	set("neili", 23500);
	set_skill("force", 360);
	set_skill("blade", 360);
	set_skill("hujia-daofa", 360);
	map_skill("blade", "hujia-daofa");
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
                (: perform_action, "blade.huanying" :),
                (: perform_action, "blade.cang" :),
                	(: perform_action, "blade.lian" :),
                		(: perform_action, "blade.xian" :),
                			(: perform_action, "blade.zhui" :),
		            (: random_move :),
        }) );


	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}

