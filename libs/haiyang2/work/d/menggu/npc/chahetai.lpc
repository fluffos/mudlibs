inherit NPC;
void create()
{
   set_name("察合台",({"cha hetai"}));
   set("gender","男性");
   set("long","铁木真的二儿子,生性粗鲁,两颗獠牙露在嘴唇外!\n");
   set("shen",-15000);
   set("combat_exp",100000);
   
     set("per",14);
   set("age",34);
   set("kee",1000);
   set("max_kee",1000);
   set("food",250);
   set("water",250);
   set("force",800);
   set("max_force",800);
   set("force_factor",40);
   
   set("chat_chance",5);
   set("chat_msg",({
  "我总看不顺眼拖雷这小子，老跟我作对。\n",
  "郭靖这傻小子居然还有人喜欢，老子早晚要把他杀了.\n",
  }));

   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("parry",100);
   set_skill("unarmed",100);
	set_skill("club", 40);
	set_skill("zhongping-qiang", 40);
	map_skill("club", "zhongping-qiang");


   setup();
   add_money("silver",20);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/yinqiang")->wield();
}
