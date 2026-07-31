// wubushe.c

#include <ansi.h>

inherit SNAKE;

void create()
{
	set_name("五步蛇", ({ "wubu she", "she" }));
	set("long", "五步蛇是福建地方毒蛇，相传中毒行路五步即行倒毙。\n");

	set("race", "野兽");
	set("age", 3);
	set("attitude", "peaceful");

	set("max_ging", 180);
	set("max_qi", 300);

	set("str", 10);
	set("con", 50);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("snake_poison", ([
		"level"  : 50,
		"perhit" : 25,
		"remain" : 50,
		"maximum": 50,
		"supply" : 2,
	]));

	set_temp("apply/attack",  50);
	set_temp("apply/damage",  10);
	set_temp("apply/defense", 70);
	set_temp("apply/armor",   10);

	set("combat_exp", 6000);
	setup();
}
