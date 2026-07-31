// zhu.c 朱熹
// CLEANSWORD 1996/2/2

inherit NPC;
inherit F_SKILL;

void create()
{
	set_name("朱熹", ({ "zhu xi", "zhu" }));
	set("long", "朱先生被称为当世第一大文学家，肚子里的墨水比海还要深。\n");
	set("gender", "男性");
	set("age", 65);

	set_skill("literate", 300);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 500000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"朱熹说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"朱熹说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"朱熹说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"朱熹说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
}

int recognize_apprentice(object ob)
{
	int money=50, level = ob->query_skill("literate", 1);

	if (level>29) money=100;
	if (level>59) money=500;
	if (level>89) money=1000;
	if (level>119) money=5000;

	ob->delete_temp("mark/朱");
	switch(MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			write("你现在的学费是每次" + MONEY_D->money_str(money) + "，请备好零钱。\n");
			return 1;
	}
	ob->set_temp("mark/朱", 1);
	return 1;
}
/*
int accept_object(object who, object ob)
{
	int money=25, level = who->query_skill("literate", 1);

	while (level >= 0) {
		money += money;
		level -= 30;
	}

	if (ob->query("money_id")) {
		if (ob->value() >= money) {
			if ((int)who->query_temp("mark/朱") < 1)
				who->set_temp("mark/朱", 1);
			message_vision("朱熹同意指点$N一些读书写字的问题。\n", who);
			who->add_temp("mark/朱", ob->value() / money);
			return 1;
		}
		return notify_fail("你现在的学费是每次" + MONEY_D->money_str(money) + "。\n");
	}
	return 0;
}
*/
