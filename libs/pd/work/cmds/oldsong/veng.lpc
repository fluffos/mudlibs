#include <std.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
	"May fire and brimstone never fail, Might all the leading fiends asail",
	"May not one wish or prayer avail; My vengance fall at head and tail!"
   }));
   set_auto(1);
   set_type("bad");
   set_song_name("anathema au vengeance");
}

int check_sing(object o) {
   if (o->query_subclass() == "bard" || o->query_subclass() == "gypsy")
     if (o->query_skill("euphony") >= 40 &&
	 o->query_stats("wisdom") >= 25)
       return 1;

}

void finish_song() {
   object ob, tp;
   int atk;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", this_player());
      return;
   }
   atk = tp->query_skill("euphony")*3/2;
   atk += tp->query_skill("entertainment")*3/2;   
   atk -= ob->query_skill("perception")/2;
   atk += random(tp->query_level()/3);
   if (atk < 10) {
     message("doh", "Nothing happens.", tp);
     ob->damage(1);
     return;
   }
   tell_room(environment(tp), "%^RED%^The flames of "+tp->query_cap_name()
     +"'s hate and vengeance %^YELLOW%^ engulf "+ob->query_cap_name()+"!",
     ({ ob, tp }));
   message("song", "%^RED%^The flamges of your hate and vengeance "
     "%^YELLOW%^engulf "+ob->query_cap_name()+"!", tp);
   message("song", "%^RED%^The flames of "+tp->query_cap_name()+"'s "
     "hate and vengeance %^YELLOW%^engulf you!", ob);
   ob->damage(atk);
}
