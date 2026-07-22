// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("老奶奶", ({ "lao nainai", "lao", "nainai", "queen" }));
  set("title", "压龙洞");   
  set("long", "一位扭腰摆臀的压龙洞妖后，身上隐隐地发出狐臭。\n");
  set("gender", "女性");
  set("age", 86);
  set("attitude", "heroism");
  set("per", 12);
  set_level(80);
  set("force_factor", 40);
  set("mana_factor", 40);

  set_skill("spells",800);
  set_skill("dao",800);
  set_skill("unarmed",800);
  set_skill("puti-zhi",800);
  set_skill("dodge",800);
  set_skill("jindouyun",800);
  set_skill("parry",800);
  set_skill("force",800);
  set_skill("wuxiangforce",800);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N翻倒在地现了真身，是一只狐狸精。\n",me);
  message_vision ("狐狸精一溜烟跑了。\n",me);
  destruct (me); 
}

void unconcious ()
{
  die ();
}
