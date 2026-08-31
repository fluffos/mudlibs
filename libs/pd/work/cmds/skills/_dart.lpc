
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

// time is in seconds
#define DART_TIME 30
#define DART_PROP "dart_abil_time"
#define DART_OB "/cmds/skills/obj/dart_ob"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && member_array(tp->query_subclass(),
      ({ "thief", "scout"  }) ) != -1 &&
      tp->query_skill("defense") >= 4*22 &&
      tp->query_skill("agility") >= 5*22)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <dart behind [feature]>\n\n"
    "This ability uses your surroundings to your advantage. You can "
    "quickly dart behind something in order to avoid being hit "
    "by an attack.\n\n"
    "[feature] is almost anything in the room that you can look at.",
    this_player() );
}

int can_cast(object tp, string feature) {

  mixed tmp;

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (!tp->clean_up_attackers())
    FAIL("You are not fighting anyone!");

  if (tp->query_rest_type())
    FAIL("You must be standing!");

  if (tp->query(DART_PROP)+DART_TIME > time())
    FAIL("Nobody would fall for that again so soon!");

  if (!strlen(feature))
    FAIL("Dart behind what?");

  tmp = environment(tp)->query_item(feature);
  if ((!functionp(tmp) && !(stringp(tmp) && strlen(tmp))) ||
      member_array(feature, environment(tp)->query_exits()) != -1)
        FAIL("You can't dart behind that!");

  return 1;
}
  
int cmd_dart(string str) {

  object tp = this_player();
  object env = environment(tp);
  object ob;
  string feature;
  string *items;
  
  if (!abil()) return 0;

  if (str && str[0..6] == "behind ") str = str[7..<1];
  feature = remove_article(str);

  if (tp->is_monster() && !strlen(feature)) {
    items = keys(env->query_items());
    if (sizeof(items))
      feature = items[random(sizeof(items))];
  }

  if (!can_cast(tp, feature)) return 0;

  if (!(ob=new(DART_OB))) {
    message("info", "An error occurred, please contact a staff member.", tp);
    return 1;
  }

  ob->move(env);
  ob->setup(tp, feature);

  message("info", "You eye "+definite_article(feature)+
    " and prepare to run behind it...", tp);

  tp->add_sp(-(2+random(7)));

  return 1;
}


