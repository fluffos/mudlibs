inherit NPC;
void create()
{
   set_name("王府亲兵",({"qin bing"}));
   set("gender","男性");
   set("long","守卫王府的士兵!\n");
        set("shen_type",-1);
   set("combat_exp",50000);
   
set("age",25);
   set("qi",500);
   set("max_qi",500);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",30);

   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
   set_skill("club",100);

   setup();
   add_money("silver",4);
carry_object(__DIR__"obj/pijia")->wear();
carry_object(__DIR__"obj/tiespear")->wield();
}
