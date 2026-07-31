inherit NPC;
#include <ansi.h>

string *first_name = ({ "青面", "金毛", "蓝皮", "长毛", "火焰"});
string *name_words = ({ "兽", "妖兽", "毒虫", "怪"});
void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name,({"shou"}));
        set("race", "野兽");
        set("long", "一只怪模怪样的野兽，正恶狠狠的盯着你。\n");
        set("age", 100); 
        set("attitude", "aggressive");

        set("max_jing", 10000); 
        set("neili", 10000); 
        set("max_neili", 100);        set("max_qi", 100000); 
        set("jiali", 700);
        set("str", 300);
        set("con", 300);

        set("limbs", ({ "头部", "身体", "尾巴","爪子" }) );
        set("verbs", ({ "bite" }) );

      set_skill("unarmed", 500);
      set_skill("dodge", 1000);
        set_temp("apply/attack", 800);
        set_temp("apply/defense", 800);
        set_temp("apply/armor", 800);

        set("combat_exp", 5000000+random(40)*200000);
 
        set_weight(500000);
        setup();
}

int hit_ob(object me, object ob, int damage)
{
       if ((string)ob->query("family/family_name") != "玄天派") {
              ob->apply_condition("fire_poison", 900
              +(int)ob->query_condition("fire_poison") );
              tell_object(ob, HIR "你觉得被咬中的地方一阵发烫！\n" NOR );
        }
}

