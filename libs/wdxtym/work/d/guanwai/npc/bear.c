// bear.c

inherit NPC;
#include <ansi.h>;

void create()
{
	set_name(CYN "黑熊" NOR, ({ "hei xiong", "bear", "xiong" }));
	set("race", "野兽");
	set("age", 20);
	set("long", "一只凶猛的黑熊，形体硕大，人立而行。\n");
	set("attitude", "aggressive");

	set("limbs", ({ "熊头", "熊身", "前爪", "后爪" }) );
	set("verbs", ({ "bite", "claw" }) );
	set("unit", "只");

	set("combat_exp", 50000);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 280);
	set_temp("apply/armor", 120);

	setup();

	set("chat_chance", 10);
	set("chat_msg", ({
		"黑熊冲着你摇头摆尾地，不知道是什么意思。\n",
		"黑熊挤了挤鼻子，你觉得它好象在笑，顿时一阵紧张。\n",
	}));
}

void init()
{
	if (query_temp("owner"))
		return;

	if (sscanf(base_name(environment()), "/d/guanwai/%*s") == 1 &&
	    environment()->query("outdoors"))
		kill_ob(this_player());
	else
	{
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}
}

void greeting(object ob)
{
	if (! objectp(ob) || environment(ob) != environment())
		return;

	message_vision("$N憨憨的看着$n。\n",
		       this_object(), ob);
}

void die()
{
	object ob, corpse;

	message_vision("$N震天动地一声惨嚎，慢慢委顿在地，死了！\n", this_object());

	if (objectp(corpse = CHAR_D->make_corpse(this_object())))
	{
		ob = new(__DIR__"xiongdan");
		ob->move(corpse);
		corpse->move(environment(this_object()));
		destruct(this_object());
	}
}
