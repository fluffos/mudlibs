//Cracked by Roath
// tang.c 唐老板 
#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"唐老板"NOR, ({ "tang nan", "tang" }));
	set("title", "当铺老板");
	set("shen_type", 0);

	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long",
		"一个微胖的中年老板，看起来很和气。\n");
	set("no_get_from", 1);

	set("dex", 80);
	set("str", 80);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set("qi", 100000);
	set("max_qi", 100000);
	set("jing", 100000);
	set("max_jing", 100000);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
}

void unconcious()
{
	message_vision("\n突然，只见$N闪身拉开柜台下一道暗门，钻了进去，咔嚓从里边把门锁上了。\n",
		this_object());
	destruct(this_object());
}

void die()
{
	message_vision("\n$N死了。\n", this_object());
	destruct(this_object());
}
int accept_kill(object me)
{
	command("say 光天化日之下竟敢行凶杀人，没王法了吗？\n");
	me->apply_condition("killer", 100);
	return 1;
}

