#define DEBUG 0

void reporting(object who, string reason, int points, string name) {
  string str = reason + "得到了" + to_chinese(points) + name + "。\n";

  if (DEBUG) {
    object baiwt = find_player("baiwt");

    if (baiwt && wizardp(baiwt))
      tell_object(baiwt, " ⊙ " + who->query("name") + str);
  }
  //  else
  //    MONITOR_D->report_system_object_msg (who, str);
}
