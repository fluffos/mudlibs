//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/npc/yao.c

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
   set_name("食人魔", ({ "shiren mo", "yao"}));
   set("gender", "男性" );
   set("age", 35);
   set("long","一个专门吃人的老妖怪。\n");
   set("max_qi",1200);
   set("max_neili",1200);
   set("neili",1200);
   set("force_factor", 40);
   set("max_neili",1200);
   set("neili",1200);
   set("combat_exp", 10050000);
   set("attitude","aggressive");
   set_skill("unarmed", 130);

   setup();
   initlvl((300+random(250)),5);
   carry_object("/clone/misc/cloth")->wear();
  // carry_object("/d/qujing/village/obj/hammer")->wield();
}

int accept_fight (object ob)
{
  
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die()
{
        object ob=query_temp("my_killer");
	if(ob->query_temp("seen"))
	{       ob->add_temp("yao_killed",1);}
        ::die();
}
