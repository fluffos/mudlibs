// Verses by J.R.R. Tolkein
#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "All that is gold does not glitter,",
     "Not all those who wander are lost",
     "The old that is strong does not wither;",
     "Deep roots are not touched by the frost"
   }));
   set_type("good");
   set_song_name("song of the ages");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 40)
     return 1;
}

void finish_song() {
   object ob, tp;
   int atk;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", tp);
      return;
   }
   atk = tp->query_skill("euphony")/15;
   tell_room(environment(tp), ob->query_cap_name()+"'s eyes open, "
     "wiser than before.",
     ({ ob }));
   message("song", "You eyes open, wider than before.", ob);
   ob->add_stat_bonus("wisdom", atk, (tp->query_skill("euphony")/5));
   tp->add_mp(-(tp->query_skill("euphony") + random(10)));
}
