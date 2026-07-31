inherit NPC;
int give_food();
void create()
{
   set_name("张山嫂",({"sansao","saozi","woman"}));
   set("gender","女性");
   set("shen_type",1);
   set("age",32);
   set("combat_exp",30000);
   set("long","张山嫂的心很好,你如果饿了的话,可以
向她要些吃的(ask sansao about eat).\n");
  
   set_skill("unarmed",150);
   set_skill("dodge",150);
   set_skill("parry",150);
   set_skill("literate",130);
   set_skill("force",130);

   set("inquiry",([
     "吃":(:give_food:),
     "eat":(:give_food:),
     ]));
  setup();
carry_object("/clone/misc/cloth")->wear();
add_money("coin",random(50));
}
int give_food()
{
  object ob;
  ob=this_player();
  if (ob->query("mingwang")<0)  {
       command("say 老娘的馒头情愿喂狗,也不给坏人吃.\n");
       return 1;
            }
  else command("say 饿了吧,这个馒头快拿着.\n");
   new("/d/sandboy/obj/mantou")->move(this_object());
  command("give mantou to "+ob->query("id"));
  return 1;
}