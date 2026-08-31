#include <std.h>

inherit DAEMON;

varargs int get_damage(object tp, object ob, int rank, string *skills, string *stats, string *extra) 
{
  int tmp=0;
  int ret=0;
  int magic=0;
  float skillmod=0;
  float statmod=0;
  float extramod=0;

  if (!tp || !ob || !rank || !sizeof(skills) || !sizeof(stats))
    return 0;
  
  if(!sizeof(extra))
    extra = ({});

  if (member_array("intelligence", stats) != -1 ||
      member_array("wisdom", stats) != -1)
        magic=1;

  switch (rank) {
  case 1:
    ret += 15; // give a min damage for newbie attacks
    if (magic) {
      skillmod=1.5;
      statmod=1;
      extramod=0;
    }
    else {
      skillmod=1;
      statmod=2;
      extramod=0;
    }
  break;
  case 2:
    if (magic) {
      skillmod=1.75;
      statmod=1;
      extramod=0;
    }
    else {
      skillmod=1;
      statmod=2.5;
      extramod=0;
    }
  break;
  case 3:
    if (magic) {
      skillmod=1.75;
      statmod=1;
      extramod=0.25;
    }
    else {
      skillmod=1;
      statmod=2.5;
      extramod=0.5;
    }
  break;
  case 4:
    if (magic) {
      skillmod=1.75;
      statmod=1;
      extramod=0.5;
    }
    else {
      skillmod=1;
      statmod=2.5;
      extramod=1;
    }
  break;
  default:
    message("info", "This ability/spell has an invalid rank "+rank+
      " Please inform an admin or use the <bug> command to report it.",
      tp);
    return 0;
  }

  //----------------------------
  foreach (string l in skills)
    tmp += tp->query_skill(l);
  tmp = tmp / sizeof(skills);
  tmp = tmp * skillmod;
  ret += tmp;
  //----------------------------
  tmp = 0;
  foreach (string s in stats)
    tmp += tp->query_stats(s);
  tmp = tmp / sizeof(stats);
  tmp = tmp * statmod;
  ret += tmp;
  //----------------------------
  if (extramod && sizeof(extra) > 0) {
    tmp = 0;
    if (magic) {
      foreach (string x in extra)
        tmp += tp->query_skill(x);
    }
    else {
      foreach (string x in extra)
        tmp += tp->query_stats(x);
    }
    tmp = tmp / sizeof(extra);
    tmp = tmp * extramod;
    ret += tmp;
  }

  //----------------------------
  if (magic) {
    ret -= ob->query_skill("magic defense")/4;
    ret -= ob->query_stats("wisdom")*3/2;
    ret -= ob->query_stats("intelligence")/8;
  }
  else {
    ret -= ob->query_skill("defense")/3;
    ret -= ob->query_stats("dexterity")/2;
    ret -= ob->query_stats("constitution")/9;
  }
  
  ret += random(tp->query_level());
  ret = ret*3/2;
       
  if (wizardp(tp))
    message("info", "Rank = "+rank+", Dmg = "+ret+"\n", tp);

  return ret;

}

