// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("老公公", ({"gong gong", "gong"}));
  set("gender", "男性");
   set("long",@LONG
白发如彭祖，苍髯赛寿星。耳中鸣玉磐，眼里幌金星。
手拄龙头拐，身穿鹤髦轻。数珠掐手中，口诵南无经。
LONG);
  set("age", 90);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 400000);
  set_skill("dodge", 60);
  set_skill("parry", 70);
  set_skill("force", 80);
  set_skill("spells", 80);
  set_skill("unarmed", 65);
  set_skill("gouhunshu", 65);
  set_skill("tonsillit", 70);
  set_skill("ghost-steps", 45);
  set_skill("jinghun-zhang", 75);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 750);
  set("max_kee", 650);
  set("max_sen", 880);
  set("force", 1000);
  set("max_force", 1000);
  set("mana", 1400);
  set("max_mana", 1000);
  set("force_factor", 65);
  set("mana_factor", 75);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/qujing/baigudong/obj/longtou");
}