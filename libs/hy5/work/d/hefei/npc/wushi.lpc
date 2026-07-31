
inherit NPC;

void create()
{
   set_name("武士",({ "wu shi","wu","shi" }) );
   set("gender", "男性" );
   set("age",25);

   set("long", "这是一名武士。\n");
       
   set("combat_exp", 100000);
   set("str",25);
   set("per",15);
   
   set("eff_jing",1000);
   set("eff_qi",1000);
   set("eff_jing",1000);
   set("max_force",1000);
   set("force",1000);
   
   set_skill("blade",100);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("force",100);

   
   
   setup();
   
   carry_object(__DIR__"obj/blade")->wield();

}

