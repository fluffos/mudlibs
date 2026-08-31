#include <std.h>
inherit SONG;
void create() {
    ::create();
    set_verses(({
        " A call to the forces that conceal land, \n With the force that frigid winter laid",
        " An icy grip, to stay my en'my's hand, \n I strike thee with the icy power that winter made"
      }));
    set_type("bad");
    set_auto(1);
    set_song_name("song of winter");
}
int check_sing(object o) {
    if (o->query_subclass() == "bard")
        if (o->query_skill("euphony") >= 13)
            return 1;
}
void finish_song() {
    object ob, tp;
    int obi, dmg;
    tp = this_object()->query_caster();
    ob = this_object()->query_target();
    if (!ob || !present(ob, environment(tp))) {
        message("info", "Nothing happens.", tp);
        return;
    }
    obi = ob->query_skill("perception")/3;
    if (tp->query_skill("euphony") < 50)
        dmg = tp->query_skill("euphony") + random(tp->query_skill("entertainment")/3);
    else dmg = tp->query_skill("euphony")/2 + random(tp->query_skill("entertainment")/2);
    dmg -= obi;
    dmg += random(tp->query_level()/3);
    
    message("info", "%^CYAN%^"+ob->query_cap_name()+"'s body is racked in pain as "+ob->query_title_gender()+" skin turns blue!", environment(ob), ob);
    message("info", "%^CYAN%^You're wracked in pain as your bones freeze!", ob);
    ob->damage(dmg);
}
