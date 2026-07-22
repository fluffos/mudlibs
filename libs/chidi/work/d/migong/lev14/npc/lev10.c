// migong lev14

#include <ansi.h>

inherit NPC;


void create()

{
    
   set_name(HIY"金龙"NOR, ({ "jin long" , "long" , "dragon" }));
                set("race", "野兽");
       set("long",
"一条浑身闪烁的金光的巨龙，看到了你，向你扑了过来。
。\n");
              set("attitude", "aggressive");
                set("vendetta/authority",1);

set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw"}) );
	       set("max_qi",20000+random(10000));
  set("max_jing",20000+random(10000));
  set("max_sen",20000+random(10000));
  set("max_mana",20000+random(10000));
  
      set("dex",100);
      set("con",100);
     set("str" ,100);
       
    set("age", 80);

       set("shen_type", -1);

        set("intellgent",1);

	set("pursuer",1);

        set("combat_exp", 8000000+random(2000000));
            set_temp("apply/attack", 400);
        set_temp("apply/damage", 400);
        set_temp("apply/armor", 400);
        set_temp("apply/defence",400);
      set_skill("dodge", 400+random(100));

      set_skill("unarmed", 400+random(100));

       set_skill("dragon", 400+random(100));

      map_skill("unarmed", "dragon");

      map_skill("dodge", "dragon");

    prepare_skill("unarmed", "dragon");
 set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
               
    (: perform_action, "unarmed.yaoyao" :),

 }) );
     set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
           }) );

    
     
   setup();

     
carry_object("/d/migong/obj/longdan");
    

}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
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
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$N一声怒吼，浑身鲜血直流，缓缓躺倒在地。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 10000000)   {
        message("vision", me->name() + "成功打死猎物增加了400经验和200潜能。\n", me);
        me->add("combat_exp",400);
        me->add("potential",200);
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}


