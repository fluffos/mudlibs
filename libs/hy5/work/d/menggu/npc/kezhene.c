inherit NPC;
void create()
{
   set_name("柯镇恶",({"ke zhene"}));
   set("gender","男性");
   set("long","江南七怪之首,可惜七年前被黑风双煞废了招子!\n");
   set("mingwang",90000);
   set("combat_exp",180000);
   set("title","飞天蝙蝠");
   
set("age",54);
   set("kee",1800);
   set("max_kee",1800);
set("food",250);
set("water",250);
   set("neili",1800);
   set("max_neili",1800);
   set("force_factor",20);

   set_skill("dodge",180);
   set_skill("force",180);
   set_skill("parry",180);
   set_skill("unarmed",180);
   set_skill("staff",180);

   setup();
   add_money("silver",80);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tiezhang")->wield();
}
