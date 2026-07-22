inherit NPC;
void create()
{
	set_name("游客", ({ "you ke",  "youke", "ke" }) );
	set("long", "这个人看起来似乎不大高兴。\n");
	if(random(10)<6) set("gender","男性");
	else set("gender","女性");

	set("age", 20+random(12));
	set("str", 16);
	set("cor", 24);
	set("cps", 11);
	set("per", (2+random(18)) );
	set("attitude", "peaceful");
	set("combat_exp", 20000+random(5000));

	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("literate", 60);
	set("chat_chance", 2);
	set("chat_msg",({
		"游客大叫道：“倒霉！真倒霉！”\n",
		"游客看着你恶狠狠的说道：“你！小心点！这事没这么容易了结！”\n",
	}));
	setup();

	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 5);
}
