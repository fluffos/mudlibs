//by dwolf
// pig.c 

#include <ansi.h>  
inherit NPC;

void create()
{
	set_name(RED"野猪"NOR, ({ "pig" }) );
	set("race", "野兽");
	set("age", 24);
	set("long", "一头凶恶的野猪。\n");
	set("attitude", "aggressive");
	
	set("str", 80);
	set("cor", 50);

	set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 100000);

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 36);
	set_temp("apply/armor", 50);

	setup();
}
