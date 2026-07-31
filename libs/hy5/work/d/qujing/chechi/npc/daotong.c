// by snowcat oct 22 1997

inherit NPC;

void create()
{
  set_name("µÀÍ¯", ({"dao tong", "dao", "tong"}));
  set("gender", "ÄÐÐÔ");
  set("combat_exp", 10000);
  set("combat_exp", 10000);

  set("age", 15);
  set("per", 20);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",3);
  set("max_jing",2000);
  set("max_qi",2000);
  set("max_jing",2000);
  set("max_neili",3000);
  set("max_neili",3000);
  set_skill("unarmed", 30+random(90));
  set_skill("dodge", 30+random(90));
  set_skill("parry", 30+random(90));
  set_skill("force", 30+random(90));
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
}


ÿ