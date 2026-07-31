//fushe.c

inherit SNAKE;
#include <ansi.h>

void create()
{
	set_name("腹蛇", ({ "fu she", "she" }));
	set("race", "野兽");
	set("age", random(10));
	set("long", "只见它全身血红，头呈三角，长蛇吞吐，嗤嗤做响。\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("con", 20);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("snake_poison", ([
		"level"  : 120,
		"perhit" : 10,
		"remain" : 20,
		"maximum": 20,
		"supply" : 1,
	]));

	set("combat_exp", 50000 + random(50000));

	set_temp("apply/attack", 20+random(10));
	set_temp("apply/damage", 10+random(10));
	set_temp("apply/armor",  15+random(10));
	set_temp("apply/defence",50+random(50));
	setup();
}

void die()
{
	object ob;
	message_vision("$N倒在地上，死了！\n", this_object());
	ob = new("/clone/misc/shedan");
	ob->move(environment(this_object()));
	::die();
}
