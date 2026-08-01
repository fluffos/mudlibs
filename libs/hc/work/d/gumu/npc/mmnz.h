// mmnz.h

#include <ansi.h>
void init() {
  object name1;
  object ob = this_player();
  object me = this_object();
  name1 = ob->query("id");

  ::init();

  if (interactive(ob)
    && !environment(ob)->query("no_fight")
    && !(me->query_temp("mmnz") != name1)
    && ob->query_temp("gm/job")
    && (time() - ob->query_temp("marks/gm_job") < 360)) {
    me->set_temp("apply/attack", random(30));
    me->set_temp("apply/dodge", random(50));
    if (!me->query_temp("skillset")) {
      command("say " + "既然被你发现小女子的踪迹，拿命来吧！");
      ob->start_busy(4);
      remove_call_out("dest");
      call_out("dest", 360);
      me->set_leader(ob);
      remove_call_out("do_clone");
      call_out("do_clone", 0, me, ob);
    } else {
      command("say 想跑？既然被你发现小女子的踪迹，拿命来吧！");
      ob->start_busy(1);
      me->set_leader(ob);
      remove_call_out("dest");
      call_out("dest", 360);
      remove_call_out("kill_ob");
      call_out("kill_ob", 0, ob);
    }
  }
}

int do_clone(object me, object ob) {
  mapping killer_skill;
  mixed *sk;  //killer_skill pair.
  int number, k_qi, k_neili, k_jing, j, k;
  string t_force, t_dodge;
  number = (int)ob->query("max_pot");
  number = number - 115;
  k_qi = (int)ob->query("max_qi");
  k_jing = (int)ob->query("max_jing");
  k_neili = (int)ob->query("max_neili");
  j = (int)ob->query("dex");
  k = (int)ob->query("str");

  me->set("dex", j * 5 / 7);
  me->set("str", k * 5 / 7);

  sk = keys(killer_skill = ob->query_skills());
  for (j = 0; j < sizeof(sk); j++) {
    set_skill(sk[j], killer_skill[sk[j]]);
  }
  sk = keys(killer_skill = ob->query_skill_map());
  for (j = 0; j < sizeof(sk); j++) {
    map_skill(sk[j], killer_skill[sk[j]]);
  }

  me->set("max_qi", k_qi / 3 * 4);
  me->set("eff_qi", k_qi / 3 * 4);
  me->set("qi", k_qi / 3 * 4);
  me->set("max_jing", k_jing / 3 * 4);
  me->set("eff_jing", k_jing / 3 * 4);
  me->set("jing", k_jing / 3 * 4);
  me->set("max_neili", k_neili / 3 * 4);
  me->set("neili", k_neili / 3 * 4);
  me->set(
    "combat_exp",
    ob->query("combat_exp") / 110 * (100 + random(me->query_per()) - random(ob->query_kar()))
  );

  me->set_temp("skillset", 1);
  me->set_leader(ob);
  remove_call_out("kill_ob");
  call_out("kill_ob", 0, ob);
  return 1;
}

void dest() {
  object me, ob;
  ob = this_player();
  me = this_object();

  write(me->query("name") + "柳眉一蹙道：下次不要再让我遇见你。\n", me);
  write(me->query("name") + "一个转身，飘身离去。\n", me);

  destruct(this_object());
}
