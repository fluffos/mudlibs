#include <ansi.h>

inherit NPC;
#include "/d/baituo/npc/snake.h"
void create()
{
        set_name("金环蛇", ({ "jin she", "she" }) );
        set("race", "蛇类");
        set("age", 2);
        set("long", "一只让人看了起毛骨悚然的金环蛇。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("cor", 20);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1500+random(200));
        set_temp("apply/attack", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence",15);
        set("shen_type",-1);
set("score",200);
setup();
}

void die()
{
        object ob;
        message_vision("$N倒在地上，死了！\n", this_object());
        ob = new("/d/baituo/obj/jindan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
/*
int hit_ob(object me, object ob, int damage)
{
        if ((int)ob->query("combat_exp") > 10000) return 1 ;
        if( random(damage) > (int)ob->query_temp("apply/armor")
                && (int)ob->query_condition("snake_poison") < 10 )
        {
                ob->apply_condition("snake_poison", 20);
                tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
        }
}
*/