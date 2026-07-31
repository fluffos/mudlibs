#include <ansi.h>
inherit NPC;
void random_chat();
int answer();
void create()
{
   set_name("清雅",({"sighmoon"}));
   set("gender","女性");
   set("age",18);
   set("per",40);
   set("combat_exp",20000);
set("long","她可是小人物的师父哦!绝对的高手...你可以向他打听使用的emote,
(ask sighmoon about this emote).\n");
   set_skill("unarmed",10);
   set_skill("dodge",10);
   set_skill("force",10);
   set_skill("parry",10);
   set_skill("stealing",10);
   set_skill("literate",10);
   
   set("chat_chance",10);
   set("chat_msg",({
   (:random_chat:),
}));
   
  
   set("inquiry",([
   "this emote":(:answer:),
   ]));
   
   setup();
   add_money("silver",30);
	carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
  ::init();
  add_action("do_vendor_list","list");
}
void random_chat()
{
  string *e,str="";
   int i;
   object npc,*inv;
   
   inv=all_inventory(environment(this_object()));
	if(!sizeof(inv))	return;
 
   e = sort_array(EMOTE_D->query_all_emote(), 1);
   str=e[random(sizeof(e))];
   command(str+" "+inv[random(sizeof(inv))]->query("id"));
   set("answer",str);  
   return;
}
int answer()
{
 command("say 这个emote么,是("+query("answer")+").\n");
 return 1;
 }
