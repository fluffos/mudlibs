// wolf.c

inherit NPC;

#include <ansi.h>

void create()
{
	set_name(WHT "野狼" NOR, ({ "wolf", "lang", "ye lang" }) );
	set("race", "野兽");
	set("age", 10);
	set("long", "一只凶猛的野狼，牙尖齿利，一副凶狠模样。\n");
	set("attitude", "aggressive");

	set("limbs", ({ "头部", "身子", "前爪", "后爪", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }));
	set("unit", "匹");

	set("combat_exp", 30000);
	set_temp("apply/attack", 180);
	set_temp("apply/defense", 150);
	set_temp("apply/armor", 50);

	setup();
}

void init()
{
	if (query_temp("owner"))
		return;

	if (sscanf(base_name(environment()), "/d/guanwai/%*s") == 1 &&
	    environment()->query("outdoors"))
	{
		if (playerp(this_player()))
			kill_ob(this_player());
	} else
	{
		remove_call_out("greeting");
		call_out("greeting", 1, this_player());
	}
}

void greeting(object ob)
{
	if (! objectp(ob) || environment(ob) != environment())
		return;

	message_vision("$N冷冷的盯着$n，目光中透露出一股狠劲。\n",
		       this_object(), ob);
}

void unconcious()
{
	die();
}

void die()
{
	message_vision("\n$N哀嚎一声，夹着尾巴逃跑了！\n", this_object());
	destruct(this_object());
}
