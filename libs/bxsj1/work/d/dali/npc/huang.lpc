// huang

inherit NPC;

void create()
{
	set_name("黄大雄", ({ "huang daxiong", "huang" }));
	set("title", "大理城守将");
	set("gender", "男性");
	set("age", 43);
	set("str", 25);
	set("dex", 20);
	set("long", "这是个身高体壮威风凛凛的军官，他身穿铁甲，手持钢刀。\n");
        set("combat_exp", 250000);
        set("unique", 1);
	set("shen_type", 1);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 90);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("liuhe-daofa", 90);
	map_skill("parry", "liuhe-daofa");
	map_skill("blade", "liuhe-daofa");
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/armor", 70);
	set_temp("apply/damage", 20);

	set("max_qi", 700);
	set("neili", 700); 
	set("max_neili", 700);
	set("jiali", 20);

	setup();
	carry_object("/clone/weapon/blade")->wield();
	carry_object("/clone/armor/armor")->wear();
}

int accept_fight(object me)
{
	command("say 本官公务在身，不愿与和江湖人动手过招。");
	return 0;
}
