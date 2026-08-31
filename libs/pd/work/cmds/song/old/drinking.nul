// Verses by "Furion"
#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
"The soldier knows many nights of woes",
"of galliant knights and painful sights",
"his spirit be layed heavily",
"upon tavern stool",
"his draughts must be taken quite heavily",
"to drown his fears in emptied beers",
"so ease pickled brain of this fermented rain",
"and stien may be downed again!"
   }));
   set_type("other");
   set_song_name("sonata of inebriety");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 175)
       return 1;
   if (o->query_subclass() == "gypsy" && o->query_skil("euphony") >= 240)
       return 1;
}

void finish_song() {
   object ob, tp;
   int i, tl;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", ob);
      return;
   }
   if (tp->query_subclass() == ob->query_subclass()) i = 7/3; else i = 2;
   tl = tp->query_skill("euphony") * i;
   ob->add_intox(-tl);
   message("info", ob->query_cap_name()+"'s drunken haze fades a "
	"little.", environment(ob), ob);
   message("info", "Your drunken haze fades a little.", ob);
}
