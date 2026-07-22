// migong lev1

#include <ansi.h>

inherit NPC;


void create()

{
    
    set_name("小贼", ({ "xiao zei", "zei" }));
    
     set("gender", "男性" );
      set("long",
"一个手脚灵快，专干偷鸡摸狗勾当的小混混。\n");
        set("attitude", "aggressive");
      
  set("vendetta/authority",1);
	 
 set("force_factor",5+random(100));
 
 set("max_qi",500+random(700));
 
 set("max_jing",500+random(700));
 
 set("max_sen",500+random(700));
 
 set("max_neili",500+random(700));
 
 set("max_mana",500+random(700));
 
 set("eff_neili",500+random(700));
 
 set("neili",500+random(700));
        
   set("per", 1);
       
   set("age", 22);
     
    set("shen", -5000);
    
     set("intellgent",1);
	
   set("pursuer",1);
        
  set("combat_exp", 150000);
  
        set("chat_chance", 40);
    
    set("chat_msg", ({
         
       "小贼喝道：竟然追到这里来了！！\n",
              
              (: random_move :),
        }) );

      
  set_skill("unarmed", 150);
         
  set_skill("blade", 150);

  set_skill("parry", 150);

   set_skill("dodge", 150);
        
  set_skill("force", 150);
       
   set_temp("apply/attack", 70);
      
  set_temp("ap5ly/defense", 70);
     
   set_temp("apply/armor", 70);
      
  set_temp("apply/damage", 70);

       
 setup();

       
 carry_object("/d/migong/obj/cloth")->wear();
    
   carry_object("/d/migong/obj/blade")->wield();
	
add_money("gold", 1);

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
