#include <ansi.h>
string ask_me() {
  //      mapping fam, my_fam;
  object asker, me;
  asker = this_player();
  me = this_object();
  //      my_fam  = me->query("family");
  //      user = users();
  //      sname = keys(user);
  //      j=0; 
  if (!(asker->query("luohan_winner")))
    return RANK_D->query_respect(asker) + "连罗汉大阵都没有过，哪有资格教化他人。";
  if ((int)asker->query("guilty") > 0)
    return RANK_D->query_respect(asker) + "你累犯数戒，身带重罪，没有资格！";
  if ((int)asker->query_skill("buddhism", 1) < 120)
    return RANK_D->query_respect(asker) + "佛法浅薄，无法渡人，还是多多念经的要紧！";
  //       if( me->query("assigned_asker") )
  //         return RANK_D->query_respect(asker)+"今日已有人在施法渡人，你过一段时间再来吧。";
  if (asker->query_condition("xuandu_job") > 0)
    return "阿弥陀佛，这位" + RANK_D->query_respect(asker) + "今日施法渡人已经过多，你过一段时间再来吧。";
  if (asker->query("class") != "bonze")
    return "渡什么渡，你也懂的渡人的道理吗?\n";
  /*      for(i=0; i<sizeof(user); i++) {
        if ( mapp(fam = user(i)->query("family")) 
          && fam["family_name"] == "少林派"
          && user(i)->query("id")!=asker->query("id")){
             monks(j)=user(i);
             j++;
             }
         }*/
  say("\n玄渡大师说道：大师佛法渊深，又肯于渡人，真是天佑我少林。\n");
  me->set("assigned_asker", asker->query("id"));
  //     asker->set("assigned_student",monk->query("id"));
  message_vision("\n玄渡大师长袖一拂，一道青焰闪过，现出一个四方莲台。\n\n", asker);
  //     tai=new("/u/hunthu/obj/liantai");
  //     tai->move("/d/shaolin/sheliyuan"); 
  //     me->move(environment(monk));
  //     message("vision", "\n玄渡大师走了过来，说道:“"+asker->query("name")+"登台说法请"+monk->query("name")+"即刻前往菩提院听法。\n",  environment(monk),monk);
  //     me->move("/d/shaolin/putiyuan");
  return "老衲已准备好了，请将奸徒交与老衲。\n";
}

int accept_object(object ob, object obj) {
  mapping fam;
  object me = this_object();
  int obj_exp, my_exp, got_pot, got_pot1;
  //       if (ob->query("id")!=me->query("assigned_asker"))
  //       return notify_fail("你是哪里跳出来的，想骗老僧我?!\n");
  if (mapp(fam = obj->query("family"))
    && fam["family_name"] == "少林派") {
    say("玄渡怒道:我少林弟子岂有奸徒，老和尚定不饶你。\n");
    me->delete("assigned_asker");
    //      ob->leader(me);
    me->kill_ob(ob);
    return 1;
  }
  if (obj->query("id") == "killer") {
    say("玄渡怒道：你这家伙到会找窍门，老和尚定不容你。\n");
    me->delete("assigned_asker");
    me->kill_ob(ob);
    return 1;
  }
  if (userp(obj) == 1) {
    me->delete("assigned_asker");
    return notify_fail("你让玩家串通作弊，以为老僧是傻瓜?\n");
  }
  /*     if (living(obj)==0){
         me->delete("assigned_asker");       
         return notify_fail("你要教死人学好？！\n");
        }*/
  obj_exp = (int)obj->query("combat_exp", 1);
  my_exp = (int)ob->query("combat_exp", 1);
  if (my_exp > obj_exp * 3 / 2) {
    me->delete("assigned_asker");
    return notify_fail("你找个小东东来劝导,太也丢身份。\n");
  }
  me->delete("assigned_asker");
  message(
    "vision",
    HIY "\n玄渡大师双手一挥，已将" + obj->query("name") + "送上莲台，四周风雷大做。\n" NOR,
    environment(ob),
    ob
  );
  write(HIY "玄渡双手一挥，已将" + obj->query("name") + "送上莲台，四周风雷大做。\n" NOR);
  if (present("jiuhuan xizhang", ob)) {
    message(HIR "vision", ob->name() + HIR "用力摇动佛门至宝九环锡杖，九环齐飞，风雷顿息。\n", environment(ob), ob);
    write("你用力摇动佛门至宝九环锡杖，九环齐飞，风雷顿息。\n" NOR);
    message("vision", ob->name() + "大声念诵大乘般若经文，一片红光笼罩着法台。\n", environment(ob), ob);
    write("你大声念诵大乘般若经文，一片红光笼罩着法台。\n");
    message("vision", ob->name() + "一声断喝，云淡风清，四处踪迹不见。\n" NOR, environment(ob), ob);
    write("你一声断喝，云淡风清，四处踪迹不见。\n");
    got_pot = (obj_exp / my_exp) * 20 + random((int)ob->query_skill("buddhism", 1) / 8);
    if (((int)ob->query("potential", 1) + got_pot) > (int)ob->query("max_pot", 1)) {
      ob->set("potential", (int)ob->query("max_pot", 1));
    }
    if (((int)ob->query("potential", 1) + got_pot1) <= (int)ob->query("max_pot", 1)) {
      ob->add("potential", got_pot1 * 5);
      ob->add("combat_exp", got_pot1 * 3);
      tell_object(
        ob,
        HIW "你被奖励了：" + chinese_number(got_pot1 * 3) + "点经验和" + chinese_number(got_pot1 * 5) + "点潜能。\n" NOR
      );
      me->delete("assigned_asker");
    }
    ob->add("neili", -random(300));
    ob->apply_condition("xuandu_job", random(3));
    if ((int)ob->query("neili", 1) < 0) {
      ob->set("neili", 0);
      ob->unconcious();
    }
    say("玄渡大师合什礼拜道:大师已无边佛法渡化凶徒，使其破去心魔真乃功德无量。\n");
    call_out("destroying", 1, obj);
    return 1;
  }
  message("vision", ob->name() + HIY "在风雷声中大声念诵经文，然而风雷越演越烈。\n" NOR, environment(ob), ob);
  write("你在风雷声中大声念诵经文，然而风雷越演越烈。\n");
  if ((int)ob->query_skill("buddhism", 1) < 120) {
    message("vision", "一道闪电劈来，正中" + ob->name() + "的头顶。\n", environment(ob), ob);
    write(RED "一道闪电劈来，正中你的头顶，好疼呀!!\n" NOR);
    call_out("destroying", 1, obj);
    ob->add("jing", -500);
    ob->unconcious();
    return 1;
  }
  message("vision", GRN "风雷渐渐远去,法台一片平静。\n" NOR, environment(ob), ob);
  got_pot1 = (obj_exp / my_exp) * 20 + random((int)ob->query_skill("buddhism", 1) / 12) * 2;
  if (((int)ob->query("potential", 1) + got_pot1) > (int)ob->query("max_pot", 1)) {
    ob->set("potential", (int)ob->query("max_pot", 1));
  }
  if (((int)ob->query("potential", 1) + got_pot1) <= (int)ob->query("max_pot", 1)) {
    ob->add("potential", got_pot1 * 5);
    ob->add("combat_exp", got_pot1 * 3);
    tell_object(
      ob,
      HIW "你被奖励了：" + chinese_number(got_pot1 * 3) + "点经验和" + chinese_number(got_pot1 * 5) + "点潜能。\n" NOR
    );
    me->delete("assigned_asker");
  }
  ob->apply_condition("xuandu_job", random(3));
  ob->add("neili", -300);
  ob->add("jing", -300);
  if ((int)ob->query("neili", 1) < 0) {
    ob->set("neili", 0);
    ob->unconcious();
  }
  say("玄渡大师说道:大师虽佛法渊深，但无佛家宝器相助，只能胜过心魔，却无法将之一鼓破去。\n");
  call_out("destroying", 1, obj);
  return 1;
}

void destroying(object obj) {
  destruct(obj);
  return;
}
