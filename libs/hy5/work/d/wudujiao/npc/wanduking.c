// by victori

inherit NPC;
#include <ansi.h>



void create()
{
        set_name(HIY"腾蛇王"NOR,({"dushe king"}));
	set("race", "野兽");
        set("long", "一条十丈多长一人来粗的大蛇，据说腾蛇万年可以化龙飞去。\n");
	set("age", 10000);
	set("attitude", "peaceful");

	set("max_jing", 20000);
	set("max_qi", 20000);
	set("eff_jing", 20000);
	set("eff_qi", 20000);
	set("jing", 20000);
	set("qi", 20000);

	set("str", 140);
	set("con", 150);

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 800);
        set_temp("apply/damage", 700);
       set_skill("unarmed",280);
       set_skill("parry",280);
       set_skill("dodge",280);
       set_skill("force",300);

	set("combat_exp", 500000);
 
        set_weight(500000);
	setup();
}
void init()
{
        object me;
        if (interactive(me = this_player()))
        {
me->start_busy(1);

      	       remove_call_out("kill_ob");
              call_out("kill_ob", 0, me);
        }
        ::init();
}

void die()
{
	string owner,name;
	object owner_ob;            
       object ob;
            message_vision("$N倒在地上，死了！但你从腾蛇的肚中发现了一样东西。\n", this_object());
            ob=new(__DIR__"obj/shenbian.c");
	      ob->move(environment(this_object()));
	      destruct(this_object());
}

int hit_ob(object me, object victim, int damage)
{
if (random(5) >3)
	       victim->apply_condition("snake_poison",
		        (int)victim->query_condition("snake_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("wugong_poison",
		        (int)victim->query_condition("wugong_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("zhizhu_poison",
		        (int)victim->query_condition("zhizhu_poison") + 3 );
else if (random(5) >3)
	       victim->apply_condition("xiezi_poison",
		        (int)victim->query_condition("xiezi_poison") + 3 );
else 	       
	       victim->apply_condition("chanchu_poison",
		        (int)victim->query_condition("chanchu_poison") + 3 );
       if ((string)victim->query("family/family_name") != "五毒教") {
	     	victim->apply_condition("snake_poison", 20
              +(int)victim->query_condition("snake_poison") );
              tell_object(victim, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}

