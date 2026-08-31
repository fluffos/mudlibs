#include <std.h>

inherit DAEMON;

int get_damage(object tp, object ob, int rank, string *skills, string
*stats, string *mstats) {

  int ret, i, tmp;
  if(!mstats)
    mstats = ({});

  if(rank == 1) {
    ret = 15;
    tmp = 0;
    i = sizeof(stats);
    while(i--)
      tmp += tp->query_stats(stats[i]);
    tmp = ret / sizeof(stats);
    tmp = tmp / 4;
    ret += tmp;
    tmp = 0;
    i = sizeof(skills);
    while(i--)
      tmp += tp->query_skill(skills[i]);
    tmp = tmp / sizeof(skills);
    ret += tmp;
    ret += random(tp->query_level());
    ret -= ob->query_skill("defense")/2;
    return ret;
  }
  else if(rank == 2) {
    ret = 0;
    tmp = 0;
    i = sizeof(stats);
    while(i--)
      tmp += tp->query_stats(stats[i]);
    tmp = tmp / sizeof(stats);
    tmp = tmp / 3;
    ret += tmp;
    tmp = 0;
    i = sizeof(skills);
    while(i--)
      tmp += tp->query_skill(skills[i]);
    tmp = tmp / sizeof(skills);
    ret += tmp;
    ret += random(tp->query_level());
    if(member_array("attack", skills) != -1)
      ret -= ob->query_skill("defense");
    else
      ret -= ob->query_skill("magic defense");
    return ret;
  }
  else if(rank == 3) {
    ret = 0;
    tmp = 0;
    i = sizeof(stats);
    while(i--)
      tmp += tp->query_stats(stats[i]);
    tmp = tmp / sizeof(stats);
    tmp = tmp / 2;
    ret += tmp;
    tmp = 0;
    i = sizeof(mstats);
    while(i--)
      tmp += tp->query_stats(mstats[i]);
    tmp = tmp / sizeof(mstats);
    tmp = tmp / 2;
    ret += tmp;
    tmp = 0;
    i = sizeof(skills);
    while(i--)
      tmp += tp->query_skill(skills[i]);
    tmp = tmp / sizeof(skills);
    ret += tmp;
    ret += random(tp->query_level());
    if(member_array("attack", skills) != -1)
      ret -= ob->query_skill("defense");
    else
      ret -= ob->query_skill("magic defense");
    ret -= ob->query_stats("dexterity") / 2;
    return ret;
  }
  else if(rank == 4) {
    ret = 0;
    tmp = 0;
    i = sizeof(stats);
    while(i--)
      tmp += tp->query_stats(stats[i]);
    tmp = tmp / sizeof(stats);
    ret += tmp;
    tmp = 0;
    i = sizeof(mstats);
    while(i--)
      tmp += tp->query_stats(mstats[i]);
    tmp = tmp / sizeof(mstats);
    ret += tmp;
    tmp = 0;
    i = sizeof(skills);
    while(i--)
      tmp += tp->query_skill(skills[i]);
    tmp = tmp / sizeof(skills);
    ret += tmp;
    ret += random(tp->query_level());
    ret -= ob->query_stats("dexterity");
    if(member_array("attack", skills) != -1) {
      ret -= ob->query_stats("constitution");
      ret -= ob->query_skill("defense");
    }
    else {
      ret -= ob->query_stats("wisdom");
      ret -= ob->query_skill("magic defense");
    }
    return ret;
  }
  else {
    message("info", "This ability/spell has an invalid rank.  "
            "Please inform an admin or use the <bug> command to report it.",
tp);
    return 1; // yes, that means it will do 1 damage.
  }
  message("info", "This ability/spell has an invalid rank.  "
          "Please inform an admin or use the <bug> command to report it.", tp);
  return 1;
}
