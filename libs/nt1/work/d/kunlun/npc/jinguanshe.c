//jinshe.c
#include "ansi.h"
inherit NPC;
void create()
{
        set_name("金冠血蛇", ({ "jinguan she", "she" }) );
        set("race", "野兽");
        set("age", 2);
        set("no_die",1);
        set("long", "一条头生金冠，身生四足，通体血红的蛇。\n");
     set("attitude", "friendly");
        set("str", 20);
        set("cor", 20);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 1500+random(200));
        set_temp("apply/attack", 20);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence",15);
        setup();
}
void init()
{
        object ob;
        ::init();
        if (interactive(this_player()))
        {
                if (!(ob = present("xionghuang", this_player())))          
                {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, this_player());
                }
        }
}
void die()
{
        object ob;
        message_vision("$N倒在地上，死了！\n", this_object());
        ob = new(__DIR__"obj/jindan");
        ob->move(environment(this_object()));
        destruct(this_object());
}
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
