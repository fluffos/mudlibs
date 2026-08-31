#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "Rain patters on soft, calm ground",
     "Flower, plant, leaf of tree",
     "Growing here on hallowed mound;",
     "Nature, set my spirit free"
   }));
   set_type("beneficial");
  set_target_required(1);
   // Changed because 'to' was causing errors in _sing.c
   set_song_name("ode to nature");
   //set_song_name("ode towards nature");
}

int song() {
  object o=this_player();
   if (o->query_class() == "wanderer" && o->query_subclass() == "bard"
	&& o->query_skill("euphony") >= 40) return 1;
}

void help() {
  message("help",
    "Syntax: <sing ode to nature [to whom]>\n\n"
    "This song calls upon natural forces to protect whomever "
    "the singer chooses.",
    this_player() );
}

void finish() {
   object ob, tp;
   int i;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
     message("info", "Nothing happens.", tp);
     return;
   }
   i = tp->query_skill("euphony")*3/2;
   message("info", ob->query_cap_name()+"'s skin hardens.",
	environment(ob));
   if (tp->query_magic_protection() < tp->query_level()/5)
     ob->add_magic_protection(({0,
	3+(tp->query_level()/10), i}));
}
