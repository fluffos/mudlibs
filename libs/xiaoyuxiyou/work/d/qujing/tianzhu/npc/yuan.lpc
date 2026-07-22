#include <ansi.h>

inherit NPC;

void create()
{
  set_name("元先生", ({ "yuan xiansheng", "xiansheng", "yuan" }) );
  set("gender", "男性");
  set("age", 50);
  set_level(10);
  set("attitude", "heroism");

  set("force_factor", random(10)+15);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set_skill("blade", 30);

  setup();

  carry_object("/d/obj/cloth/changpao")->wear();
}

