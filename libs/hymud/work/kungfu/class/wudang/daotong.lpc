// daotong.c 道童

inherit NPC;

void create()
{
	set_name("道童", ({ "daotong", "dao", "tong" }));
	set("long", 
		"他是武当山的小道童。\n");
	set("gender", "男性");
	set("age", 16);
	set("attitude", "peaceful");
	set("shen_type", 1);
        set("class", "taoist");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("max_qi", 5500);
	set("max_jing", 5000);
	set("neili", 5500);
	set("max_neili", 5500);

	set("combat_exp", 80000+random(50000));
	set("score", 1000);

set_skill("claw", 50);
set_skill("strike", 60);
	set_skill("force", 150);
	set_skill("taiji-shengong", 80);
	set_skill("dodge", 180);
	set_skill("tiyunzong", 80);
	set_skill("unarmed", 90);
	set_skill("taiji-quan", 100);
	set_skill("parry", 170);
	set_skill("sword", 100);
	set_skill("taiji-jian", 100);
	set_skill("wudang-array", 100);
	set_skill("array",100);
	set_skill("taoism", 100);
	set_skill("literate", 100);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.lian" :),                
        }) );
	create_family("武当派", 5, "弟子");

	setup();
		carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/greyrobe")->wear();
}
