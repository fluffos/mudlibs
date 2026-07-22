// written by smile 12/09/1998

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("黑面山神", ({"heimian shanshen", "shanshen"}));
  set("gender", "男性");
  set("age", 70);
  set_level(90);
  set("attitude", "friendly");
  set("per", 20);
  set_skill("dodge", 100);
  set_skill("force", 100);
  set_skill("parry", 100);
  set_skill("spells",100);
  set_skill("dao", 100);
  set_skill("puti-zhi", 100);
  set_skill("jindouyun", 100);
  set_skill("wuxiangforce",100);
  map_skill("force","wuxiangforce");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("spells", "dao");
  set("max_sen",1800);
  set("max_gee",1800);
  set("max_gin",1800);
  set("force",800);
  set("max_force",800);
  set("max_mana",1280);
  set("force_factor",60);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}