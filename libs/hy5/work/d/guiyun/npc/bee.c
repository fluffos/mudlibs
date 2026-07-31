// Npc: /d/guiyun/npc/bee.c
// Last Modified by winder on Jul. 9 2001

inherit NPC;

void create()
{
        set_name("ÃÛ·ä", ({ "bee", "mifeng", "feng" }) );
	set("race", "Ò°ÊŞ");
	set("subrace", "·É³æ");
        set("age", 2);
        set("long", "Ò»Ö»·ÉÀ´·ÉÈ¥µÄĞ¡ÃÛ·ä¡£\n");
	set("attitude", "aggressive");
        set("combat_exp", 500);
    set("limbs", ({ "×ì","´¥½Ç", "ÉíÌå", "Î²´Ì"}));
    set("verbs", ({ "bite" }) );
	set_temp("apply/attack", 5);
        set_temp("apply/defense", 4);
        set_temp("apply/damage", 5);
        set_temp("apply/armor", 2);

        setup();
}
