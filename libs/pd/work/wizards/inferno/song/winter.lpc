#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "A call to the forces that conceal land,",
     "With the force that frigid winter laid",
     "An icy grip, to stay my en'my's hand",
     "I strike thee with the icy power that winter made"
   }));
   set_type("bad");
   set_auto(1);
   set_song_name("song of winter");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard")
     if (o->query_skill("euphony") >= 13)
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
   obi = tp->query_level();
   tpi = ob->query_level()/2;
   obi -= tpi;
   if (obi <= 1) obi = random(4) + 1 + random(5) + random(3);
   if (tp->query_skill("euphony") < 50)
	dmg = tp->query_skill("euphony");
   else dmg = tp->query_skill("euphony") / 2;
   dmg += obi;
   message("info", "%^CYAN%^"+ob->query_cap_name()+"'s body "
	"is wracked in pain as "+ob->query_title_gender()+
	"bones freeze!", environment(ob), ob);
   message("info", "%^CYAN%^You're wracked in pain as your bones "
	"freeze!", ob);
   ob->damage(dmg);
}
