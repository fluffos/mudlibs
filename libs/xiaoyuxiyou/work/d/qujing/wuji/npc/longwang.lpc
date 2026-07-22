//Changed 
#include <skill.h>
inherit NPC;

void create()
{
  set_name("井龙王", ({"jing longwang","longwang","wang"}));
  set("long","井里的龙王，掌管着井底的世界。\n");
  set("gender", "男性");
  set("age", 55);
  set("class","dragon");
  set("attitude", "peaceful");
  set("shen_type", 1);
  set_level(80);

  set("rank_info/respect", "陛下");
  set("force_factor", 90);
  set("mana_factor", 40);
  set_skill("unarmed",800);
  set_skill("dodge",800);
  set_skill("force",800);
  set_skill("parry",800);
  set_skill("fork",800);
  set_skill("spells",800);
  set_skill("seashentong",800);
  set_skill("dragonfight",800);
  set_skill("dragonforce",800);
  set_skill("fengbo-cha",800);
  set_skill("dragonstep",800);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");

  setup();

  carry_object("/d/obj/cloth/longpao")->wear();
}