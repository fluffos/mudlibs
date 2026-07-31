// bear.c
// Date: Sep.22 1997

inherit NPC;
#include <ansi.h>;

void create()
{
        set_name( WHT"白熊"NOR, ({ "hei xiong", "bear","xiong" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只凶猛的白熊，形体硕大，人立而行。\n");
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "熊头", "熊身", "前爪", "后爪" }) );
        set("verbs", ({ "bite", "claw" }) );
set("max_qi", 15000);
set("max_jing", 15000);
set("max_neili", 15000);
        set("combat_exp", 300000);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2300);
        set_temp("apply/damage", 2300);


        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "白熊冲着你摇头摆尾地，不知道是什么意思。\n",
                "白熊挤了挤鼻子，你觉得它好象在笑，顿时一阵紧张。\n",
        }) );
}

void die()
{
        object ob, corpse;
        message_vision("$N震天动地一声惨嚎，慢慢委顿在地，死了！\n", this_object());
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        ob = new(__DIR__"xiongdan");
        ob->move(corpse);
        corpse->move(environment(this_object()));
        destruct(this_object());
}
