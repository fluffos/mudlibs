// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("蜜", ({"mi"}));
  set("title", "虫怪");
  set("gender", "男性");
  set("age", 12);
  set("per", 9);
  set_level(41);
  set("long", "一只虫模虫样的妖怪，长有二尺五六寸，重约八九斤。\n");
  set("attitude", "aggressive");

  set("force_factor", 18);
  set_skill("unarmed",410);
  set_skill("dodge",410);
  set_skill("parry",410);
  setup();
  carry_object("/d/obj/cloth/shoupi")->wear();
}

void die ()
{
  message_vision ("\n$N变成一只小虫儿嘤嘤地飞走了。\n",this_object());
  destruct (this_object());
}

void unconcious ()
{
  die ();
}