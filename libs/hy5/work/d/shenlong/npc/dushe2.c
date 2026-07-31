inherit NPC;

void kuser();

void create()
{
    set_name("毒蛇", ({ "dushe", "snake", "she" }) );
    set("race", "野兽");
    set("age", 20);
    set("long", "一条黄中间黑的毒蛇，全身血红、长舌吞吐、嗤嗤作声、头作三角\n");
    set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 20000);
	
	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);
	call_out("kuser",5);
	setup();
}

void kuser()
{
      object *ob,me;
      int i;
      
      me=this_object();
        if(!environment(me))  return;
      ob = all_inventory(environment(me));
      for(i=0;i<sizeof(ob);i++)
      {
          if(userp(ob[i]))
	  {
          	me->kill_ob(ob[i]);
		ob[i]->kill_ob(me);
	  } 
      }
      call_out("kuser",5);
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 8);
        return 0;
}

 
