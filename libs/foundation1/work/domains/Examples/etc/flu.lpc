#include <std.h>

inherit GERM;

int coughs;

void create() {
    germ::create();
    coughs = 80;
    set_name("flu");
    set_id( ({ "flu" }) );
    set_short("the flu");
    set_long("A viral infection which is mostly harmless, but which "
      "generally afflicts most beings during their lifetime.");
    set_communicable(10);
    set_cure_level(1);
    set_life_span(300);
    set_type("viral");
}

void suffer(object ob) {
    coughs--;
    if(coughs%2) return;
    ob->add_hp(-((int)ob->query_hp()/10));
    message("my_action", "You cough horridly!", ob);
    message("other_action", (string)ob->query_cap_name()+" coughs horribly!",
      environment(ob), ob);
    if(!coughs) this_object()->remove();
}
