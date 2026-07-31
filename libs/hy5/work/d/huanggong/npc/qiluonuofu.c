inherit NPC;
void create()
{
   set_name("齐洛诺夫",({"qiluo nuofu"}));
   set("gender","男性");
   set("age",45);
   set("combat_exp",5000);
   set("mingwang",200);
   set("long","这位是俄罗斯使者.\n");
   set_skill("unarmed",10);
   set_skill("parry",10);
   set_skill("dodge",10);
   set_skill("literate",10);
   set("chat_chance",4);
   set("chat_msg",({
  "齐洛诺夫道:我们正在等候康熙大帝的接见.\n",
  "齐洛诺夫道:我们带了许多美女,珠宝来求和.\n",
  }));
   
   setup();
   add_money("silver",10);
}