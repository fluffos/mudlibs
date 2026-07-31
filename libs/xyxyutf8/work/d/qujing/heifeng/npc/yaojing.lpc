//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/xiaoyao.c

inherit NPC;

void create()
{
  string str;
  int i = (random(4)+1)*15;
  set_name("妖精", ({"yao jing","yao", "jing"}));
  set("gender", "男性");
  set("age", i*10);
  set("long","一个守洞的妖精。\n");
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
