inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("花无邪", ({ "hua wuxie","girl", "dizi" }));
	set("age", 22);
	set("gender", "女性");
	set("attitude", "peaceful");
	set("str", 34);
	set("per", 26);
       set("title","雁荡三剑");
       set("nickname","慈心剑");
set("combat_exp", 1000000);
	set_skill("unarmed", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("force", 160);

create_family("雁荡派",2,"弟子");
    set("chat_chance", 7);
	set("chat_msg", ({
		"各有所痴,哪也叫无可奈何!\n",
		(:random_move:)
	}));
	setup();
       add_money("silver",60);
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
