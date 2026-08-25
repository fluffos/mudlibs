#include <std.h>

inherit OBJECT;

int __InvisTime;
mixed *__Invis;

void create() {
    ::create();
    set_name("invis");
    set_id( ({ "invis" }) );
    set_invis(1);
    set_prevent_put("What are you doing?");
    set_prevent_drop("What are you doing?");
}

void create_invis(object who, string what, int x) {
    __Invis = ({ who, what });
    __InvisTime = time() + x;
    who->set_invis( (: this_object(), "test_invis" :) );
    move(who);
}

int test_invis(object who, object whom) {
    if(!__Invis) {
        if(this_object()) this_object()->remove();
        return 0;
    }
    if(__InvisTime < time()) {
        message("environment", "You are feeling more vulnerable now.",
          __Invis[0]);
        this_object()->remove();
        return 0;
    }
    if(__Invis[0] != who) return 0;
    if((string)whom->query_race() == __Invis[1]) return 1;
    return 0;
}

int remove() {
    int x;

    if(!__Invis || !sizeof(__Invis)) return ::remove();
    if(__Invis[0])
      __Invis[0]->remove_invis_test( (: this_object(), "test_invis" :) );
    x = ::remove();
    if(!this_object()) return x;
    else __Invis[0]->set_invis( (: this_object(), "test_invis" :) );
    return x;
}
