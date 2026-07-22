// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "牛头精",
  "独角牛精",
  "短尾牛精",
  "牛精",
  "野牛精",
  "牦牛精",
  "山牛精",
  "水牛精",
  "黄牛精",
});

void create()
{
  int i = 30+random(20);
  string str;
  set_name(names[random(sizeof(names))], ({"yao jing", "yao", "jing"}));
  set("gender", "男性");
  set("age", 30+random(20));
  set("attitude", "aggressive");
  set_level(i);
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
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qinglong/obj/shield")->wear();
  str = "/d/qujing/qinglong/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}