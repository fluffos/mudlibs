// migong lev6

#include <ansi.h>

inherit NPC;



void create()

{
    
   set_name(HIW"白猿"NOR, ({ "bai yuan" , "yuan" }));
                set("race", "野兽");
       set("long",
"一只雪白的猿猴，看起来很有灵性。
。\n");
            
set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw" }) );
	       set("max_qi",40000+random(5000));
  set("max_qi",40000+random(5000));
  set("max_jing",40000+random(5000));
  set("max_sen",40000+random(5000));
  set("max_mana",40000+random(5000));
  set("max_neili",20000+random(5000));
  set("neili",20000+random(5000));
  
      set("dex",100);
     set("str" ,100);
set("no_get",1);
    set("age", 15);

       set("shen_type", -1);

        set("combat_exp", 6000000);
                  
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/defence", 200);
        set_skill("houquan", 400+random(100));

        set_skill("dodge", 300+random(100));

        set_skill("unarmed", 300+random(100));

       set_skill("parry", 300+random(100));

       map_skill("unarmed", "houquan");

       map_skill("parry", "houquan");


   setup();

    
   

}

int hit_ob(object me, object ob, int damage)
{
if (ob)
{
	ob->apply_condition("wugong_poison", 40);
        ob->apply_condition("chanchu_poison", 40);
        ob->apply_condition("xiezi_poison", 40);
        ob->apply_condition("snake_poison", 40);
        ob->apply_condition("zhizhu_poison", 40);
        tell_object(ob, HIG "你觉得被打中的地方一阵麻痒！\n" NOR );
}
}
void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse,obj;
               int exp,pot,score,i;
        int maxpot;
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;   
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));me->add("combat_exp",random(12));me->add("potential",random(8));

        if((int)me->query("combat_exp") < 4800000)   {
if (random(80) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"+corpse->query("name")+"!"NOR"。\n");
             corpse->move(killer);
}        
        message("vision", me->name() + "成功打死白猿增加了800经验和600潜能。\n", me);
        me->add("combat_exp",800);
        me->add("potential",600);
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));
                obj = new("/clone/box/gbox");
                obj->move(environment(this_object()));           
        destruct(ob);
        }
               destruct(ob);
        return;
}
