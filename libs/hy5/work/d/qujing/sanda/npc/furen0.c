//Cracked by Roath
// 妖神之争  １。０
//  happ@YSZZ 2000.4.13

#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("老妇人", ({"fu ren", "fu", "ren"}));
  set("gender", "女性");
  set("real",1);
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 14000000);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
 
  set("max_jing", 700);
  set("max_qi", 700);
  set("max_jing", 700);
  set("neili", 800);
  set("max_neili", 800);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  initlvl((300+random(300)),5);
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/baoxiang/obj/zhuzhang");
}

void unconcious()
{
  die();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
    object corpse,pusa;
pusa = new ("/d/qujing/sanda/npc/pusa");

  if (ob)
  {
    ob->set_temp("obstacle/sanda_furen_killed",1);
   pusa->announce_success (ob);
  destruct (pusa);
  }
  message_vision ("\n$N翻倒在地上，死了，现出一堆白骨。\n",me);

::die();
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/sanda/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}


int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}


void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
