#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "There are many knives through-out this world;",
     "Many swords great and small,",
     "But there is a blade that slays and smites",
     "This blade, my friend... This blade is mine!"
   }));
   set_auto(1);
   set_type("bad");
   set_song_name("song of blades");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 30)
   if (o->query_skill("blade") >= 15 || o->query_skill("knife") >= 15)
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
   if (tp->query_skill("blade") > tp->query_skill("knife"))
     atk = tp->query_skill("blade");
   else
     atk = tp->query_skill("knife");
   atk += tp->query_skill("euphony") + random(20);
   atk -= ob->query_stats("wisdom");
   if (atk < 10) {
     message("doh", "Nothing happens.", tp);
     ob->damage(1);
     return;
   }
   tell_room(environment(tp), "A magical blade of mithril silver launches "
     "at "+ob->query_cap_name()+"!",
     ({ ob }));
   message("song", "A magical blade of mithril appears in front "
     "of "+tp->query_cap_name()+" and stabs you into your body!", ob);
   ob->damage(atk, atk);
}
