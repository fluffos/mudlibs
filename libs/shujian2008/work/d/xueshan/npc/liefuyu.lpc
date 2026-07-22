// liefuyu.c 裂腹鱼
// by iceland
inherit NPC;

void create()
{
	set_name("裂腹鱼", ({ "liefu yu","liefuyu","yu"}) );
	set("long",
"一条半透明的小鱼，可以模模糊糊的看到身体内的骨骼，只生长在寒冷的水
里，听说它的肉质鲜美，而且可以驱寒健体。
LONG
        ");
	set("race", "野兽");
	set("age", 5);

	set("eff_jing", 200);
	set("max_jing",200);
	set("max_qi", 300);

	set("str", 10);
	set("dex", 45);
	set("con", 15);
	set("int", 20);
	set("unique", 2);

	set("limbs", ({ "头部", "身体", "尾巴"}) );
	set("verbs", ({ "bite"}) );
	set_temp("apply/attack", 20);
	set_temp("apply/dodge", 45);

	set("combat_exp", 3000);
        set("chat_chance", 2);
        set("chat_msg", ({
"裂腹鱼游过来好奇的看了看你，又游走了。\n",
"裂腹鱼游过来轻轻啄了啄你，你觉得痒痒的。\n",
}) );
        setup();
}
void die()
{
	object ob;
	message_vision("$N无力的扭动了几下，肚皮朝天死掉了。\n", this_object());
	ob = new(FOOD_D("yuyou"));
	ob->move(environment(this_object()));
	destruct(this_object());
}
