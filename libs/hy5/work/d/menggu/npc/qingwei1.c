inherit NPC;
void create()
{
   set_name("Ñ²ÂßÇ×±ø",({"qin bing"}));
   set("gender","ÄÐÐÔ");
   set("long","ÔÚÓªÕÊÖÐÑ²ÂßµÄÇ×ÎÀ±ø!\n");
   set("shen",2000);
   set("combat_exp",80000);
   set("area_name","ÃÉ¹Å²ÝÔ­");
   
set("age",18+random(30));
set("qi",5500);
   set("max_qi",5500);
set("food",250);
set("water",250);
   set("neili",1000);
   set("max_neili",1000);
   set("force_factor",20+random(30));

   set_skill("dodge",100+random(50));
   set_skill("force",100+random(50));
   set_skill("parry",100+random(50));
   set_skill("unarmed",100+random(50));
   set_skill("blade",100+random(50));
   set("chat_chance",5);
   set("chat_msg",({
   	(:random_move:),
   }));

   setup();
   add_money("silver",5+random(20));
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/blade")->wield();
}
void init()
{
  object ob;
  ::init();
  if (interactive(ob=this_player())&&!is_fighting())  {
  	remove_call_out("greeting");
  	call_out("greeting",1,ob);
    }
  }
void greeting(object ob)
{ 
  if (!ob||environment(ob)!=environment())  return;
  if (ob->query("banghui")!=query("banghui"))   {
    kill_ob(ob);
    return;
   }
   return;
}

