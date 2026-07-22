// zhangfang.c 帐房

inherit NPC;

void create()
{
	set_name("董帐房", ({ "zhang fang", "zhangfang", "zhang", "fang", }));
	set("long","他深得林震南的信任，负责管理镖局的往来帐目。");
	set("gender", "男性");
	set("age", 35);

	set("combat_exp", 120000);
	set("shen_type", 1);

	set_skill("unarmed", 30);
	set_skill("blade", 40);
	set_skill("parry", 30);
	set_skill("dodge", 30);

	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
        add_money("gold", 1);
}
