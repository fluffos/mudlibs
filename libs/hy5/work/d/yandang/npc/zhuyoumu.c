inherit NPC;

void create()
{
	set_name("朱由穆", ({ "zhu youmu"}));
	set("age", 36);
	set("gender", "男性");
	set("attitude", "peaceful");
	set("str", 34);
       set("title","侠士");
	set("combat_exp", 10000+random(10000));
	set_skill("unarmed", 60+random(40));
	set_skill("dodge", 60+random(40));
	set_skill("parry", 60+random(40));
	set_skill("sword", 60+random(40));
	set_skill("force", 60+random(40));
    set("chat_chance", 7);
	set("chat_msg", ({
		"听说落雁山庄藏有三宝,不知道会在哪儿!\n",
		(:random_move:)
	}));
	setup();
add_money("silver",20);
carry_object("/clone/misc/cloth")->wear();
}
