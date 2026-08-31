#include <std.h>
inherit OBJECT;

static int once = 0;

void create() {
    ::create();
    set_name("mark");
    set_short("");
    set_id( ({ "mark" }));
    set_long("A burnt mark seared permanently into your forehead.");
    set_weight(0);
}

int query_auto_load() { return 1; }

int drop() { return 1; }

int bury() { return 1; }

int move(string str) { 
    if (!once) { once = 1; ::move(str); } else {
        if (environment(this_object())->is_living())
            return 1;
        else ::move(str);
    }
    return 1;

}

string extra_look() {
    string ob;
    object o;
    ob = environment(this_object())->query_cap_name();
    o = (this_player());
    return "%^BOLD%^%^RED%^"+ob+" has a burn mark the shape of a circlet across "+o->query_title_gender()+" forehead and temples. "
    "%^BOLD%^%^WHITE%^An inscription in the burn reads: Annar Tilin%^RESET%^\n";
}
