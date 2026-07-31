// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("老奶奶", ({ "lao nainai", "lao", "nainai", "queen" }));
  set("title", "压龙洞");   
  set("long", "一位扭腰摆臀的压龙洞妖后，身上隐隐地发出狐臭。\n");
  set("gender", "女性");
  set("age", 86);
  set("attitude", "heroism");
  set("per", 12);
  set("max_qi", 800);
  set("max_jing", 800);
  set("max_jing", 800);
  set("neili", 700);
  set("max_neili", 700);
  set("force_factor", 40);
  set("max_neili", 700);
  set("neili", 700);
  set("mana_factor", 40);
  set("combat_exp", 750000);
  set("combat_exp", 16000000);


  setup();
  initlvl((310+random(310)),58);
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object taishang = new ("/d/qujing/pingding/npc/taishang");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/pingding_laonai_killed",1);
  taishang->announce_success (ob);
  destruct (taishang); 
  }
  message_vision ("\n$N翻倒在地现了真身，是一只狐狸精。\n",me);
  message_vision ("狐狸精死了。\n",me);
::die();
}



void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  ::kill_ob(ob);
}


