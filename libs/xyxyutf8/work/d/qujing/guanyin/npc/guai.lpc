#include <ansi.h>
inherit NPC;

void create()
{
  int i = 35+random(10);
  set_name("妖怪", ({"yao guai","guai"}));
  set("gender", "男性");
  set("age", 25);
  set("yaoguai","yaoguai");  
  set("attitude","aggressive");
  set("per", 8);
  set_skill("parry", 10*i);
  set_skill("unarmed", 10*i);
  set_skill("dodge", 10*i);
  set_skill("blade", 10*i);
  set_skill("fork", 10*i);
  set_skill("mace", 10*i);
  set_skill("spear", 10*i);
  set_skill("sword", 10*i);
  set_skill("whip", 10*i);
  set_skill("axe", 10*i);
  set_skill("hammer", 10*i);
  set_skill("rake", 10*i);
  set_skill("stick", 10*i);
  set_skill("staff", 10*i);
  set_skill("dagger", 10*i);
  set("force_factor",8*i);
  set("chat_chance",10);
  set("chat_msg",({
         "妖怪嘴里嘟嘟囔囔的也不知道在说些什么！\n",
  }));
  setup();
  carry_object("/d/obj/armor/tongjia")->wear();
  carry_object("/d/obj/weapon/fork/fork")->wield();
}