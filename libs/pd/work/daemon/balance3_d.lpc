#include <std.h>

inherit DAEMON;

varargs int get_damage(object tp, object ob, int rank,
string *skills, string *stats, string *extra) {

  int tmp=0;
  int ret=0;
  int magic=0;
  int noskills=0;
  int nostats=0;
  float skillmod=0;
  float statmod=0;
  float extramod=0;
  int perc=100;

  if (!tp || !ob || !rank || !sizeof(skills) || !sizeof(stats))
    return 0;
  
  if(!sizeof(extra))
    extra = ({});

  if (member_array("intelligence", stats) != -1 ||
      member_array("wisdom", stats) != -1)
        magic=1;

  if (member_array("none", skills) != -1)
    noskills = 1;

  if (member_array("none", stats) != -1)
    nostats = 1;

  switch (rank) {
  case 1:
    ret += 15; // give a min damage for newbie attacks
    if (noskills) {
      skillmod=0;
      statmod=6;
      extramod=0;
    }
    else if (nostats) {
      skillmod=2;
      statmod=0;
      extramod=0;
    }
    else if (magic) {
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
    if (noskills) {
      skillmod=0;
      statmod=6.5;
      extramod=0;
    }
    else if (nostats) {
      skillmod=2.25;
      statmod=0;
      extramod=0;
    }
    else if (magic) {
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
    if (noskills) {
      skillmod=0;
      statmod=7;
      extramod=0;
    }
    else if (nostats) {
      skillmod=2.5;
      statmod=0;
      extramod=0;
    }
    else if (magic) {
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
    if (noskills) {
      skillmod=0;
      statmod=7.5;
      extramod=0;
    }
    else if (nostats) {
      skillmod=2.75;
      statmod=0;
      extramod=0;
    }
    else if (magic) {
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
  //----------------------------
  ret += random(tp->query_level());
  ret = ret*3/2;
  //----------------------------
  if (noskills) {
    tmp = tp->query_level() * (17 + rank - 1);
    if (ret > tmp)
      ret = tmp + (ret - tmp) * 65 / 100;
  }
  //----------------------------
  if (tp->query_blind())
    ret = ret*2/3;
  if (ob->query_blind())
    ret = ret*6/5;
  //----------------------------
  perc = tp->query_property("damage percent");
  if (perc != 0 && perc != 100)
    ret = ret * perc / 100;
  //----------------------------

  if (wizardp(tp))
    message("info", "Rank = "+rank+", Dmg = "+ret+"\n", tp);

  return ret;

}

// returns the weight of the largest thing you can steal without being caught
int get_steal(object tp, object tgt, int rank, string *skills, string *stats) {

  int light, vision, tmp;
  int ret = 0;
  float skillmod = 0;
  float statmod = 0;

  if (!tp || !tgt || !rank || rank > 4 || !sizeof(skills) || !sizeof(stats))
    return 0;

  if (rank == 1)
    ret += 10;

  if (tp->query_subclass() && tp->query_subclass() == "thief") {
    skillmod = 0.7 + (rank-1)*0.2;
    statmod = 1.7 + (rank-1)*0.2;
  }
  else {
    skillmod = 0.5 + (rank-1)*0.1;
    statmod = 1.1 + (rank-1)*0.1;
  }

  tmp = 0;
  foreach (string sk in skills)
    tmp += tp->query_skill(sk);
  tmp /= sizeof(skills);
  tmp *= skillmod;
  ret += tmp;

  tmp = 0;
  foreach (string st in stats)
    tmp += tp->query_stats(st);
  tmp /= sizeof(stats);
  tmp *= statmod;
  ret += tmp;

  // the bigger tmp is, the worse tgt can see
  tmp = absolute_value(2 - effective_light(tgt));
  ret += tmp * (ret/8);

  // query_stolen is increased when we steal from people/mobs
  // also when giving things to mobs
  tmp = tp->query_stolen(tgt);
  ret -= tmp * (ret/5);

  if (tp->query_blind())
    ret -= ret*2/3;

  if (tgt->query_blind())
    ret += ret/3;

  if (tp->query_invis())
    ret += ret/5;

  ret += tp->query_stealth();

  if (tgt->is_player()) {
    ret -= tgt->query_skill("perception");
    ret -= tgt->query_skill("stealing");
    ret -= tgt->query_stats("dexterity");
    ret -= tgt->query_stats("intelligence");
  }
  else {
    ret -= tgt->query_skill("perception")*3/4;
    ret -= tgt->query_skill("stealing")/2;
    ret -= tgt->query_stats("dexterity");
    ret -= tgt->query_stats("intelligence");
  }
  if (tgt->query_class() && tgt->query_class() == "rogue")
    ret -= ret/4;

  ret += random(tp->query_level()/3);

  ret /= 3;

  tmp = tgt->query_level() - tp->query_level();
  if (tmp > 5) ret -= (tmp-5)*3/2;

  if (wizardp(tp))
    message("info", "Rank = "+rank+", Steal = "+ret, tp);

  return ret;

}

int get_cost(int dmg, int rank, string type) {
  float tmp;
  float mod;
  int mult;
  int rand;
  int ret;

  switch (type) {
    case "sp": mod = 45.0; mult = 13+rank; break;
    case "mp": mod = 20.0; mult = 17+rank; break;
    default: return 500;
  }

  switch (rank) {
    case 1: case 2:
    break;
    case 3: case 4:
      mod += dmg/(150-rank*30);
    break;
    default: return 500;
  }

  tmp = dmg / mod;
  if (tmp < 1.5)
    tmp = 1.5;

  ret = to_int( mult * log(tmp) );
  ret += random(3 + ret / (7+rank));

  return ret;
}

float diminishing_returns(mixed val, mixed scale) {
  float mult, trinum;
  if (val < 0)
    return -diminishing_returns(-val, scale);
  mult = val / to_float(scale);
  trinum = (sqrt(8.0 * mult + 1.0) - 1.0) / 2.0;
  return trinum * scale;
}

