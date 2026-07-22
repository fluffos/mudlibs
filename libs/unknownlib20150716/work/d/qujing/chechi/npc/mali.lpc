// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("犸力大仙", ({"mali daxian", "daxian"}));
  set("gender", "男性");
  set("age", 40);
  set("attitude", "peaceful");
  set_level(47);
  set("daoxing", 3000000);

  set_skill("dodge",470);
  set_skill("parry",470);
  set_skill("force",470);
  set_skill("spells",470);
  set_skill("unarmed",470);
  set_skill("gouhunshu", 470);
  set_skill("tonsillit", 470);
  set_skill("ghost-steps",470);
  set_skill("jienan-zhi",470);
  
  map_skill("dodge", "ghost-steps");
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("eff_dx",-300000);
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