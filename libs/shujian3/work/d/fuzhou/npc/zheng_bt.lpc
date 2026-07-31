// zheng_bt.c 郑镖头

inherit NPC;
void create()
{
	set_name("郑镖头", ({ "zheng biaotou", "zheng", "biaotou" }));
	set("gender", "男性");
	set("age", 40);
	set("long", "他是「福威镖局」的一个镖头。\n");
	set("shen_type", 1);

        set("str", 35);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        set("max_qi", 2600);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 20);
        set("combat_exp", 380000);

	set_skill("blade", 160);
	set_skill("cuff", 150);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("force", 150);
	set_skill("shenghuo-shengong", 150);
	set_skill("xiaoyaoyou", 150);
	set_skill("yanxing-daofa", 160);
	map_skill("force", "shenghuo-shengong");
	map_skill("blade","yanxing-daofa");
	map_skill("parry","yanxing-daofa");
	map_skill("dodge","xiaoyaoyou");

	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/damage", 30);

	setup();
	carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 2 + random(10));
}
