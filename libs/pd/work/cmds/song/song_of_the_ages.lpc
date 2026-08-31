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
   set_type("beneficial");
  set_target_required(1);
   set_song_name("song of the ages");
}

int song() {
  object o=this_player();
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 40)
     return 1;
}

void help() {
  message("help",
    "Syntax: <sing song of the ages [to whom]>\n\n"
    "The song of the ages inspires its target to be "
    "much wiser than normal.",
    this_player() );
}

void finish() {
   object ob, tp;
   int atk;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp)) || ob->query_stat_bonus("wisdom") ) {
      message("info", "Nothing happens.", tp);
      return;
   }
   atk = tp->query_skill("euphony")/5;
   tell_room(environment(tp), ob->query_cap_name()+"'s eyes open, "
     "wiser than before.",
     ({ ob }));
   message("song", "Your eyes open, wiser than before.", ob);
   ob->add_stat_bonus("wisdom", atk, (tp->query_skill("euphony")/1));
}
