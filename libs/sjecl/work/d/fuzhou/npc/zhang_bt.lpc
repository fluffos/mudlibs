// zhang_bt.c 张镖头

inherit NPC;
void create()
{
	set_name("张镖头", ({ "zhang biaotou", "zhang", "biaotou" }));
	set("gender", "男性");
	set("age", 40);
	set("long", "他是「福威镖局」的一个镖头。\n");
	set("shen_type", 1);

        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 35);
        set("max_qi", 1600);
        set("max_jing", 800);
        set("max_jingli", 1200);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 20);
        set("combat_exp", 180000);

	set_skill("blade", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("force", 50);
	set_skill("yijin-jing", 50);
	set_skill("shaolin-shenfa", 50);
	set_skill("xiuluo-dao", 50);
	map_skill("force", "yijin-jing");
	map_skill("blade","xiuluo-dao");
	map_skill("parry","xiuluo-dao");
	map_skill("dodge","shaolin-shenfa");

	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/damage", 30);

	setup();
	carry_object(BINGQI_D("blade"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("silver", 5+random(20));
}
