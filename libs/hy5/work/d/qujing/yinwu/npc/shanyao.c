// created by snowcat on 12/5/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("山妖", ({"shan yao","yao"}));
  set("gender", "男性");
  set("age", 40);
  set("long","一个凶相毕露的山妖。\n");
  set("attitude", "aggressive");
  set("combat_exp", 500000);
  set("combat_exp", 400000);
  
  set("no_nk_reward",1);

  set("per", 15);
  set_skill("parry", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("blade", 80);
  set_skill("staff", 80);
  set_skill("club", 80);
  set_skill("spear", 80);
  set_skill("sword", 80);
  set_skill("whip", 80);
  set_skill("axe", 80);
  set_skill("hammer", 80);
  set_skill("staff", 80);
  set_skill("staff", 80);
  set_skill("staff", 80);
  set_skill("dagger", 80);
  set("max_jing",400);
  set("max_qi",400);
  set("max_jing",400);
  set("neili",400);
  set("max_neili",400);
  set("max_neili",400);
  set("force_factor",3);
  setup();
    initlvl((500+random(500)),random(63));
  carry_object("/d/qujing/yinwu/obj/cloth")->wear();
}

