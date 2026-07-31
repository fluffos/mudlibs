// NPC : /d/wudang/npc/bird.c 小鸟
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"小鸟"NOR, ({ "xiao niao", "niao","bird"}) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只十分可爱的小鸟。\n");
        set("attitude", "peaceful");
        
        set("limbs", ({ "头部", "身体", "脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
        
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}

