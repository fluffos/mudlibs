// gao.c

inherit NPC;
int give_jade();
int show_king();

void create()
{
  set_name("国王", ({"ghost guo wang", "guo wang", "wang", "king"}));
  set("long", "头戴一顶冲天冠，腰束一条碧玉带，身穿一领飞龙舞凤赭黄袍。\n");
  set("title", "乌鸡国");
  set("gender", "男性");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set_level(1);
  set_skill("unarmed", 1);
  set_skill("dodge", 1);
  set_skill("parry", 1);
  set("max_gin", 1);
  set("max_kee", 1);
  set("max_sen", 1);
  
  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void die ()
{
  object king = this_object(); 
  message_vision ("$N大惊失色，噌地一声化为一缭青烟飞去。\n",king);
  destruct (king);
}

void unconcious()
{
  die();
}