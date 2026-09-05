

inherit NPC;

void create()
{
	set_name("闲汉", ({ "xian han", "han" }));
	set("gender", "男性");
	set("age", 39);
	set("long", "他是一个无所事事的闲汉，兴趣就是到处看看。\n");
	
	set("combat_exp", 3000);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

      
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
