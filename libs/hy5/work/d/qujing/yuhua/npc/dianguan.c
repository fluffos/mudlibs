#include <ansi.h>

inherit NPC;

void create()
{
  set_name("µî¹Ù", ({ "dian guan", "guan" }) );
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("combat_exp", 100000+random(20000));
  set("attitude", "heroism");

  set("str", 30);
  set("max_qi", 400);
  set("max_jing", 400);
  set("neili", 400);
  set("max_neili", 400);
  set("force_factor", random(30)+15);
  set_skill("unarmed", 40);
  set_skill("parry", 40);
  set_skill("dodge", 40);
  set_skill("blade", 40);

  setup();

  carry_object("/d/obj/cloth/gongpao")->wear();
}

