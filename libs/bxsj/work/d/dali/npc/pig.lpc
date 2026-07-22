//wolf2.c

inherit NPC;

void create()
{
	set_name("野猪", ({ "ye zhu" ,"zhu", "pig"}) );
	set("race", "野兽");
	set("age", 5);
	set("long", "一只膘肥体壮，肥头大耳的野猪。\n");
	set("attitude", "aggressive");

	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "头部", "身体", "腿部", "尾巴",}) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 6000);

        set("chat_chance",50);
	set_temp("apply/attack", 25);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",20);

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
	}) );


	setup();
}
void die()
{
	object ob;
	message_vision("$N凄惨的嚎了几声, 在地上打了几个滚，仰天死了。\n", this_object());
	ob = new(__DIR__"obj/zhurou");
	ob->move(environment(this_object()));
	destruct(this_object());
}

