//Cracked by Roath
inherit NPC;

string *names = ({
  "[33m兔精[m",
  "[34m狐精[m",
  "[35m獐怪[m",
  "[36m鹿精[m",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({"yao jing"}));
  set("per",12);
  i = 35+random(10);
  set_level(i);
  set("force_factor",10);
  set_skill("unarmed",i*10);
  set_skill("dodge",i*10);
  set_skill("force",i*10);
  set_skill("parry",i*10);
  set_skill("spells",i*10);
  setup();
  carry_object("/d/qujing/huangfeng/obj/cloth")->wear();  
}
