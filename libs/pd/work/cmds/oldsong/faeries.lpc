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
     tpi = tp->query_level();
   else tpi = 10;
   obi = random(ob->query_level()/2);
  tpi -= obi;
   if (tpi < 1) tpi = 1;
   dmg = tpi;
   dmg += tp->query_skill("euphony")/2;
   dmg += random(tp->query_level()/3);
   message("info", "%^ORANGE%^Thousands of tiny faeries attack "
	+ob->query_cap_name()+"!", environment(ob), ob);
   message("info", "%^ORANGE%^Thousands of tiny faeries attack you!",
	ob);
   ob->damage(dmg);
}
