// gao.c

inherit NPC;
int give_jade();
int show_king();

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "头戴一顶冲天冠，腰束一条碧玉带，身穿一领飞龙舞凤赭黄袍。\n");
  set("title", "乌鸡国");
  set("gender", "男性");
  set("age", 46);
  set("per", 30);
  set("dex", 200);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 200000);
  set("combat_exp", 8000000);

  set_skill("unarmed", 300);
  set_skill("dodge", 300);
  set_skill("parry", 300);
  set("max_jing",58000);
  set("max_qi",58000);
  set("max_jing",58000);
  set("max_neili",58000);
  set("neili",58000);
  set("max_neili",58000);
  	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_temp("apply/parry",200);
	set_temp("apply/dodge",200);
	set_temp("apply/armor",8500);
	
  set("eff_dx",15000);
  set("nkgain",90);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void announce_success()
{
  object me = this_object();
  object where = environment(me);
  string id = me->query("my_saver");
  object who;

  if (! id)
    return;

  who = present(id,where);
  if (! who)
    return;

  remove_call_out ("announce");
  call_out ("announce",8,me,who);
}

void announce(object me, object who)
{//disabled announce and reward...
  int i;

  if (who->query_temp("obstacle/wuji") != "saved")
    return;

  if (who->query("obstacle/wuji") == "done")
  {
    //tell_object (who,"你已经过了这一关，什么都得不到了！\n");
    return;
  }  

  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/wuji","done");
  who->add("combat_exp",i+15000);
       who->add("potential",i*8);
   who->add("mpgx",10);who->add("expmax",2);
  command("thank "+who->query("id"));
  command("chat "+who->query("name")+"乌鸡国救我回生，大灭妖道还我乾坤！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(i+15000)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");
  who->save();
  command("follow none");
}

