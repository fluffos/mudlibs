#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit SONG;

void create() {
 ::create();
   set_verses(({
     "There are many knives through-out this world; Many swords great and small,",
     "But there is a blade that slays and smites; This blade, my friend... This blade is mine!"
   }));
   set_auto(1);
   set_type("attack");
  set_target_required(1);
   set_song_name("song of blades");
}

int song() {
  object o=this_player();
   if (o->query_subclass() == "bard" && o->query_skill("euphony") >= 30)
   if (o->query_skill("blade") >= 15 || o->query_skill("knife") >= 15)
     return 1;
}

void help() {
  message("help",
    "Syntax: <sing song of blades [to whom]>\n\n"
    "A magical song that creates a blade to attack a foe.",
    this_player() );
}

void finish() {
   object ob, tp;
   int atk;
   tp = this_object()->query_caster();
   ob = this_object()->query_target();
   if (!ob || !present(ob, environment(tp)) || environment(tp)->query_property("no attack")) {
      message("info", "Nothing happens.", tp);
      return;
   }
   if (tp->query_skill("blade") > tp->query_skill("knife"))
     atk = BALANCE3_D->get_damage( tp, ob, 2, ({ "blade", "euphony" }),
                                   ({ "charisma" }) );
   else
     atk = BALANCE3_D->get_damage( tp, ob, 2, ({ "knife", "euphony" }),
                                   ({ "charisma" }) );
   atk = atk*3/2;
   if (atk < 10) {
     message("info", "Nothing happens.", tp);
     return;
   }
   tell_room(environment(tp), "A magical blade of mithril silver launches "
     "at "+ob->query_cap_name()+"!",
     ({ ob }));
   message("song", "A magical blade of mithril appears in front "
     "of "+tp->query_cap_name()+" and stabs into your body!", ob);
   ob->do_damage("random", atk, DAMAGE_SONG | DAMAGE_PIERCE, 0, tp);
}
