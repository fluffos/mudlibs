// created 4/4/1997 by snowcat

inherit NPC;

void create()
{
  set_name("梅鸳鸯", ({"mei yuanyan", "mei"}));
  set_level(41);
  set("title", "护宫女使");
  set("gender", "女性");
  set("age", 42);
  set("long", "一位看护西梁宫殿的女使臣。\n");

  set_skill("snowsword",410);
  set_skill("sword",410);
  set_skill("unarmed",410);
  set_skill("dodge",410);
  set_skill("parry",410);
  set_skill("dragonstep",410);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");

  set("force_factor", 4);

  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  carry_object("/d/obj/weapon/sword/xijian")->wield();
}

