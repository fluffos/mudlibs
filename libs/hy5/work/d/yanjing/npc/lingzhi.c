inherit NPC;
void create()
{
   set_name("灵智上人",({"lingzhi shangren"}));
   set("gender","男性");
   set("mingwang",-9000);
   set("combat_exp",123000);
   set("title","大手印");
   set("age",54);
   set("kee",780);
   set("max_kee",780);
   set("food",250);
   set("water",250);
   set("force",780);
   set("max_force",780);
   set("force_factor",30);

   set_skill("dodge",78);
   set_skill("force",59);
   set_skill("parry",97);
   set_skill("unarmed",104);
   set_skill("spear",23);
   set_skill("blade",78);
 
   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/jiasha")->wear();
}
