// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(MAG"毒蜥"NOR, ({ "du long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条浑身发紫，丑陋不堪的毒蜥，看到了你，向你扑了过来。
。\n");
             // set("attitude", "aggressive");
               // set("vendetta/authority",1);
set("title",HIR"四脚神龙"NOR);
set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",2000+random(1000));
  set("max_jing",2000+random(1000));
  set("max_sen",2000+random(1000));
  set("max_mana",2000+random(1000));
  
      set("dex",30);
      set("con",30);
     set("str" ,30);
       
    set("age", 30);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);
 set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.yaoyao" :),

   (: perform_action, "unarmed.tuwu" :),

 }) );
        set("combat_exp", 80000+random(20000));
            set_temp("apply/attack", 10);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/defence",10);
      set_skill("dodge", 50+random(100));

      set_skill("unarmed",50+random(100));

       set_skill("dragon", 50+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
     
   setup();

    

     

}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		 name() + "消失在附近的草丛中。\n" , environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("number",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
        who=this_player();

        
        who->apply_condition("zdizi_busy",6);
        level=who->query("combat_exp");
        set("no_drop",1);
        set("no_get",1);
	set("double_attack", who->query("double_attack"));
	set("szj", who->query("szj"));

	set("str", (who->query("str") > 60 ? 60 : who->query("str")));
	set("int", (who->query("int") > 60 ? 60 : who->query("int")));
	set("con", (who->query("con") > 60 ? 60 : who->query("con")));
	set("dex", (who->query("dex") > 60 ? 60 : who->query("dex")));
	set("kar", (who->query("kar") > 60 ? 60 : who->query("kar")));
	set("combat_exp", (int)(who->query("combat_exp",1)*3/4));
	set("max_neili", who->query("max_neili",1));
	set("neili", query("max_neili"));
	set("max_qi", who->query("max_qi",1));
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("max_jing", who->query("max_jing",1));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("fooz", (query("str") + 10) * 10);
	set("water", (query("str") + 10) * 10);
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			fight_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->fight_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}
void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
		enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->fight_ob(enemy[i]);
                        enemy[i]->fight_ob(owner);
                }
        }

	}

}

void unconcious()
{
        die();
}

void die()
{
        object ob;
        message_vision("$N爬了出去！\n", this_object());

        destruct(this_object());
}


int hit_ob(object me, object ob, int damage)
{
   if( (random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("shenlong_poison") < 10) 
	|| random(5)==0
	) {
		ob->apply_condition("shenlong_poison", 10);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
	}
}
