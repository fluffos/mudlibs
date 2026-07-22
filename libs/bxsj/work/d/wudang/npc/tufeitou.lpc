// NPC : /d/wudang/npc/tufeitou.c

inherit NPC;

void create()
{
	set_name("土匪头", ({ "tufei tou","bandit leader","tou" }) );
	set("gender", "男性");
	set("age", 54);
	set("long",
		"这家伙满脸杀气，一付凶神恶煞的模样，令人望而生畏。\n");
	set("combat_exp", 300000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set("apply/attack", 80);
	set("apply/defense", 80);

	set("chat_chance", 5);
	set("chat_msg", ({
		"土匪头嘿嘿地冷笑着: 今天你就别想从这里活着出去了!\n",
	}) );

	set_skill("sword", 30);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);

	setup();
        carry_object(BINGQI_D("changjian"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
	add_money("silver", 80);
}
