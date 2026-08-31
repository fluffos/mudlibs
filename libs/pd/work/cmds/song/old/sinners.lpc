#include <daemons.h>
#include <std.h>
inherit SONG;
void create() {
 ::create();
   set_verses(({
     "Might you die and be forced to earn your dinners,",
     "In the pits of hell, with demons and thieving sinners!"
   }));
   set_auto(1);
   set_type("bad");
   set_song_name("sinners psalm");
}
int check_sing(object o) {
   if (o->query_subclass() == "gypsy" || o->query_subclass() == "jester")
       return 1;
}
void finish_song() {
   object ob, tp;
   int obi, tpi, dmg;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!tp) return;
   if (!ob) {
      message("info", "Nothing happens.", tp);
      return;
   }
  if (!present(lower_case(ob->query_name()), environment(tp))) {
     message("info", "Nothing happens.", tp);
     return;
}
   if (tp->query_level() > 10)
     tpi = random(tp->query_level());
   else tpi = random(10);
   obi = random(ob->query_level());
   tpi -= obi;
   if (tpi < 1) tpi = 1;
   dmg = BALANCE_D->get_damage( tp, ob, 1, ({ "euphony" }),
                                   ({ "charisma" }) );
   dmg = dmg*3/2;
   if (dmg < 10){
    write("Your song fails.");
    return 0;
   }   
   message("info", "%^ORANGE%^Thousands of tiny faeries attack "
	+ob->query_cap_name()+"!", environment(ob), ob);
   message("info", "%^ORANGE%^Thousands of tiny faeries attack you!",
	ob);
   ob->damage(dmg);
}
