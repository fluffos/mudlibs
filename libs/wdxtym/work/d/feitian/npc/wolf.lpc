// wolfdog.c

#include <login.h>
#include <move.h>
inherit NPC;

void create()
{
	set_name("饿狼", ({ "wolf" }) );
	set("race", "野兽");
	set("age", 4);
	set("long", "一只两眼冒着绿光的恶狼。\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("cor", 30);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);

	set("chat_chance", 6);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
               "恶狼向天狂嚎几声．\n",
                "恶狼眼里的绿光使你不寒而颤．\n"
	}) );

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob);
	}
}


void die()
{
	object ob;
	message_vision("$N仰天长嚎一声，死了！\n", this_object());
	ob = new(__DIR__"obj/langpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}

