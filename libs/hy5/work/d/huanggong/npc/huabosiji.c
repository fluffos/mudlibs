inherit NPC;
void create()
{
   set_name("华伯斯基",({"huabo siji"}));
   set("gender","男性");
   set("age",45);
   set("combat_exp",51000);
   set("mingwang",200);
   set("long","这位是俄罗斯使者.\n");
   set_skill("unarmed",10);
   set_skill("parry",10);
   set_skill("dodge",10);
   set_skill("literate",10);
   set("chat_chance",4);
   set("chat_msg",({
  "华伯斯基道:我们正在等候康熙大帝的接见.\n",
  "华伯斯基道:你好!你好!how are you?\n",
  }));
   
   setup();
   add_money("silver",10);
}