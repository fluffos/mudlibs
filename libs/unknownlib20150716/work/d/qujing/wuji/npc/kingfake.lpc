// gao.c

inherit NPC;

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "头戴一顶冲天冠，腰束一条碧玉带，身穿一领飞龙舞凤赭黄袍。\n");
  set("title", "乌鸡国");
  set("gender", "男性");
  set("age", 46);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set_level(40);

  set("force_factor", 10);
  set("mana_factor", 30);
  set_skill("unarmed",400);
  set_skill("dodge",400);
  set_skill("force",400);
  set_skill("parry",400);
  set_skill("fork",400);
  set_skill("spells",400);
  set_skill("seashentong",400);
  set_skill("dragonfight",400);
  set_skill("dragonforce",400);
  set_skill("fengbo-cha",400);
  set_skill("dragonstep",400);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");
  set("eff_dx",-30000);
  set("nkgain",180);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void die ()
{
  object me = this_object ();
  message_vision ("$N发出一声长长的哀鸣，在尘土里现了青毛狮子的原身！\n",me);
  message_vision ("\n青毛狮子瞪着琉璃盏红眼，喘着粗气。\n",me);
  destruct (me);   
}