// created 11/6/1997 by snowcat

inherit NPC;

void create()
{
  string dir;
  set_name("金圣宫", ({"jinsheng gong", "gong", "queen"}));
  set("title", "朱紫国");
  set("gender", "女性");
  set("age", 28);
  set("per", 26);
  set("rank_info/respect", "娘娘");
  set_level(30);

  set_skill("snowsword",300);
  set_skill("sword",300);
  set_skill("dragonfight",300);
  set_skill("unarmed",300);
  set_skill("dodge",300);
  set_skill("parry",300);
  set_skill("spells",300);
  set_skill("dragonstep",300);
  map_skill("dodge", "dragonstep");
  map_skill("unarmed", "dragonfight");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
}
