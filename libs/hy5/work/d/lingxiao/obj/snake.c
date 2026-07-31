//LUCAS 2000-6-18
//snake.c

inherit NPC; 
#include <ansi.h> 

string* sheobj = ({
     "/d/lingxiao/obj/blood"
     "/d/baituo/obj/shepi" 
     "/d/shenlong/obj/shedan"
});

void create()
{
        set_name(HIW"雪山怪蛇"NOR, ({ "snake", "she" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只雪山怪蛇,它通体雪白,眼如烈炎,看来这个冰洞是它的巢穴。\n");
        set("attitude", "aggressive");
        set("qi", 5000);
        set("max_qi", 5000);
        set("jing", 500);
        set("max_jing", 500);
        set("str", 100);
        set("cor", 90);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1500000); 

        
        set_temp("apply/attack", 85);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 88);
        set_temp("apply/defence",80); 

        carry_object("sheobj[random(sizeof(sheobj))]");

        setup();

} 

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 10 ) {
                ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻木,看来中毒了！\n" NOR );
        }
}


