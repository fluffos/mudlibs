// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("Ì«¼à", ({"tai jian", "jian"}));
  set("gender", "ÄĞĞÔ");
  set("combat_exp", 70000);
  set("age", 40);
  set("per", 25);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",10);
  set("max_jing",500);
  set("max_qi",500);
  set("max_jing",500);
  set("max_neili",600);
  set("max_neili",600);
  set_skill("unarmed", 40);
  set_skill("dodge", 40);
  set_skill("parry", 40);
  set_skill("force", 40);
  set_skill("spells", 40);
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
}

