
#include <std.h>
#include <rooms.h>

#define BUMP_PROP "bump_abil_info"
#define BUMP_TIME 14

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

object *who = ({});

int abil() { return 1; }

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <bump [who]>\n"
    "        <bump [who] [direction]>\n\n"
    "Lets you try to push someone out of the way, "
    "but you better be stronger than your opponent!\n\n"
    "See also: allow",
    this_player() );
}

int can_cast(object tp, object tgt, string dir) {
  object env;

  if (!tp) return 0;

  env = environment(tp);

  if (env->query_property("no bump") || env->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You'd need a body with which to bump.");

  if (!tgt)
    FAIL("Bump who?");

  if (!living(tgt))
    FAIL("You bump "+definite_article(tgt->query_short())+".");

  if (tgt->query_property("no bump"))
    FAIL(capitalize(tgt->query_subjective())+
         " cannot be bumped.");

  if (tp->query_sp() < 20)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot bump "+tgt->query_cap_name()+" yet.");

  if (strlen(dir) && env->query_exit(dir) == ROOM_VOID)
    FAIL("There is no exit here by that name.");

  if (strlen(dir) && dir == "up")
    FAIL("You can't push someone upwards.");

  if (!sizeof(env->query_exits() - ({ "up" })))
    FAIL("There is nowhere to bump "+tgt->query_objective()+"!");

  return 1;
}

int cmd_bump(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string dir;
  int hit, miss, allow;
  mixed tmp;

  if (str) {
    if ((tmp = strsrch(str, " ", -1)) == -1)
      tgt = present(str, env);
    else {
      dir = str[tmp+1 .. <1];
      tgt = present(str[0 .. tmp-1], env);
    }
  }

  if (!can_cast(tp, tgt, dir)) return 0;

  tp->set_disable();

  // this part checks if you can push someone when they are
  // actively resisting you
  hit = tp->query_stats("strength");
  hit += tp->query_stats("dexterity")/3;

  miss = tgt->query_stats("strength");
  miss += tgt->query_stats("dexterity")/3;
  miss += tgt->query_stats("constitution")/2;
  if (strlen(dir))
    miss += tgt->query_stats("dexterity")/3;

  hit -= miss;

  allow = (member_array(tp->query_name(), tgt->query_allow("bump")) != -1);

  if (!allow && hit < 1) {
    tp->add_hp(-random(20));
    tp->add_sp(-random(10));
    message("info", tgt->query_cap_name()+" shoves you to the ground!", tp);
    message("info", tp->query_cap_name()+" tries to bump you, but you "
      "shove "+tp->query_objective()+" to the ground.", tgt);
    message("info", tp->query_cap_name()+" is shoved to the ground while "
      "trying to bump "+tgt->query_cap_name()+".", env, ({ tp, tgt }) );
  }
  else if (!allow && hit < random(100)) {
    tp->add_hp(-random(10));
    tp->add_sp(-random(20));
    tgt->add_hp(-random(7));
    message("info", "You give "+tgt->query_cap_name()+" a bruise while "
      "trying to bump "+tgt->query_objective()+".", tp);
    message("info", tp->query_cap_name()+" gives you a bruise while "
      "trying to bump you.", tgt);
    message("info", tp->query_cap_name()+" fails to push "+
        tgt->query_cap_name()+" aside.", env, ({ tp, tgt }) );
  }
  else {
    // the following lines are necessary to make sure you are strong enough to
    // push someone even when they allow you to, no little mages bumping
    // big buff fighters
    hit = tp->query_stats("strength") + tp->query_stats("dexterity")/3;
    miss = tgt->query_stats("constitution") + tgt->query_stats("strength")/3;
    if (hit < miss) {
      tp->add_sp(-random(7));
      message("info", "You try to bump "+tgt->query_cap_name()+" but "
          "you are not strong enough.", tp);
      message("info", tp->query_cap_name()+" tries to bump you but "+
          tp->query_subjective()+" is not strong enough.", tgt);
      message("info", tp->query_cap_name()+" tries to bump "+
          tgt->query_cap_name()+" but doesn't seem to be strong enough.",
          env, ({ tp, tgt }) );
    }
    if (!strlen(dir)) {
      tmp = env->query_exits() - ({ "up" });
      dir = tmp[random(sizeof(tmp))];
    }
    if (tmp = env->query_door(dir) && env->query_closed(tmp)) {
      tp->add_sp(-random(15));
      tgt->add_hp(-random(30));
      message("info", "You shove "+tgt->query_cap_name()+" into the "+tmp+"!", tp);
      message("info", tp->query_cap_name()+" shoves you into the "+tmp+"!", tgt);
      message("info", tp->query_cap_name()+" shoves "+tgt->query_cap_name()+
          " into the "+tmp+"!", env, ({ tp, tgt }) );
    }
    else if (env->query_pre_exit_function(dir)) {
      message("info", "A strange force prevents you from "
          "pushing "+tgt->query_cap_name()+" "+dir+".", tp);
    }
    else {
      tp->add_sp(-random(15));
      tgt->add_hp(-random(5));
      message("info", "You push "+tgt->query_cap_name()+" "+dir+".", tp);
      
      tgt->set(BUMP_PROP, ({ time(), tp, file_name(env) }) );
      if (!userp(tgt)) {
        who += ({ tgt });
        set_heart_beat(1);
      }

      tgt->move(env->query_exit(dir));
    }
  }

  // don't let anyone die from bump
  if (tp->query_hp() < 1) tp->set_hp(1);
  if (tgt->query_hp() < 1) tgt->set_hp(1);

  return 1;
}

void heart_beat() {
  foreach (object p in who) {
    if (!p) who -= ({ p });
    else {
      mixed *info = p->query(BUMP_PROP);
      if (sizeof(info) < 3) {
        p->set(BUMP_PROP, 0);
        who -= ({ p });
      }
      if (!userp(p) && time() - info[0] > BUMP_TIME) {
        p->move_player(info[2], "angrily");
        message("min", p->query_cap_name()+" arrives angrily.", environment(p), p);
        who -= ({ p });
      }
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}
