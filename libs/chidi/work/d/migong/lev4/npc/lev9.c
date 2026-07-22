// migong lev4

#include <ansi.h>

inherit NPC;


void create()

{
    
    set_name(HIG"僵尸"NOR, ({ "jiangshi" , "shi" }));
    
     set("gender", "男性" );
      set("long", "浑身都是绿色的液体，令人恶心。\n");
        set("attitude", "aggressive");
      
  set("vendetta/authority",1);
	 
 set("force_factor",20+random(200));
 
 set("max_qi",1500+random(1000));
 
 set("max_jing",1500+random(1000));
 
 set("max_sen",1500+random(1000));
 
 set("max_neili",1500+random(1000));
 
 set("max_mana",1500+random(1000));
 
 set("eff_neili",1500+random(1000));
 
 set("neili",1500+random(1000));
        
   set("per", 1);
       
   set("age", 22);
     
    set("shen", -1000);
    
     set("intellgent",1);
	
   set("pursuer",1);
        
  set("combat_exp", 1500000);
  
    set_skill("unarmed", 200);
         
    set_skill("parry", 200);

   set_skill("dodge", 200);
        
    set_temp("apply/attack", 100);
      
  set_temp("ap5ly/defense", 100);
     
   set_temp("apply/armor", 100);
      
  set_temp("apply/damage", 100);

       
 setup();

       
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
        
        message_vision(WHT"$N啪的一声瘫倒在地上。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") < 700000)   {
        message("vision", me->name() + "成功打死猎物增加了50经验和25潜能。\n", me);
        me->add("combat_exp",50);
        me->add("potential",25);
        destruct(ob);
        }
              me->add("score",1);
               destruct(ob);
        return;
}


