// created by snowcat on 12/5/1997

inherit NPC;

void create()
{
  string str;
  int i = random(15)+20;
  set_name("小妖", ({"xiao yao","yao"}));
  set("gender", "男性");
  set("age", i*10);
  set("long","一个鬼头鬼脑的小妖。\n");
  set_level(i);
  set("per", 15);
  set_skill("parry", i*10);
  set_skill("unarmed", i*10);
  set_skill("dodge", i*10);
  set_skill("blade", i*10);
  set_skill("fork", i*10);
  set_skill("mace", i*10);
  set_skill("spear", i*10);
  set_skill("sword", i*10);
  set_skill("whip", i*10);
  set_skill("axe", i*10);
  set_skill("hammer", i*10);
  set_skill("rake", i*10);
  set_skill("stick", i*10);
  set_skill("staff", i*10);
  set_skill("dagger", i*10);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
  str = "/d/qujing/yinwu/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}