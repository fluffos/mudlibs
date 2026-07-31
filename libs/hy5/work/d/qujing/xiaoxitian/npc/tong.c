// created by snowcat on 12/16/1997

inherit NPC;
#include "/d/migong/romnpc2.c"
string *names = ({
  "ºÚÊó¹Ö",
  "»Æáì¹Ö",
  "»Òáõ¹Ö",
  "°×áû¹Ö",
  "³àâ¡¹Ö",
  "ÍÁâ¬¹Ö",
  "Ê¯â¥¹Ö",
  "Ä¾â®¹Ö",
  "Ë®âµ¹Ö",
});

void create()
{
  set_name("Ð¡Í¯", ({"xiao tong", "tong"}));
  set("gender", "ÄÐÐÔ");
  set("age", 13);
  set("combat_exp", 150000+random(30000));
  set("combat_exp", 100000);

  set("per", 10);
  set_skill("parry", 80);
  set_skill("unarmed", 80);
  set_skill("dodge", 80);
  set_skill("blade", 80);
  set_skill("staff", 80);
  set_skill("staff", 80);
  set_skill("hammer", 80);
  set_skill("sword", 80);
  set_skill("staff", 80);
  set_skill("staff", 80);
  set("max_jing",1100);
  set("max_qi",1100);
  set("max_jing",1100);
  set("neili",1100);
  set("max_neili",1100);
  set("max_neili",1100);
  set("force_factor",10);
  setup();
  initlvl((600+random(600)),46);
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/qujing/xiaoxitian/obj/shield");
}

void kill_ob (object ob)
{
  object me = this_object();

  if (me->query("id")!="yao guai")
  {
    set("combat_exp",1000000+random(70000));
  set("combat_exp", 700000+random(70000));
  set("eff_qi",1100);
  set("qi",1100);
  set("jing",1100);
  set("eff_jing",1100);

    message_vision ("$N¶ÙÊ±±äÁËÑÕÉ«£¬ÏÖÁËÑý¾«µÄ±¾Ïà£¡\n",me);
    me->set_name(names[random(sizeof(names))], ({"yao guai", "yao", "guai", "xiao tong", "tong"}));
    command("wear dun");
  }
  ::kill_ob(ob);
}

