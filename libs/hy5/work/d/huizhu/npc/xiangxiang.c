inherit NPC;
void create()
{
   set_name("香香公主",({"gong zhu"}));
   set("gender","女性");
   set("long","木卓伦的小女儿,自幼体有异香!\n");
   set("score",2000);
   set("combat_exp",40000);
   set("area_name","回族牧群");
   
set("per",35);
set("age",17);
   set("qi",900);
   set("max_qi",900);
set("food",250);
set("water",250);
   set("neili",500);
   set("max_neili",500);
   set("force_factor",10);

   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set_skill("whip",80);

   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/whip")->wield();
}
