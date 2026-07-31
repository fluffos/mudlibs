//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  if (random(2))
    set_name("°¢ÂÞ", ({ "a luo", "a", "luo" }));
  else
    set_name("½ÒÚÐ", ({ "jie di", "jie", "di" }));
  set("title", "ÁéÉ½");
  set("gender", "ÄÐÐÔ");
  set("age", 100);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_qi", 1800);
  set("max_jing", 1800);
  set("max_jing", 1800);
  set("neili", 1800);
  set("max_neili", 1800);
  set("force_factor", 80);
  set("max_neili", 1800);
  set("neili", 1800);
  set("mana_factor", 80);
  set("combat_exp", 1000000);
  set("combat_exp", 1500000);


  setup();
          initlvl((300+random(300)),random(63));
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

ÿ