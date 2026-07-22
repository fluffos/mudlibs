#include <ansi.h>

inherit NPC;

void create()
{
  set_name("殿官", ({ "dian guan", "guan" }) );
  set("gender", "男性");
  set("age", 40);
  set_level(4);
  set("attitude", "heroism");

  set("str", 30);
  set("force_factor", random(30)+15);
  set_skill("unarmed", 40);
  set_skill("parry", 40);
  set_skill("dodge", 40);
  set_skill("blade", 40);

  setup();

  carry_object("/d/obj/cloth/gongpao")->wear();
}

