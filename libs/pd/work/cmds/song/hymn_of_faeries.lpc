#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "Warriors, silent, true and quick",
     "Attack with wielded sharpened sticks!"
   }));
   set_auto(1);
   set_type("attack");
  set_target_required(1);
   set_song_name("hymn of faeries");
}

int song() {
  object o=this_player();
   if (o->query_subclass() == "bard")
       return 1;
}

void help() {
  message("help",
    "Syntax: <sing hymn of faeries [to whom]>\n\n"
    "A simple song for bards that calls small faeries "
    "to attack a foe.",
    this_player() );
}

void finish() {
   object ob, tp;
   int obi, tpi, dmg;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp)) || environment(tp)->query_property("no attack")) {
      message("info", "Nothing happens.", tp);
      return;
   }
   if (tp->query_level() > 10)
     tpi = tp->query_level();
   else tpi = 10;
   obi = random(ob->query_level()/2);
  tpi -= obi;
   if (tpi < 1) tpi = 1;
   dmg = BALANCE3_D->get_damage( tp, ob, 1, ({ "euphony" }),
                                   ({ "charisma" }) );
   message("info", "%^ORANGE%^Thousands of tiny faeries attack "
	+ob->query_cap_name()+"!", environment(ob), ob);
   message("info", "%^ORANGE%^Thousands of tiny faeries attack you!",
	ob);
   ob->do_damage("all", dmg, DAMAGE_SONG | DAMAGE_PIERCE, DAMAGE_NO_SEVER, tp);
}
