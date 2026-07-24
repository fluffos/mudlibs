// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
    set_name(HIR"山贼王"NOR, ({ "boss zei", "zei" }));
    
     set("gender", "男性" );
      set("long",
"一个抢家劫舍的恶棍大王。\n");
        set("attitude", "aggressive");
      
  set("vendetta/authority",1);
	 
 set("force_factor",10+random(100));
 
 set("max_qi",24900+random(3900));
 
 set("max_jing",24900+random(3900));
 
 set("max_sen",24900+random(3900));
 
 set("max_neili",24900+random(3900));
 
 set("max_mana",24900+random(3900));
 set("no_get",1);    
 set("eff_neili",9900+random(3900));
 
 set("neili",29900+random(3900));
        
   set("per", 1);
       
   set("age", 22);
     set("dex", 100);
    set("str", 100);
    set("shen", -5000);
    
     set("intellgent",1);
	
   set("pursuer",1);
        
  set("combat_exp", 1000000);
  
      
  set_skill("unarmed", 300);
         
  set_skill("sword", 300);

  set_skill("parry", 300);

   set_skill("dodge", 300);
        
  set_skill("force", 300);
       
   set_temp("apply/attack", 100);
      
  set_temp("ap5ly/defense", 100);
     
   set_temp("apply/armor", 100);
      
  set_temp("apply/damage", 300);

       
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
ob->start_busy(3);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
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


        if((int)me->query("combat_exp") < 2800000)   {
        message("vision", me->name() + "成功打死山贼王增加了800经验和600潜能。\n", me);
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


