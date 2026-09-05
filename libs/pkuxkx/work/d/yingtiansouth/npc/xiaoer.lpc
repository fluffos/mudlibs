inherit NPC;

void create()
{
	set_name("客栈老板", ({ "kezhan laoban", "laoban","lao ban" }));
	set("gender", "男性");
	set("age", 45);
	set("str", 25);
	set("dex", 16);
	set("long", "他是客栈老板，对人不错，生意所以不错，因为他以前是都府亲军，一般地痞也不敢来惹他。\n");
	set("combat_exp", 900000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 100);
	set_skill("force", 100);
	set_skill("spear", 100);
	set_skill("yangjia-qiang", 250);
	set_skill("dodge", 100);
	set_skill("parry", 100);

	map_skill("spear", "yangjia-qiang");
	map_skill("parry", "yangjia-qiang");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);
	set("neili", 4000); 
	set("max_neili", 4000);
	set("jiali", 10);

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

