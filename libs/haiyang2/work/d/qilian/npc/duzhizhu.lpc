//fushe.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIB"毒蜘蛛"NOR, ({ "du zhizhu", "zhizhu" }) );
	set("race", "野兽");
	set("subrace", "爬虫");
	set("age", random(10));
	set("long", "一只生活在大漠边缘的毒蜘蛛。\n");
        set("attitude", "aggressive");
	    set("limbs", ({ "嘴","触角", "身体", "尾刺"}));
    set("verbs", ({ "bite" }) );
	set("str", 20);
	set("cor", 20);
	set("combat_exp", 30000+random(500000));

	set_temp("apply/attack", 120+random(10));
	set_temp("apply/damage", 10+random(10));
	set_temp("apply/armor", 15+random(10));
	set_temp("apply/defence",120+random(10));
	setup();
}

