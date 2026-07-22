// NPC : /d/wudang/npc/shanji.c 山鸡
#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"山鸡"NOR, ({ "shan ji", "ji"}) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一只羽毛艳丽的大山鸡。\n");
        set("attitude", "peaceful");
        
        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 500);
        
        set_temp("apply/attack", 2);
        set_temp("apply/defense", 5);
        set_temp("apply/damage", 2);
        set_temp("apply/armor", 1);

        setup();
}

void die()
{
        object ob;
        message_vision("$N凄惨地鸣叫了几声，一头载到地上死了。\n", this_object());
        ob = new(FOOD_D("sjitui"));
        ob->move(environment(this_object()));
        destruct(this_object());
}
        
