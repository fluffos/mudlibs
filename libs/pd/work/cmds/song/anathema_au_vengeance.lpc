#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
	"May fire and brimstone never fail, Might all the leading fiends asail",
	"May not one wish or prayer avail; My vengeance fall at head and tail!"
   }));
   set_auto(1);
   set_type("attack");
  set_target_required(1);
   set_song_name("anathema au vengeance");
}

int song() {
  object o=this_player();
   if (o->query_subclass() == "bard" || o->query_subclass() == "gypsy")
     if (o->query_skill("euphony") >= 90)
       return 1;

}

void help() {
  message("help",
    "Syntax: <sing anathema au vengeance [to whom]>\n\n"
    "A song of great power, the anathema au vengeance can cause "
    "great damage to an enemy.",
    this_player() );
}

void finish() {
   object ob, tp;
   int atk;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp)) ||
      environment(tp)->query_property("no attack") ||
      environment(tp)->query_property("no magic")) {
        message("info", "Nothing happens.", tp);
        return;
   }
   atk = BALANCE3_D->get_damage( tp, ob, 2, ({ "euphony", "entertainment" }),
                                   ({ "charisma" }) );
   atk = atk*3/2;
   if (atk < 10) {
     message("info", "Nothing happens.", tp);
     return;
   }
   tell_room(environment(tp), "%^RED%^The flames of "+tp->query_cap_name()
     +"'s hate and vengeance %^YELLOW%^engulf "+ob->query_cap_name()+"!",
     ({ ob, tp }));
   message("song", "%^RED%^The flames of your hate and vengeance "
     "%^YELLOW%^engulf "+ob->query_cap_name()+"!", tp);
   message("song", "%^RED%^The flames of "+tp->query_cap_name()+"'s "
     "hate and vengeance %^YELLOW%^engulf you!", ob);
   ob->do_damage("all", atk, DAMAGE_SONG | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);
}
