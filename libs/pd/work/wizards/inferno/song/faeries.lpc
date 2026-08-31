#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "Warriors, silent, true and quick",
     "Attack with wielded sharpened sticks!"
   }));
   set_auto(1);
   set_type("bad");
   set_song_name("hymn of faeries");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard")
       return 1;
}

void finish_song() {
   object ob, tp;
   int obi, tpi, dmg;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", tp);
      return;
   }
   if (tp->query_level() > 10)
     tpi = random(tp->query_level());
   else tpi = random(10);
   if (ob->query_level() > tp->query_level())
     obi = random(ob->query_level());
   if (obi > (tpi * 2)) tpi /= 2;
   else if (obi > tpi) { if (tpi > 10) tpi -= 10; }
   else tpi -= obi;
   if (tpi == 0) tpi = 1;
   dmg = tpi;
   dmg += random(3) + random(3) + 1 + random(3);
   message("info", "%^ORANGE%^Thousands of tiny faeries attack "
	+ob->query_cap_name()+"!", environment(ob), ob);
   message("info", "%^ORANGE%^Thousands of tiny faeries attack you!",
	ob);
   ob->damage(dmg);
}
