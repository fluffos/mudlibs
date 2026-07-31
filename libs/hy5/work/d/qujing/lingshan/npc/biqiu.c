//Cracked by Roath
// snowcat 12 14 1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  if (random(2))
  {
    set_name("±ÈÇðÉ®", ({ "biqiu seng", "biqiu", "seng" }));
    set("gender", "ÄÐÐÔ");
  }
  else
  {
    set_name("±ÈÇðÄá", ({ "biqiu ni", "biqiu", "ni" }));
    set("gender", "Å®ÐÔ");
  }
  set("title", "ÁéÉ½");
  set("age", 80);
  set("attitude", "peaceful");
  set("str",40);
  set("per",40);
  set("max_qi", 1200);
  set("max_jing", 1200);
  set("max_jing", 1200);
  set("neili", 1200);
  set("max_neili", 1200);
  set("force_factor", 60);
  set("max_neili", 1200);
  set("neili", 1200);
  set("mana_factor", 60);
  set("combat_exp", 600000);
  set("combat_exp", 800000);



  setup();
        initlvl((300+random(300)),random(63));
  carry_object("/d/obj/cloth/jia_sha")->wear();
}

ÿ