// guanbing.h
// all include 官兵，武将 by Lklv 2002.1.18
// update by lsxk@hsbbs 增加自动报警，grin

#include <get_place.h>
#include <ansi.h>

void init() {
  object ob;
  ::init();
  if (interactive(ob = this_player())
    && living(this_object())
    && ob->query_condition("killer")) {
    remove_call_out("kill_ob");
    call_out("kill_ob", 0, ob);
  }
}

int accept_fight(object me) {
  string p;
  object env = environment(this_object());

  p = get_place(file_name(env));
  if (!me) return 0;
  if (me->query("guanbing_chat_alarm"))
    message(
      "system",
      HIY "【" + HIR + "官府警讯" + HIY + "】" + this_object()->query("name") + "(" + this_object()->query("id") + ")：各位注意！" + HIC + p + HIG + env->query("short") + HIY + "正遭到攻击！请附近平民迅速撤离危险地区！\n" NOR,
      users()
    );

  if (query("id") == "wu jiang") {
    command("pei ");
    command("say 敢对朝廷命官无礼，今天让大爷我教训教训你！\n");
    fight_ob(me);
    return 1;
  }
  command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
  if (!is_killing(me->query("id")))
    me->add_condition("killer", 5);
  kill_ob(me);
  return 1;
}

void kill_ob(object ob) {
  string p;
  object env = environment(this_object());

  p = get_place(file_name(env));
  if (!ob) return;

  if (ob->query("guanbing_chat_alarm"))
    message(
      "system",
      HIY "【" + HIR + "官府警讯" + HIY + "】" + this_object()->query("name") + "(" + this_object()->query("id") + ")：各位注意！" + HIC + p + HIG + env->query("short") + HIY + "正遭到攻击！请附近平民迅速撤离危险地区！\n" NOR,
      users()
    );

  if (query("id") == "wu jiang")
    command("say 你！你！你！来人啊，给我拿下这个反贼！！！");
  else
    command("say 反贼！哪里走！！！");
  ::kill_ob(ob);
}
