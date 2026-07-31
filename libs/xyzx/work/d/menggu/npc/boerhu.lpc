inherit NPC;
void create()
{
   set_name("博尔术",({"boer shu"}));
   set("gender","男性");
   set("long","铁木真手下四杰之一,勇猛过人!\n");
   set("shen",25000);
   set("combat_exp",120000);
   
set("age",45);
   set("kee",2000);
   set("max_kee",2000);
set("food",250);
set("water",250);
set("chat_chance",8);
set("chat_msg",({
"博尔术偷偷告诉你:只有九天浣花神箭才能对付草原上的鹰鹫.\n",
"博尔术叹道:悬崖下的白雕是鹰鹫的天敌.\n",
}));
   set("neili",1500);
   set("max_neili",1500);
   set("force_factor",60);

   set_skill("dodge",160);
   set_skill("force",160);
   set_skill("parry",160);
   set_skill("unarmed",160);
	set_skill("club", 140);
	set_skill("zhongping-qiang", 140);
	map_skill("club", "zhongping-qiang");

   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/tieqiang")->wield();
}
