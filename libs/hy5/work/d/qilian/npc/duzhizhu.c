//fushe.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIB"¶¾Ö©Öë"NOR, ({ "du zhizhu", "zhizhu" }) );
	set("race", "Ò°ÊŞ");
	set("subrace", "ÅÀ³æ");
	set("age", random(10));
	set("long", "Ò»Ö»Éú»îÔÚ´óÄ®±ßÔµµÄ¶¾Ö©Öë¡£\n");
        set("attitude", "aggressive");
	    set("limbs", ({ "×ì","´¥½Ç", "ÉíÌå", "Î²´Ì"}));
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

