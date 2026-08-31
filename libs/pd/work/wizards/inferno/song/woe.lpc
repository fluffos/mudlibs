#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
	"Bruadar and Smith and Glinn",
	"May flails of sorrow flay!",
	"May you lie low in waves of woe,",
	"And tortures slow each day!"
   }));
   set_type("bad");
   set_song_name("fugue of woes");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" && o->query_level() >= 12)
       return 1;
}

void finish_song() {
   object ob, tp;
   int atk, time;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", ob);
      return;
   }
   atk = - (tp->query_skill("euphony")/30);
   time = tp->query_stats("intelligence") -
	  ob->query_stats("intelligence");
   if (time < 0) {
      time = random(4) + 1;
   } else if (time >= 6) time += random(10);
     else time += random(5);
   if (ob->query_stats_bonus("dexterity") <= (atk)) {
      message("info", "Nothing happens.", environment(ob));
      return;
   }
   message("info", ob->query_cap_name()+" appears to be more clumsy and "
	"slow.", environment(ob), ob);
   message("info", "You feel more clumsy and slow.", ob);
   ob->add_stat_bonus("dexterity", atk, time);
}
