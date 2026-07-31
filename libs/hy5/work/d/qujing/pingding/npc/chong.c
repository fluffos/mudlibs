// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("ÁæÀş³æ", ({ "lingli chong", "lingli", "chong" }));
  set("gender", "ÄĞĞÔ");
  set("age", 24);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 500);
  set("max_jing", 500);
  set("max_jing", 500);
  set("neili", 500);
  set("max_neili", 500);
  set("force_factor", 20);
  set("max_neili", 500);
  set("neili", 500);
  set("mana_factor", 20);
  set("combat_exp", 400000);
  set("combat_exp", 500000);

  set_skill("spells", 40);


  setup();
  initlvl((100+random(100)),13);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}
