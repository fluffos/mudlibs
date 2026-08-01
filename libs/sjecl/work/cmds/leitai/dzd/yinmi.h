int do_kill(string arg);
int do_tiao(string arg);

void init() {
  object room, *ob;
  object me = this_player();
  object here = this_object();
  int i;

  ::init();
  add_action("do_kill", "kill");
  add_action("do_kill", "ansuan");
  add_action("do_kill", "touxi");
  add_action("do_tiao", "tiao");

  if (!me) return;

  if (userp(me) && !wizardp(me)) {
    if (!room = find_object(OUT_DOWN))
      room = load_object(OUT_DOWN);
    ob = all_inventory(here);
    for (i = 0; i < sizeof(ob); i++) {

      if (ob[i]->query("marry") && me->query("marry") && me->query("marry/id") == ob[i]->query("id")) {
        tell_object(
          me,
          HIM "你看到" + ob[i]->query("name") + "在这里大吃一惊，深情地看着" + me->query("gender") == "男性" ? "她" : "他" + "，嗲道：你怎么也来这里了啊。\n" NOR
        );
        tell_object(ob[i], HIM "" + me->query("name") + "看到你在这里大吃一惊，深情地看着你，嗲道：你怎么也来这里了啊。\n" NOR);
        continue;
      }


      if (userp(ob[i]) && !wizardp(ob[i]) && ob[i] != me) {
        tell_object(me, HIW "你突然发现" + ob[i]->name() + "也" + W_MSG + ",不禁大吃一惊！\n" NOR);
        message_vision(HIW "$n看到$N发现了$p，大吼一声，向$N扑了过来!\n" NOR, me, ob[i]);
        tell_object(ob[i], "藏在这么隐秘的地方居然也会被发现，你不禁手脚大乱。\n");
        ob[i]->add_busy(1 + random(4));
        me->kill_ob(ob[i]);
        ob[i]->kill_ob(me);
        return;
      }
    }
  }
  "/cmds/std/look.lpc"->look_room(me, here);
}

int do_tiao(string arg) {
  object me = this_player();
  string msg1, msg2;
  if (me->is_busy() || me->is_fighting())
    return notify_fail("你正忙着呢。\n");
  if (!arg || arg != "down")
    return notify_fail("你要跳到哪儿？\n");
  if (W_MSG == "附在石壁上") {
    msg1 = HIY "$N轻轻一纵身，如羽毛般轻轻飘了下来。\n" NOR;
    msg2 = HIY "" + me->name() + "从石壁上跳了下来\n" NOR;
  }
  if (W_MSG == "在树上") {
    msg1 = HIY "$N轻轻一纵，跳到了地上。\n" NOR;
    msg2 = HIY "" + me->name() + "从树上跳了下来\n" NOR;
  }
  message_vision(msg1, me);
  me->move(OUT_DOWN);
  message("vision", msg2, OUT_DOWN, me);
  return 1;
}

string look_down() {
  object room;
  if (!room = find_object(OUT_DOWN))
    room = load_object(OUT_DOWN);
  "/cmds/std/look.lpc"->look_room(this_player(), room);
  return "" "";
}

int do_kill(string arg) {
  object ob, room;
  object me = this_player();
  if (me->is_busy() || me->is_fighting())
    return notify_fail("你正忙着呢。\n");
  if (!arg || !(room = find_object(OUT_DOWN)))
    return notify_fail("你要偷袭谁？\n");
  if (!(ob = present(arg, room)))
    return notify_fail("你要偷袭谁？\n");
  if (!ob->is_character() || ob->is_corpse())
    return notify_fail("看清楚一点！\n");
  if (!userp(ob))
    return notify_fail("偷袭npc? ……\n");
  //if(wiz_level(me) < wiz_level(ob))
  //return notify_fail("你不能偷袭巫师等级比你高的对手。\n");
  message_vision(HIW "$N从石壁上一跃而下，气势如虹，直取" + ob->name() + "！\n" NOR, me);
  message_vision(HIW "忽然一股杀气袭来，$N抬头望去，只见一个人影挟着劲气飞掠而下！！\n" NOR, ob);
  me->move(room);
  if (!random(10)) {
    message_vision(HIY "却见$N早有准备，身子轻轻一侧让过来势，趁机对$n发动攻击。\n" NOR, ob, me);
    me->start_busy(3);
  } else if (!random(5)) {
    message_vision(HIW "$N大吃一惊，匆忙将身子向后一仰，$n堪堪擦着$N的鼻尖掠过！\n" NOR, ob, me);
  } else {
    message_vision(HIR "$N只觉一股凌厉刺骨的杀气袭来，不及回避，已被$n一击而中！！\n" NOR, ob, me);
    ob->start_busy(4);
  }
  me->kill_ob(ob);
  if (!userp(ob))
    ob->kill_ob(me);
  else {
    ob->fight_ob(me);
    if (userp(me))
      tell_object(ob, HIR "如果你要和" + me->name() + "性命相搏，请你也对这个人下一次kill指令。\n" NOR);
  }
  return 1;
}
