// by snowcat 11/1/1997

inherit NPC;

void create()
{
  set_name("奔波儿灞", ({ "benboer ba", "ba" }) );
  set("gender", "男性" );
  set("title", "鲇鱼怪");
  set_level(49);
  set("age", 30);
  set("attitude", "heroism");

  set_skill("force",490);
  set_skill("spells",490);
  set_skill("unarmed",490);
  set_skill("sword",  490);
  set_skill("dodge",  490);
  set_skill("parry",  490);

  set("force_factor", 10);

  setup();

  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void die()
{
  object me = this_object();
  object fish = new("/d/qujing/jisaiguo/obj/fish");

  fish->set_name("鲇鱼",({"fish"}));
  fish->move(environment(me));
  message_vision("\n$N慢慢地倒下，现形为一条鲇鱼。\n",me);
  destruct(me);
}