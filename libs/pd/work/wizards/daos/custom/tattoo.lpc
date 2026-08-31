#include <std.h>

inherit OBJECT;

mapping *dispatched;

void create() {
    ::create();
    set_id(({"tattoo", "symbol", "symbols"}));
    set_name("Angelic Symbols");
    set_long("%^YELLOW%^Holy symbols %^WHITE%^are tattooed all over your body. Each and every one is in the %^YELLOW%^Annarian %^WHITE%^script, and holds the %^BLACK%^infernal %^WHITE%^name of a %^RED%^Demon %^BOLD%^WHITE%^vanquished.%^RESET%^");
    set_short("%^BOLD%^WHITE%^H%^YELLOW%^o%^RESET%^ORANGE%^l%^BOLD%^WHITE%^y %^YELLOW%^S%^RESET%^ORANGE%^y%^BOLD%^WHITE%^m%^YELLOW%^b%^RESET%^ORANGE%^o%^BOLD%^WHITE%^l%^YELLOW%^s%^RESET%^");
    set_weight(0);
    set_value(0);

    if(!dispatched)
	dispatched = ([ ]);
}

mixed *query_auto_load() {
    if(this_player()->query_name() == "aziraphale")
	return ({"/wizards/daos/custom/tattoo", dispatched });
    else
	return 0;
}

void init_arg(mapping stuff) {
    dispatched = stuff;
}

void notify_kill(object hades) {
    if(hades->query_race() == "demon")
	add_kill(hades->query_name());
}

void add_kill(string hades_name) {
    if(dispatched[hades_name])
	dispatched[hades_name]++;
    else
	dispatched[hades_name] = 1;
}

string extra_look() {
    string look_me, *key_me, tmp;
    int i, total, longest;

    i = sizeof(key_me = keys(dispatched));
    total = 0;
    tmp = "";
    longest = 0;

    while(i--) {
	if(strlen(key_me[i]) > longest)
	    longest = strlen(key_me[i]);
    }
    i = sizeof(key_me);        
    while(i--) {
	total += dispatched[key_me[i]];
	tmp += "%^BOLD%^RED%^"+arrange_string(capitalize(key_me[i]), (longest))+" %^RESET%^[%^BOLD%^BLACK%^"+dispatched[key_me[i]]+"%^RESET%^]\n";
    }

    look_me = "Aziraphale's skin shines with "+(total == 1 ? "an angelic symbol" : "angelic symbols")+", listing the demons he has dispatched.\n";
    look_me = look_me + tmp;
    return look_me;
}

string query_long() {
    string tmp, *key_me;
    int i;

    tmp = ".";
    i = sizeof(key_me = keys(dispatched));
    while(i--) {
	tmp = (capitalize(key_me[i])+", "+tmp);
    }
    return ::query_long()+"\n"+"%^BOLD%^BLACK%^"+tmp;
}


int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }
