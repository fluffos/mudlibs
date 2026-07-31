// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("°ÍÉ½»¢", ({ "bashan hu", "bashan", "hu" }));
  set("gender", "ÄĞĞÔ");
  set("age", 34);
  set("attitude", "heroism");
  set("per", 30);
  set("max_qi", 600);
  set("max_jing", 600);
  set("max_jing", 600);
  set("neili", 600);
  set("max_neili", 600);
  set("force_factor", 30);
  set("max_neili", 600);
  set("neili", 600);
  set("mana_factor", 30);
  set("combat_exp", 500000);
  set("combat_exp", 800000);


  set_skill("unarmed", 50);

  setup();
   initlvl((320+random(320)),61);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}
