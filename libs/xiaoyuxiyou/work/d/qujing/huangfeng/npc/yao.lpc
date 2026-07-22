// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/yao.c

inherit NPC;

string *names = ({
  "雪狼怪",
  "银狐精",
  "野豹怪",
  "狡免精",
  "黑雕怪",
  "白鹿怪",
  "青蛇精",
});

void create()
{
  int i = 30+random(11);
  string str;
  set_name(names[random(sizeof(names))], ({"yao jing", "yao", "jing"}));
  set("gender", "男性");
  set("age", 30*i);
  set("combat_exp", 30000*i);
  set("per", 10);
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
  set("force_factor",10*i);
  set("chat_chance", 5);
  set("chat_msg", ({ (: random_move :) }));
  
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  str = "/d/qujing/qilin/obj/weapon10";
  str[strlen(str)-1] = '0'+random(3);
  carry_object(str)->wield();
}
