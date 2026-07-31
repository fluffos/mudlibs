//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.7
//  /d/qujing/village/npc/yao.c

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
   set_name("雪猿", ({ "xue yuan", "yao"}));
   set("gender", "男性" );
   set("age", 35);
   set("long","一个专门吃人的雪猿。\n");
   set("max_qi",120000);
   set("max_neili",120000);
   set("neili",120000);
   set("force_factor", 400);
   set("max_neili",1200);
   set("neili",1200);
   set("combat_exp", 10500000);
   set("attitude","aggressive");
   set_skill("unarmed", 130);

   setup();
   initlvl((300+random(280)),4);
   carry_object("/clone/misc/cloth")->wear();
   carry_object(__DIR__"test");
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
