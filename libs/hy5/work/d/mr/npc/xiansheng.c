// xiansheng.c 教书先生
inherit NPC;

void create()
{
	set_name("教书先生", ({ "teacher" , "xiansheng" }));
	set("long", "他就是慕容家请来的教书先生。\n");
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
	
}

int recognize_apprentice(object ob)
{
	int money=50, level = ob->query_skill("literate", 1);

	if (level>29) money=100;
	if (level>59) money=500;
	if (level>89) money=1000;
	if (level>119) money=5000;
	       if (!(int)ob->query_temp("mark/老师"))
               return 0;
        ob->add_temp("mark/老师", -1);
        return 1;
	/*ob->delete_temp("mark/朱");
	switch(MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			write("你现在的学费是每次" + MONEY_D->money_str(money) + "，请备好零钱。\n");
			return 1;
	}
	ob->set_temp("mark/朱", 1);
	return 1;*/
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
			if ((int)who->query_temp("mark/老师") < 1)
				who->set_temp("mark/老师", 1);
message_vision("私塾先生同意指点$N一些读书写字的问题。\n", who);
			who->add_temp("mark/老师", ob->value() / money);
			if( who->query_skill("literate", 1) > 121){
        tell_object(who,"你现在已有一定的文化知识,也可以自己读书深造了。\n");
        return 1;
		}
		return notify_fail("你现在的学费是每次" + MONEY_D->money_str(money) + "。\n");
	}
		return 1;}
return 1;
}
