// xiansheng.c 教书先生
inherit NPC;

void create()
{
	set_name("教书先生", ({ "xian sheng" , "xiansheng", "teacher" }));
	set("long", "教书先生是苏州一带有名的学究。\n");
	set("gender", "男性");
	set("age", 65);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 20);

	set("combat_exp", 120000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"教书先生说道：普天之下，莫非王土；率土之滨，莫非王臣。\n",
		"教书先生说道：出家人，小过损益焉；无妄大过，未济咸困之。\n",
		"教书先生说道：大学之道，在明明德。在亲民，在止于至善。 \n",
		"教书先生说道：格物致知，诚意正心，修身齐家，治国平天下。\n",
	}) );
}
