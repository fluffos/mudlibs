#include "ansi.h"
#define REFRESH_TIME 120
/* 定义自动清除的时间 单位 秒 */
string *query_same_ip(object me, mapping all, string ip);

int meisdummy(object me, object target) {
  if (me->query("registered") > 2) return 0;  //vip have no this limit	
  if (userp(target) && userp(me)
    && (!living(target) && me->query("mud_age") < (time() - me->query("birthday")) / 24
      || me->query("mud_age") / 6 > me->query("combat_exp"))) return 1;
  return 0;
}

int pktime_limit(object me, object target) {
  string ts = ctime(time())[0..2];
  mapping be_killed_ip;
  string *ids;
  /*
	([
		ciwei:127.0.0.1,
	])
	*/

  if (!userp(me) || !userp(target)) return 0;

  if (strsrch(file_name(environment(me)), "/cmds/leitai/") >= 0
    && strsrch(file_name(environment(target)), "/cmds/leitai/") >= 0) return 0;

  if (target->query_temp("be_killed_ip") && !mapp(target->query_temp("be_killed_ip")))
    target->delete_temp("be_killed_ip");
  be_killed_ip = target->query_temp("be_killed_ip");
  if (!be_killed_ip) be_killed_ip = ([]);
  ids = keys(be_killed_ip);
  if (me != target && interactive(me) && (!sizeof(ids) || member_array(getuid(me), ids) == -1))  //不在攻击过的列表内才采取措施 再加上必须是连线的玩家
  {
    string *ips = values(be_killed_ip);
    string *check_idip = query_same_ip(target, be_killed_ip, query_ip_number(me));
    if (ips && sizeof(ips) && member_array(
      query_ip_number(me),
      ips
    ) != -1 && check_idip && sizeof(check_idip) > 0)  //得出ML PK的结论
    {
      log_file("nosave/MLPK",
        sprintf(
          "%-8s 可能跟 %s MLPK %-8s 来自%s",
          getuid(me),
          implode(check_idip, ","),
          getuid(target),
          query_ip_number(me)
        ),
        this_object());
      tell_object(me, sprintf(HIG "\n本游戏禁止Multi-Login TK，已经有%s个和你IP相同的玩家(%s)与目标在战斗了。\n" NOR,
        chinese_number(sizeof(check_idip)), implode(check_idip, ",")));
      tell_object(me, BLINK HIR "你的犯规行为已经被系统记录，请立刻到百姓留言版自首你的犯规行为。\n\n" NOR NOR);
    }
    if (check_idip && sizeof(check_idip) > 2) {
      return 1;  //不让他杀了
    }
    be_killed_ip[getuid(me)] = query_ip_number(me);
    call_out("delete_ip_flag", REFRESH_TIME, target, getuid(me));
    target->set_temp("be_killed_ip", be_killed_ip);
    //target->start_call_out( (:call_other, this_object(), "delete_ip_flag", getuid(me) :),5);
  }

  if (target->query_condition("killer") && target->query_condition("pk")) return 0;

  if (strsrch(file_name(environment(me)), "/d/group") >= 0
    && strsrch(file_name(environment(me)), "/d/group/entry") != 0) return 0;

  ts = replace_string(ts, "Sun", "星期日");
  ts = replace_string(ts, "Mon", "星期一");
  ts = replace_string(ts, "Tue", "星期二");
  ts = replace_string(ts, "Wed", "星期三");
  ts = replace_string(ts, "Thu", "星期四");
  ts = replace_string(ts, "Fri", "星期五");
  ts = replace_string(ts, "Sat", "星期六");



  return 0;

  if (ts == "星期日" || ts == "星期六") return 0;

  notify_fail("今天是" + ts + "，您只能在规定区域内进行主动攻击行为。\n");
  return 1;
}

string *query_same_ip(object me, mapping all, string ip) {
  string *ret = ({});
  string *k;
  object targetob;
  if (!all) return 0;
  if (!k = keys(all) || !sizeof(k)) return 0;
  if (!ip) return 0;
  for (int i = 0; i < sizeof(k); i++) {
    if (all[k[i]] == ip) {
      targetob = find_player(k[i]);
      if (!targetob) continue;
      if (me->is_fighting(targetob)) ret += ({ k[i] });
    }
  }
  return ret;
}

void delete_ip_flag(object me, string id) {
  mapping bekilledip;
  //message("wizard:ciwei",sprintf(HIR"定时清除信息：%O id:%s\n"NOR,me,id),users());	
  if (!me) return;
  bekilledip = me->query_temp("be_killed_ip");
  if (!bekilledip || !mapp(bekilledip)) return;
  map_delete(bekilledip, id);
}
