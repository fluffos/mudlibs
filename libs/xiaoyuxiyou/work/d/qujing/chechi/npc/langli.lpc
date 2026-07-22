// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("狼力大仙", ({"langli daxian", "daxian"}));
  set("gender", "男性");
  set("age", 40);
  set("attitude", "peaceful");
  set_level(37);

  set_skill("dodge", 370);
  set_skill("parry", 370);
  set_skill("force", 370);
  set_skill("spells", 360);
  set_skill("unarmed", 360);
  set_skill("gouhunshu", 320);
  set_skill("tonsillit", 320);
  set_skill("ghost-steps", 340);
  set_skill("jienan-zhi", 340);
  map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-400000);
  set("nkgain",400);

  set("force_factor", 15);
  set("mana_factor", 80);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}

void unconcious()
{
  object bone = new ("/d/obj/misc/bone");

  bone->move(environment(this_object()));
  message_vision ("\n$N浑身一软瘫在地上，化做一堆零散的兽骨。\n",
                  this_object());
  destruct(this_object());
}

void die()
{
	unconcious();
}