// yiren.c

inherit NPC;

void create()
{
	set_name("艺人", ({ "yi ren","ren","yi" }) );
	set("gender", "男性" );
	set("age", 38);
	set("long", "一个中年艺人，他走南闯北，一脸风霜。据说是从东土来的\n");

	set("str", 30);
	set("cor", 30);
	set("cps", 30);
	set("int", 15);

	set("max_qi", 500);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 50);
	set("shen_type", 0);

	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);

	set("combat_exp", 15000);

	set("max_force", 200);
	set("force_factor", 2);

	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 80);
	setup();
	set("chat_chance", 10);
	set("chat_msg", ({
                       "艺人说道: 小人是从东土来的，初到贵地还请大家捧个场～\n",
		"艺人说道: 大家看好不好，小绝活，大爷们看着给俩铜板吧～\n",
		"艺人深吸一口气，双手翻飞，打出一路太祖长拳。\n",
		"艺人一路拳法使罢，向大家作了一个揖，都是些小伎俩，爷们见笑了。\n",
	}) );
	//add_money("silver", 10);
}

int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 10) {
        	 command("smile");
	         command("say 多谢这位" + RANK_D->query_respect(me) +"，在下给你作揖了 !");
	}
        else {
        	 command("shake");
	         command("say 真是抱歉，这种东西我还用不着，多谢这位爷了 !");
		 return 0;
        }

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "放过小的吧，小的那里是您对手？\n");
	return 0;
}
