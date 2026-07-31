//jinshe.c

#include "ansi.h"

inherit SNAKE;

void create()
{
	set_name("金环蛇", ({ "jin she", "she" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只让人看了起毛骨悚然的金环蛇。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("con", 20);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("snake_poison", ([
		"level"  : 40,
		"perhit" : 20,
		"remain" : 40,
		"maximum": 40,
		"supply" : 2,
	]));

	set("combat_exp", 2500+random(1200));

	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 18);
	set_temp("apply/defence",15);
	setup();
}

void die()
{
	object ob;
	message_vision("$N倒在地上，死了！\n", this_object());
	ob = new("/d/baituo/npc/obj/jindan");
	ob->move(environment(this_object()));
	::die();
}
