//diaoyuchi.h
// modified by wind, by ahxia@HC, y2k

//如果对钓鱼的效果不满意，调整一下#define
#define MAX_EXP 3000000
#define EXP_RATIO 2
#define EXP_BASE 50
#define POT_RATIO 3/2
#define POT_BASE 30
#define FISH_BUSY(x) (4+random(x))

void init() {
  add_action("do_fish", "fish");
  add_action("do_banned", ({ "exert", "yun", }));
  add_action("do_banned2", ({ "steal", "fight", "kill", "touxi", "persuade" }));
  add_action("do_banned2", ({ "cast", "conjure", "hit", "perform", "scribe" }));
}

int do_banned(string arg) {
  object me = this_player();

  if (!me || !environment(me)) return 1;
  if (arg == "roar") {
    tell_room(environment(me), HIG + me->name() + "作孽般地大叫了起来～～\n" NOR, ({ me }));
    write(HIR "你自己作孽大叫，很容易倒霉的。\n" NOR);
    me->die();
  }
  return 0;
}
int do_banned2(string arg) {
  tell_object(this_player(), "钓鱼的时候乱闹企不把鱼吓跑了？！\n");
  return 1;
}


int do_fish() {
  object me, fish;
  me = this_player();
  if (me->is_fighting())
    return notify_fail("一边打架一边钓鱼，太累了吧？\n");
  if (me->is_busy())
    return notify_fail("你还是等鱼饵换好了在放杆吧！\n");
  if (me->query("qi") < 10)
    return notify_fail("你还是先休息一下吧，生命是第一位的。\n");
  if ((int)me->query("combat_exp") > MAX_EXP)
    return notify_fail("你已经不能通过钓鱼增加经验了。 \n");
  me->start_busy(FISH_BUSY(2));
  message_vision("$N拿起一根钓鱼杆坐在大石头上钓起鱼来……\n", me);

  call_out("fishing_msg", 1, me);
  return 1;
}
void reward_me(object me) {
  int kar, cps, exp, pot, reward;

  object ob;
  if (!me) return;

  exp = (int)me->query("combat_exp");
  pot = (int)me->query("potential");
  kar = me->query("kar");
  cps = me->query("cps");

  me->receive_damage("qi", 10);

  if (random(kar + cps) > ((kar + cps) / 10) * 9) {
    message_vision("$N钓到一条红鳟鱼\n", me);
    ob = new(__DIR__ "obj/fish_duke");
    ob->move(me);
    reward = EXP_BASE + 50 + (random(kar)) * EXP_RATIO;
    me->set("combat_exp", exp + reward);
    tell_object(me, "你得到了" + reward + "点经验，");
    reward = POT_BASE + 20 + (random(kar)) * POT_RATIO;
    me->set("potential", pot + reward);
    tell_object(me, reward + "点潜能。\n");
    return;
  }

  if (random(kar + cps) > ((kar + cps) / 5) * 3) {
    message_vision("$N钓到一条白鲳鱼\n", me);
    ob = new(__DIR__ "obj/fish_white");
    ob->move(me);
    reward = EXP_BASE + 30 + (random(kar)) * EXP_RATIO;
    me->set("combat_exp", exp + reward);
    tell_object(me, "你得到了" + reward + "点经验，");
    reward = POT_BASE + 10 + (random(kar)) * POT_RATIO;
    me->set("potential", pot + reward);
    tell_object(me, reward + "点潜能。\n");
    return;
  }

  if (random(kar + cps) > ((kar + cps) / 3) * 2) {
    message_vision("$N钓到一条大鲤鱼\n", me);
    ob = new(__DIR__ "obj/fish_li");
    ob->move(me);
    reward = EXP_BASE + 70 + (random(kar)) * EXP_RATIO;
    me->set("combat_exp", exp + reward);
    tell_object(me, "你得到了" + reward + "点经验，");
    reward = POT_BASE + 50 + (random(kar)) * POT_RATIO;
    me->set("potential", pot + reward);
    tell_object(me, reward + "点潜能。\n");
    return;
  }

  message_vision("$N钓到一条小泥鳅\n", me);
  ob = new(__DIR__ "obj/fish_niqiu");
  ob->move(me);
  reward = EXP_BASE;
  me->set("combat_exp", exp + reward);
  tell_object(me, "你得到了" + reward + "点经验，");
  reward = POT_BASE;
  me->set("potential", pot + reward);
  tell_object(me, reward + "点潜能。\n");
  return;
}

void fishing_msg(object me) {
  if (!me) return;
  message_vision("$N只见鱼漂猛然一动，急忙提杆…\n", me);
  call_out("reward_me", 1, me);
}
