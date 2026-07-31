// create by snowcat 11/6/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("妖王", ({"yao wang", "wang" }));
  set("title","黄狮精");
  set("gender", "男性");
  set("age", 40);
  set("attitude", "aggressive");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_qi", 1000);
  set("max_jing", 1000);
  set("max_jing", 1000);
  set("neili", 800);
  set("max_neili", 800);
  set("force_factor", 70);
  set("max_neili", 800);
  set("neili", 800);
  set("mana_factor", 40);
  set("combat_exp", 560000);
  set("combat_exp", 65600000);


  set("eff_dx",-80000);
  set("nkgain",100);
  
  setup();
  initlvl((700+random(700)),57);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baotou/obj/siming")->wield();
  
}

void die()
{
  object me = this_object();
  object where = environment();

  message_vision("只见$N摔倒在地，现了本形。原来是只金毛狮子！\n",me);
  set_name("金毛狮子", ({"yao wang", "wang" }));
  delete("title");
  ::die();
}

void unconcious()
{
  die();
}
