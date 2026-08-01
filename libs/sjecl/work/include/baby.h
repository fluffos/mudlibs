#include "ansi.h"
#include "combat.h"

string status_color(int current, int max);

void init() {
  object ob;
  ob = this_object();
  add_action("do_kill", ({ "kill", "fight", "hit", "steal" }));
  add_action("do_get", "get");
  add_action("do_drop", "drop");
  add_action("do_shape", "qk");
  add_action("do_cun", "cundang");
  add_action("do_teach", "jiao");
}

string query_save_file() {
  string id;

  id = query("momid");
  if (!stringp(id)) return 0;
  return sprintf("/data/baby/%c/%s", id[0], id + ".lpc");
}


int save() {
  string file;

  if (stringp(file = this_object()->query_save_file())) {
    assure_file(file + __SAVE_EXTENSION__);
    return save_object(file);
  }
  return 0;
}

int restore() {
  string file;

  if (stringp(file = this_object()->query_save_file()))
    return restore_object(file);
  return 0;
}

void die() {
  int i;
  object owner, *enemy;
  int jing, qi, exp;

  exp = (int)query("combat_exp");
  jing = (int)query("max_jing");
  qi = (int)query("max_qi");

  if (!environment()->query("no_death_penalty"))
    set("combat_exp", exp / 10 * 9);
  set("eff_qi", qi);
  set("eff_jing", jing);
  set("qi", qi);
  set("jing", jing);

  save();
  ::die();
}

int do_drop(string arg) {
  object me = this_object(), who = this_player(), env;
  if (!arg) return 0;
  env = environment(who);
  if (present(arg, who) != me) return 0;
  if (me->move(env)) {
    message_vision("$N把$n从怀里放了下来。\n", who, me);
    return 1;
  }
  return 0;
}

int do_get(string arg) {
  object me = this_object(), who = this_player(), env;

  if (!arg) return 0;
  env = environment(who);
  if (present(arg, env) != me) return 0;
  if (who->query("id") == me->query("momid") || who->query("id") == me->query("popid")) {
    if (me->move(who)) {
      message_vision("$N弯下腰把$n抱了起来，搂在怀里。\n", who, me);
    } else {
      message_vision("$N弯下腰一抱却没把$n抱起来，小家伙好沉哪！\n", who, me);
    }
  } else {
    message_vision("$N蹲下身朝$n伸开双手，$n却一下子闪开了．．．\n", who, me);
  }
  return 1;
}

int do_kill(string arg) {
  object me, who;
  string name, verb, what, obj;
  if (!arg) return 0;
  verb = query_verb();
  me = this_player();

  if (verb == "steal") {
    if (sscanf(arg, "%s from %s", what, obj) != 2)
      return 0;
  } else obj = arg;

  if (!objectp(who = present(obj, environment(me))) || !living(who)) return 0;

  if (who == this_object()) {
    switch (verb) {
      case "kill":
        tell_object(environment(this_object()),
          who->query("name") + "拼命地哭了起来：爹～～，娘～～，" +
          me->query("name") + "要杀我．．．快回来呀！\n");
        break;
      case "hit":
        tell_object(environment(this_object()),
          who->query("name") + "大哭了起来：爹～～，娘～～，" +
          me->query("name") + "欺负我．．．快回来呀！\n");
        break;
      case "fight":
        tell_object(environment(this_object()),
          who->query("name") + "哭了起来：爹～～，娘～～，" +
          me->query("name") + "要抢我的糖吃．．．快回来呀！\n");
        break;
      case "steal":
        tell_object(environment(this_object()),
          who->query("name") + "哭了起来：爹～～，娘～～，" +
          me->query("name") + "要偷吃我的糖！\n");
        break;
      case "beg":
        tell_object(environment(this_object()),
          who->query("name") + "小嘴一歪哭了起来：爹～～，娘～～，" +
          me->query("name") + "要骗我的糖吃！\n");
        break;
    }
  }
  command(verb);
  return 0;
}

void relay_emote(object ob, string verb) {
  if (!userp(ob)) return;

  switch (verb) {
    case "kick":
      command("say 爹～～，娘～～，" + ob->query("name") + "踢我耶！");
      command("kick " + ob->query("id"));
      break;
    case "slap":
      command("say 爹～～，娘～～，" + ob->query("name") + "打我耶，好痛啊～～～～");
      command("slap " + ob->query("id"));
      break;
    case "hit":
      command("pain " + ob->query("id"));
      break;
    case "bite":
      command("face " + ob->query("id"));
      break;
    case "papaya":
      command("angry");
      break;
  }
}

void relay_whisper(object me, string msg) {
  if (member_array(me->query("id"), query("parents")) == -1) {
    message_vision((string)this_object()->query("name") + "疑惑地看着$N。\n", me);
    return;
  }

  //note, do not allow the order contain "chat", "tell"...
  //may need disable more later...
  if (strsrch(msg, "chat") != -1 || strsrch(msg, "tell") != -1 || strsrch(msg, "follow") != -1 ||
    strsrch(msg, "apprentice") != -1 || strsrch(msg, "recruit") != -1)
    return;
  if (msg) {
    remove_call_out("relaying");
    call_out("relaying", 1 + random(3), msg);
  }
}

void relaying(string msg) {
  //execute the order.
  command(msg);
}

string status_color(int current, int max) {
  int percent;

  if (max > 0) percent = current * 100 / max;
  else percent = 100;
  if (percent > 100) return HIC;
  if (percent >= 90) return HIG;
  if (percent >= 60) return HIY;
  if (percent >= 30) return YEL;
  if (percent >= 10) return HIR;
  return RED;
}

int do_shape(string arg) {
  mapping my;
  string shape;
  int at_pt, pa_pt, do_pt;
  my = query_entire_dbase();
  printf(NOR "┌──────────────────────────────┐\n" NOR);
  printf("│" HIY "【精神】%s%6d/%6d %s(%3d%%)" NOR, status_color(
    my["jing"],
    my["eff_jing"]
  ), my["jing"],
    my["eff_jing"], status_color(
      my["eff_jing"],
      my["max_jing"]
    ), my["eff_jing"] * 100 / my["max_jing"]);
  printf(HIY "  【精力】%s%6d/%6d %s(%3d%%)  " NOR "│\n", status_color(
    my["jingli"],
    my["eff_jingli"]
  ), my["jingli"],
    my["eff_jingli"], status_color(
      my["jingli"],
      my["eff_jingli"]
    ), my["jingli"] * 100 / my["eff_jingli"]);
  printf("│" HIY "【气血】%s%6d/%6d %s(%3d%%)" NOR, status_color(
    my["qi"],
    my["eff_qi"]
  ), my["qi"], my["eff_qi"],
    status_color(my["eff_qi"], my["max_qi"]), my["eff_qi"] * 100 / my["max_qi"]);
  printf(HIY "  【内力】%s%6d/%6d (+%3d)  " NOR "│\n", status_color(
    my["neili"],
    my["max_neili"]
  ), my["neili"],
    my["max_neili"], my["jiali"]);
  printf("│父亲： " HIW "%-13s" NOR "母亲： " HIC "%-13s" NOR "年龄： %-12s │\n",
    my["pop"], my["mom"], chinese_number(my["age"]) + "岁");
  printf("│才智： %d/%-10d体质： %d/%-10d体态： %d/%-9d │\n", query_int(), my["int"], query_con(),
    my["con"], query_per(), my["per"]);
  printf("│速度： %d/%-10d力量： %d/%-10d灵性： %d/%-9d │\n", query_dex(), my["dex"], query_str(),
    my["str"], query_kar(), my["kar"]);
  printf("│教养： %-13d个性： %-13d经验： " HIR "%-12d" NOR " │\n", my["obe"], my["tol"], my["combat_exp"]);
  at_pt = COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
  pa_pt = COMBAT_D->skill_power(this_object(), "parry", SKILL_USAGE_DEFENSE);
  do_pt = COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
  printf(
    "│攻击力： " WHT "%-21d" NOR "防御力： " WHT "%-21d" NOR "│\n" NOR,
    at_pt + 1,
    pa_pt / 2 + do_pt / 2 + 1
  );
  printf(NOR "└──────────────────────────────┘\n" NOR);
  return 1;
}

int do_cun(string arg) {
  object me, ob;
  me = this_player();
  ob = this_object();

  if (me->is_busy())
    return notify_fail("你上一个动作还没有完成！\n");

  if (me->is_fighting())
    return notify_fail("你还是专心作战吧！\n");

  if (!(me->query("id") == ob->query("momid") || me->query("id") == ob->query("popid")))
    return notify_fail("什么？\n");

  if (ob->query_temp("saved"))
    return notify_fail("经常存盘有害系统硬盘健康，请稍后再试。\n");
  //        ob->set_temp("saved", 1);
  ob->save();
  ob->start_call_out((: call_other, me, "delete_temp", "saved" :), 60 + random(60));

  write("孩子的情况已经储存完毕。\n");
  return 1;
}


int do_teach(string arg) {
  object me, ob;
  int gin_cost, amount, myskill, itskill;
  string student, skill;

  me = this_player();
  ob = this_object();

  if (me->is_busy()) return notify_fail("你现在正忙着呢。\n");

  if (me->is_fighting()) return notify_fail("你不能在战斗中教人知识。\n");

  if (ob->is_busy()) return notify_fail("孩子现在无法认真听讲。\n");

  if (!arg || (sscanf(arg, "%s about %s", student, skill) != 2))
    return notify_fail("指令格式：jiao <某人> about <技能>\n");

  if (student != ob->query("id")) return notify_fail("你要教谁？\n");

  if (!myskill = me->query_skill(skill, 1)) return notify_fail("这项技能你好象还不会呢！\n");

  if (me->query("id") != ob->query("momid") && me->query("id") != ob->query("popid"))
    return notify_fail("自己的孩子自己教，你不用担这份心啦。\n");

  if (!living(ob)) return notify_fail("嗯....你得先把" + ob->name() + "弄醒再说。\n");

  if (!ob->query("is_baby")) return notify_fail("人家也有师傅，有得着你来教？\n");

  itskill = ob->query_skill(skill, 1);

  if (myskill <= itskill) return notify_fail(ob->name() + "以嘲笑的目光望着你。\n");

  if ((int)me->query("potential") < 1) return notify_fail("你的潜能不够！\n");

  gin_cost = (int)ob->query_int();

  if ((int)me->query("jing") < gin_cost) return notify_fail("你显然太累了没有办法教！\n");

  me->receive_damage("jing", gin_cost);
  //	me->add("potential",-1);
  amount = (int)me->query("int") + (int)ob->query("int");

  message_vision(sprintf("$N不厌其烦地教$n「%s」。\n", to_chinese(skill)), me, ob);

  if ((int)ob->query_temp("is_hungry") > 30 + random(5) || ob->query("is_hungry")) {
    ob->set("is_hungry", 1);
    ob->delete_temp("is_hungry");
    return notify_fail("孩子大哭大闹，好像是饿了\n");
  }
  if (random(30) > ob->query("tol")) {
    if (ob->query("age") < 5)
      message_vision("$n哇哇地大哭起来，$N说什么也哄不住。\n", me, ob);
    else
      message_vision("$n大哭大闹，说什么也不听$N话。\n", me, ob);
  } else {
    ob->add_skill(skill, amount);
    //		ob->improve_skill(skill, amount);
    ob->add("combat_exp", amount / 20 + random(amount / 20));
    message_vision(sprintf("$N似乎真的学会了一些「%s」！\n", to_chinese(skill)), ob);
    me->add("combat_exp", 30);
    me->start_busy(random(2) + 1);
    ob->start_busy(1);
    ob->add_temp("is_hungry", 1);
  }
  return 1;
}

varargs void add_skill(string skill, int amount) {
  if (!find_object(SKILL_D(skill)) && file_size(SKILL_D(skill) + ".lpc") < 0)
    error("F_SKILL: No such skill (" + skill + ")\n");

  if (!mapp(skills)) skills = ([]);
  if (undefinedp(skills[skill])) skills[skill] = 0;

  if (!amount) amount = 1;

  if (!mapp(learned)) learned = ([ skill: amount ]);
  else (int)learned[skill] += amount;

  if (learned[skill] > (skills[skill] + 1) * (skills[skill] + 1)) {
    skills[skill]++;
    learned[skill] = 0;
    this_object()->set_skill(skill, skills[skill] + 1);
  }
}

int accept_object(object me, object obj) {
  object ob;
  ob = this_object();
  if (me->query("id") != ob->query("momid") && me->query("id") != ob->query("popid"))
    return notify_fail("人家父母会照顾自己的孩子啦。\n");
  /*
	if( ! obj->wear() )  {
		command("cry");
                return 0;
	}
*/
  call_out("baby_wear", 1, me, obj);
  return 1;
}

void baby_wear(object me, object obj) {
  message_vision(sprintf("$N给自己的孩子穿上一%s%s。\n", obj->query("unit"), obj->query("name")), me);
  obj->move(this_object());
  obj->wear();
}
