// shusheng.c 书生

inherit NPC;

void create()
{
        set_name("书生", ({ "shu sheng", "shu" ,"sheng" }));
	set("gender", "男性");
        set("age", 25);
        set("long", "他拿着一本书，正在看着，根本不知道你在看他。\n");
	
        set("combat_exp", 600);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);

	setup();
	carry_object("/clone/misc/cloth")->wear();
        add_money("coin",30);
}
