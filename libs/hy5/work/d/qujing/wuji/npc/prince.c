
inherit NPC;
#include "/d/migong/romnpc2.c"
void create()
{
  set_name("太子", ({"tai zi", "zi", "prince"}));
  set ("long", "乌鸡国的王太子，成人之后不再常进宫，常以狩猎为乐。\n");
  set("title", "乌鸡国");
  set("gender", "男性");
  set("age", 20);
  set("combat_exp", 300000);
  set("combat_exp", 21500000);

  set_skill("blade", 90);
  set_skill("dodge", 90);
  set_skill("parry", 90);
  set_skill("unarmed", 90);

  set("max_jing", 400);
  set("max_qi", 700);
  set("max_neili", 800);
  set("neili", 1000);
  set("force_factor", 45);
  setup();
 initlvl((200+random(200)),61);
  carry_object("/d/obj/weapon/blade/jindao")->wield();
  carry_object("/d/obj/armor/jinjia")->wear();
}

int accept_object (object who, object ob)
{
  object me = this_object();

  if (ob->query("id") != "yu gui")
    return 0;

  if (
      who->query_temp("obstacle/wuji_queen")==0 )
    call_out("refuse_it",2,me,who,ob);
  else
    call_out("accept_it",2,me,who,ob);
  who->set_temp("obstacle/wuji_jade",1);
  return 1;
}

void refuse_it (object me, object who, object ob)
{
  message_vision ("$N看见金厢白玉圭脸色一变，高声叫道："+
                  "“贼人！吾家珍国宝何时落入你手中！”\n",me,ob);
  message_vision ("$N怒发冲冠，大喝一声要杀死$n！\n",me,who);
  me->kill_ob(who);
  who->kill_ob(me);
  destruct (ob);
}

void accept_it (object me, object who, object ob)
{
  message_vision ("$N看见金厢白玉圭脸色一变，禁不住叫道："+
                  "“恩人！此乃吾家珍国宝也！”\n",me,ob);  
  message_vision ("$N涕泪皆下。\n",me);
  call_out ("give_jing",2,me,who);
  destruct (ob);
}

void give_jing (object me, object who)
{
  object ob = new ("/d/qujing/wuji/obj/jing");
  message_vision ("\n$N对$n说道：“恩人，我身边亦有一宝，请笑纳！”\n",me,who);   message_vision ("\n说着$N取出一匣子，拿出一小瓶来。\n",me,who);  
  ob->move(me);
  ob->move(who);
}
