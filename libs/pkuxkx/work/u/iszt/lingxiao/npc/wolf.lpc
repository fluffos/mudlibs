inherit NPC;

void create()
{
	set_name("狼", ({ "wolf", "lang" }) );
	set("race", "野兽");
	set("age", 10);
	set("long", "一匹恶狼, 眼睛放着绿光，露着白森森的獠牙。\n");
	set("attitude", "aggressive");
	set("limbs", ({ "头", "身体", "前腿", "后腿", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("max_qi", 300);
	set("max_jing", 200);
	set("combat_exp", 3000);

	set("chat_chance", 3);
	set("chat_msg", ({
		"「嗥~~~~」狼发出一声嗥叫。\n",
		"狼凶巴巴地盯着你，好象随时都要扑上来！\n",
	}));

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 40);
	set("senlin", 1);

	setup();
}
