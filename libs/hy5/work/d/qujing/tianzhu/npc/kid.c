#include <ansi.h>

inherit NPC;

void create()
{
  set_name("Ñ§Í¯", ({ "xue tong", "tong", "kid" }) );
  set("gender", "ÄÐÐÔ");
  set("age", 9);
  set("combat_exp", 100+random(10));
  set("attitude", "heroism");

  set("str", 20);
  set("max_qi", 100);
  set("max_jing", 100);
  set("neili", 100);
  set("max_neili", 100);

  setup();

  carry_object("/d/obj/cloth/linen")->wear();
}

