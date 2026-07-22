// migong lev3

#include <ansi.h>

inherit NPC;


void create()

{
    
    set_name("大盗", ({ "dadao" }));
    
     set("gender", "男性" );
      set("long",
"满脸横肉，无恶不做的江洋大盗。\n");
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
     
    set("shen", -10000);
    
     set("intellgent",1);
	
   set("pursuer",1);
        
  set("combat_exp", 500000);
  
    set_skill("unarmed", 200);
         
  set_skill("sword", 200);

  set_skill("parry", 200);

   set_skill("dodge", 200);
        
  set_skill("force", 200);
 
set_skill("jinshe-jian", 200);
 
  set_skill("changquan", 200);
   
   map_skill("sword"  , "jinshe-jian");

map_skill("unarmed"  , "changquan");

prepare_skill("unarmed", "changquan");
   set_temp("apply/attack", 100);
      
  set_temp("ap5ly/defense", 100);
     
   set_temp("apply/armor", 100);
      
  set_temp("apply/damage", 100);

       
 setup();

       
 carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/sword")->wield();
	
add_money("gold", random(3));

}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment(ob)->query("no_fight") && random(10) < 5)
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
