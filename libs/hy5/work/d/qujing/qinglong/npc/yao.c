// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "Å£Í·¾«",
  "¶À½ÇÅ£¾«",
  "¶ÌÎ²Å£¾«",
  "Å£¾«",
  "Ò°Å£¾«",
  "êóÅ£¾«",
  "É½Å£¾«",
  "Ë®Å£¾«",
  "»ÆÅ£¾«",
});

void create()
{
  int i = random(9)+1;
  string str;
  set_name(names[random(sizeof(names))], ({"yao jing", "yao", "jing"}));
  set("gender", "ÄÐÐÔ");
  set("age", 30*i);
  set("attitude", "aggressive");
  set("combat_exp", 80000*i);
  set("per", 10);
  set_skill("parry", 100*i);
  set_skill("unarmed", 100*i);
  set_skill("dodge", 100*i);
  set_skill("blade", 100*i);
  set_skill("staff", 100*i);
  set_skill("club", 100*i);
  set_skill("spear", 100*i);
  set_skill("sword", 100*i);
  set_skill("whip", 100*i);
  set_skill("axe", 100*i);
  set_skill("hammer", 100*i);
  set_skill("staff", 100*i);
  set_skill("staff", 100*i);
  set_skill("staff", 100*i);
  set_skill("dagger", 100*i);
  set("max_jing",1200*i);
  set("max_qi",1200*i);
  set("max_jing",1200*i);
  set("neili",1200*i);
  set("max_neili",1200*i);
  set("max_neili",1200*i);
  set("force_factor",10*i);
  setup();
  carry_object("/d/obj/cloth/shoupiqun")->wear();
  carry_object("/d/qujing/qinglong/obj/shield")->wear();
  str = "/d/qujing/qinglong/obj/weapon0";
  str[strlen(str)-1] = '0'+random(6);
  carry_object(str)->wield();
}

ÿ