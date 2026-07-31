// migong lev2

#include <ansi.h>

inherit NPC;


void create()

{
    
    set_name(HIY"采花淫僧"NOR, ({ "boss hua", "hua" }));
    
     set("gender", "男性" );
      set("long",
"一个采花无数的采花淫僧。\n");
        set("attitude", "aggressive");
      
  set("vendetta/authority",1);
	 
 set("force_factor",10+random(100));
 
 set("max_qi",25900+random(3900));
 
 set("max_jing",25900+random(3900));
 
 set("max_sen",25900+random(3900));
 
 set("max_neili",15900+random(3900));
 
 set("max_mana",25900+random(3900));
 
 set("eff_neili",19900+random(3900));
 
 set("neili",19900+random(3900));
        
   set("per", 1);
       
   set("age", 22);
     
    set("shen", -5000);
    set("no_get",1);    
     set("intellgent",1);
	
   set("pursuer",1);
        
  set("combat_exp", 2000000);
  
      
  set_skill("unarmed", 300);
         
  set_skill("sword", 300);

  set_skill("parry", 300);

   set_skill("dodge", 300);
        
  set_skill("force", 300);
	set_skill("hunyuan-yiqi", 185);
	set_skill("shaolin-shenfa", 185);
	set_skill("finger", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("buddhism", 185);
	set_skill("literate", 185);

set_skill("jingang-quan", 185);
	set_skill("damo-jian", 185);
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("parry", "nianhua-zhi");
       map_skill("sword", "damo-jian");
   map_skill("unarmed", "jingang-quan");
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
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));

        if((int)me->query("combat_exp") < 3300000)   {
        message("vision", me->name() + "成功打死采花淫僧增加了800经验和600潜能。\n", me);
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


