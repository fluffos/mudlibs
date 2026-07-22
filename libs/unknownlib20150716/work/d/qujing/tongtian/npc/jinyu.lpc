//Cracked by Roath
// created 12/18/1997 by snowcat

inherit NPC;

void create()
{
  set_name("金鳞怪", ({ "jinlin guai", "jinglin", "guai" }));
  set("title", "通天河");   
  set("long", "一位身着金甲的妖怪。\n");
  set("gender", "男性");
  set("age", 76);
  set_level(70);
  set("attitude", "aggressive");
  set("per",700);
  set("force_factor", 100);
  set("max_mana", 600);
  set("mana_factor", 20);

  set_skill("spells",700);
  set_skill("dao",700);
  set_skill("unarmed",700);
  set_skill("hammer",700);
  set_skill("dragonfight",700);
  set_skill("dodge",700);
  set_skill("dragonstep", 700);
  set_skill("parry",700);
  set_skill("force", 70);
  set_skill("dragonforce", 700);
  map_skill("spells", "dao");
  map_skill("unarmed", "dragon-step");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  setup();
  carry_object("/d/obj/armor/jinjia")->wear();
  carry_object("/d/obj/weapon/hammer/bahammer")->wield();
}

void die ()
{
  object me = this_object();
  message_vision ("\n$N一甩尾巴，现出金鱼的原身。\n",me);
  message_vision ("\n天上怒喝一声：金鱼，归我莲花池也！\n",me);
  message_vision ("金鱼闻声，乖乖地一纵身扭着腰摇晃着头游走了。\n",me);
  destruct (me);
}

void unconcious ()
{
  die ();
}