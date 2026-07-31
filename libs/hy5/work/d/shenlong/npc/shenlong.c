inherit NPC;

void kuser();

void create()
{
    set_name("五彩神龙", ({ "shenlong" }) );
    set("race", "野兽");
    set("age", 20);
    set("long", "一条粗如水桶的巨蛇，身长几十丈，口中不断地喷着毒雾\n");
    set("attitude", "peaceful");
	
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 300000);
	set("qi",10000);
	set("eff_qi",10000);
	set("max_qi",10000);
       set("jing",10000);
       set("max_jing",10000);

	set_temp("apply/attack", 200);
	set_temp("apply/defense", 400);
	set_temp("apply/damage", 280);
	set_temp("apply/armor", 400);
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

void die()
{
	object ob1,ob2,who;
    message_vision("$N惨叫了数声，挣扎了几下就不动了。\n", this_object());
	ob1 = new(__DIR__"obj/sl_dan");
	ob1->move(environment(this_object()));
       who=this_object()->query_temp("last_damage_from");
	if(objectp(who))
	{
	if(!objectp(ob2 = new(__DIR__"obj/sl_cloth")))
		ob2 = new(__DIR__"obj/sl_pi");
	ob2->set_temp("owner",who);
	ob2->move(who);
	}
       if(objectp(who) && userp(who) && living(who) && who->query_temp("marks/hant"))
                who->set_temp("marks/dragon",1);

	destruct(this_object());
}
	


 
