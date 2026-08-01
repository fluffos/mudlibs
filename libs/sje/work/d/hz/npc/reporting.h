/*  <SecCrypt CPL V3R05>  */


#define  DEBUG  0

void informing(object me, object who, string str) {
  //  if  (!  DEBUG)  return;

  object xiaoyao = find_player("xiaoyao");

  str = replace_string(str, "$N", me->query("name"));
  str = replace_string(str, "$n", who->query("name"));
  if (xiaoyao && wizardp(xiaoyao))
    tell_object(xiaoyao, "  ◇  " + str);
}

void reporting(object who, string reason, int points, string name) {
  string str = reason + "得到了" + to_chinese(points) + "点" + name + "。\n";

  //  if  (!  DEBUG)  return;

  object xiaoyao = find_player("xiaoyao");

  if (xiaoyao && wizardp(xiaoyao))
    tell_object(xiaoyao, "  ⊙  " + who->query("name") + str);
}
