//买彩票专用  by lsxk@hsbbs 2007/9/25
string Random_Source(int);

string *s_char = ({ "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
  "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
  "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
  "~", "!", "@", "#", "$", "%", "^", "&", "*" });

string This_Source = Random_Source(SIZE_OF_SOURCE);

string Random_Source(int i) {
  string str, p, file_msg;
  int j;
  object obj;

  if (objectp(obj = load_object("/log/cpTag.lpc"))) {
    delete("no_buy");
    str = obj->query("caipiao_id");
    destruct(obj);
    message(
      "system",
      HIY "\n\n【天涯搏彩】：" + HIG + "本期天涯摸彩备选号为：" + HIW + str + HIG + " 请根据您的喜好排列后，去摸彩中心购买！\n\n" NOR,
      users()
    );
    return str;
  }

  for (j = 0; j < i; j++) {
    p = s_char[random(sizeof(s_char))];
    if (!str)
      str = p;
    else
      str = str + " " + p;

    s_char -= ({ p });
  }

  s_char = ({ "1", "2", "3", "4", "5", "6", "7", "8", "9", "0",
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    "~", "!", "@", "#", "$", "%", "^", "&", "*" });

  delete("no_buy");
  message(
    "system",
    HIY "\n\n【天涯搏彩】：" + HIG + "本期天涯摸彩备选号为：" + HIW + str + HIG + " 请根据您的喜好排列后，去摸彩中心购买！\n\n" NOR,
    users()
  );

  file_msg = sprintf("// 搏彩开彩序号标记备份! \n");
  file_msg += "inherit ROOM;\n";
  file_msg += "void create()\n";
  file_msg += "{\n";
  file_msg += sprintf("\tset(\"short\", \"搏彩标记\");\n");
  file_msg += sprintf("\tset(\"caipiao_id\",\"%s\");\n", str);
  file_msg += "\tsetup();\n";
  file_msg += "}\n";

  rm("/log/cpTag.lpc");
  assure_file("/log/cpTag.lpc");
  if (write_file("/log/cpTag.lpc", file_msg, 1) != 1) {
    write("无法写入文件，请通知在线巫师！\n");
  }
  return str;
}

int buy_caipiao(string arg) {
  int i, k;
  string strMyCP, huobi, count;
  object me = this_player();
  object cp;

  if (!arg) return notify_fail("你要买什么?\n" NOR);

  if (query("no_buy"))
    return notify_fail("现在是对奖时间，请等待系统公布开彩信息后，再来购买！\n" NOR);

  if (me->query("caipiao_id") != This_Source) {
    me->delete("caipiao");
    me->delete("caipiao_id");
    me->delete("caipiao_zhongjiang_list");
    me->delete("caipiao_shot");
    tell_object(me, "系统发现你身上有以前未对奖的彩票，已经自动清除！\n");
  }
  if (sscanf(arg, "%s with %s", strMyCP, huobi)) {
    if (huobi != "黄金")
      return notify_fail(HIG "请根据“" + HIR + "buy 您想要的摸彩序号 with [黄金]" + HIG + "”的格式来进行摸彩!\n" NOR);
  } else return notify_fail(HIG "格式错误！请根据“" + HIR + "buy 您想要的摸彩序号 with [黄金]" + HIG + "”的格式来进行摸彩!\n" NOR);

  if (strMyCP != "random" && sizeof(strMyCP) != (SIZE_OF_SOURCE * 2 - SIZE_OF_SOURCE / 2 - 1))
    return notify_fail("您所购买的序号长度不对，请确定您买的是" + chinese_number(SIZE_OF_SOURCE) + "位长度的号码,并且每隔两位用“-”符号连接！\n");

  if (strMyCP == "random")
    strMyCP = cp_kaijiang(1);

  for (k = 0; k < sizeof(me->query("caipiao")); k++)
    if (strMyCP == me->query("caipiao/第" + chinese_number(k + 1) + "张/my_caipiao"))
      return notify_fail("你已经买过这张序号了，不能重复购买！\n");

  if (huobi == "黄金") {
    if ((int)me->query("balance") < GOLD_COST)
      return notify_fail("你的黄金数量不够，无法参与!\n");

    me->add("balance", -GOLD_COST);
    tell_object(
      me,
      HIY "您花了" + chinese_number(GOLD_COST / 10000) + "锭黄金，购买了序号为：" + strMyCP + " 的彩票！\n" NOR
    );
    tell_object(me, HIG "购买成功！请关注系统开彩信息，祝您好运！\n" NOR);
  }

  count = chinese_number(sizeof(me->query("caipiao")) + 1);
  me->set("caipiao/第" + count + "张/time", time());
  me->set("caipiao/第" + count + "张/my_caipiao", strMyCP);
  me->set("caipiao/第" + count + "张/huobi", huobi);
  me->set("caipiao_id", This_Source);

  if (!present("cai piao", me)) {
    cp = new(__DIR__ "obj/caipiao");
    cp->move(me);
  }

  return 1;
}
