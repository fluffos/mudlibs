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
   set_type("detrimental");
  set_target_required(1);
   set_song_name("fugue of woes");
}

int song() {
  object o=this_player();
   if (o->query_subclass() == "bard" || o->query_subclass() == "gypsy" && o->query_level() >= 12)
       return 1;
}

void help() {
  message("help",
    "Syntax: <sing fugue of woes [to whom]>\n\n"
    "Fugue of woes is a song which causes those who hear it to "
    "become a good deal more clumsy and slow. It wears off after a while.",
    this_player() );
}

void finish() {
   object ob, tp;
   int atk, time;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", tp);
      return;
   }
   atk = - (tp->query_skill("euphony")/7);
    time = tp->query_skill("entertainment")/3 -
         ob->query_skill("perception")/25;
   if (time < 0) {
      time = random(4) + 1;
    }
   if (ob->query_stat_bonus("dexterity") <= (atk)) {
      message("info", "Nothing happens.", environment(ob));
      return;
   }
   message("info", ob->query_cap_name()+" appears to be more clumsy and "
	"slow.", environment(ob), ob);
   message("info", "You feel more clumsy and slow.", ob);
   ob->add_stat_bonus("dexterity", atk, time);
}
