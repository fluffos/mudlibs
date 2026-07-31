// modified by smile 12/12/1998
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("老妇人", ({"fu ren", "fu", "ren"}));
  set("gender", "女性");
    set("long",@LONG
两鬓如冰雪，行步需怯怯。
弱体瘦伶仃，脸如枯菜叶。
颧骨望上翘，嘴唇往下别。
LONG);
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 512000);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  set_skill("force", 70);
  set_skill("spells", 70);
  set_skill("unarmed", 70);
  set_skill("gouhunshu", 70);
  set_skill("tonsillit", 70);
  set_skill("ghost-steps", 70);
  set_skill("jinghun-zhang", 70);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 850);
  set("max_kee", 900);
  set("max_sen", 700);
  set("force", 950);
  set("max_force",950);
  set("mana", 980);
  set("max_mana", 1500);
  set("force_factor", 70);
  set("mana_factor", 75);
  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/baigudong/obj/zhuzhang");
}
