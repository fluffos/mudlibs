#include <ansi.h>

inherit NPC;

void create()
{
  set_name("士兵", ({ "shi bing", "bing" }) );
  set("gender", "男性");
  set("age", 15+random(15));
  set_level(18);
  set("attitude", "heroism");

  set("force_factor", random(50)+25);
  set_skill("unarmed", 180);
  set_skill("parry", 180);
  set_skill("dodge", 180);
  set_skill("blade", 180);

  setup();

  carry_object("/d/obj/weapon/blade/wandao")->wield();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}

