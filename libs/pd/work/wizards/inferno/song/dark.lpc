#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "What a curse it would be, not to see,",
     "How horrid to loose one's sight;",
     "Forever trapped within a cage of night",
     "Bare it well; for this curse, this plague.. Belongs to thee!"
   }));
   set_type("bad");
   set_song_name("song of darkness");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 56
    && o->query_stats("intelligence") >= 18)
     return 1;
}

void finish_song() {
   object ob, tp, blind;
   int atk;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", ob);
      return;
   }
   atk = random(5) + tp->query_level()/10;
   tell_room(environment(tp), ob->query_cap_name()+"'s eyes shutter "
     "closed.", ({ ob }));
   message("song", "The light of the world fades away.", ob);
   blind = new("/wizards/inferno/song/misc/blind");
   blind->set_blind(atk);
   blind->move(ob);
}
