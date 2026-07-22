// created 11/6/1997 by snowcat

inherit NPC;

void create()
{
  string dir;
  set_name("毗蓝婆", ({"pilan po", "po", "daogu"}));
  set("title", "道姑");
  set("gender", "女性");
  set("age", 58);
  set("per", 26);
  set("rank_info/respect", "菩萨");
  set("combat_exp", 1000000);
  set("daoxing", 1500000);

  set_skill("snowsword", 90);
  set_skill("sword", 90);
  set_skill("dragonfight", 90);
  set_skill("unarmed", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("spells", 90);
  set_skill("dragonstep", 90);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("max_gin", 900);
  set("max_kee", 900);
  set("max_sen", 900);
  set("force", 900);
  set("max_force", 900);
  set("mana", 900);
  set("max_mana", 900);
  set("force_factor", 90);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
}