//Cracked by Roath
//¡¾ÊñÉ½½£ÅÉ¡¿dhxy-evil 2000.7.5
inherit BHNPC;

string *names = ({
  "³¤ÉàÑý",
  "ÈýÍÈÑý",
  "É¨°ÑÑý",
  "¶ÏÍ·Ñý",
});

void create()
{
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("race", "Ò°ÊÞ");
  set("age", 100+random(201));
  set("combat_exp", 500000+random(500001));
  set("limbs", ({ "Í·²¿", "ÉíÌå", "Ç°×¦", "Î²°Í", "¶ÇÆ¤", "ºó×¦"}) );
  set("verbs", ({ "bite", "claw"}) );
  set("attitude", "aggressive");
  set("per", 10);
  set_skill("parry", 200);
  set_skill("unarmed", 200);
  set_skill("dodge", 200);
  set_skill("blade", 200);
  set("max_jing",2000);
  set("max_qi",2000);
  set("neili",2000);
  set("max_neili",1500);
  set("jiali",5000);
  setup();
 carry_object("/clone/weapon/blade")->wield();
}
