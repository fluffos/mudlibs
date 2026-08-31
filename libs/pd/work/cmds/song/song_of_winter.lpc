#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit SONG;
void create() {
    ::create();
    set_verses(({
        " A call to the forces that conceal land, \n With the force that frigid winter laid",
        " An icy grip, to stay my en'my's hand, \n I strike thee with the icy power that winter made"
      }));
    set_type("attack");
  set_target_required(1);
    set_auto(1);
    set_song_name("song of winter");
}
int song() {
  object o=this_player();
    if (o->query_subclass() == "bard")
        if (o->query_skill("euphony") >= 13)
            return 1;
}
void help() {
  message("help",
    "Syntax: <sing song of winter [to whom]>\n\n"
    "The song of winter magically creates a bitter cold to hurt your foe.",
    this_player() );
}
void finish() {
    object ob, tp;
    int obi, dmg;
    tp = this_object()->query_caster();
    ob = this_object()->query_target();
    if (!ob || !present(ob, environment(tp)) || environment(tp)->query_property("no attack")) {
        message("info", "Nothing happens.", tp);
        return;
    }
    obi = ob->query_skill("perception")/3;
    dmg = BALANCE3_D->get_damage( tp, ob, 1, ({ "euphony", "entertainment" }),
                                   ({ "charisma" }) );

    dmg = dmg*4/3;
    
    message("info", "%^CYAN%^"+ob->query_cap_name()+"'s body is racked in pain as "+ob->query_possessive()+" skin turns blue!", environment(ob), ob);
    message("info", "%^CYAN%^You're wracked in pain as your bones freeze!", ob);
    ob->do_damage("all", dmg, DAMAGE_SONG | DAMAGE_ICE, DAMAGE_NO_SEVER, tp);
}
