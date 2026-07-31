// created by snowcat on 12/9/1997

inherit NPC;

string *names = ({
  "â®Ê¨",
  "Ñ©Ê¨",
  "â¡â¥Ê¨",
  "°×ÔóÊ¨",
  "·üÀêÊ¨",
  "ÞÒÊ¨",
  "ÔÆ±ª",
  "Ë®±ª",
  "»¨±ª",
  "Ê¯±ª",
  "²Ý±ª",
  "É½±ª",
  "°×Ã«»¢",
  "ÇàÃæ»¢",
  "»¨°ß»¢",
  "´óÍõ»¢",
  "°Ë½Å»¢",
  "Ë«Î²»¢",
});

void create()
{
  int i = random(5)+5;
  string str;
  set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai"}));
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
  set("max_jing",1100*i);
  set("max_qi",1100*i);
  set("max_jing",1100*i);
  set("neili",1100*i);
  set("max_neili",1100*i);
  set("max_neili",1100*i);
  set("force_factor",110*i);
  setup();
  carry_object("/d/qujing/zhujie/obj/cloth2")->wear();
  str = "/d/qujing/zhujie/obj/weapon20";
  str[strlen(str)-1] = '0'+random(4);
  carry_object(str)->wield();
}

ÿ