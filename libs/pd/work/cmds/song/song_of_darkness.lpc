#include <std.h>
#include <daemons.h>

inherit SONG;

void create() {
 ::create();
   set_verses(({
     "What a curse it would be, not to see, How horrid to loose one's sight;",
     "Forever trapped within a cage of night, Bare it well; for this curse, this plague.. Belongs to thee!"
   }));
   set_type("detrimental");
  set_target_required(1);
   set_song_name("song of darkness");
}

int song() {
  object o=this_player();
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 56)
     return 1;
}

void help() {
  message("help",
    "Syntax: <sing song of darkness [to whom]>\n\n"
    "This song causes your enemy to be blinded.",
    this_player() );
}

void finish() {
   object ob, tp, blind;
   int atk;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp))) {
      message("info", "Nothing happens.", tp);
      return;
   }
   atk = random(11) + tp->query_level()/4 + tp->query_skill("euphony")/9;
   tell_room(environment(tp), ob->query_cap_name()+"'s eyes shutter "
     "closed.", ({ ob }));
   message("song", "The light of the world fades away.", ob);
  ob->set_blind(1);
  DELAY_D->add_delay(atk, ob, "set_blind", ({ 0 }), 0);
/*
    blind = new("/cmds/song/obj/blind");
   blind->set_blind(atk);
   blind->move(ob);
*/
}
