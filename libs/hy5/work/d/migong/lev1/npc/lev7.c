// migong lev1

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(RED"蜈蚣"NOR, ({ "wu gong"}));
      
          set("race", "野兽");
       set("long",
"一只有毒的火红色大蜈蚣。
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
	       set("max_qi",500+random(500));
  set("max_jing",500+random(500));
  set("max_sen",500+random(500));
  set("max_mana",500+random(500));
  
      set("dex",20);
     set("str" ,25);
       
    set("age", 5);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 300000);
                  
        set_temp("apply/attack", 50);
        set_temp("apply/damage", 50);
        set_temp("apply/armor", 50);
        set_temp("apply/defence",50);

   setup();

        

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;int exp,pot;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;   
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上死了。\n"NOR,ob,me);
exp=8+random(5);
        if((int)me->query("combat_exp") < 400000) exp=exp*5;
pot=exp*3/4;
        message("vision", me->name() + "获得了"+exp+"点经验和"+pot+"点潜能。\n", me);
        me->add("combat_exp",exp);
        me->add("potential",pot);

	::die();
}



int hit_ob(object me, object ob, int damage)
{
   if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("wugong_poison") < 10 ) {
		ob->apply_condition("wugong_poison", 20);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
	}
}
