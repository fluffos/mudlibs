// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("银角大王", ({ "yinjiao dawang", "yinjiao", "dawang", "wang" }));
  set("title", "莲花洞");   
  set("long", "一位神态傲然的莲花洞妖王。\n");
  set("gender", "男性");
  set("age", 54);
  set_level(90);
  set("attitude", "heroism");
  set("force_factor",900);
  set("mana_factor",900);

  set_skill("spells",900);
  set_skill("dao",900);
  set_skill("unarmed",900);
  set_skill("puti-zhi",900);
  set_skill("dodge",900);
  set_skill("jindouyun",900);
  set_skill("parry",900);
  set_skill("force",900);
  set_skill("wuxiangforce",900);
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
  message_vision ("\n$N无可奈何地现了真身，原来是太上老君的银角童子。\n",me);
  message_vision ("\n银角童子鞠了个躬：时辰已到，去见太上老君也。\n",me);
  message_vision ("银角童子往外奔去",me);
  destruct (me);
}
