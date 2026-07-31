// wolf.c
// Date: Sep.22 1997
#include <ansi.h>[D
inherit NPC;

void create()
{
        set_name(HIW"Ñ©ÀÇ"NOR, ({ "wolf", "lang" }) );
        set("race", "Ò°ÊÞ");
        set("age", 5);
        set("long", "Ò»Ö»¶ÀÐÐµÄÀÇ£¬°ëÕÅ×ÅµÄ´ó×ìÀïÂ¶×Å¼¸¿Åâ²ÑÀ¡£\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "ÀÇÍ·", "ÀÇÉí", "Ç°×¦", "ºó×¥", "Î²°Í" }) );
        set("verbs", ({ "bite", "claw" }) );
set("max_qi", 15000);
set("max_jing", 15000);
set("max_neili", 15000);

        set("combat_exp", 200000);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2300);
        set_temp("apply/damage", 2300);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "Ñ©ÀÇÞÇåå×ÅÎ²°Í£¬Í»È»Ì§Í·£¬³åÄã·¢³öÒ»ÉùÆàÀ÷µÄ³¤º¿¡£\n",
                "Ñ©ÀÇÉÁ×Å"+HIG" ÂÌÓÄÓÄµÄÑÛ¹â"+NOR"³åÄãÃéÁËÃé£¬ÑªÅè¾Þ¿ÚÀï´ð´ðµÎ×Å¹þÀ®×Ó¡£\n",
        }) );
}

void die()
{
        int a;
        object ob,me=this_player();
        a=me->query_temp("marks/bing");
        a=a|1;
        me->set_temp("marks/bing",a);
        ob = new(__DIR__"obj/langpi");
        ob->move(environment(this_object()));
        destruct(this_object());
}

        
