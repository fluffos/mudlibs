// xu_bt.c 许镖头

inherit NPC;
void create()
{
	set_name("许镖头", ({ "xu biaotou", "xu", "biaotou" }));
	set("gender", "男性");
	set("age", 40);
	set("long", "他是「福威镖局」的一个镖头，平常喜欢赌钱。\n");
	set("shen_type", 1);

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 2000);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 20);
        set("combat_exp", 120000);

	set_skill("blade", 70);
	set_skill("dodge", 75);
	set_skill("parry", 75);
	set_skill("force", 75);
	set_skill("shenyuan-gong", 75);
	set_skill("tiyunzong", 75);
	set_skill("liuhe-daofa", 75);
	map_skill("force", "shenyuan-gong");
	map_skill("blade","liuhe-daofa");
	map_skill("parry","liuhe-daofa");
	map_skill("dodge","tiyunzong");

	set_temp("apply/attack", 55);
	set_temp("apply/defense", 35);
	set_temp("apply/damage", 30);

	setup();
	carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 2+random(30));
}
