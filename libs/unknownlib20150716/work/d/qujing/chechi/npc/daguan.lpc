// by snowcat oct 24 1997

inherit NPC;

void create()
{
  set_name("管家", ({"guan jia", "jia"}) );
  set("gender", "男性" );
  set("age", 35);

  set_level(5);
  set("str", 25);
  set("attitude","heroism");

  set("force_factor",2);
  set("max_gin",300);
  set("max_kee",300);
  set("max_sen",300);
  set("max_force",400);
  set("max_mana",400);

  set_skill("unarmed",50);
  set_skill("dodge",50);
  set_skill("parry",50);
  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("coin", 50+random(50));
}