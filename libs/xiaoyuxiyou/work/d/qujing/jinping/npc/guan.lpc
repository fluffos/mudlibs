#include <ansi.h>

inherit NPC;

void create()
{
  set_name("府官", ({ "fu guan", "guan" }) );
  set("gender", "男性");
  set("age", 40);
  set_level(29);
  set("attitude", "heroism");

  set("force_factor", random(30)+15);
  set_skill("unarmed", 240);
  set_skill("parry", 240);
  set_skill("dodge", 240);
  set_skill("blade",240);

  setup();

  carry_object("/d/obj/cloth/changpao")->wear();
}

