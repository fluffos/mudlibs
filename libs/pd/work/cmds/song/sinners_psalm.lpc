#include <daemons.h>
#include <std.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^ORANGE%^"
#define RES "%^RESET%^"

inherit SONG;

void create() {
  ::create();
  set_verses(({
    "Might you die and be forced to earn your dinners,",
    "In the pits of hell, with demons and thieving sinners!"
  }));
  set_auto(1);
  set_type("attack");
  set_target_required(1);
  set_song_name("sinners psalm");
}

int song() {
  object o=this_player();
  if (o->query_subclass() == "gypsy" || o->query_subclass() == "jester")
    return 1;
}

void help() {
  message("help",
    "Syntax: <sing sinners psalm [to whom]>\n\n"
    "Sinners psalm is a weak attack song for those wanderers "
    "prone to curses.",
    this_player() );
}

void finish() {
  object ob, tp, env;
  int dmg;
  tp = this_object()->query_caster();
  ob = this_object()->query_target();
  
  if (!tp) return;
  
  env = environment(tp);
  if (!ob || environment(ob) != env || env->query_property("no attack")) {
     message("info", "Nothing happens.", tp);
     return;
  }

  dmg = BALANCE3_D->get_damage( tp, ob, 1,
          ({ "euphony" }),
          ({ "charisma" }) );

  dmg = dmg/2;
  if (dmg < 10)
    message("info", "Your song fails.", tp);
  else {
    message("info", COL+"Thousands of tiny faeries attack "+
                    ob->query_cap_name()+"!"+RES, env, ob);
    message("info", COL+"Thousands of tiny faeries attack you!"+RES, ob);
    ob->do_damage("all", dmg, DAMAGE_SONG | DAMAGE_IMPACT, DAMAGE_NO_SEVER, tp);
  }
}

