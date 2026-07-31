//LUCAS 2000-6-18
//snake.c

inherit NPC; 
#include <ansi.h>

void create()
{
        set_name("巨蟒", ({ "snake", "mang" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", HIB"一条巨蟒,有水桶粗,以吃小动物为生。\n"NOR);
        set("attitude", "aggressive");
        set("qi", 8000);
        set("max_qi", 8000);
        set("jing", 5000);
        set("max_jing", 5000);
        set("str",50);
        set("con",50);
        set("dex",50);
        set("int",5);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000000);

        
        set_temp("apply/attack", 85);
        set_temp("apply/damage", 80);
        set_temp("apply/armor", 88);
        set_temp("apply/defence",80);

        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("parry",100);
        set_skill("force",100);
        setup();

} 

int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 10 ) {
                ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG"你觉得被咬中的地方一阵麻木,看来中毒了！\n" NOR );
        }
}

void die()
{
        object ob, corpse;
        message_vision(RED"$N硕大一个蛇头高高抬起,然后慢慢委顿下来，死了！\n"NOR, this_object());
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        destruct(this_object());
}

