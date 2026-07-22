// created 11/20/1997 by snowcat

inherit NPC;

void create()
{
  set_name("辟尘大王", ({ "pichen dawang", "dawang" }));
  set("title", "玄英洞");   
  set("long", "一位妖怪，鼻子上长着一根角。");
  set("gender", "男性");
  set("age",70);
  set_level(70);
  set("attitude", "heroism");
  set("per", 29);
  set("force_factor",700);
  set("mana_factor", 80);

  set_skill("spells",700);
  set_skill("dao",700);
  set_skill("unarmed",700);
  set_skill("dragonfight",700);
  set_skill("dodge",500);
  set_skill("jindouyun",700);
  set_skill("qianjun-bang",700);
  set_skill("parry",700);
  set_skill("force",700);
  set_skill("wuxiangforce",700);
  set_skill("stick",700);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("parry", "qianjun-bang");
  map_skill("stick", "qianjun-bang");
  set("env/wimpy",50);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qinglong/obj/stick")->wield();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N扑倒在地，还原为一头犀牛。\n",me);
  message_vision ("\n天空四木禽星一闪，犀牛被一道光捉了去！\n",me);
  destruct(me);
}

void unconcious ()
{
  die ();
}
