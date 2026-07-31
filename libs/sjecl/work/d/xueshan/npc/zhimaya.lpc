// zhimaya.c 支麻鸭
// by iceland
inherit NPC;

void create()
{
	set_name("支麻鸭", ({ "zhima ya","zhimaya","ya"}) );
	set("long","一只灰仆仆的鸭子，很不起眼，不过是雪山的特产，别处是看不到的。\n");
	set("race", "野兽");
	set("age", 3);

	set("max_jing",200);
	set("max_qi", 500);
	set("max_neili", 1);

	set("str", 20);
	set("dex", 15);
	set("con", 15);
	set("int", 20);

	set("limbs", ({ "头部", "身体", "脖子","翅膀"}) );
	set("verbs", ({ "poke"}) );
	set_temp("apply/attack", 20);
	set_temp("apply/dodge", 15);
	set("unique", 1);

	set("combat_exp", 2000);
        set("chat_chance", 3);
	set("chat_msg", ({
(: this_object(), "random_move" :),
"支麻鸭嘎嘎的叫了两声，挪动短腿笨拙的走了几步，拿嘴在地上啄了两下。\n",
"支麻鸭啄了你的脚几下，看来不感兴趣，东张西望的走开了。\n"
}) );
        setup();
	set("race", "飞禽");
}

void die()
{
	object ob;
	message_vision("$N的脖子软软的垂在地上，一动不动了。\n", this_object());
    ob = new(FOOD_D("yasui"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
