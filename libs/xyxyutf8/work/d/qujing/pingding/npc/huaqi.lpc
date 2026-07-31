// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("狐阿七大王", ({ "huaqi dawang", "huaqi", "dawang", "wang" }));
  set("title", "压龙洞");   
  set("long", "一位扭腰摆臀的压龙洞妖王，身上隐隐地发出狐臭。\n");
  set_level(75);
  set("gender", "男性");
  set("age", 64);
  set("attitude", "heroism");
  set("force_factor",750);
  set("mana_factor",750);

  set_skill("spells",750);
  set_skill("dao",750);
  set_skill("unarmed",750);
  set_skill("puti-zhi",750);
  set_skill("dodge",750);
  set_skill("jindouyun",750);
  set_skill("parry",750);
  set_skill("force",750);
  set_skill("wuxiangforce",750);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N翻倒在地现了真身，是一只狐狸精。\n",me);
  message_vision ("狐狸一溜烟跑了。\n",me);
  destruct (me);
}

void unconcious ()
{
  die ();
}
