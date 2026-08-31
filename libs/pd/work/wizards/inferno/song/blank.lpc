#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
   }));
   set_type("good/bad/other");
   set_song_name("");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" || o->query_subclass() == "jester")
     if (o->query_skill("euphony") >= 77)
       return 1;

}

void finish_song() {
   object ob, tp;
   int obi, tpi, val, i, xxx;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", ob);
      return;
   }
}
