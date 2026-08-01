string ask_qishang() {
  mapping fam;
  object me = this_player();
  fam = me->query("family");
  if (!fam || fam["family_name"] != "明教" || fam["master_name"] != "张无忌")
    return "嗯....这我可不清楚，你最好问问别人吧。";
  if (me->query_skill("qishang-quan", 1) < 50)
    return "你先把七伤拳的基础打好再说吧。\n";
  if (me->query("xie_qishang"))
    return "咦，义父不是已经把七伤拳的拳理教了你吗？\n";
  if (me->query_temp("marks/七伤"))
    return "咦，我不是叫你出海去拜访我义父谢狮王了吗？\n";
  me->set("luopan/bhd");
  me->set_temp("marks/七伤", 1);
  command("hmm");
  command("whisper " + me->query("id") + " 我义父在极北冰火岛上，大概位于黄道带以北九百五十、以东二百个距离的地方。");
  new("/d/mingjiao/obj/luopan")->move(this_object());
  command("give luo pan to " + me->query("id"));
  return "这七伤拳，是当年我义父亲自传我的绝技，你如果真有信心和毅力，就出海去拜访我义父吧！\n";
}

string ask_book() {
  mapping fam;
  object me = this_player();
  fam = me->query("family");
  if (!fam || fam["family_name"] != "明教" || fam["master_name"] != "张无忌")
    return "我有一本太极拳经，是当年我武当的太师父送给我的。";
  me->set_temp("marks/秘1", 1);
  return "我有一本太极拳经，是当年我武当的太师父送给我的，现我交张散人了。";
}

string ask_me() {
  object me = this_player();
  if (me->query("jiuyang/zhang"))
    return "你知道“经在油中”此话的含义了么？";
  if (!me->query_temp("jiuyang/wei"))
    return "最近明教繁荣昌盛，也未听闻有什么别的消息。";
  me->delete_temp("jiuyang/wei");
  me->set("jiuyang/zhang", 1);
  return "想当年太师傅在少林曾听闻昆仑派“昆仑三圣”何足道带话到少林说“经在油中”，\n" +
    "不知道此话有何含义。";
}

string ask_shu() {
  mapping fam;
  object ob;
  if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
    return "嗯....这我可不清楚，你最好问问别人吧。";
  ob = unew("/d/mingjiao/obj/cuff_book");
  if (!clonep(ob)) return "你来晚了，「七伤拳谱」已经被你师兄拿去了。";
  if (clonep(ob) && ob->violate_unique()) {
    destruct(ob);
    return "你来晚了，「七伤拳谱」已经被你师兄拿去了。";
  }
  ob->move(this_player());
  return "好吧，这本「七伤拳谱」你拿回去好好钻研。";
}

int do_lingwu(string arg) {
  object me = this_player();
  object who = this_object();
  int i = me->query_skill("qiankun-danuoyi", 1);
  if (!living(who))
    return notify_fail("张无忌现在的状况，看来无法回答你任何问题。\n");
  if (!arg || arg != "qiankun-danuoyi") {
    message_vision("$N向$n讨教一些关于武学上的疑问。\n", me, who);
    command("dunno " + me->query("id"));
    return 1;
  }
  if (me->is_busy() || me->is_fighting()) {
    command("say 你正忙着干别的事情呢，忙完了再说吧。");
    return 1;
  }
  if (me->query("jing") < 10)
    return notify_fail("你太累了，还是休息一会吧。\n");
  if ((int)me->query("potential", 1) < 1)
    return notify_fail("你潜能不够，已经用完了。\n");
  if (i <= 200) {
    command("say 你的乾坤大挪移等级不够，还不能从我这里学到什么。");
    return 1;
  }
  message_vision("$N向$n讨教关于「" + to_chinese(arg) + "」的疑问。\n", me, who);
  write("你听了张无忌的指点，对" + to_chinese(arg) + "的体会又深了一层。\n");
  me->receive_damage("jing", i / 5 * 2);
  me->add("potential", -random(2));
  me->improve_skill(arg, me->query_skill("literate", 1) / 3 + 1);
  return 1;
}

int accept_object(object who, object ob) {
  object me;
  mapping fam;
  me = this_object();
  fam = who->query("family");

  if (userp(ob)) return 0;
  if ((string)ob->query("id") == "shenghuo ling") {
    if (!(fam) || fam["family_name"] != "明教") {
      command("thank " + (string)who->query("id"));
      command("say 多谢你为本教找回了圣物，不知我应该怎么谢谢你？\n");
      remove_call_out("destroying");
      call_out("destroying", 1, ob);
      return 1;
    }
    if (fam["family_name"] == "明教" &&
      (fam["master_name"] != "张无忌" || who->query_temp("mj_jiaozhu"))) {
      command("nod " + (string)who->query("id"));
      command("say 你为本教找回了圣物，这笔功劳不小啊！\n");
      remove_call_out("destroying");
      call_out("destroying", 1, ob);
      who->add("shen", who->query("combat_exp") / 10 + 2000);
      who->add("combat_exp", 100 + random(50));
      tell_object(who, HIW "你被奖励了一些正神和经验值。\n" NOR);
      return 1;
    }
    if (me->query("mj_jiaozhu")) {
      command("pat " + (string)who->query("id"));
      command("say 不错不错，但有人已经比你先找到了。\n");
      return 0;
    }
    command("ah " + (string)who->query("id"));
    command("say 你竟找回了本教圣物，不愧是我的弟子！");
    command("say 上代阳教主有遗命，寻回圣物者当可修习本教神功，你去秘道中试试吧。");
    who->set_temp("mj_jiaozhu", 1);
    me->set("mj_jiaozhu", 1);
    remove_call_out("restart");
    call_out("restart", 14400, me, ob);
    return 1;
  } else if (ob->query("name") == "成昆的首级" && ob->query("id") == "head") {
    if (ob->query("victim_user")) {
      command("say 这不是真的成昆！");
      return 0;
    }
    if (ob->query("kill_by") != who) {
      command("say 但他好象不是你杀的吧？你是怎么得到这块人头的？");
      return 0;
    }
    command("say 好！你能杀了成昆为谢狮王报仇，不愧是我明尊座下弟子！");
    command("thumb " + (string)who->query("id"));
    call_out("destroying", 1, ob);
    who->add("shen", who->query("combat_exp") / 10 + 2000);
    who->add("combat_exp", 100 + random(50));
    who->add("potential", 40);
    if (who->query("potential") > who->query("max_pot"))
      who->set("potential", who->query("max_pot"));
    tell_object(who, HIW "你被奖励了一些正神、潜能和经验值。\n" NOR);
    return 1;
  } else return 0;
}

void restart(object me, object ob) {
  if (me->query("mj_jiaozhu"))
    me->delete("mj_jiaozhu");
  destruct(ob);
}

void destroying(object obj) {
  destruct(obj);
}

int pfm_qishang() {
  object me, weapon;
  me = this_object();
  weapon = me->query_temp("weapon");
  if (me->is_busy()) return 0;
  if (me->query_skill_prepared("cuff") != "qishang-quan") {
    command("bei none");
    command("enable cuff qishang-quan");
    command("bei qishang-quan");
  }
  if (objectp(weapon)) weapon->unequip();
  this_object()->set("jiali", 50);
  command("perform qishang");
  return 1;
}

int pfm_chan() {
  object me, weapon, *obj, wep;
  int i;
  mapping weapon_prop;
  me = this_object();
  weapon = me->query_temp("weapon");
  obj = all_inventory(me);
  if (me->is_busy()) return 0;
  this_object()->set("jiali", 1);
  if (weapon && weapon->query("skill_type") == "sword") {
    command("perform chan");
    return 1;
  }
  for (i = 0; i < sizeof(obj); i++)
    if (mapp(weapon_prop = obj[i]->query("weapon_prop"))
      && obj[i]->query("skill_type") == "sword")
      wep = obj[i];
  if (wep) {
    if (weapon) weapon->unequip();
    command("wield " + wep->query("id"));
  }
  return 1;
}

int pfm_zhen() {
  object weapon, me;
  me = this_object();
  weapon = me->query_temp("weapon");
  if (me->is_busy()) return 0;
  if (me->query_skill_prepared("cuff") != "taiji-quan") {
    command("bei none");
    command("enable cuff taiji-quan");
    command("bei taiji-quan");
  }
  if (objectp(weapon)) weapon->unequip();
  this_object()->set("jiali", 25);
  command("perform zhen");
  return 1;
}

int pfm_tougu() {
  command("exert tougu");
  return 1;
}

int pfm_yi() {
  object me, target, *obj, *enemy;
  int i, sz;
  me = this_object();
  enemy = me->query_enemy();
  if (!enemy || !arrayp(enemy)) return 0;
  sz = sizeof(enemy);
  if (sz > 4) sz = 4;
  if (sz > 0) target = enemy[random(sz)];
  else return 0;
  if (!me->is_killing(target->query("id"))) return 0;
  obj = all_inventory(environment(me));
  i = random(sizeof(obj));
  if (!obj[i]->is_character()) return 0;
  command("perform yi " + obj[i]->query("id"));
  return 1;
}
