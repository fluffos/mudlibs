// YUJ@SJ 版权所有

object ob;
int timer = 0;

int is_corpse() { return 1; }
void move_to_court(object ob);
void test_robot(object obj);
void question();

void create() {
  set_name("银翼杀手", ({ "blade runner", "runner" }));

  set("gender", "机器");
  set("age", 20);
  set("no_quest", 1);
  set("no_drop", 1);
  set("no_get", 1);
  set_temp("apply/long",
    ({ "这是一个专门追缉机器人的机器探员。\n"
      "如果利用机器自动回答问题，档案将被无条件删除。\n" })
  );
  set_skill("dodge", 1000);
  set("max_qi", 10000);
  set("qi", 10000);
  set("max_jing", 10000);
  set("jing", 10000);

  set("combat_exp", 5000000);

  set("inquiry", ([
    "name": "你还有这闲功夫啊？专心回答问题吧！",
    "rumors": "听说有机器人混入本MUD，嘿嘿，我可是火眼金睛呀。",
  ]));
  set("attitude", "friendly");
  set("env/invisibility", 1);

  setup();
  set_weight(0);
}

void init() {
  if (environment() == ob) {
    question();
    add_action("do_answer", ({ "answer" }));
    add_action("wait",
      ({
        "ask", "beep", "chat", "chat*", "emote", "exercise",
        "irc", "irc*", "learn", "lingwu", "mm",
        "party", "party*", "post", "practice", "quit",
        "reply", "respirate", "rumor", "rumor*",
        "say", "sj", "study", "sleep",
        "teach", "team", "tell", "to", "whisper",
      })
    );
  }
}

int wait() {
  write("对不起，请先回答问题。\n");
  return 1;
}

void kill_ob(object ob) {
  ob->remove_killer(this_object());
  remove_killer(ob);
  message_vision("$N沮丧地发现银翼杀手根本不理会作战请求。\n", ob);
}

void unconcious() {
  reincarnate();
  set("eff_qi", query("max_qi"));
  set("qi", query("max_qi"));
  set("eff_jing", query("max_jing"));
  set("jing", query("max_jing"));
  set("jingli", query("eff_jingli"));
  say("银翼杀手狞笑着说：我是无敌不死版！\n");
  command("hehe");
}

void die() {
  unconcious();
}

void give_reward(object ob) {
  mapping skills, skls = ([]), skls2 = ([]);
  int sn, sn2, lvl = 0;
  string skill;
  string *quest_skill = ({ "jiuyin-zhengong", "hamagong", "kuihua-xinfa" });

  if (ob->query("registered") < 3) return;
  switch (ob->add_temp("robot_check_pass", 1)) {
    case 1:
      skills = ob->query_skills();
      if (!(sn = sizeof(skills))) break;
      sn2 = sn;
      foreach (skill, int val in skills) {
        if (SKILL_D(skill)->type() == "martial"
          || (sn2 > 5 && SKILL_D(skill)->type2() == "worker")) {
          skls2 += ([ skill: val ]);
          lvl += val;
        } else sn--;
      }
      if (!sn) break;
      lvl /= sn;
      foreach (skill, int val in skls2) {
        if (val >= 0) {
          skls += ([ skill: val ]);
        }
      }

      sn = random(sizeof(skls));
      skill = keys(skls)[sn];

      while (member_array(skill, quest_skill) != -1 || SKILL_D(skill)->type2() == "worker") {
        sn = random(sizeof(skls));
        skill = keys(skls)[sn];
      }

      lvl = values(skls)[sn];
      lvl *= lvl / 2;
      lvl = lvl / 2 + random(lvl / 2);

      if (SKILL_D(skill)->type2() == "worker") {
        if (values(skls)[sn] > 300)
          lvl = lvl / 3;
        else if (values(skls)[sn] > 200)
          lvl = lvl / 2;
      }

      write("你获得了" + chinese_number(lvl) + "点「" + to_chinese(skill) + "」的奖励。\n");
      ob->improve_skill(skill, lvl, 1);
      log_file("nosave/ROBOT",
        sprintf("%s(%s)通过检查，奖励 %s %d。\n",
          ob->query("name"), ob->query("id"), skill, lvl
        ), ob
      );
      break;
    case 2:
      lvl = 500 + random(500);
      write("你获得了" + chinese_number(lvl) + "点经验的奖励。\n");
      ob->add("combat_exp", lvl);
      log_file("nosave/ROBOT",
        sprintf("%s(%s)通过检查，奖励 exp %d。\n",
          ob->query("name"), ob->query("id"), lvl
        ), ob
      );
    default:
      ob->delete_temp("robot_check_pass");
  }
}

void move_to_court(object ob) {
  string room;
  int times, times2;

  ob->delete_temp("robot_check_pass");
  ob->apply_condition("robot", 15);
  message_vision("$N把$n带去了法庭。\n", this_object(), ob);
  if (!stringp(room = base_name(environment(ob))) || environment(ob)->query("no_save")) {
    if (ob->query("enter_wuguan"))
      room = "/d/wuguan/dayuan";
    else room = "/d/city/chmiao";
  }
  if (ob->query("robot") < 2) {
    ob->set("catch_robot_place", room);
    ob->move("/d/wizard/robot_court");
    tell_object(ob, "你已经累计被银翼杀手抓送机器人法庭" + chinese_number(ob->add("robot", 1)) + "次了。\n");
  } else {
    ob->delete("robot");
    times2 = times = ob->add("rules", 1);
    if (times2 > 3 && ob->query("registered") == 3)
      times2 = 3;

    ob->set("relax_timeout_room", room);
    ob->apply_condition("relax", times2 * 30);

    message("channel", HIW "\n【纪律】" + ob->query("name") + "(" + capitalize(ob->query("id"))
      + ")因为「机器人」，违反书剑游戏规则共计" + chinese_number(times)
      + "次，决定给予关禁闭" + chinese_number(times2 * 10) + "分钟的处罚。\n\n" NOR, users());

    tell_object(ob, "银翼杀手把你直接抓到了桃花源。\n");
    ob->move("/d/wizard/relax");
    log_file("nosave/ROBOT",
      sprintf("%s(%s)因为机器人被关禁闭，共计违规 %d 次。\n",
        ob->query("name"), ob->query("id"), times
      ), ob
    );
  }
}

void test1() {
  object me = this_object();

  if (ob) {
    timer -= 10;
    if (timer > 0) {
      message("channel", "银翼杀手警告你：你还有" + chinese_number(timer) + "秒钟的考虑时间。\n", ob);
      me->move(ob, 1);
      call_out("test1", 10);
    } else {
      if (!interactive(ob) || query_idle(ob) >= 170) {
        "/cmds/usr/quit"->main(ob);
        if (me) destruct(me);
      } else {
        // 防止player故意晕倒等bug. snowman@SJ 12/06/2000.
        if (!living(ob)) ob->revive(1);
        message_vision(
          query("name") + "叹了口气道：$N一点反应都没有，又是一个机器人嫌犯！\n", ob
        );
        move_to_court(ob);
        destruct(me);
      }
    }
  } else destruct(me);
}

void test_player(string player) {
  object ob = find_player(player);

  if (ob) test_robot(ob);
}
