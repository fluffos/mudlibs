inherit NPC;
void create()
{
      set_name("伐木工",({"famu gong","worker"}));
      set("gender","男性");
      set("age",20+random(40));
      set("shen_type",1);
      set("combat_exp",30000+random(40000));
      set("str",40);
      set("per",16);
      set_skill("unarmed",15);
      set_skill("parry",15);
      set_skill("dodge",15);
      set("chat_chance",3);
      set("chat_msg",({
                     "伐木工抡起大斧砍起树来.\n",
                     "伐木工瞄了瞄砍的缺口，使劲一推，‘轰'的一声，树倒了.\n",
                     "伐木工把砍下的松木码成一堆儿.\n",
               }));
      setup();
      carry_object("/clone/misc/cloth")->wear();
      carry_object(__DIR__"obj/axe")->wield();
      add_money("silver",10);
 }
void init()
{
   object ob;
   ::init();
     if (interactive(ob=this_player())&&!is_fighting())
           {   remove_call_out("greeting");
               call_out("greeting",1,ob);
           }
}
void greeting(object ob)
{   if (!ob||environment(ob)!=environment()) return;
    if (ob->query_temp("work/kan")==1)
       {   command("say 是来干活的吧，请用(kan wood).\n");
            return;
        }
   else return;
}