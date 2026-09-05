//qingshe.c
#include <ansi.h>
inherit NPC;
#include "/d/baituo/npc/snake.h"
void create()
{
        set_name("竹叶青蛇", ({ "qing she", "she" }) );
        set("race", "蛇类");
        set("age", 2);
        set("long", "一只让人看了起鸡皮疙瘩的竹叶青蛇。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("cor", 20);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 3000+random(300));
        set_temp("apply/attack", 18);
        set_temp("apply/damage", 15);
        set_temp("apply/armor", 12);
        set_temp("apply/defence",16);
        set("shen_type",-1);
set("score",200);
setup();
}

void die()
{
        object ob;
        message_vision("$N倒在地上，死了！\n", this_object());
        ob = new("/d/baituo/obj/qingdan");
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
