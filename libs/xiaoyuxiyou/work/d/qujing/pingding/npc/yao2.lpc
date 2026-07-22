// created by snowcat on 4/12/1997

inherit NPC;

void create()
{
  string str;
  set_name("小妖", ({"xiao yao","yao"}));
  set("gender", "男性");
  set("age", 20);
  set("long","一个凶相毕露的小妖。\n");
  set("attitude", "aggressive");
  set_level(40+random(10));
  set("daoxing", 100000);

  set("per", 15);
  set_skill("parry",400);
  set_skill("unarmed",400);
  set_skill("dodge",400);
  set_skill("blade",400);
  set_skill("fork",400);
  set_skill("mace",400);
  set_skill("spear",400);
  set_skill("sword",400);
  set_skill("whip",400);
  set_skill("axe",400);
  set_skill("hammer",400);
  set_skill("rake",400);
  set_skill("stick",400);
  set_skill("staff",400);
  set_skill("dagger",400);
  set("force_factor",10);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/pingding/obj/armor")->wear();
  str = "/d/qujing/pingding/obj/weapon10";
  str[strlen(str)-1] = '0'+random(2);
  carry_object(str)->wield();
}