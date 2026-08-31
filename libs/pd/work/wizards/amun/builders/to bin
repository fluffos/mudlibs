
#include <std.h>
#include <objects.h> // for OB_CORPSE

#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^GREEN%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int spell() {
  object tp=this_player();
// sensitive info changed:
  if (tp && tp->query_subclass() == "necromancer" && tp->query_level() >= 100)
    return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  message("help",
    "Syntax: <gravescent> or <gravescent [whom]>\n\n"
    "A divining spell that necromancers use to detect if there are "
    "any dead bodies in the area. They may also try to find where a "
    "specific corpse lies.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your own ghostly presence overwhelms anything you might have sensed.");
  
  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy with combat to concentrate.");
  
  return 1;
}

int cmd_gravescent(string str) {
  object tp=this_player();
  object env=environment(tp);
  string envfile;
  string *path;
  string *races=({});
  object *corpses;
  object tgtcorpse;
  int cost;
  int tgt=0;
  
  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  if (str && str != "") {
//sensitive info changed:
    cost=700000;
    tgt=1;
  }
  else
//sensitive info changed:
    cost = 500000;

  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  tp->set_magic_round(2);
  tp->add_mp(-(cost+random(cost/9)));
  
  // OB_CORPSE from objects.h
  corpses = children(OB_CORPSE);

  if (tgt) {
    message("magic", COL+"You focus your senses to find the "+
      COL2+"corpse"+COL+" of "+capitalize(str)+"..."+RES, tp);
    foreach (object corpse in corpses) {
      if (corpse->query_player_corpse() && lower_case(corpse->query_name()) == str) {
        tgtcorpse=corpse;
        break;
      }
    }
    if (tgtcorpse) {
      message("magic", COL2+environment(tgtcorpse)->query_short()+RES, tp);
    }
    else {
      message("magic", "You cannot find it.", tp);
    }
  }
  
  else {

    path = explode(base_name(env), "/");
    if (regexp(path[1], "nopk|freepk"))
      path = path[0..2];
    else
      path = path[0..1];

    envfile="/"+implode(path,"/")+"/";

    // base_name returns the same as file_name without the #001 on the end
    corpses = filter(corpses, 
      function (object cor, string envfile) {
        return environment(cor) && clonep(cor) &&
               regexp(base_name(environment(cor)), "^"+envfile);
      }, envfile);

    if (!sizeof(corpses)) {
      message("magic", COL+"You focus your senses but feel "
                       "no death around you."+RES,tp);
    }
    else {
      foreach (object corpse in corpses)
        races += ({corpse->query_old_race()+" corpse"});
      message("magic", COL+"You focus your senses and feel "+
        COL2+"death"+COL+" in the air...\n"+
        COL2+implode(consolidate_string(races), ", "), tp);
    }
  }
  
  return 1;
}

