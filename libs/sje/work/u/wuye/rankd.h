// rankd.c
// optimize by Yu Jue 98.2.27
//changed by wzfeng 98 10 25

#include <ansi.h>

string query_rank(object ob) {
  int shen = ob->query("shen");
  int budd;
  int pxj = (int)ob->query_skill("pixie-jian", 1);
  int age = ob->query("age");
  int divorce = ob->query("divorce");
  string rank = ob->query("rank");
  string color = ob->query("rankcolor");  //让wiz可以set rank的颜色

  if (ob->is_ghost())
    return HIB "【孤魂野鬼】" NOR;


  if (stringp(rank)) {
    rank = (rank + "        ")[0..7];
    switch (color) {
      case "BLK":
        return BLK "【" + rank + "】" NOR;
      case "RED":
        return RED "【" + rank + "】" NOR;
      case "GRN":
        return GRN "【" + rank + "】" NOR;
      case "YEL":
        return YEL "【" + rank + "】" NOR;
      case "BLU":
        return BLU "【" + rank + "】" NOR;
      case "MAG":
        return BLK "【" + rank + "】" NOR;
      case "CYN":
        return CYN "【" + rank + "】" NOR;
      case "WHT":
        return WHT "【" + rank + "】" NOR;
      case "HIR":
        return HIR "【" + rank + "】" NOR;
      case "HIG":
        return HIG "【" + rank + "】" NOR;
      case "HIB":
        return HIB "【" + rank + "】" NOR;
      case "HIM":
        return HIM "【" + rank + "】" NOR;
      case "HIC":
        return HIC "【" + rank + "】" NOR;
      case "HIW":
        return HIW "【" + rank + "】" NOR;
      case "HIY":
        return HIY "【" + rank + "】" NOR;

      default:
        return HIG "【" + rank + "】" NOR;

    }
  }

  switch (ob->query("family/family_name")) {
    case "峨嵋派": budd = ob->query_skill("dacheng-fofa", 1); break;
    case "少林派":
    case "天龙寺": budd = ob->query_skill("buddhism", 1); break;
    case "武当派":
    case "全真教": budd = ob->query_skill("taoism", 1); break;
    case "古墓派": budd = ob->query_skill("sword", 1); break;
    case "明教": budd = ob->query_skill("shenghuo-shengong", 1); break;
    case "丐帮": budd = ob->query_skill("huntian-qigong", 1); break;
    case "神龙岛": budd = ob->query_skill("dulong-dafa", 1); break;
    case "铁掌帮": budd = ob->query_skill("guiyuan-tunafa", 1); break;
    case "大理": budd = ob->query_skill("qiantian-yiyang", 1); break;
    case "大轮寺": budd = ob->query_skill("huanxi-chan", 1); break;
    case "桃花岛": budd = ob->query_skill("qimen-bagua", 1); break;
  }

  switch (ob->query("gender")) {
    case "女性":
    case "雌性":
      switch (wizhood(ob)) {
        case "(admin)": return HIW "【 女  神 】" NOR;
        case "(arch)": return HIY "【 龙  女 】" NOR;
        case "(wizard)": return HIG "【 仙  子 】" NOR;
        case "(apprentice)": return HIC "【 女  巫 】" NOR;
        case "(immortal)": return HIC "【 女门客 】" NOR;
        default:
          if (ob->query("PKS") > 20 && ob->query("PKS") > ob->query("MKS") / 4)
            return HIR "【杀人女魔】" NOR;
          if ((int)ob->query("thief") > 10)
            return "【 女惯窃 】";
          if (!ob->query("class")) {
            if (shen >= 1000000) return HIC "【绝世天娇】" NOR;
            if (shen >= 500000) return HIC "【旷世女侠】" NOR;
            if (shen >= 50000) return HIC "【 女大侠 】" NOR;
            if (shen >= 5000) return HIC "【 女  侠 】" NOR;
            if (shen >= 500) return HIC "【 小侠女 】" NOR;
            if (shen <= -1000000) return HIR "【盖世罗刹】" NOR;
            if (shen <= -500000) return HIR "【旷世女魔】" NOR;
            if (shen <= -50000) return RED "【 女魔头 】" NOR;
            if (shen <= -5000) return RED "【 大魔女 】" NOR;
            if (shen <= -500) return RED "【 小魔女 】" NOR;
          }
          switch (ob->query("class")) {
            case "bonze":
              if (ob->query("luohan_winner")) {
                if (budd >= 180) return HIW "【 神  尼 】" NOR;
                if (budd >= 140) return HIW "【 长  老 】" NOR;
                if (budd >= 90) return HIW "【 师  太 】" NOR;
              }
              if (budd >= 60) return WHT "【 比丘尼 】" NOR;
              if (budd >= 30 || age >= 20) return WHT "【 沙弥尼 】" NOR;
              return WHT "【 学戒女 】" NOR;
            case "taoist":
              if (budd >= 180) return HIW "【 玄  女 】" NOR;
              if (budd >= 140) return HIY "【 仙  姑 】" NOR;
              if (budd >= 100) return YEL "【 散  人 】" NOR;
              if (budd >= 50 || age >= 20) return YEL "【 道  姑 】" NOR;
              return "【 小道姑 】";
              //Add Gumu Player
            case "sworder":
              if (budd >= 180) return HIR "【 剑  圣 】" NOR;
              if (budd >= 140) return HIY "【 剑  仙 】" NOR;
              if (budd >= 100) return HIC "【 女剑侠 】" NOR;
              if (budd >= 50 || age >= 18) return YEL "【 女剑客 】" NOR;
              return "【 女剑士 】";
              //// Modify by Xiaoyao
            case "huanxi":
              if (budd >= 180 && shen >= 0) return HIW "【 欢喜佛 】" NOR;
              if (budd >= 180 && shen < 0) return HIW "【 欢喜魔 】" NOR;
              if (budd >= 140) return HIY "【 圣  女 】" NOR;
              if (budd >= 90) return HIY "【 飞  天 】" NOR;
              if (budd >= 60) return YEL "【 乾达婆 】" NOR;
              if (budd >= 30 || age >= 20) return CYN "【 神妙女 】" NOR;
              return CYN "【 授  事 】" NOR;

            case "kirk":
              if (budd >= 180) return HIR "【 圣  姑 】" NOR;
              if (budd >= 150) return HIR "【 右护法 】" NOR;
              if (budd >= 130) return RED "【 堂  主 】" NOR;
              if (budd >= 100) return HIM "【 坛  主 】" NOR;
              if (budd >= 80) return CYN "【 香  主 】" NOR;
              if (budd >= 50 || age >= 18) return MAG "【 女教众 】" NOR;
              return "【 女教徒 】";
            case "beggar":
              if (budd >= 180) return HIW "【 神  丐 】" NOR;
              if (budd >= 160 && ob->query("shen") >= 0) return HIC "【 义  丐 】" NOR;
              if (budd >= 160 && ob->query("shen") < 0) return HIR "【 恶  丐 】" NOR;
              if (budd >= 140) return HIC "【 舵  主 】" NOR;
              if (budd >= 100) return CYN "【 龙  头 】" NOR;
              if (budd >= 50 || age >= 18) return CYN "【 叫化子 】" NOR;
              return "【 小乞丐 】";
            case "fighter":
              if (budd >= 180) return HIW "【 逸  仙 】" NOR;
              if (budd >= 140) return HIC "【 逸  贤 】" NOR;
              if (budd >= 100) return WHT "【 逸  士 】" NOR;
              if (budd >= 50 || age >= 18) return CYN "【 青  衣 】" NOR;
              return "【 民  女 】";
            case "bandit": return "【 女飞贼 】";
            case "dancer": return "【 舞  妓 】";
            case "scholar": return "【 才  女 】";
            case "officer": return "【 女  官 】";
            case "alchemist": return "【 女方士 】";
            case "shaman": return "【 女巫医 】";
            default:
              if (ob->query("marry")) {
                if (age < 30) return "【 少  妇 】";
                if (age < 50) return "【中年妇人】";
                return "【 老妇人 】";
              }
              if (divorce > 2) {
                if (age < 50) return "【 荡  妇 】";
                return "【 老荡妇 】";
              }
              if (divorce) {
                if (age < 50) return "【 寡  妇 】";
                return "【 老寡妇 】";
              }
              if (age < 18) return "【 少  女 】";
              if (age < 30) return "【青年女子】";
              if (age < 50) return "【中年女子】";
              return "【 老处女 】";
          }
      }
    case "无性":
      {
        if (pxj >= 200) return HIR "【 九千岁 】" NOR;
        if (pxj >= 180) return HIR "【 厂  公 】" NOR;
        if (pxj >= 150) return HIR "【 大档头 】" NOR;
        if (pxj >= 120) return HIM "【东厂千户】" NOR;
        if (pxj >= 90) return MAG "【东厂百户】" NOR;
        if (pxj >= 60) return MAG "【太监总管】" NOR;
        if (pxj >= 30) return MAG "【 太  监 】" NOR;
        if (pxj >= 1) return MAG "【 小太监 】" NOR;
      }
    default:
      switch (wizhood(ob)) {
        case "(admin)": return HIW HBBLU "【 天  神 】" NOR;
        case "(arch)": return HIY "【 龙  神 】" NOR;
        case "(wizard)": return HIG "【 仙  人 】" NOR;
        case "(apprentice)": return HIC BBLU "【 巫  师 】" NOR;
        case "(immortal)": return HIC "【 门  客 】" NOR;
        default:
          if (((int)ob->query("PKS") > 20) && ((int)ob->query("PKS") > (int)ob->query("MKS")) / 4)
            return HIR "【杀人魔王】" NOR;
          if ((int)ob->query("thief") > 10)
            return "【 惯  窃 】";
          if (!ob->query("class")) {
            if (shen >= 1000000) return HIC "【绝世神侠】" NOR;
            if (shen >= 500000) return HIC "【旷世大侠】" NOR;
            if (shen >= 50000) return HIC "【 大  侠 】" NOR;
            if (shen >= 5000) return HIC "【 侠  客 】" NOR;
            if (shen >= 500) return HIC "【 少  侠 】" NOR;
            if (shen <= -1000000) return HIR "【盖世狂魔】" NOR;
            if (shen <= -500000) return HIR "【 魔  王 】" NOR;
            if (shen <= -50000) return RED "【 大  魔 】" NOR;
            if (shen <= -5000) return RED "【 魔  头 】" NOR;
            if (shen <= -500) return RED "【 少  魔 】" NOR;
          }
          switch (ob->query("class")) {
            case "bonze":
              if (ob->query("luohan_winner")) {
                if (budd >= 180) return HIW "【 神  僧 】" NOR;
                if (budd >= 150) return WHT "【 长  老 】" NOR;
                if (budd >= 120) return HIY "【 圣  僧 】" NOR;
                if (budd >= 80) return HIY "【 罗  汉 】" NOR;
              }
              if (budd >= 60) return YEL "【 尊  者 】" NOR;
              if (budd >= 40) return YEL "【 禅  师 】" NOR;
              if (budd >= 30) return YEL "【 比  丘 】" NOR;
              return "【 僧  人 】";
            case "taoist":
              if (budd >= 180) return HIW "【 天  尊 】" NOR;
              if (budd >= 140) return HIY "【 天  师 】" NOR;
              if (budd >= 100) return YEL "【 真  人 】" NOR;
              if (budd >= 50 || age >= 20) return YEL "【 道  士 】" NOR;
              return "【 道  童 】";
            case "sworder":
              if (budd >= 180) return HIR "【 剑  宗 】" NOR;
              if (budd >= 140) return HIY "【 剑  狂 】" NOR;
              if (budd >= 100) return HIC "【 剑  侠 】" NOR;
              if (budd >= 50 || age >= 18) return YEL "【 剑  客 】" NOR;
              return "【 剑  士 】";
              //// Modify by Xiaoyao
            case "huanxi":
              if (budd >= 180 && shen >= 0) return HIW "【 欢喜佛 】" NOR;
              if (budd >= 180 && shen < 0) return HIW "【 欢喜魔 】" NOR;
              if (budd >= 140) return HIY "【 天  王 】" NOR;
              if (budd >= 90) return HIY "【 大护法 】" NOR;
              if (budd >= 60) return YEL "【 金  刚 】" NOR;
              if (budd >= 30 || age >= 20) return CYN "【 力  士 】" NOR;
              return CYN "【 杂  役 】" NOR;

            case "kirk":
              if (budd >= 180) return HIW "【 副教主 】" NOR;
              if (budd >= 150) return WHT "【 左护法 】" NOR;
              if (budd >= 130) return HIC "【 堂  主 】" NOR;
              if (budd >= 100) return CYN "【 坛  主 】" NOR;
              if (budd >= 80) return CYN "【 香  主 】" NOR;
              if (budd >= 50 || age >= 18) return CYN "【 教  众 】" NOR;
              return "【 教  徒 】";
            case "beggar":
              if (budd >= 180) return HIW "【 神  丐 】" NOR;
              if (budd >= 160 && ob->query("shen") >= 0) return HIC "【 义  丐 】" NOR;
              if (budd >= 160 && ob->query("shen") < 0) return HIR "【 恶  丐 】" NOR;
              if (budd >= 140) return HIC "【 舵  主 】" NOR;
              if (budd >= 100) return CYN "【 龙  头 】" NOR;
              if (budd >= 50 || age >= 18) return CYN "【 叫化子 】" NOR;
              return "【 小乞丐 】";
            case "brigand":
              if (budd >= 180) return WHT "【 山大王 】" NOR;
              if (budd >= 140) return HIC "【 寨  主 】" NOR;
              if (budd >= 100) return CYN "【 当  家 】" NOR;
              if (budd >= 50 || age >= 18) return CYN "【 头  目 】" NOR;
              return "【 小喽罗 】";
            case "swordsman":
              if (budd >= 180) return HIY "【 亲  王 】" NOR;
              if (budd >= 160) return WHT "【 侯  爷 】" NOR;
              if (budd >= 140) return HIC "【 将  官 】" NOR;
              if (budd >= 100) return CYN "【 侍  卫 】" NOR;
              if (budd >= 50 || age >= 18) return CYN "【 校  尉 】" NOR;
              return "【 兵  士 】";
            case "fighter":
              if (budd >= 180) return HIW "【 隐  圣 】" NOR;
              if (budd >= 140) return HIC "【 隐  贤 】" NOR;
              if (budd >= 100) return WHT "【 隐  士 】" NOR;
              if (budd >= 50 || age >= 18) return CYN "【 门  生 】" NOR;
              return "【 平  民 】";
            case "bandit": return "【 盗  贼 】";
            case "scholar": return "【 书  生 】";
            case "officer": return "【 官  差 】";
            case "alchemist": return "【 方  士 】";
            case "shaman": return "【 巫  医 】";
            case "eunuch": return "【 太  监 】";
            default:
              if (ob->query("marry")) {
                if (age < 30) return "【青年男子】";
                if (age < 50) return "【中年男子】";
                return "【 老头儿 】";
              }
              if (divorce > 2) {
                if (age < 50) return "【花花公子】";
                return "【花心老头】";
              }
              if (divorce) {
                if (age < 50) return "【 鳏  夫 】";
                return "【 老鳏夫 】";
              }
              if (age < 18) return "【 少  年 】";
              if (age < 30) return "【青年男子】";
              if (age < 50) return "【中年男子】";
              return "【 老处男 】";
          }
      }
  }
}

string query_respect(object ob) {
  int age;
  string str;
  if (stringp(str = ob->query("rank_info/respect")))
    return str;
  if (ob->query("race") != "人类") return ob->name();

  age = ob->query("age");
  if (ob->query_skill("beauty") > 30) age -= (ob->query_skill("beauty") - 30) / 5;
  switch (ob->query("gender")) {
    case "女性":
    case "雌性":
      switch (ob->query("class")) {
        case "bonze":
          if (age < 20) return "小师太";
          return "师太";
        case "taoist":
          if (age < 20) return "小仙姑";
          return "仙姑";
        case "huanxi":
          if (age < 20) return "小灵女";
          return "女菩萨";
        default:
          if (age < 20) return "小姑娘";
          if (age < 50) return "姑娘";
          return "婆婆";
      }
    default:
      switch (ob->query("class")) {
        case "bonze":
          if (age < 20) return "小师父";
          return "大师";
        case "taoist":
          if (age < 20) return "道兄";
          return "道长";
        case "huanxi":
          if (age < 20) return "小师父";
          return "上人";
        case "fighter":
        case "swordsman":
          if (age < 20) return "小老弟";
          if (age < 50) return "壮士";
          return "老前辈";
        case "eunach":
          if (age < 20) return "小公公";
          return "公公";
        default:
          if (age < 20) return "小兄弟";
          if (age < 50) return "壮士";
          return "老爷子";
      }
  }
}

string query_rude(object ob) {
  int age;
  string str;

  if (stringp(str = ob->query("rank_info/rude"))) return str;
  if (ob->query("race") == "野兽") return "禽兽";

  age = ob->query("age");
  if (ob->query_skill("beauty") > 30) age -= (ob->query_skill("beauty") - 30) / 5;
  switch (ob->query("gender")) {
    case "女性":
    case "雌性":
      switch (ob->query("class")) {
        case "bonze": return "贼尼";
        case "huanxi": return "臭藏尼";
        case "taoist": return "妖女";
        default:
          if (age < 20) return "小贱人";
          if (age < 50) return "贱人";
          return "死老太婆";
      }
    default:
      switch (ob->query("class")) {
        case "bonze":
          if (age < 50) return "死秃驴";
          return "老秃驴";
        case "huanxi":
          if (age < 30) return "死喇嘛";
          return "老秃驴";
        case "taoist": return "死牛鼻子";
        case "eunach":
          if (age < 18) return "小阉贼";
          return "阉贼";
        default:
          if (age < 20) return "小王八蛋";
          if (age < 50) return "臭贼";
          return "老匹夫";
      }
  }
}

string query_self(object ob) {
  int age;
  string str;
  int pxj = (int)ob->query_skill("pixie-jian", 1);
  if (stringp(str = ob->query("rank_info/self")))
    return str;
  if (ob->query("race") == "野兽") return ob->name();

  age = ob->query("age");
  if (ob->query_skill("beauty") > 30) age -= (ob->query_skill("beauty") - 30) / 5;
  switch (ob->query("gender")) {
    case "女性":
    case "雌性":
      switch (ob->query("class")) {
        case "bonze":
          if (age < 50) return "贫尼";
          return "老尼";
        case "huanxi":
          if (age < 50) return "贫尼";
          return "老尼";
        default:
          if (age < 30) return "小女子";
          return "妾身";
      }
    default:
      switch (ob->query("class")) {
        case "bonze":
          if (age < 50) return "贫僧";
          return "老衲";
        case "taoist":
          return "贫道";
        case "huanxi":
          if (age < 30) return "大喇嘛我";
          return "本佛爷";
        case "eunach":
          if (pxj >= 200) return "本千岁";
          if (pxj >= 150) return "本官";
          if (pxj >= 90) return "下官";
        default:
          if (age < 50) return "在下";
          return "老头子";
      }
  }
}

string query_self_rude(object ob) {
  int age;
  string str;
  int pxj = (int)ob->query_skill("pixie-jian", 1);


  if (stringp(str = ob->query("rank_info/self_rude")))
    return str;
  if (ob->query("race") == "野兽") return "禽兽我";

  age = ob->query("age");
  if (ob->query_skill("beauty") > 30) age -= (ob->query_skill("beauty") - 30) / 5;
  switch (ob->query("gender")) {
    case "女性":
    case "雌性":
      switch (ob->query("class")) {
        case "bonze":
          if (age < 50) return "贫尼";
          return "老尼";
        case "huanxi":
          if (age < 50) return "贫尼";
          return "老尼";
        default:
          if (age < 20) return "本小姐";
          if (age < 50) return "本姑娘";
          return "老娘";
      }
    default:
      switch (ob->query("class")) {
        case "bonze":
          if (age < 50) return "大和尚我";
          return "老和尚我";
        case "taoist":
          return "本山人";
        case "hunxi":
          if (age < 30) return "大喇嘛我";
          return "本佛爷我";
        case "eunach":
          if (pxj >= 90) return "本官";
        default:
          if (age < 50) return "大爷我";
          return "老子";
      }
  }
}

string query_close(object ob) {
  int a1, a2;

  if (objectp(ob)) {
    if (a2 = ob->query("age") * 12 + ob->query("month"))
      a1 = this_player()->query("age") * 12 + this_player()->query("month");
    else {
      a1 = this_player()->query("mud_age");
      a2 = ob->query("mud_age");
    }
  } else {
    a1 = this_player()->query("age") * 12 + this_player()->query("month");
    a2 = 0;
  }

  if (ob->query_skill("beauty") > 30) a2 -= (ob->query_skill("beauty") - 30) / 5 * 12;
  if (this_player()->query_skill("beauty") > 30)
    a1 -= (this_player()->query_skill("beauty") - 30) / 5 * 12;

  switch (ob->query("gender")) {
    case "女性":
    case "雌性":
      if (userp(ob) && ob->query("id") == this_player()->query("marry/id"))
        return "娘子";

      if (a2 - a1 >= 240) return "姑姑";
      if (a1 - a2 >= 240) return "侄女";
      if (a1 > a2) return "贤妹";
      return "姐姐";
      break;
    default:
      if (userp(ob) && ob->query("id") == this_player()->query("marry/id"))
        return "相公";

      if (a2 - a1 >= 240) return "叔叔";
      if (a1 - a2 >= 240) return "贤侄";
      if (a1 > a2) return "贤弟";
      return "哥哥";
  }
}

string query_self_close(object ob) {
  int a1, a2;

  if (objectp(ob)) {
    if (a2 = ob->query("age") * 12 + ob->query("month"))
      a1 = this_player()->query("age") * 12 + this_player()->query("month");
    else {
      a1 = this_player()->query("mud_age");
      a2 = ob->query("mud_age");
    }
  } else {
    a1 = this_player()->query("age") * 12 + this_player()->query("month");
    a2 = 0;
  }

  switch (this_player()->query("gender")) {
    case "女性":
    case "雌性":
      if (a1 - a2 >= 240) return "姑姑我";
      if (a2 - a1 >= 240) return "侄女我";
      if (a1 > a2) return "姐姐我";
      return "小妹我";
      break;
    default:
      if (a1 - a2 >= 240) return "叔叔我";
      if (a2 - a1 >= 240) return "小侄我";
      if (a1 > a2) return "愚兄我";
      return "小弟我";
  }
}
