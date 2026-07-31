// bantouyan.c 斑头雁
// by iceland
inherit NPC;

void create()
{
	set_name("斑头雁", ({ "bantou yan","bantouyan","yan"}) );
	set("long","一只正四处寻找食物的大雁，头部和背部上的羽毛都有好看的斑点。\n");
	set("race", "野兽");
	set("age", 3);

	set("eff_jing", 200);
	set("max_jing",200);
	set("max_qi", 500);

	set("str", 20);
	set("dex", 25);
	set("con", 15);
	set("int", 20);

	set("limbs", ({ "头部", "身体", "脖子","翅膀"}) );
	set("verbs", ({ "poke"}) );
	set_temp("apply/attack", 20);
	set_temp("apply/dodge", 25);

	set("combat_exp", 5000);
        set("chat_chance", 3);
	set("chat_msg", ({
(: this_object(), "random_move" :),
"斑头雁昂起脖子，扑扇了几下翅膀，警惕的望了望四周。\n",
"斑头雁狐疑的看着你，往远处走开了几步。\n",
}) );
        setup();
	set("race", "飞禽");
}

void die()
{
	object ob;
	message_vision("$N无力的拍打了几下翅膀，一头倒在地上死了。\n", this_object());
    ob = new(ARMOR_D("yanling"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
