// created by snowcat on 12/5/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  string str;
  int i = random(4)+8;
  set_name("妖精", ({"yao jing","yao", "jing"}));
  set("gender", "男性");
  set("age", 20*i);
  set("long","一个守洞的妖精。\n");
  set("combat_exp", 20000*i);
  set("per", 15);
  set_skill("parry", 20*i);
  set_skill("unarmed", 20*i);
  set_skill("dodge", 20*i);
  set_skill("blade", 20*i);
  set_skill("staff", 20*i);
  set_skill("club", 20*i);
  set_skill("spear", 20*i);
  set_skill("sword", 20*i);
  set_skill("whip", 20*i);
  set_skill("axe", 20*i);
  set_skill("hammer", 20*i);
  set_skill("staff", 20*i);
  set_skill("staff", 20*i);
  set_skill("staff", 20*i);
  set_skill("dagger", 20*i);
  set("max_jing",200*i);
  set("max_qi",200*i);
  set("max_jing",200*i);
  set("neili",200*i);
  set("max_neili",200*i);
  set("max_neili",200*i);
  set("force_factor",10*i);
  setup();
  initlvl((500+random(500)),random(63));
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
  str = "/d/qujing/yinwu/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}


