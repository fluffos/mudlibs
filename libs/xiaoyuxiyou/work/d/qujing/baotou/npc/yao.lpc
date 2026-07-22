// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "虎怪",
  "狼怪",
  "彪怪",
  "豹怪",
  "羊怪",
  "鹿怪",
  "马怪",
});

void create()
{
  int i = 30+random(15);
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
  set("gender", "男性");
  set("age", 30*i);
  set("attitude", "aggressive");
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
  setup();
  carry_object("/d/qujing/baotou/obj/cloth1")->wear();
  carry_object(sprintf("/d/qujing/baotou/obj/weapon%d",random(4)))->wield();
}