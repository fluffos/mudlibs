// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("独角兕大王", ({ "dujiaosi dawang", "dujiaosi", "dawang", "wang" }));
  set("title", "金兜洞");   
  set("long", "一位身材壮实的大块头妖王，头上长着一只角。\n");
  set("gender", "男性");
  set_level(88);
  set("age", 70);
  set("attitude", "heroism");
  set("per", 30);

  set_skill("spells",880);
  set_skill("dao",880);
  set_skill("unarmed", 880);
  set_skill("puti-zhi", 880);
  set_skill("dodge",880);
  set_skill("jindouyun",880);
  set_skill("parry", 880);
  set_skill("force",880);
  set_skill("spear",880);
  set_skill("wuxiangforce",880);
  set_skill("bawang-qiang",880);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/jindou/obj/qiang")->wield();
  if ("/d/qujing/jindou/obj/zhuoreal"->in_mud())
    carry_object("/d/qujing/jindou/obj/zhuofake");
  else
    carry_object("/d/qujing/jindou/obj/zhuoreal");
}

void die ()
{
  object me = this_object();
  message_vision ("\n一阵风吹来，传来天上李老君的声音：牛儿回家也！\n",me);
  message_vision ("\n$N闻声现了原身，果然是一头大青牛。\n",me);
  message_vision ("大青牛沿着李老君声音的方向奔去",me);
  destruct (me); 
}

void unconcious ()
{
  die ();
}
