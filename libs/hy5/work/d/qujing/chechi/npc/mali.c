// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  string dir;

  set_name("犸力大仙", ({"mali daxian", "daxian"}));
  set("gender", "男性");
  set("age", 40);
  set("attitude", "peaceful");
  set("combat_exp", 4700000+random(50000));
  set("combat_exp", 3000000);

  set_skill("dodge", 370);
  set_skill("parry", 370);
  set_skill("force", 370);
  set_skill("spells", 370);
  set_skill("unarmed", 370);

  set("con", 70);
  set("cor", 70);
  set("int", 70);
  set("per", 70);
  set("spi", 70);
  set("cps", 70);

  set("eff_dx",-300000);
  set("nkgain",400);

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



void die()
{
  //object bone = new ("/d/obj/misc/bone");

  //bone->move(environment(this_object()));
  message_vision ("\n$N浑身一软瘫在地上，化做一堆零散的兽骨。\n",
                  this_object());
  ::die();
}
