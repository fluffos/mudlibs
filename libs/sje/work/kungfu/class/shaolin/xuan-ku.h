// xuan-ku.h for fight and get letter from Xuan

#include <ansi.h>

string *names = ({
  "chengguan luohan",
  "chengzhi luohan",
  "chengming luohan",
  "chengjing luohan",
  "chengjian luohan",
  "chengxing luohan",
  "chengji luohan",
  "chengmie luohan",
  "chenghe luohan",
});

void preparing(object, object);

string ask_me() {
  mapping fam, my_fam, skl;
  object fighter, me, room, monk;
  string *sname;
  int i, j;

  fighter = this_player();
  me = this_object();
  my_fam = me->query("family");

  skl = fighter->query_skills();
  if (mapp(skl)) sname = keys(skl);

  if (fighter->query("luohan_winner"))
    return RANK_D->query_respect(fighter) + "已然闯过罗汉大阵，可不要拿老衲开这等玩笑。";

  for (i = 0; i < sizeof(skl); i++) {
    if (skl[sname[i]] < 80 && sname[i] != "medicine")
      return RANK_D->query_respect(fighter) + "功力不够，不够资格闯罗汉大阵。";
  }

  if (mapp(fam = fighter->query("family"))
    && fam["family_name"] == "少林派"
    && fam["generation"] != (my_fam["generation"] + 2))
    return RANK_D->query_respect(fighter) + "辈份不合，不够资格闯罗汉大阵。";

  if ((int)fighter->query("guilty") > 0)
    return RANK_D->query_respect(fighter) + "你累犯数戒，身带重罪，我如何能准许你闯罗汉大阵！";

  if (me->query("assigned_fighter"))
    return RANK_D->query_respect(fighter) + "，今日已有人挑战罗汉大阵，你过一段时间再来吧。";

  fighter->set_temp("xuanku-asked", 1);

  say("\n玄苦说道：好吧，我去召集罗汉堂长老，稍候在中央练武场上等你。\n");

  me->set("assigned_fighter", fighter->query("id"));

  if (!fighter->query_temp("xuannan-asked"))
    say("\n玄苦又道：请你速去告知般若堂玄难大师，请他即刻召集般若堂诸罗汉。\n");

  message_vision("\n玄苦大师往西离开。\n\n", fighter);

  for (j = 1; j < 10; j++) {
    room = load_object("/d/shaolin/luohan" + j);

    me->move(room);

    if (!objectp(monk = present(names[j - 1], room))) {
      me->move("/d/shaolin/lhtang");
      me->delete("assigned_fighter");
      message_vision("\n玄苦大师走了过来。\n\n", fighter);
      return "真是对不起，罗汉堂中有人不在，无法举行罗汉大阵。\n";
    }

    message("vision", "\n玄苦大师走了过来，跟" + monk->query("name") + "俯耳轻声说了几句。\n", room, monk);
    message("vision", monk->query("name") + "罗汉点了点头，玄苦大师快步走了出去。\n", room, monk);
  }

  me->set("location", 1);  // 防止 reset 召回 Yuj 19991115
  me->move("/d/shaolin/hguangz2");

  call_out("waiting", 1, me, 0);

  return "好！大家都出来了。\n";
}

void waiting(object me, int wait_time) {
  object fighter;

  if (wait_time >= 300) {
    say("玄苦说道：看来他不会来了，我们回去罢！\n\n");
    call_out("do_back", 0, me);
    return;
  }

  if (!objectp(fighter = present(me->query("assigned_fighter"), environment(me)))) {
    call_out("waiting", 1, me, wait_time + 1);
    return;
  }
  if (!present("xuannan dashi", environment(me)) || !fighter->query_temp("xuannan-asked")) {
    if (random(10) == 0)
      say("\n玄苦说道：" + RANK_D->query_respect(fighter) + "去请了玄难大师没有？ 照理他现在该到了罢？\n");

    call_out("waiting", 1, me, wait_time + 1);
    return;
  }
  preparing(me, fighter);
}

void preparing(object me, object fighter) {
  object monk, room;

  room = load_object("/d/shaolin/hguangz2");

  monk = present("daojue chanshi", room);
  if (monk) {
    message("vision", "玄苦大师跟道觉禅师俯耳轻声说了几句。\n", room, monk);
    monk->move("/d/shaolin/houdian");
    message("vision", monk->query("name") + "禅师点了点头，快步往北离开。\n", room);
  }

  message("vision", HIY "\n玄苦大师大声宣布：东罗汉大阵合围！\n" NOR, room);
  message("vision", "\n只听四周响起沙沙的脚步声，东西十八位罗汉们个个神情肃杀，\n"
    "或赤手空拳，或手持兵器，慢慢地围了上来，堵住了通路。\n\n", room);

  say("玄苦又道：准备，罗汉大阵即刻发动！\n\n");

  fighter->delete_temp("xuannan-asked");
  fighter->delete_temp("beat_count");
  fighter->set_temp("fighting", 1);

  call_out("fighting", 3, me, fighter, 0);
}

void fighting(object me, object fighter, int count) {
  object monk1, room1, room2;

  if (count++ < 9) {
    room1 = load_object("/d/shaolin/luohan" + count);
    room2 = load_object("/d/shaolin/hguangz2");

    message("vision", "\n罗汉大阵急速地旋转着，一层层地向内收紧！\n" NOR, room2);

    monk1 = present(names[count - 1], room1);
    if (monk1) {
      monk1->move(room2);
      monk1->move(room1);
    }
  }

  if (!fighter || !living(fighter) || environment(fighter) != environment(me)) {
    if (objectp(fighter)) {
      fighter->delete_temp("fighting");
      fighter->delete_temp("beat_count");
    }

    command("chat* 摇了摇头，说道：想不到... 唉！");
    command("sigh");
    call_out("do_back", 3, me);
    return;
  }
  if (count > 9) {
    if (objectp(fighter) && (int)fighter->query_temp("beat_count") >= 18)
      call_out("do_recruit", 2, me, fighter);
    else
      call_out("do_back", 3, me);
  } else call_out("fighting", 2, me, fighter, count);
}

void do_recruit(object me, object fighter) {
  mapping ft_fam;

  if (!objectp(fighter)) {
    call_out("do_back", 1, me);
    return;
  }
  fighter->delete_temp("beat_count");
  fighter->delete_temp("fighting");
  fighter->add("combat_exp", 7500);
  fighter->set("luohan_winner", 1);

  command("chat* congra");
  if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "少林派") {
    command("bow");
    command("say " + RANK_D->query_respect(fighter) + "此番过阵，当对本身修行大有助益，百尺竿头，更进一步，老衲就此别过！\n");
    call_out("do_back", 3, me);
  } else {
    command("say 恭喜你闯过了十八罗汉大阵！本寺有此等杰出弟子，届时必当为武林放一异彩！\n");
    call_out("do_back", 30, me);
  }
}

void do_back(object me) {
  object monk, room1, room2;

  message("vision", "\n玄苦大师挥了挥手， 罗汉堂长老们随即鱼贯离开练武场。\n", environment(me));

  room1 = load_object("/d/shaolin/hguangz2");
  room2 = load_object("/d/shaolin/houdian");

  monk = present("daojue chanshi", room2);
  if (monk) monk->move(room1);

  me->delete("assigned_fighter");
  me->move("/d/shaolin/lhtang");
  me->delete("location");
}

void attempt_apprentice(object ob) {
  object me;
  mapping ob_fam, my_fam;
  string name, new_name;

  me = this_object();
  my_fam = me->query("family");

  name = ob->query("name");

  if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "少林派") {
    command("say " + RANK_D->query_respect(ob) + "与本派素无来往，不知此话从何谈起？");
    return;
  }

  if ((string)ob->query("class") != "bonze" && ob_fam["family_name"] == "少林派") {
    command("say " + RANK_D->query_respect(ob) + "是俗家弟子，不能在寺内学艺。");
    return;
  }

  if (ob_fam["generation"] < my_fam["generation"]) {
    command("say " + RANK_D->query_respect(ob) + "，贫僧哪里敢当 !");
    return;
  }

  if (ob_fam["generation"] == (my_fam["generation"])) {
    command("nod");
    command("recruit " + ob->query("id"));
  }

  if (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "澄") {
    command("say " + ob_fam["master_name"] + "的徒弟怎么跑到我这儿来了，哈哈哈 !");
    command("recruit " + ob->query("id"));
  }

  if (ob_fam["generation"] == (my_fam["generation"] + 2)) {
    if (ob->query("luohan_winner")) {
      command("say 老衲垂死之年，又得一可塑之才，真是可喜可贺 !");

      name = ob->query("name");
      new_name = "澄" + name[2..3];
      ob->set("name", new_name);

      command("say 从今以后你的法名叫做" + new_name + "，恭喜你荣升为少林派澄字辈罗汉之一 !");
      command("recruit " + ob->query("id"));
    } else {
      command("say " + RANK_D->query_respect(ob) + "，你没有闯过十八罗汉大阵，不能越级拜师。");
    }
  }
}
