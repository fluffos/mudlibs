// created 12/18/1997 by snowcat

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("ÒÐº£Áú", ({ "yihai long", "yihai", "long" }));
  set("gender", "ÄÐÐÔ");
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
  set("combat_exp", 500000);


  setup();
  initlvl((100+random(100)),0);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

ÿ