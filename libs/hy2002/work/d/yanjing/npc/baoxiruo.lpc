inherit NPC;
void create()
{
   set_name("包惜弱",({"bao xiruo"}));
   set("gender","女性");
   set("long","现在的王妃,当年临安牛家村的扬家嫂子!\n");
   set("mingwang",6000);
   set("combat_exp",6000);
   set("title","王妃");
   
set("per",30);
set("age",38);
   set("qi",500);
   set("max_qi",500);
set("food",250);
set("water",250);
   set("neili",100);
   set("max_neili",100);
   set("force_neili",10);

   set_skill("dodge",20);
   set_skill("force",20);
   set_skill("parry",20);
   set_skill("unarmed",20);
   set_skill("club",30);
   set_skill("literate",20);

   set("inquiry",([
   "扬铁心":"铁心,你知道?可惜他过世快十八年了!\n",
   "扬康":"这几天不知怎的,老爱往后院跑!\n",
   "铁枪":"是我丈夫遗留下来的,可不能给你.\n",
  ]));
   setup();
   add_money("silver",6);
carry_object(__DIR__"obj/skirt")->wear();
carry_object(__DIR__"obj/haltspear");
}
