#include <ansi.h>
inherit NPC;
void create()
{
        set_name(RED "°ßìµÃÍ»¢" NOR, ({ "lao hu","tiger" }) );
        set("race", "Ò°ÊÞ");
        set("age", 20);
        set("attitude","aggressive");
        set("str",100);
        set("long",RED "    Ò»Ö»Ð×ÃÍµÄµõ¾¦°×¶î½õÃ«´ó³æ!!" NOR+"µ«¼û:\n"+@LONG
               Ã«ÅûÒ»´ø½ð»ÆÉ«£¬×¦Â¶Òø¹³Ê®°ËÖ»¡£
               ¾¦ÈçÉÁµçÎ²Èç±Þ£¬¿ÚËÆÑªÅèÑÀËÆêª¡£
               ÉìÑüÕ¹±ÛÊÆÕøÄü£¬°ÚÎ²Ò¡Í·ÉùÅùö¨¡£
               É½ÖÐºüÍÃ¾¡Ç±²Ø£¬½§ÏÂâ¯Â¹½ÔÁ²´ï¡£
LONG);

        set("limbs", ({ "Í·²¿", "ÉíÌå", "Î²°Í" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1000000);
        setup();
        carry_object(__DIR__"obj/tigercloth")->wear();
}


