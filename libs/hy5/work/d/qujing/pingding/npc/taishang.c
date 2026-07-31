// rewritten by snowcat on 4.12.1997

inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("太上老君", ({"taishang laojun", "taishang", "laojun"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("combat_exp", 10000000);

  set("per", 25);
  set_skill("dodge", 180);
  set_skill("force", 180);
  set_skill("parry", 180);

  set("max_jing",1800);
  set("max_qi",1800);
  set("max_jing",1800);
  set("neili",1800);
  set("max_neili",1800);
  set("max_neili",1800);
  set("force_factor",125);
  setup();
initlvl((1000+random(1000)),1);
  carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/pingding") == "done")
    return;
  if (! who->query_temp("obstacle/pingding_huaqi_killed"))
    return;
  if (! who->query_temp("obstacle/pingding_laonai_killed"))
    return;
  if (! who->query_temp("obstacle/pingding_jinjiao_killed"))
    return;
  if (! who->query_temp("obstacle/pingding_yinjiao_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/pingding","done");
  who->add("combat_exp",i+14000);
   who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("chat "+who->query("name")+"平顶山压龙山施威，替老夫收回金银童子！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(i+14000)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
  who->save();
}


