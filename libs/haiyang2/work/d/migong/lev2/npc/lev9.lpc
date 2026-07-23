// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
    set_name("山贼", ({ "shan zei", "zei" }));
    
     set("gender", "男性" );
      set("long",
"一个抢家劫舍的恶棍。\n");
        set("attitude", "aggressive");
      
  set("vendetta/authority",1);
	 
 set("force_factor",10+random(100));
 
 set("max_qi",1900+random(900));
 
 set("max_jing",1900+random(900));
 
 set("max_sen",1900+random(900));
 
 set("max_neili",2900+random(900));
 
 set("max_mana",2900+random(900));
 
 set("eff_neili",2900+random(900));
 
 set("neili",900+random(900));
        
   set("per", 1);
       
   set("age", 22);
     
    set("shen", -5000);
    
     set("intellgent",1);
	
   set("pursuer",1);
        
  set("combat_exp", 300000);
  
      
  set_skill("unarmed", 200);
         
  set_skill("sword", 200);

  set_skill("parry", 200);

   set_skill("dodge", 200);
        
  set_skill("force", 200);
       
   set_temp("apply/attack", 100);
      
  set_temp("ap5ly/defense", 100);
     
   set_temp("apply/armor", 100);
      
  set_temp("apply/damage", 100);

       
 setup();

       
 carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/sword")->wield();
	
add_money("gold", 2);

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
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;    
              me->add("score",1);
        message_vision(WHT"$N啪的一声瘫倒在地上死了。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 800000)   {
        message("vision", me->name() + "成功打死猎物增加了40经验和20潜能。\n", me);
        me->add("combat_exp",40);
        me->add("potential",20);
        destruct(ob);
        }
               destruct(ob);
        return;
}
