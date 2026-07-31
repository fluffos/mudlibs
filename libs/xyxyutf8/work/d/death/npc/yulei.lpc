//puti.c
inherit NPC;

void create()
{
	set_name("郁垒", ({"yu lei", "lei"}));
	set("title", "祀户");
	set("gender", "男性");
	set("long", "一个红脸怒相的勇士，身高足有丈外，站在那里威风凛凛。\n");
	set("age", 30);
	set("attitude", "peaceful");
	set_level(120);
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("force",1800);
	set("max_force", 1000);
	set("force_factor", 60);
	set("max_mana", 800);
	set("mana", 1500);
	set("mana_factor", 40);
	set("combat_exp", 500000);
  	set("daoxing", 200000);

	set_skill("unarmed", 1200);
	set_skill("dodge", 1200);
	set_skill("parry", 1200);
	set_skill("sword", 1200);
 	set_skill("force", 1000);
	set_skill("spells", 1000);
	set_skill("moshenbu", 1200);
	set_skill("zhuihun-sword", 1200);
	set_skill("changquan", 1000);
	map_skill("unarmed", "changquan");
	map_skill("dodge", "moshenbu");
	map_skill("sword", "zhuihun-sword");
	map_skill("parry", "zhuihun-sword");
	setup();
        carry_object(0,"armor",random(100))->wear();
        carry_object(0,"cloth",random(100))->wear();
        carry_object(0,"pifeng",random(100))->wear();
        carry_object(0,"kui",random(100))->wear();
        carry_object(0,"shoes",random(100))->wear();
        carry_object(0,"sword",random(100))->wield();
}