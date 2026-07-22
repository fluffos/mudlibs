// written by smile 12/13/1998

inherit NPC;

void create()
{
  set_name("灵吉菩萨", ({"lingji pusa", "pusa"}));
  set("long", "一位慈眉善目的老人，闻说法力高强，
在此设院讲经传道，渡化世人。\n");
  set("gender", "男性");
  set("age", 80);
  set("attitude", "friendly");
  set("combat_exp", 2000000);
  set("per", 100);
  set_skill("dodge", 200);
  set_skill("force", 200);
  set_skill("spells",190);
  set_skill("unarmed",200);
  set_skill("buddhism", 190);
  set_skill("jienan-zhi", 200);
  set_skill("lotusmove", 160);
  set_skill("lotusforce",180);
  map_skill("force","lotusforce");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("spells", "buddhism");
  set("max_sen",3000);
  set("max_gee",3000);
  set("max_gin",3000);
  set("force",3000);
  set("max_force",3000);
  set("max_mana",3000);
  set("mana",3000);
  set("force_factor",175);
  set("mana_factor",100);
  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
	(: cast_spell, "bighammer" :),
        }) );
  setup();

  carry_object("/d/qujing/huangfeng/obj/jiasha")->wear();
}