// shenjinyin.c 沈金音

inherit NPC;

void create()
{
	set_name("沈金音", ({ "shen jinyin", "shen", "jinyin" }));
	set("gender", "女性");
	set("age", 19);
	set("long", "张宝林的小弟子，长的如西施再世。\n");
	
	set("combat_exp", 1500);
	set("shen_type", -1);

	set("attitude", "peaceful");
	
	set_skill("unarmed", 22);
	set_skill("dodge", 22);
	set_temp("apply/attack", 11);
	set_temp("apply/defense", 11);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",8);
}
