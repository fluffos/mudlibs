// quest for force dacheng-fofa linji-zhuang
// Lklv 2001.10.18 update

#include <ansi.h>

int ask_force() {
  command("say 峨嵋派修习内功之法据我所知，峨嵋派祖师爷郭襄曾经在牛心石上修炼内功。\n");
  return 1;
}

int ask_fofa() {
  object me = this_player();
  switch (random(4)) {
    case 0: {
      command("say 既然你问我大乘佛法，我先给你讲个故事听。
		大承和尚曾住在峨嵋山。
		有个僧人问他：什么是胜峰？　大承说；直耸烟岚。
		僧人又问：向上事（即脱俗之事）如何？　他答：立地三尺五。
		僧人又问：什么是佛法？　他就说：兴义门前咚咚鼓。
		那僧说：这我不懂。　大承和尚是怎样回答他的呢？\n");
      me->set_temp("ask_force_1", 1);
      call_out("do_nod1", 5, me); return 1;
    }
    break;

    case 1: {
      command("say 既然你问我大乘佛法，我先给你讲个故事听。
		密印安民曾在华藏寺开法。
		密印安民有一次请教名僧圆悟：什么是古帆未挂？
		圆悟说：庭前柏树子。密印安民大悟彻悟后说了什么？\n");
      me->set_temp("ask_force_2", 1);
      call_out("do_nod2", 5, me); return 1;
    }
    break;

    case 2: {
      command("say 既然你问我大乘佛法，我先给你讲个故事听。
		罗汉和尚曾住在峨嵋山延福院里。
		有僧人问他：什么是西来大意？　他说；井中红焰，日里浮沤。
		僧人问：这怎么领会？　罗汉和尚是怎样回答他的呢？\n");
      me->set_temp("ask_force_3", 1);
      call_out("do_nod3", 5, me); return 1;
    }
    break;

    case 3: {
      command("say 既然你问我大乘佛法，我先给你讲个故事听。
		慧真广悟曾在峨嵋山出家。
		慧真广悟开堂那天，有个僧人出来问：什么是佛法大意？
		慧真广悟说：日出方知天下朗，无油哪点佛前灯？
		僧人又问：什么是双峰境？　慧真广悟是怎样回答他的呢？\n");
      me->set_temp("ask_force_4", 1);
      call_out("do_nod4", 5, me);
      return 1;
    }
    break;
  }
}

int ask_linji() {
  command("say 临济十二庄一共有十二庄，每练成一庄都有对自身有莫大好处，
		特别是当将十二庄互为反正融会贯通时，对内力修为会有助益，并
		可增加可以使用的内功特异功能。希望你能好好静心修炼，将来必
		有大成。\n");
  return 1;
}

int do_nod1(object me) {
  if (this_player()) me = this_player();
  if (!me->query_temp("ask_force_1")) return 0;
  if (me->query("potential", 1) < 1) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query("jing", 1) < (60 - (int)me->query("int") * 2)) {
    write("你仔细想了半天，也想不出来。\n");
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121) {
    if (random(10) > 3) {
      write(HIY "你想起在一部经书里读到过这个故事。
			你说：朝打三千，暮打八百。\n" NOR, me);
      me->improve_skill("dacheng-fofa", (int)me->query("int") * 4);
      me->receive_damage("jing", 80 - (int)me->query("int") * 2);
      me->add("potential", -1);
      me->delete_temp("ask_force_1", 1);
      return 1;
    } else {
      write("你仔细想了半天，也想不出来。\n");
      me->receive_damage("jing", 25);
      me->delete_temp("ask_force_1");
      return 1;
    }
  }
}

int do_nod2(object me) {
  if (this_player()) me = this_player();
  if (!me->query_temp("ask_force_2")) return 0;
  if ((int)me->query("jing", 1) < (60 - (int)me->query("int") * 2)) {
    write("你仔细想了半天，也想不出来。\n");
    return 1;
  }
  if (me->query("potential", 1) < 1) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121) {
    if (random(10) > 3) {
      write(HIC "你想起在一部经书里读到过这个典故。
			你答道：古人说“一滴投于巨壑”，殊不知大海也投于一滴！\n" NOR, me);
      me->improve_skill("dacheng-fofa", (int)me->query("int") * 4);
      me->receive_damage("jing", 80 - (int)me->query("int") * 2);
      me->add("potential", -1);
      me->delete_temp("ask_force_2", 1);
      return 1;
    } else {
      write("你仔细想了半天，也想不出来。\n");
      me->receive_damage("jing", 25);
      me->delete_temp("ask_force_2");
      return 1;
    }
  }
}

int do_nod3(object me) {
  if (this_player()) me = this_player();
  if (!me->query_temp("ask_force_3")) return 0;
  if ((int)me->query("jing", 1) < (60 - (int)me->query("int") * 2)) {
    write("你仔细想了半天，也想不出来。\n");
    return 1;
  }
  if (me->query("potential", 1) < 1) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121) {
    if (random(10) >= 3) {
      write(HIR "你想起在一部书里读到过这个典故。你道：遥指扶桑日那边。\n" NOR, me);
      me->improve_skill("dacheng-fofa", (int)me->query("int") * 4);
      me->receive_damage("jing", 80 - (int)me->query("int") * 2);
      me->add("potential", -1);
      me->delete_temp("ask_force_3", 1);
      return 1;
    } else {
      write("你仔细想了半天，也想不出来。\n");
      me->receive_damage("jing", 25);
      me->delete_temp("ask_force_3");
      return 1;
    }
  }
}

int do_nod4(object me) {
  if (this_player()) me = this_player();
  if (!me->query_temp("ask_force_4")) return 0;
  if ((int)me->query("jing", 1) < (60 - (int)me->query("int") * 2)) {
    write("你仔细想了半天，也想不出来。\n");
    return 1;
  }
  if (me->query("potential", 1) < 1) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) < 101 || (int)me->query_skill("dacheng-fofa", 1) > 121) {
    write("你仔细想了半天，也想不出来。\n");
    me->receive_damage("jing", 80 - (int)me->query("int") * 2);
    return 1;
  }
  if ((int)me->query_skill(
    "dacheng-fofa",
    1
  ) >= 101 && (int)me->query_skill("dacheng-fofa", 1) <= 121) {
    if (random(10) > 3) {
      write(HIW "你想起在一部经书里读到过这个典故。你答道：夜听水流庵后竹，昼起看云面前山。\n" NOR, me);
      me->improve_skill("dacheng-fofa", (int)me->query("int") * 4);
      me->receive_damage("jing", 80 - (int)me->query("int") * 2);
      me->add("potential", -1);
      me->delete_temp("ask_force_4", 1);
      return 1;
    } else {
      write("你仔细想了半天，也想不出来。\n");
      me->receive_damage("jing", 25);
      me->delete_temp("ask_force_4");
      return 1;
    }
  }
}
