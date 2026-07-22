// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "蝴蝶精",
  "细腰蜂精",
  "麻蚊精",
  "花姐精",
  "彩蛛精",
});

void create()
{
  int i = 30+random(10);
  set_name(names[random(sizeof(names))], ({"yao jing", "jing", "jing"}));
  set("gender", "女性");
  set("age", 20);
  set_level(i);
  set("per", 10);
  set_skill("parry",i*10);
  set_skill("unarmed",i*10);
  set_skill("dodge",i*10);
  set_skill("blade",i*10);
  set_skill("fork",i*10);
  set_skill("mace",i*10);
  set_skill("spear",i*10);
  set_skill("sword",i*10);
  set_skill("whip",i*10);
  set_skill("axe",i*10);
  set_skill("hammer",i*10);
  set_skill("rake",i*10);
  set_skill("stick",i*10);
  set_skill("staff",i*10);
  set_skill("dagger",i*10);
  set("force_factor",10*i);
  setup();
  carry_object("/d/qujing/dudi/obj/cloth")->wear();
  carry_object("/d/qujing/dudi/obj/fork")->wield();
}