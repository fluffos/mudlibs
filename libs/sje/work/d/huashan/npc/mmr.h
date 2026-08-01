// mmr.h for hs job

#include <ansi.h>

int do_clone(object me, object ob);

void init() {
  object ling, name1;
  object ob = this_player();
  object me = this_object();
  name1 = ob->query("id");
  ling = present("ling pai", me);

  if (interactive(ob)
    && !environment(ob)->query("no_fight")
    && ling
    && ling->query_temp("mmr") == name1
    && ling->query_temp("hsjob") == name1
    && me->query_temp("mmr") == name1
    && ob->query_temp("hs/jobji")
    && ob->query_temp("hs/have")) {
    command("say 想跑，大爷今天就超渡你！！！");
    me->set_leader(ob);
    if (!me->query_temp("skillset")) do_clone(me, ob);
    remove_call_out("kill_ob");
    call_out("kill_ob", 1, ob);
  }
}

int do_clone(object me, object ob) {
  mapping killerskill1;
  int number, k_qi, k_neili, k_jing;
  string t_force, t_dodge;
  number = (int)ob->query("max_pot");
  if (me->query("combat_exp", 1) > 3000000)
    number = number - 100;
  else number = number - 110;
  k_qi = (int)ob->query("max_qi");
  k_jing = (int)ob->query("max_jing");
  k_neili = (int)ob->query("max_neili");

  killerskill1 = skill2[random(sizeof(skill2))];
  number = (int)(number - (random(5) ? 1 : -1) * random(number / 10));
  if (me->query("combat_exp", 1) > 3000000)
    me->set("dex", ob->query("dex") * 6 / 5);
  else me->set("dex", ob->query("dex"));
  me->set("str", ob->query("str"));
  if (me->query("combat_exp", 1) > 3000000)
    me->set("con", ob->query("con") * 6 / 5);
  else me->set("con", ob->query("con"));

  //add log to HS_JOB_LOG
  //      if (userp(ob) && (number > ((int)ob->query("max_pot")-100)))
  if (number > ((int)ob->query("max_pot") - 100))
    write_file("/log/job/HS_JOB", sprintf("%s %s(%s) 第%d次任务目标等级%d，本人等级%d。\n",
      ctime(time())[4..19], ob->name(1), ob->query("id"), (int)ob->query("hs_job"), number, (int)ob->query("max_pot") - 100));

  /*set killer's skill*/

  t_force = k_force[random(sizeof(k_force))];
  t_dodge = k_dodge[random(sizeof(k_dodge))];

  me->set_skill("force", number);
  me->set_skill("dodge", number);
  me->set_skill("parry", number);
  me->set_skill(t_force, number);
  me->set_skill(t_dodge, number);
  me->set_skill(killerskill1["t_skill"], number);
  me->set_skill(killerskill1["b_skill"], number);


  /* set killer's  skill maps */

  me->map_skill("force", t_force);
  me->map_skill("dodge", t_dodge);
  me->map_skill("parry", killerskill1["t_skill"]);
  me->map_skill(killerskill1["b_skill"], killerskill1["t_skill"]);

  /* set killer's skill prepares */

  me->prepare_skill(killerskill1["b_skill"], killerskill1["t_skill"]);

  /* copy entire dbase values */

  me->set("max_qi", k_qi * 6 / 5);
  me->set("eff_qi", k_qi * 6 / 5);
  me->set("qi", k_qi * 6 / 5);
  me->set("max_jing", k_jing);
  me->set("eff_jing", k_jing);
  me->set("jing", k_jing);
  me->set("max_neili", k_neili);
  me->set("neili", k_neili);
  me->set("jiali", k_neili / 40);
  me->set("combat_exp", ob->query("combat_exp"));

  if (me->query("combat_exp", 1) > 3000000) {
    me->set_temp("apply/attack", number / 5 + random(number / 4));
    me->set_temp("apply/dodge", 50);
  }

  me->set_temp("skillset", 1);
  remove_call_out("dest");
  call_out("dest", 200);
  return 1;
}

void dest() {
  if (!living(this_object())) {
    call_out("dest", 10);
    return;
  }
  say(name() + "道：他奶奶的，这次算你命大，下回看老子还饶得了你！\n");
  say(name() + "匆匆离开。\n");
  destruct(this_object());
}

void unconcious() {
  object me, ob, name1, ling;
  me = this_object();
  ob = this_player();
  name1 = ob->query("id");
  ling = present("ling pai", ob);
  if (ling
    && !(ling->query_temp("mmr") != name1)
    && !(me->query_temp("mmr") != name1)) {
    if (!(ling->query_temp("killed"))) {
      ling->set_temp("killed", 1);
      ob = new("/clone/money/gold");
      ob->move(me);
    } else {
      ling->add_temp("killed", 1);
    }
  }
  ::unconcious();
}

int hit = 0;

int hit_ob(object me, object ob, int damage) {
  hit += 2;
  if (damage > 800) return (800 - damage);
  return 0;
}

int ob_hit(object me, object ob, int damage) {
  if (!hit) return -damage * 8 / 10;
  hit--;
  return 0;
}
