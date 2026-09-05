// mayue.c

inherit NPC;

void create()
{
	set_name("麻雀", ({ "maque" }) );
	set("race", "野兽");
	set("age", 1);
	set("long", "一只好可爱的麻雀哦。\n它在草地上蹦来蹦去的，不停地叽叽喳喳.\n");
	set("limbs", ({ "头部", "身体", "前腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 50);
	set("chat_msg", ({"唧唧唧唧.......\n",
		(: this_object(), "random_move" :),
	}));
	set_temp("apply/dodge", 10);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 10);

	set("shen_type",1);set("score",200);setup();
}
