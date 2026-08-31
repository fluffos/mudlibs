#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
	"Venom dripping, open vein",
	"Burning, searing, wrenching pain",
	"Poison; breathe, poison; blight,",
	"Poison; seethe, poisoned fight."
   }));
   set_type("bad");
   set_song_name("curse of venom");
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
   val = 2;
   tpi = tp->query_level();
   obi = ob->query_level();
   i = 10;
   while (i >= -10) {
     if ((obi + i) == tpi) { val = 0; i = -10; }
     i--;
   }
   if (val == 2) {
     if (tpi > obi) val = 1;
     else if (tpi < obi) val = -1;
   }
   if (val == -1)
     xxx = 0;
   else if(val == 1)
     xxx = 5 + random(5);
   else
     xxx = 10 + random(5);
   if (val == 0) { 
     message("info", "Your song is ineffective.", tp);
     message("info", tp->query_cap_name()+"'s attempt to poison you "
	"fails.", ob);
     return;
   }
   message("info", "%^MAGENTA%^Poison seeps into "+ob->query_cap_name()+
	"'s blood.", tp);
   message("info", "%^MAGENTA%^Poison seeps into your blood.", ob);
   ob->add_poisoning(xxx);
}
