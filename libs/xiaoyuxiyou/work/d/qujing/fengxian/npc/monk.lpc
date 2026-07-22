// by snowcat 11/6/1997

inherit NPC;

void create()
{
  set_name("慈悲和尚", ({"cibei heshang", "heshang", "shang", "monk"}));
  set("gender", "男性");
  set("age", 50);
  set("per", 25);
  set("attitude", "peaceful");
  set("shen_type", 1);
    set_level(10);
  set("combat_exp", 60000);
  set("daoxing", 100000);
  
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set("max_gin",200);
  set("max_kee",200);
  set("max_sen",200);
  set("max_force",100);
  set("max_mana",100);
  set("force_factor",12);
  setup();
  carry_object("/d/obj/cloth/monkcloth")->wear();
  carry_object("/d/obj/weapon/blade/jiedao")->wield();
}

int accept_money(object who, int v)
{
  object me = this_object();
  int value = v;
  int required = (50 - who->query("kar"))*50000;

  if (required<500000)
    required = 500000;

  if (value < required)
  {
    message_vision ("$N说道：依施主的福缘，这些钱怕是不够。\n",me);
    return 0;
  }
  message_vision ("$N说道：多谢施主！\n",me);
  message_vision ("$N向$n深深一拜。\n",me,who);
  who->set_temp("obstacle/fengxian_donated",1);
  return 1;
}

void return_ob (object ob, object who)
{
  if (ob)
    command ("give "+ob->query("id")+" to "+who->query("id"));
}

void destruct_me (object ob)
{
  destruct (ob);
}