// created 11/20/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("美后", ({ "mei hou", "hou", "queen" }));
  set("title", "比丘国");   
  set("long", "一位娇俊无比，貌似观音的王后。\n");
  set("gender", "女性");
  set("age", 17);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 333700);
  set("max_jing", 333700);
  set("max_jing", 333700);
  set("neili", 333700);
  set("max_neili", 333700);
  set("force_factor", 60);
  set("max_neili", 333700);
  set("neili", 400);
  set("mana_factor", 60);
  set("combat_exp", 410000);
  set("combat_exp", 55500000);


  setup();
    initlvl((600+random(600)),53);
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
  carry_object("/d/qujing/biqiu/obj/neck")->wear();
  carry_object("/d/qujing/biqiu/obj/wrists")->wear();
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}

void die ()
{
  object ob = query_temp("my_killer");
  object me = this_object();

  if (ob)
    ob->set_temp("obstacle/biqiu_hou",1);
  message_vision ("\n$N扑在地上现了原身，原是一只狐狸精。\n",me);
  me->set_name("狐狸精", ({"huli jing", "huli", "jing"}));
  ::die();
}

void unconcious ()
{
  die ();
}

