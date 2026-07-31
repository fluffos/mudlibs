//Cracked by Roath
inherit NPC;

void create()
{
  set_name("òùòð¾«", ({"bianfu jing","jing"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("long","Ò»¸öÔôÃ¼ÊóÑÛµÄÀÏÑý¾«¡£\n");
  set("combat_exp", 300000+random(3000));
  set("combat_exp", 300000);

  set("per", 15);
  set_skill("dodge", 130);
  set_skill("parry", 130);
  set_skill("unarmed", 130);
  set_skill("force", 130);
  set_skill("spells", 130);
  set_skill("dagger", 130);

  set("max_jing",8000);
  set("max_qi",8000);
  set("max_jing",8000);

  set("max_neili", 5000);
  set("neili", 500);
  set("force_factor", 25);
  set("max_neili", 500);
  set("neili", 500);
  set("mana_factor", 25);

  setup();
  carry_object("/d/qujing/kusong/obj/needle0")->wield();
  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

ÿ