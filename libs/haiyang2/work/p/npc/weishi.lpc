#include <ansi.h>
inherit NPC;
void create()
{
   set_name(HIG"帮会卫士"NOR,({"wei shi"}));
   set("no_get",1);
   set("gender","男性");
   set("long","保卫帮派的一个卫士!\n");
   set("mingwang",2000);
   set("combat_exp",500000);
      
set("age",18+random(30));
set("qi",1500);
   set("max_qi",1500);
set("food",250);
set("water",250);
   set("neili",3000);
   set("max_force",1000);
   set("force_factor",20+random(30));

   set_skill("dodge",100+random(50));
   set_skill("force",100+random(50));
   set_skill("parry",100+random(50));
   set_skill("unarmed",100+random(50));
   set_skill("blade",100+random(50));

   setup();
   add_money("silver",5);
carry_object("clone/cloth/cloth")->wear();
carry_object("clone/weapon/gangdao")->wield();
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
  command("say 你尽然在这里动手?");
    kill_ob(ob);
    return;
   }
   return;
}

