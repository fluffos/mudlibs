int do_walk() {
  string start_room;
  string name, weapon;
  object room;
  object ob;
  mapping obmap;
  int n;
  int i;
  object *inv;
  if (!environment())
    return 0;
  name = color_title[random(sizeof(color_title))] + first_name[random(sizeof(first_name))];
  name += name_words[random(sizeof(name_words))];

  if (time() - query("check_time") > 24000 && random(100) > 90 || !query_heart_beat(this_object())) {
    set_name((order[random(13)]) + name, ({ "killer", "shashou", "sha shou" }));
    set("gender", "男性");
    set("title", color_title[random(sizeof(color_title))]);
    n = 0;
    inv = all_inventory(this_object());

    for (i = 0; i < sizeof(inv); i++) {
      if (inv[i]->query("dynamic_quest"))
        command("chat " + inv[i]->query("name") + (order[random(13)]) + "我已经拿到手了。。。撤!!  \n" NOR);
    }

    message_vision("$N笑了笑说：东西已经到手，任务完成，撤了！\n" NOR, this_object());
    destruct(this_object());
    return 0;
  }

  n = 0;
  foreach (ob in all_inventory(environment())) {
    if (!ob) continue;
    if (!ob->query("dynamic_quest"))
      continue;
    command("get all");
    n++;
  }


  random_move();
  return 1;
}

int accept_fight(object ob) {
  command("say " + RANK_D->query_self(this_object())
    + "怎么可能是" + RANK_D->query_respect(ob)
    + "的对手？\n");
  return 0;
}

void fighting(object ob) {
  fight_ob(ob);
}

int kill_ob(object ob) {
  //解决halt后不战斗的问题
  ob->set_temp("tasknpc", 1);
  command("fear");
  command("say 不好，我被识破了!!");
  if (random(3) == 1) {
    command("say 逃啊!!");
    if (random(2) == 1) {
      command("go south");
      command("go west");
    }

    else {
      command("go north");
      command("go east");
    }
  }

  if (ob->query("combat_exp") > 4000000) {
    ::kill_ob(ob);
    message_vision(HIR "$N摇了摇头，道：“我和你拼了！！”\n说完双眼直视$n，运起神功，$n觉得有点害怕了。\n" NOR,
      this_object(), ob);
  }

}

mapping *dizhia = ({

  ([ "cdizhi": "苗疆",
    "weizhi2": "/d/miaojiang/jiedao4", ]),
  ([ "cdizhi": "扬州",
    "weizhi2": "/d/city/xjs", ]),
  ([ "cdizhi": "杭州",
    "weizhi2": "/d/hz/changlang1", ]),
  ([ "cdizhi": "杭州",
    "weizhi2": "/d/hz/yuquan", ]),
  ([ "cdizhi": "杭州",
    "weizhi2": "/d/hz/longjing", ]),
  ([ "cdizhi": "杭州",
    "weizhi2": "/d/hz/huanglongdong", ]),
  ([ "cdizhi": "武当",
    "weizhi2": "/d/wudang/shijie1", ]),
  ([ "cdizhi": "武当",
    "weizhi2": "/d/wudang/xuanyuemen", ]),
  ([ "cdizhi": "峨嵋",
    "weizhi2": "/d/emei/guanyinqiao", ]),
  ([ "cdizhi": "峨嵋",
    "weizhi2": "/d/emei/basipan3", ]),
  ([ "cdizhi": "峨嵋",
    "weizhi2": "/d/emei/caopeng", ]),
  ([ "cdizhi": "明教",
    "weizhi2": "/d/mingjiao/bishui", ]),
  ([ "cdizhi": "明教",
    "weizhi2": "/d/mingjiao/shanting", ]),
  ([ "cdizhi": "福州",
    "weizhi2": "/d/fuzhou/haigang", ]),
  ([ "cdizhi": "福州",
    "weizhi2": "/d/fuzhou/laozhai", ]),
  ([ "cdizhi": "星宿海",
    "weizhi2": "/d/xingxiu/shamo3", ]),
  ([ "cdizhi": "少林寺",
    "weizhi2": "/d/shaolin/songshu2", ]),
  ([ "cdizhi": "襄阳",
    "weizhi2": "/d/xiangyang/tanxi", ]),
  ([ "cdizhi": "雪山",
    "weizhi2": "/d/xueshan/shanlu1", ]),
  ([ "cdizhi": "华山",
    "weizhi2": "/d/huashan/yunu", ]),
  ([ "cdizhi": "慕容山庄",
    "weizhi2": "/d/mr/xiaojing1-2", ]),
  ([ "cdizhi": "慕容山庄",
    "weizhi2": "/d/mr/liulin", ]),
  ([ "cdizhi": "苏州城",
    "weizhi2": "/d/suzhou/baodaiqiao", ]),
  ([ "cdizhi": "苏州城",
    "weizhi2": "/d/suzhou/shihu", ]),
  ([ "cdizhi": "苏州城",
    "weizhi2": "/d/suzhou/xuanmiaoguan", ]),
  ([ "cdizhi": "苏州城",
    "weizhi2": "/d/suzhou/zijinan", ]),
  ([ "cdizhi": "少林寺",
    "weizhi2": "/d/shaolin/xiaolu-3", ]),
  ([ "cdizhi": "少林寺",
    "weizhi2": "/d/shaolin/talin1", ]),
  ([ "cdizhi": "武当",
    "weizhi2": "/d/wudang/husunchou", ]),
  ([ "cdizhi": "少林寺",
    "weizhi2": "/d/shaolin/shanlu8", ]),
  ([ "cdizhi": "星宿海",
    "weizhi2": "/d/xingxiu/mogaoku", ]),
  ([ "cdizhi": "峨嵋",
    "weizhi2": "/d/emei/jiulaodong", ]),
  ([ "cdizhi": "峨嵋",
    "weizhi2": "/d/emei/gudelin3", ]),
  ([ "cdizhi": "恒山",
    "weizhi2": "/d/hengshan/cuiping2", ]),
  ([ "cdizhi": "恒山",
    "weizhi2": "/d/hengshan/guolaoling", ]),
  ([ "cdizhi": "佛山镇",
    "weizhi2": "/d/foshan/duchang", ]),
  ([ "cdizhi": "黄河沿岸",
    "weizhi2": "/d/huanghe/shulin5", ]),
  ([ "cdizhi": "佛山镇",
    "weizhi2": "/d/foshan/road10", ]),
  ([ "cdizhi": "佛山镇",
    "weizhi2": "/d/foshan/xiaolu2", ]),
  ([ "cdizhi": "恒山",
    "weizhi2": "/d/hengshan/beiyuemiao", ]),
  ([ "cdizhi": "丐帮分舵",
    "weizhi2": "/d/gb/xinglin2", ]),
  ([ "cdizhi": "丐帮分舵",
    "weizhi2": "/d/gb/shangang", ]),
  ([ "cdizhi": "黄河沿岸",
    "weizhi2": "/d/huanghe/huanghe4", ]),
  ([ "cdizhi": "青城山",
    "weizhi2": "/d/huanghe/shamo", ]),

});


void unconcious() {
  object ob, me;
  mapping dizhis;
  int exp, nei, nei1;

  ob = this_object();
  dizhis = dizhia[random(sizeof(dizhia))];

  exp = ob->query("combat_exp");
  if (ob->query("kill") < 3 + random(5)) {
    message_vision(WHT "$N深吸口气，冷笑道，好身手！说完强忍伤痛纵身向「" + dizhis["cdizhi"] + "」处逃走。\n" NOR, ob, me);
    this_object()->set("eff_jing", (int)this_object()->query("max_jing"));
    this_object()->set("jing", (int)this_object()->query("max_jing"));
    this_object()->set("eff_qi", (int)this_object()->query("max_qi"));
    this_object()->set("qi", (int)this_object()->query("max_qi"));
    this_object()->set("jingli", (int)this_object()->query("max_jingli"));
    this_object()->set("neili", (int)this_object()->query("max_neili"));
    this_object()->set("food", (int)this_object()->max_food_capacity());
    this_object()->set("water", (int)this_object()->max_water_capacity());
    this_object()->remove_all_killer();
    this_object()->clear_condition();
    this_object()->concious();
    this_object()->add_temp("apply/attack", random(120));
    this_object()->add_temp("apply/armor", 100 + random(120));
    this_object()->add_temp("apply/damage", 20 + random(20));
    ob->add("kill", 1);
    ob->add("combat_exp", exp / 3);
    ob->move(dizhis["weizhi2"]);
    this_object()->concious();
    return;
  }

  ::unconcious();
}


void die() {
  object ob, me;
  mapping dizhis;
  int exp, nei, nei1;

  ob = this_object();
  dizhis = dizhia[random(sizeof(dizhia))];

  exp = ob->query("combat_exp");
  if (ob->query("kill") < 3 + random(5)) {
    message_vision(WHT "$N深吸口气，冷笑道，好身手！说完强忍伤痛纵身向「" + dizhis["cdizhi"] + "」处逃走。\n" NOR, ob, me);
    this_object()->set("eff_jing", (int)this_object()->query("max_jing"));
    this_object()->set("jing", (int)this_object()->query("max_jing"));
    this_object()->set("eff_qi", (int)this_object()->query("max_qi"));
    this_object()->set("qi", (int)this_object()->query("max_qi"));
    this_object()->set("jingli", (int)this_object()->query("max_jingli"));
    this_object()->set("neili", (int)this_object()->query("max_neili"));
    this_object()->set("food", (int)this_object()->max_food_capacity());
    this_object()->set("water", (int)this_object()->max_water_capacity());
    this_object()->remove_all_killer();
    this_object()->clear_condition();
    this_object()->concious();
    this_object()->add_temp("apply/attack", random(120));
    this_object()->add_temp("apply/armor", 100 + random(120));
    this_object()->add_temp("apply/damage", 20 + random(20));
    ob->add("kill", 1);
    ob->add("combat_exp", exp / 3);
    ob->move(dizhis["weizhi2"]);
    this_object()->concious();
    return;
  }

  ::die();
}
