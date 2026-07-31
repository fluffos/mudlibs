// snake.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIG"竹叶青"NOR, ({ "zhuye qing", "snake" }) );
	set("long", "一只昂首吐着"HIR"红信"NOR"的"HIG"竹叶青"NOR"正虎视眈眈地盯著你。\n");
	set("race", "野兽");
	set("age", 3);
	set("attitude", "peaceful");
	set("max_jing", 80);
	set("max_qi", 80);

	set("str", 10);
	set("cor", 50);
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	set("combat_exp", 2000);
	setup();
}

void init()
{
        object me,ob;
        ::init();
        if (interactive(me = this_player()))
        {
	if (!(ob = present("xionghuang", this_player())))          
               {
	       remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
		}
        }
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 20);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
