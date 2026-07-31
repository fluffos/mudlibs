inherit NPC;
void create()
{
   set_name("蒙古牧民",({"mu min"}));
   set("gender","男性");
   set("long","铁木真部落中族人!\n");
   set("shen",5000);
   set("combat_exp",60000);
   
set("age",54);
   set("kee",600);
   set("max_kee",600);
set("food",250);
set("water",250);
   set("neili",200);
   set("max_neili",200);
   set("force_factor",20);

   set_skill("dodge",60);
   set_skill("force",60);
   set_skill("parry",60);
   set_skill("unarmed",60);

   setup();
   add_money("silver",3);
carry_object(__DIR__"obj/cloth")->wear();
}
