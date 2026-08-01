int ask_hu_quest() {
  object me = this_player();
  if (me->query_temp("hu/quest1") != 2) {
    command("say 怎么突然提起他做什么？");
    return 1;
  } else {
    command("say 原来胡先生还健在？");
    command("jump");
    command("say 我帮胡先生狠狠的骂了这个家伙一顿，而且他也自己中了自己的毒死了。");
    command("say 胡先生若是能亲自看到，想必会很高兴。");
    me->set_temp("hu/quest1", 3);
    return 1;
  }
}

int ask_hu() {
  object me = this_player();
  if (!me->query_temp("hu/quest2")) {
    command("say 胡青牛先生号称蝶谷医仙，医术一流，不过脾气有点怪。");
    return 1;
  } else {
    command("ah");
    command("say 真是对不住，最近明教将要起事，我实在抽不出身。");
    command("say 麻烦了你三番两此帮忙胡先生送口信。");
    command("say 请告诉他，无忌安好，并且请他小心身子。");
    command("say 这个铁炎令你拿去，让胡先生看看吧。");
    me->apply_condition("hu_quest", 5);
    new("/d/mingjiao/obj/tieyan")->move(me);
    return 1;
  }
}

int ask_hdg() {
  object me = this_player();
  command("say 蝴蝶谷是胡青牛神医的居所，在安徽附近，跟着蝴蝶就能找到了。");
  me->set_temp("hdg", 1);
  return 1;
}

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
  if (!me->query("jiuyang/wei"))
    return "最近明教繁荣昌盛，也未听闻有什么别的消息。";
  me->set("jiuyang/zhang", 1);
  return "想当年太师傅在少林曾听闻昆仑派“昆仑三圣”何足道带话到少林说“经在油中”，\n" +
    "不知道此话有何含义。";
}

string ask_fel() {
  object me = this_player();
  if (me->query("family/master_name") != "张无忌")
    return ("这是我明教的宝物，你并非我的传人，不能给你！");

  if (present("shangshanfae ling", me))
    return "咦？赏善罚恶令不是在你身上么？";

  if (present("shangshanfae ling", this_object())) {
    command("give shangshanfae ling to " + me->query("id"));
    return ("这赏善罚恶令就给你了，你可要妥善保管好！");
  } else return ("你来晚了，赏善罚恶令已经让我送与他人了。");
}

string ask_shu() {
  mapping fam;
  object ob;
  if (!(fam = this_player()->query("family")) || fam["family_name"] != "明教")
    return "嗯....这我可不清楚，你最好问问别人吧。";
  if (this_player()->query_temp("cuff_book_flood"))
    return "小子！想骗我的书卖钱？去死吧！！！。";
  ob = unew(BOOK_D("cuff_book"));
  if (!clonep(ob)) return "你来晚了，「七伤拳谱」已经被你师兄拿去了。";
  if (clonep(ob) && ob->violate_unique()) {
    destruct(ob);
    return "你来晚了，「七伤拳谱」已经被你师兄拿去了。";
  }
  ob->move(this_player());
  this_player()->set_temp("cuff_book_flood", 1);  // slogan river !
  return "好吧，这本「七伤拳谱」你拿回去好好钻研。";
}

int do_lingwu(string arg) {
  object me = this_player();
  object who = this_object();
  int i = me->query_skill("qiankun-danuoyi", 1);
  int lv = me->query("max_pot") - 100;
  if (!living(who))
    return notify_fail("张无忌现在的状况，看来无法回答你任何问题。\n");

  if (me->query("family/master_name") != "张无忌")
    return notify_fail("你非我弟子，向我讨教什么啊？\n");

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
  write("你向张无忌讨教关于「" + to_chinese(arg) + "」的疑问。\n");
  write("你听了张无忌的指点，对" + to_chinese(arg) + "的体会又深了一层。\n");
  //天赋“领悟大师”影响效果：  by spiderii@ty ..lsxk想法太过变态了
  if (me->query("relife/quest/lwds")) {
    if (random(100) > me->query("relife/quest/lwds") * 10)
      write(HIC "你经过转世重修后，领悟到了武技万变不离其宗的道理，瞬间领悟到了乾坤大挪移的精华所在。\n" NOR);
    me->set_skill("qiankun-danuoyi", lv);
  }

  i = i / 5 * 2;
  if (i > 100) i = 100;
  me->receive_damage("jing", i);
  if (me->query_skill("qiankun-danuoyi", 1) < 300)
    me->add("potential", -random(2));
  me->improve_skill(arg, me->query_skill("literate", 1) / 3 + 1);
  return 1;
}

int accept_object(object who, object ob) {
  object me;
  object *dest;
  mapping fam;
  int i, j = 0;

  me = this_object();
  fam = who->query("family");

  if (userp(ob)) return 0;
  if (ob->query("id") == "tie ling" && ob->query("name") == HIB "玄铁令" NOR) {
    if (this_player()->query("mjling/complete")) {
      command("smile");
      command("say 我会帮你好好收著的。");
      this_player()->add("mjling/ling", ob->query_amount());
      call_out("destroying", 1, ob);
      return 1;
    }
    command("nod");
    command("say 多谢，下次有需要可以再来找我。\n");
    this_object()->add("ling", ob->query_amount());
    call_out("destroying", 1, ob);
    return 1;
  }
  if ((string)ob->query("id") == "shenghuo ling") {
    if (!(fam) || fam["family_name"] != "明教") {
      command("thank " + (string)who->query("id"));
      command("say 多谢你为本教找回了圣物，不知我应该怎么谢谢你？\n");
      call_out("destroying", 1, ob);
      return 1;
    }
    if (fam["family_name"] == "明教"
      && (fam["master_name"] != "张无忌" || who->query_temp("mj_jiaozhu"))) {
      command("nod " + (string)who->query("id"));
      command("say 你为本教找回了圣物，这笔功劳不小啊！\n");
      call_out("destroying", 1, ob);
      who->add("shen", 2000);
      who->add("combat_exp", 100 + random(50));
      tell_object(who, HIW "你被奖励了一些正神和经验值。\n" NOR);
      return 1;
    }
    dest = users();
    i = sizeof(dest);
    while (i--) {
      if (userp(dest[i]) && !wizardp(dest[i]) && dest[i]->query_temp("mj_jiaozhu"))
        j++;
    }
    if (j > 0) {
      command("pat " + (string)who->query("id"));
      command("say 不错不错，但有人已经比你先找到了。\n");
      return 0;
    }
    command("ah " + (string)who->query("id"));
    command("say 你竟找回了本教圣物，不愧是我的弟子！");
    command("say 上代阳教主有遗命，寻回圣物者当可修习本教神功，你去秘道中试试吧。");
    who->set_temp("mj_jiaozhu", 1);
    call_out("destroying", 1, ob);
    return 1;
  } else if (ob->query("name") == "成昆的首级" && ob->query("id") == "shouji") {
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
    who->add("shen", MAX(ABS(who->query("shen")) / 5, 50000));  //增加shen 降低exp奖励
    if (who->query("shen") > who->query("combat_exp"))
      who->set("shen", who->query("combat_exp"));  //for hsdizi hehe
      who->add("combat_exp", 50 + random(50));
    who->add("potential", 40);
    if (who->query("potential") > who->query("max_pot"))
      who->set("potential", who->query("max_pot"));
    tell_object(who, HIW "你被奖励了一些正神、潜能和经验值。\n" NOR);
    return 1;
  } else return 0;
}

string ask_ling() {
  object ob, ob1, ob2, me = this_player();
  ob1 = present("yitian jian", me);
  ob2 = present("tulong dao", me);
  if (this_object()->query("making"))
    return "别太心急了。";
  if (!this_object()->query("waiting")) {
    if (!me->query_temp("mj/ling")) {
      if (!ob1 || !ob2 || me->query("family/family_name") != "明教")
        return "铸令艰难无比，连我教第一匠人吴副旗使也想不出当初圣火令如何铸出的。";
      command("consider");
      command("say 听太师父说过，当年郭大侠夫妇将神雕大侠杨过的一把玄铁剑熔了，铸造成两把神兵利器。");
      command("say 如今你两把兵器都到手了，也许可以用同样的方法铸出不下于圣火令的兵器？");
      command("walkby");
      me->set_temp("mj/ling", 1);
      return "也许....";
    } else {
      command("nod");
      command("say 我先到光明顶广场等你。");
      command("party 我与" + me->query("name") + "要尝试铸令，请各位来光明顶广场帮忙。");
      command("party 也请各位通知各旗使，来光明顶广场准备。");
      ob = this_object();
      ob->move("/d/mingjiao/gmd");
      ob->set("waiting", 1);
      return "我先走一步。";
    }
  }
  if (!ob1 || !ob2)
    return "你的材料呢？";
  command("ok");
  command("say 既然你已准备好，再等一会，大家都来了我们就来试试。");
  call_out("start_ling", 60, me, 0);
  this_object()->set("making", 1);
  return "就快准备好了。";
}

void start_ling(object me, int count) {
  object room, *obs, ob1, ob2, ob3, ob;
  int i, neili;
  room = environment(me);
  switch (count) {
    case 0:
      if (present("wen cangsong", room) && present("yan tan", room)) {
        message_vision(HIG "厚土，巨木两旗开始将准备好的木头土石堆成一个巨灶。\n" NOR, me);
        call_out("start_ling", 20, me, 1);
      } else {
        message_vision(HIG "但是厚土，巨木两旗使不在，无法成功的建立炉灶。\n" NOR, me);
        me->delete_temp("mj/ling");
        this_object()->delete("making");
      }
      break;
    case 1:
      if (present("xin ran", room) && present("tang yang", room)) {
        message_vision(HIR "烈火旗升起了雄雄大火，洪水旗在外围围了一圈，准备应付紧急状况。\n" NOR, me);
        call_out("start_ling", 20, me, 2);
      } else {
        message_vision(HIR "但是烈火，洪水两旗使不在，无法起火。\n" NOR, me);
        me->delete_temp("mj/ling");
        this_object()->delete("making");
      }
      break;
    case 2:
      ob1 = present("yitian jian", me);
      ob2 = present("tulong dao", me);
      ob3 = present("shenghuo ling", me);
      if (!ob1 || !ob2) {
        message_vision(HIW "但是$N忘了带刀剑，无法铸造。\n", me);
        me->delete_temp("mj/ling");
        this_object()->delete("making");
        return;
      }
      if (!ob3) {
        message_vision(HIW "但是$N忘了带圣火令，没有适合的把手，无法铸造。\n", me);
        me->delete_temp("mj/ling");
        this_object()->delete("making");
        return;
      }
      if (present("zhuang zheng", room)) {
        message_vision(HIW "庄铮赤裸著上身，把刀剑放入炉中，开始熔铸。\n" NOR, me);
        destruct(ob1);
        destruct(ob2);
        call_out("start_ling", 20, me, 3);
      } else {
        message_vision(HIW "但是锐金旗使不在，无法铸造。\n" NOR, me);
        me->delete_temp("mj/ling");
        this_object()->delete("making");
      }
      break;
    case 3:
      message_vision(HIY "在场的明教弟子皆上前，使用圣火神功的传功心法帮忙。\n" NOR, me);
      obs = all_inventory(room);
      for (i = 0; i < sizeof(obs); i++) {
        if (obs[i]->query("family/family_name") == "明教")
          neili += obs[i]->query("neili");
      }
      this_object()->set("total_neili", neili);
      if (neili < 30000) {
        message_vision(HIY "但是大家集合的内力还是不够强，众人内力耗尽，昏了过去。\n" NOR, me);
        for (i = 0; i < sizeof(obs); i++) {
          if (obs[i]->query("family/family_name") == "明教")
            obs[i]->unconcious();
          obs[i]->set("neili", 0);
        }
        me->delete_temp("mj/ling");
        this_object()->delete("making");
      } else {
        message_vision(HIM "集合了众人之力，两把神兵利器终于开始慢慢的熔解！\n" NOR, me);
        message_vision(HIM "两把兵器中似乎有什么纸片，但是立刻被烧成灰了。\n" NOR, me);
        for (i = 0; i < sizeof(obs); i++) {
          if (obs[i]->query("family/family_name") == "明教")
            obs[i]->set("neili", 0);
        }
        call_out("start_ling", 20, me, 4);
      }
      break;
    case 4:
      message_vision(HIC "玄铁以及白金砂的熔浆慢慢的流入了事先刻好形状的土坑。\n" NOR, me);
      neili = this_object()->query("total_neili");
      neili = neili / 10000 + random(3);
      message_vision(HIC "$N待炉灶冷却，上前取出了" + (neili + 10) + "把玄铁令！\n" NOR, this_object());
      command("party 感谢各位的帮忙，玄铁令铸造成功了。");
      command("party 现在我与各位旗使必须休息一下，有需要玄铁令的请向我询问。");
      message_vision(HIW "张无忌以及五行旗使离开了此地。\n" NOR, me);
      me->delete_temp("mj/ling");
      me->set("mjling/complete", 1);
      me->set("mjling/ling", 10);
      ob = present("zhang wuji", room);
      ob->delete("making");
      ob->move("/d/mingjiao/sht");
      ob->set("ling", neili);
      ob = present("zhuang zheng", room);
      destruct(ob);
      ob = present("wen cangsong", room);
      destruct(ob);
      ob = present("tang yang", room);
      destruct(ob);
      ob = present("xin ran", room);
      destruct(ob);
      ob = present("yan tan", room);
      destruct(ob);
  }
}

string ask_getling() {
  if (this_player()->query_skill("shenghuo-lingfa", 1) < 150)
    return "你功夫还不够呢。";

  if (present("xuantie ling", this_player())
    && present("xuantie ling", this_player())->query_amount() > 1)
    return "你身上的令已经够用啦";

  if (this_player()->query("mjling/complete")
    && this_player()->query("mjling/ling") > 0) {
    command("smile");
    new("clone/weapon/xuantie-ling")->move(this_player());
    this_player()->add("mjling/ling", -1);
    return "你的玄铁令在这，别弄丢啦。";
  }

  if (this_object()->query("ling") < 1)
    return "我现在身上并无玄铁令。";

  command("ok");
  command("say 用完了请再交给我，让其他人使用。");
  this_object()->add("ling", -1);
  new("/clone/weapon/xuantie-ling")->move(this_player());
  return "别弄丢了啊。";
}
/*
void restart(object me, object ob)
{
	if(me->query("mj_jiaozhu"))
		me->delete("mj_jiaozhu");
	if (ob) destruct(ob);
}
*/
void destroying(object ob) {
  if (ob) destruct(ob);
}

int pfm_qishang() {
  object me, weapon;
  me = this_object();
  weapon = me->query_temp("weapon");
  if (me->is_busy()) return 0;
  if (me->query_skill_prepared("cuff") != "qishang-quan") {
    me->prepare_skill("cuff");
    me->map_skill("cuff", "qishang-quan");
    me->prepare_skill("cuff", "qishang-quan");
  }
  if (objectp(weapon)) {
    message_vision("$N将手中的$n插回腰间。\n", me, weapon);
    weapon->unequip();
  }
  this_object()->set("jiali", 50);
  command("perform qishang");
  return 1;
}

int pfm_duanhun() {
  object me, weapon;
  me = this_object();
  weapon = me->query_temp("weapon");
  if (me->is_busy()) return 0;
  if (me->query_skill_prepared("cuff") != "qishang-quan") {
    me->prepare_skill("cuff");
    me->map_skill("cuff", "qishang-quan");
    me->prepare_skill("cuff", "qishang-quan");
  }
  if (objectp(weapon)) {
    message_vision("$N将手中的$n插回腰间。\n", me, weapon);
    weapon->unequip();
  }
  this_object()->set("jiali", 150);
  command("perform duanhun");
  return 1;
}

int pfm_tisha() {
  object me, weapon, *obj, wep;
  int i;
  mapping weapon_prop;

  me = this_object();
  weapon = me->query_temp("weapon");
  obj = all_inventory(me);
  if (me->is_busy()) return 0;
  this_object()->set("jiali", 150);
  if (me->query_skill_prepared("cuff") != "shenghuo-lingfa") {
    me->prepare_skill("cuff");
    me->map_skill("cuff", "shenghuo-lingfa");
    me->prepare_skill("cuff", "shenghuo-lingfa");
  }
  if (weapon && weapon->query("skill_type") == "dagger") {
    command("perform tisha");
    return 1;
  }
  for (i = 0; i < sizeof(obj); i++)
    if (mapp(weapon_prop = obj[i]->query("weapon_prop"))
      && obj[i]->query("skill_type") == "dagger")
      wep = obj[i];
  if (wep) {
    if (weapon) weapon->unequip();
    command("wield " + wep->query("id"));
    command("perform tisha");
  }
  return 1;
}
/*
int pfm_chan()
{
	object me,weapon, *obj, wep;
	int i;
	mapping weapon_prop;

	me = this_object();
	weapon = me->query_temp("weapon");
	obj = all_inventory(me);
	if(me->is_busy()) return 0;
	this_object()->set("jiali", 1);
	if(weapon && weapon->query("skill_type") == "sword" ){
		command("perform chan");
		return 1;
	}
	for(i=0; i<sizeof(obj); i++)
	if(mapp(weapon_prop = obj[i]->query("weapon_prop"))
	&& obj[i]->query("skill_type")=="sword")
		wep = obj[i];
	if(wep){
		if(weapon) weapon->unequip();
		command("wield "+wep->query("id"));
	}
	return 1;
}
*/
int pfm_zhen() {
  object weapon, me;
  me = this_object();
  weapon = me->query_temp("weapon");
  if (me->is_busy()) return 0;
  if (me->query_skill_prepared("cuff") != "taiji-quan") {
    me->prepare_skill("cuff");
    me->map_skill("cuff", "taiji-quan");
    me->prepare_skill("cuff", "taiji-quan");
  }
  if (objectp(weapon)) {
    message_vision("$N将手中的$n插回腰间。\n", me, weapon);
    weapon->unequip();
  }
  this_object()->set("jiali", 25);
  command("perform zhen");
  return 1;
}

int pfm_tougu() {
  command("exert powerup");
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
