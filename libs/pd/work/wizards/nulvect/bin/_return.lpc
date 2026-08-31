
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RETURN_PROP "return_abil_info"
#define RETURN_ROOM "/cmds/skills/obj/return_room"
#define TRAILMARK_PROP "trailmark_abil_info"
#define TRAILMARK_OB "/cmds/skills/obj/trailmark_ob"

#define PATHS ({ "/d/nopk/", "/d/freepk/", "/wizards/", "/d/" })
// this sucks, but it's the only way I could think of...
#define CONTINENTS ({\
    ({\
       "/d/nopk/", "/d/citrin/", "/d/lodos/", "/d/shadow/",\
       "/d/distopia/", "/d/durst/", "/d/forest/", "/d/helgrath/",\
       "/d/lodos_path/", "/d/roston/", "/d/sewers/", "/d/tirunmts/",\
       "/d/waterworld/", "/d/aekari/", "/wizards/detach/forbiden/",\
    }),\
    ({ "/wizards/powerman/" }),\
    ({ "/d/freepk/merkkerri/" }),\
    ({ "/d/freepk/rhondale/" }),\
    ({ "/d/freepk/purgatory/" }),\
    ({ "/d/inferi_island/" }),\
    ({ "/d/freepk/keys/dou/" }),\
    ({ "/d/freepk/keys/til/" }),\
    ({ "/d/freepk/keys/sorn/" }),\
})

inherit DAEMON;

void continue_return(mixed *args);
void finish_return(mixed *args);
int do_checks(object tp, object *others);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "scout" &&
      tp->query_skill("perception") >= 50*6 &&
      tp->query_skill("agility") >= 40*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <return [trailmark name]>\n\n"
    "After leaving a mark on a trail, a scout can "
    "quickly return to that trail using this ability. ",
    this_player() );
}

int can_cast(object tp, string name, mapping marks) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your senses are too confused.");

  if (!sizeof(marks))
    FAIL("You have not marked any trails.");

  if (nullp(marks[name]))
    FAIL("You have not marked a trail by that name.");

  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy fighting!");

  if (tp->query_sp() < 75)
    FAIL("You are too tired.");

  return 1;
}

int cmd_return(string str) {
  object tp = this_player();
  object env = environment(tp);
  object newenv;
  object ob, room;
  object *riders, *followers;
  mapping marks;
  string tppath, obpath;
  int flag = 0;

  if (!abil()) return 0;

  marks = (mapping)tp->query(TRAILMARK_PROP) || ([]);

  if (!can_cast(tp, str, marks)) return 0;

  newenv = environment(marks[str]["ob"]);
  if (!newenv)
    FAIL("An error occurred, please contact an immortal.");

  tppath = base_name(env);
  obpath = base_name(newenv);

  /*
   * after testing, I thought this would be cooler without
   * the area restriction...

  foreach (string p in PATHS) {
    if (!strsrch(tppath, p)) {
      tppath = tppath[strlen(p)..<1];
      break;
    }
  }
  foreach (string p in PATHS) {
    if (!strsrch(obpath, p)) {
      obpath = obpath[strlen(p)..<1];
      break;
    }
  }

  if (tppath[0..<strsrch(tppath, "/")] !=
      obpath[0..<strsrch(obpath, "/")])
        FAIL("You are not in the same area as that trail.");
  */

  // but still need a continent restriction, can't run over water
  foreach (string *list in CONTINENTS) {
    int tmp = 0;
    foreach (string dir in list) {
      if (!strsrch(tppath, dir))
        tmp += 1;
      if (!strsrch(obpath, dir))
        tmp += 1;
      if (tmp == 2) {
        flag = 1;
        break;
      }
    }
    if (flag) break;
  }
  if (!flag)
    FAIL("You are too far away from that trail.");

  // store everyone in a temporary room so nobody seems them
  // during the run
  room = new(RETURN_ROOM);

  if (!room || tp->move(room))
    FAIL("An error occurred, please contact an immortal.");

  tp->set(RETURN_PROP, ({ env, room, newenv }) );
  tp->set_paralyzed(12, "You are running towards your trail marker!");
  tp->add_sp(-(75+random(15)));

  riders = tp->query_riders();
  if (!sizeof(riders)) riders = ({});
  else {
    riders->set(RETURN_PROP, ({ env, room, newenv }) );
    riders->move(room);
    riders->add_sp(-(5+random(10)));
    riders->set_paralyzed(12, "You are being carried quickly by "+
      tp->query_cap_name()+"!");
  }

  followers = tp->query_followers();
  if (!sizeof(followers)) followers = ({});
  else {
    followers->set(RETURN_PROP, ({ env, room, newenv }) );
    followers->move(room);
    followers->add_sp(-(15+random(10)));
    followers->set_paralyzed(12, "You are being pulled along by "+
      tp->query_cap_name()+"!");
  }

  // tp, riders, and followers have left env by now
  message("info", "You get your bearings, then start "
    "running towards your trail marker!", tp);
  message("info", tp->query_cap_name()+" looks around for a moment, "
    "then starts running quickly, carrying you with "+
    tp->query_objective()+"!", riders);
  message("info", tp->query_cap_name()+" looks around for a moment, "
    "then starts running quickly, pulling you behind "+
    tp->query_objective()+"!", followers);
  message("info", tp->query_cap_name()+" looks around for a moment, "
    "then dashes away quickly!", env, ({ tp })+riders+followers);

  call_out("continue_return", 4, ({ tp, riders, followers }) );

  return 1;
}

void continue_return(mixed *args) {
  object tp = args[0];
  object *riders = args[1];
  object *followers = args[2];
  object *all = ({ tp }) + riders + followers;

  if (!do_checks(tp, riders+followers)) return;

  if (tp)

  call_out("finish_return", 4, args);
}

void finish_return(mixed *args) {
  object tp = args[0];
  object *riders = args[1];
  object *followers = args[2];
  object *all = ({ tp }) + riders + followers;

  if (!do_checks(tp, riders+followers)) return;

  message("info", "You arrive at the trail marker.", all);

  foreach (object who in all) {
    object *prop = (object *)who->query(RETURN_PROP);
    who->set_paralyzed(0);
    who->move(prop[2]);
  }

}

int do_checks(object tp, object *others) {

  object *all = ({ tp }) + others;

  foreach (object who in all) {
    int flag;
    object *prop = (object *)who->query(RETURN_PROP);
    if (!who)
      flag = 1;
    else if (!interactive(who)) {
      who->change_net_died_here(prop[0]);
      flag = 1;
    }
    else if (!tp || !interactive(tp) || environment(tp) != environment(who)) {
      who->move(prop[0]);
      flag = 1;
    }
    if (flag) all -= ({ who });
  }

  return sizeof(all);

}

