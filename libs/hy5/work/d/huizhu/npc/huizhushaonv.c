inherit NPC;
void create()
{
   set_name("回族少女",({"shao nv"}));
   set("gender","女性");
   set("combat_exp",4000);
   set("area_name","回族牧群");
   set("score",300);
   
set("per",25);
set("age",19);
   set("qi",500);
   set("max_qi",500);
set("food",250);
set("water",250);
   set("force",100);
   set("max_force",100);
   set("force_factor",10);

   set_skill("dodge",20);
   set_skill("force",20);
   set_skill("parry",20);
   set_skill("unarmed",20);
   set_skill("whip",20);
   set_skill("sword",20);
   set_skill("club",20);

   setup();
   add_money("silver",1);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/whip")->wield();
}
