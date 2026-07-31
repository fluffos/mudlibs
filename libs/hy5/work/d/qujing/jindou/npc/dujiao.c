// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"

void create()
{
  set_name("独角兕大王", ({ "dujiaosi dawang", "dujiaosi", "dawang", "wang" }));
  set("title", "金兜洞");   
  set("long", "一位身材壮实的大块头妖王，头上长着一只角。\n");
  set("gender", "男性");
  set("age", 70);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 236500);
  set("max_jing", 226500);
  set("max_jing", 226500);
  set("neili", 130000);
  set("max_neili", 130000);
  set("force_factor", 180);
  set("max_neili", 13000);
  set("neili", 1650);
  set("mana_factor", 185);

  set("combat_exp", 30000000);

  set_skill("spells", 90);

  set_skill("unarmed", 200);

  setup();
  initlvl((430+random(430)),18);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jindou/obj/qiang")->wield();
    carry_object("/d/qujing/jindou/obj/zhuoreal");

}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object fabao = present ("fabao",me);
object li = new ("/d/qujing/jindou/npc/lilao");
  if (ob)
  {
    ob->set_temp("obstacle/jindou_killed",1);
      li->announce_success (ob);
  destruct (li); 
  }
  message_vision ("\n一阵风吹来，传来天上李老君的声音：牛儿回家也！\n",me);
  message_vision ("\n$N闻声现了原身，果然是一头大青牛。\n",me);
  message_vision ("大青牛沿着李老君声音的方向奔去",me);
  if (fabao)
  {
     message_vision ("，丢下一只$n。\n",me,fabao);

  }
  else
    message_vision ("。\n",me);
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
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

