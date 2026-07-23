
inherit NPC;

void create()
{
   set_name("武士",({ "wu shi","wu","shi" }) );
   set("gender", "男性" );
   set("age", 32);
   set("long", "这是一个浪迹江湖的武士。\n");
       
   set("combat_exp",60000);
   set("str", 25);
   set("per", 20);
   set_skill("blade",80);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("force",80);
   set("max_jing",500);
   set("max_sen",500);
   set("max_qi",500);
   set("force",500);
   set("max_force",500);

   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
   carry_object(__DIR__"obj/blade")->wield();
  
}

