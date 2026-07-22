// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("牛角大王", ({ "niujiao dawang", "dawang" }));
  set("long", "一位妖怪，鼻子上长着一根角。");
  set("gender", "男性");
  set("age",50);
  set_level(50);
  set("attitude", "heroism");
  set("per", 29);
  set("force_factor",500);
  set("mana_factor", 80);

  set_skill("spells",500);
  set_skill("dao",500);
  set_skill("unarmed",500);
  set_skill("dragonfight",500);
  set_skill("dodge",300);
  set_skill("jindouyun",500);
  set_skill("sanban-axe",500);
  set_skill("parry",500);
  set_skill("force",500);
  set_skill("wuxiangforce",500);
  set_skill("axe",500);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "sanban-axe");
  map_skill("axe", "sanban-axe");
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void unconcious ()
{
  die ();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N扑倒在地，还原为一头犀牛。\n犀牛一溜烟跑了。\n\n",me);
  destruct(me);
}