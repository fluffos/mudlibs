inherit NPC;
void create()
{
   set_name("蒙古铁骑",({"menggu bing"}));
   set("gender","男性");
   set("long","贴身保护铁木真的士兵!\n");
   set("shen",2000);
   set("combat_exp",80000);
   
set("age",18+random(30));
set("qi",9500);
   set("max_qi",9500);
set("food",250);
set("water",250);
   set("neili",19000);
   set("max_neili",19000);
   set("force_factor",20+random(30));

     set_temp("apply/attack",  150);
        set_temp("apply/defense", 150);
	set("shen_type", 1);

 set("max_qi",3300+random(5690));
  set("max_jing",3300+random(5890));
  set("max_sen",3300+random(5890));
  set("max_neili",5000);
  set("max_mana",3300+random(5890));
  set("eff_neili",3300+random(5390));
  set("neili",5000);
        set("str", 35);
        set("per", 25);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(2000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.kuang" :),
                (: perform_action, "blade.kuang" :),
                (: perform_action, "blade.leitingpili" :),
        }) );


        set_skill("unarmed", 280+random(380));
        set_skill("blade", 280+random(380));
        set_skill("parry", 280+random(380));
        set_skill("dodge", 280+random(380));
        set_skill("kuang-blade", 280+random(180));
        set_skill("taiji-shengong", 280+random(180));
	map_skill("blade", "kuang-blade");
	map_skill("parry", "kuang-blade");
	map_skill("force", "taiji-shengong");
        set_temp("apply/attack", 160);
        set_temp("apply/defense",160);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 190);

   setup();
   add_money("silver",5+random(20));
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/blade")->wield();
}
