
inherit NPC;

void create()
{
        set_name("朱先生", ({"zhu xiansheng", "zhu","xiansheng"}));
        set("title", "书院先生");
        set("gender", "男性");
        set("age", 64);
        set("long","这是书院的先生,他是南朝的大儒.\n");
         set("qi", 500); 
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100);
        set("sen",300);
        set("max_sen",300);
        set("combat_exp",300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("env/wimpy", 50);

        set_skill("literate",200);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 50, level = ob->query_skill("literate", 1);

	if (level > 29) money = 100;
	if (level > 59) money = 500;
	if (level > 89) money = 1000;
	if (level > 119) money = 2500;

	ob->delete_temp("mark/literate");
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2:
			write("你现在的学费是每次" + MONEY_D->money_str(money) + "，请备好零钱。\n");
			return 0;
	}
        ob->set_temp("mark/literate", 1);
        return 1;
}


