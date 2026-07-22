// migong lev6

#include <ansi.h>

inherit NPC;



void create()

{
    
   set_name(HIW"白猿"NOR, ({ "bai yuan" , "yuan" }));
                set("race", "野兽");
       set("long",
"一只雪白的猿猴，看起来很有灵性。
。\n");
            
set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" , "claw" }) );
	       set("max_qi",10000+random(5000));
  set("max_jing",10000+random(5000));
  set("max_sen",10000+random(5000));
  set("max_mana",10000+random(5000));
  
      set("dex",100);
     set("str" ,100);
       
    set("age", 15);

       set("shen_type", -1);

        set("combat_exp", 5000000);
                  
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/defence", 200);
        set_skill("houquan", 300+random(100));

        set_skill("dodge", 300+random(100));

        set_skill("unarmed", 300+random(100));

       set_skill("parry", 300+random(100));

       map_skill("unarmed", "houquan");

       map_skill("parry", "houquan");


   setup();

    
   

}
int accept_object(object who, object ob)
{
	   if ((string)ob->query("id")=="xian tao") {
            say("白猿开心的叫了一声，往北面一闪。\n");
             move("/d/migong/lev6/dong102");
            }
		return 1;
}