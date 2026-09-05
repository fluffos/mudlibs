//shusheng.c
//by hehe
//2003.3.13

inherit NPC;

void create()
{
	set_name("书生", ({ "shu sheng" , "shu" , "sheng"}));
	set("long",
		"他就是慕容家请来的教书先生曲清,据说是上过北大，看起来牛牛的样子。\n"
		"他看起来温文尔雅，一派风流。\n"
		);
	set("gender", "男性");
	set("age", 25);

	set_skill("literate", 1000);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 500000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/shoes1")->wear();
    carry_object(__DIR__"obj/cloth")->wear(); 
    set("chat_chance",5);
    set("chat_msg",({
		"教书先生道：“知之为知之，不知为不知，是知也......”\n",
		"教书先生道：“旺才，你也太调皮了，给我好好听课......”\n",
	}));
	
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
			message_vision("私塾先生同意指点$N一些读书写字的问题。\n", who);
			who->add_temp("mark/朱", ob->value() / money);
			return 1;
		}
		return notify_fail("你现在的学费是每次" + MONEY_D->money_str(money) + "。\n");
	}
	return 0;
}
