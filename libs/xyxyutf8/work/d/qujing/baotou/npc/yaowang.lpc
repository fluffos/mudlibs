// create by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("妖王", ({"yao wang", "wang" }));
  set("title","黄狮精");
  set("gender", "男性");
  set_level(59);
  set("age", 40);
  set("attitude", "aggressive");
  set("shen_type", 1);
  set("per", 30);
  set("force_factor",590);
  set("mana_factor", 40);

  set_skill("unarmed",590);
  set_skill("dodge",590);
  set_skill("parry",590);
  set_skill("spells",590);
  set_skill("force",590);
  set_skill("staff",590);
  set_skill("gouhunshu",590);
  set_skill("tonsillit",590);
  set_skill("ghost-steps",590);
  set_skill("jinghun-zhang",590);
  set_skill("lunhui-zhang",590);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-80000);
  set("nkgain",100);
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/baotou/obj/siming")->wield();
  
}

void die()
{
  object me = this_object();
  object where = environment();

  message_vision("只见$N摔倒在地，现了本形。原来是只金毛狮子！\n",me);
  message_vision("金毛狮子一溜烟，走远了。\n",me);
  destruct(me);
}

void unconcious()
{
  die();
}