// create by snowcat 10/16/1997

inherit NPC;

void create()
{
  set_name("国王", ({"guo wang", "king" }));
  set("title","车迟国");
  set("gender", "男性");
  set("rank_info/respect", "陛下");
  set("age", 80);
  set_level(5);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("force_factor", 50);
  set("mana_factor", 40);

  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("spells", 50);
  set_skill("force", 50);
  set_skill("seashentong", 50);
  set_skill("dragonforce", 50);
  set_skill("dragonstep", 50);
  set_skill("dragonfight", 50);
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "dragonstep");
  map_skill("force", "dragonforce");
  map_skill("spells", "seashentong");
  set("eff_dx",30000);
  set("nkgain",180);
  
  setup();
  carry_object("/d/obj/cloth/mangpao")->wear();
  
}