// rewritten by snowcat on 4.12.1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("昴宿星官", ({"maoxiu xingguan", "xingguan", "guan"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("combat_exp", 91500000);

  set("per", 25);
  set_skill("dodge", 120);
  set_skill("force", 120);
  set_skill("parry", 120);
  set_skill("spells",160);

  set("max_jing",1600);
  set("max_qi",1600);
  set("max_jing",1600);
  set("neili",1800);
  set("max_neili",1800);
  set("max_neili",1800);
  set("force_factor",125);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/dudi") == "done")
    return;
  if (! who->query_temp("obstacle/dudi_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/dudi","done");
  who->add("combat_exp",i+31000);
     who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"毒敌山显圣名，琵琶洞除蝎怪！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(i+31000)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
  who->save();
}

