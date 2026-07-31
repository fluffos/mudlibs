//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("ÆÐÈø", ({ "pu sa", "pu", "sa" }));
  set("title", "ÁéÉ½");
  set("gender", "ÄÐÐÔ");
  set("age", 1000);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_qi", 3000);
  set("max_jing", 3000);
  set("max_jing", 3000);
  set("neili", 3000);
  set("max_neili", 3000);
  set("force_factor", 120);
  set("max_neili", 3000);
  set("neili", 3000);
  set("mana_factor", 120);
  set("combat_exp", 1600000);
  set("combat_exp", 3000000);

  set_skill("spells", 140);


  setup();
          initlvl((300+random(300)),random(63));
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

ÿ