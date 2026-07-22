inherit NPC;
void create()
{
	set_name("游客", ({ "you ke",  "ke" }) );
	set("long", "这个人看起来似乎不大高兴。\n");
	if(random(10)<6)
		set("gender","男性");
	else
		set("gender","女性");

	set("age", 20);
	set("str", 16);
	set("cor", 24);
	set("cps", 11);
	set("per", (10 +random(18)));

	set("attitude", "peaceful");

	set("food",100);
	set("water",100);

	set("combat_exp", 5000+random(20000));

	set_skill("unarmed", 60);
	set_skill("parry", 60);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("literate", 60);

	set("chat_chance",3);
	set("chat_msg",({
		"游客大叫到：“倒霉！真倒霉！”\n",
		"游客看着你恶狠狠的说到：“你！小心点！这事没这么容易了结！”\n",
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 30);
}
