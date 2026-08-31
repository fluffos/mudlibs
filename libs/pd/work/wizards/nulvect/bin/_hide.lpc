
#include <std.h>
// rooms.h for ROOM_CACHE
#include <rooms.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL RES+"%^BLUE%^"

inherit DAEMON;

string *separators = ({
  "in",
  "under",
  "behind",
});

// hiddenobs = ({
//   ({ object item, object room, object behind, string feature,
//      string playername, int difficulty, int behindflag }),
// })
mixed *hiddenobs = ({
});

void check_search(string str);


int abil() { 
  object tp = this_player();
  if (tp && member_array(tp->query_subclass(),
      ({ "thief", "jester", }) ) != -1 &&
      tp->query_skill("stealth") >= 12*5)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <hide [item] "+implode(separators, "/")+" [feature]>\n\n"
    "Sometimes a thief needs to stash something for a while, and this is how "
    "he does it. Anyone with enough knowledge and perception can find the "
    "item by searching. Larger items are harder to hide and easier to find, "
    "of course.\n"
    "[feature] can be almost anything in the room that you can look at.",
    this_player() );
}

int can_cast(object tp, object item, string feature, object behind) {

  mixed tmp;
  object env;
  int ret = 1;

  if (!tp) return 0;

  env = environment(tp);

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You should be more worried about being dead.");

  if (tp->query_sp() < 10)
    FAIL("You are too tired.");

  if (tp->clean_up_attackers())
    FAIL("You are too busy fighting!");

  if (!item)
    FAIL("Hide what?");

  if (!strlen(feature))
    FAIL("Hide it where?");

  if (living(item) || item->query_property("no hide") || item->drop())
    FAIL("You cannot hide that.");

  // you can hide behind something in the set_items, or an object in the room
  // if it's big enough
  tmp = env->query_item(feature);
  if (feature != "shadows" && !functionp(tmp) && !(stringp(tmp) && strlen(tmp))) {

    if (objectp(behind)) {
      if (behind->query_weight() < 20)
        FAIL(capitalize(definite_article(strip_color(behind->query_short())))+
          " is not big enough to hide anything.");
      tmp = env->query_search("default");
      if (functionp(tmp) || (stringp(tmp) && strlen(tmp)) ||
          member_array(feature, env->query_exits()) != -1 )
            FAIL("You can't hide it there.");
      ret = 2;
    }

    else
      FAIL("There is no "+feature+" to hide it with!");
  }

  // check if there's already a search by that name,
  // or if feature is an exit in the room
  tmp = env->query_search(feature);
  if (functionp(tmp) || (stringp(tmp) && strlen(tmp)) ||
      member_array(feature, env->query_exits()) != -1 )
        FAIL("You can't hide it there.");

  return ret;
}

int cmd_hide(string str) {
  object tp = this_player();
  object env = environment(tp);
  object item, behind;
  int hide, weight, tmp, bflag;
  string itemname, feature, sep;
  mixed search;

  if (!abil()) return 0;

  if (str) {
    foreach (string s in separators) {
      if (sscanf(str, "%s "+s+" %s", itemname, feature) == 2) {
        sep = s;
        break;
      }
    }
    if (!sep) {
      itemname = str;
      sep = "in";
      feature = "shadows";
    }
  }

  if (itemname) {
    item = present(itemname, tp);
    if (!item)
      item = present(itemname, env);
  }

  behind = present(feature, env);

  bflag = can_cast(tp, item, feature, behind);
  if (!bflag) return 0;

  bflag--;

  itemname = strip_color(item->query_short());
  weight = item->query_weight();

  tp->set_disable(1);
  tp->add_sp(-(10+weight));

  hide = 0;
  tmp = tp->query_level()-11;
  if (tmp > 0) hide += tmp;
  tmp = (tp->query_stats("intelligence")-15)*2/3;
  if (tmp > 0) hide += tmp;
  hide -= weight;

  if (hide < 0) {
    message("info", "You try to hide "+definite_article(itemname)+
                    ", but it's too big.", tp);
    if (!tp->use_stealth(10))
      message("info", tp->query_cap_name()+" looks around "+
        definite_article(feature)+" like "+tp->query_subjective()+
        "'s trying to hide something.", env, tp);
    return 1;
  }

  hiddenobs += ({
    ({ item, env, behind, feature, tp->query_name(), hide, bflag }),
  });
  if (bflag)
    behind->set_search("default", (: check_search :) );
  else
    env->set_search(feature, (: check_search :) );
  item->move(ROOM_CACHE);
  set_heart_beat(1);

  message("info", "You hide "+definite_article(itemname)+
                  " "+sep+" "+definite_article(feature)+".", tp);
  if (!tp->use_stealth(10))
    message("info", tp->query_cap_name()+" hides something.", env, tp);

  return 1;

}

void heart_beat() {
  foreach (mixed arr in hiddenobs) {
    object item = arr[0];
    object room = arr[1];
    object behind = arr[2];
    string feature = arr[3];
    string pname = arr[4];
    int difficulty = arr[5];
    int behindflag = arr[6];
    if (!item || !room) {
      hiddenobs -= ({ arr });
      if (item)
        item->remove();
      if (room)
        room->remove_search(feature);
      continue;
    }
    if (behindflag && (!behind || environment(behind) != room)) {
      hiddenobs -= ({ arr });
      item->move(room);
      if (behind)
        behind->remove_search("default");
    }
  }
  if (!sizeof(hiddenobs)) set_heart_beat(0);
}

void check_search(string str) {
  object tp = this_player();
  object env = environment(tp);
  mixed searches;
  object item, behind, room;
  string pname, itemname;
  int find, difficulty, bflag;

  if (!str || !strlen(str)) return;

//  message("info", str+": \n"+sprintf("%O", hiddenobs), tp);
 
  searches = filter(hiddenobs, (:
    ($1[1] == $(env) &&
      ($1[3] == $(str) ||
        ($1[6] && objectp(present($1[3], $(env))))
      )
    )
  :) );

  if (!tp->use_stealth(3))
    message("search", tp->query_cap_name()+" searches "+
      definite_article(str)+".", env, tp);

  // sizeof(searches) should never be > 1, but just in case...
  if (sizeof(searches) != 1) {
    message("search", "You find nothing odd.", tp);
    return;
  }

  searches = searches[0]; // mixed can do this
  item = searches[0];
  room = searches[1];
  behind = searches[2];
  pname = searches[4];
  difficulty = searches[5];
  bflag = searches[6];

  if (pname != tp->query_name()) {
    find = tp->query_stats("intelligence") - 15;
    find *= 3;
    find += tp->query_skill("perception") - 40;
    if (tp->query_class() == "rogue")
      find /= 6;
    else
      find /= 8;
    find -= difficulty;
  }
  else
    find = 1;

  if (!item || (bflag && (!behind || environment(behind) != room)) || find < 1) {
    message("search", "You find nothing odd.", tp);
    return;
  }

  itemname = strip_color(item->query_short());
  message("search", "You find "+indefinite_article(itemname)+"!", tp);
  if (item->move(tp))
    item->move(env);
  if (behind)
    behind->remove_search("default");
  else
    env->remove_search(str);
  hiddenobs -= ({ searches });

}
