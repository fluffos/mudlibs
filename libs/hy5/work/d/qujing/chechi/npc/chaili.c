// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  string dir;

  set_name("²òÁ¦´óÏÉ", ({"chaili daxian", "daxian"}));
  set("gender", "ÄÐÐÔ");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 4200000+random(50000));
  set("combat_exp", 2500000);

  set_skill("dodge", 360);
  set_skill("parry", 360);
  set_skill("force", 360);
  set_skill("spells", 360);
  set("con", 70);
  set("cor", 70);
  set("int", 70);
  set("per", 70);
  set("spi", 70);
  set("cps", 70);
  //map_skill("dodge", "ghost-steps");

  set("max_jing", 3200);
  set("max_qi", 3200);
  set("max_jing", 3200);
  set("neili", 3200);
  set("max_neili", 3200);
  set("neili", 3200);
  set("max_neili", 3200);
  set("force_factor", 15);
  set("mana_factor", 80);
  setup();
       initlvl((180+random(180)),0);
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

