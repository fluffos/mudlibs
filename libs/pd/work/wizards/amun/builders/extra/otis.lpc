#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Otis");
    set("id", ({"otis", "tiger"}) );
    set_short("%^BOLD%^%^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This %^GREEN%^magnificent %^BLACK%^T%^WHITE%^i%^BLACK%^g%^WHITE%^e%^BLACK%^r, whose name is O%^WHITE%^t%^BLACK%^i%^WHITE%^s%^BLACK%^, has a black body with %^WHITE%^crea%^RESET%^%^WHITE%^my w%^BOLD%^%^WHITE%^hite %^BLACK%^s%^WHITE%^t%^BLACK%^r%^WHITE%^i%^BLACK%^p%^WHITE%^e%^BLACK%^s.  He %^RESET%^%^RED%^bares %^BOLD%^%^BLACK%^his t%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^t%^BOLD%^%^BLACK%^h at you as he %^RED%^growls %^BLACK%^and his %^GREEN%^e%^CYAN%^m%^GREEN%^e%^CYAN%^r%^GREEN%^a%^CYAN%^l%^GREEN%^d %^CYAN%^e%^GREEN%^y%^CYAN%^e%^GREEN%^s %^RESET%^%^RED%^flash %^BOLD%^%^BLACK%^at you as you turn away.  You have a feeling that he is s%^RESET%^%^GREEN%^t%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^k%^BOLD%^%^BLACK%^i%^RESET%^%^GREEN%^n%^BOLD%^%^BLACK%^g you as you move away from him.%^RESET%^");
    set_race("tiger");
    set_body_type("tiger");
}

void heart_beat() {
    ::heart_beat();
    if (this_player() && this_object()) {
	if (environment(this_object()) != environment(this_player())) {
	    message("info", "%^BOLD%^%^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s %^BLACK%^stalks after Artemis.%^RESET%^", environment(this_player()));
	    this_object()->move(environment(this_player()));
	}
    }
}

int is_invincible() {
    message("info", "%^BOLD%^%^BLACK%^O%^WHITE%^t%^BLACK%^i%^WHITE%^s %^BLACK%^smites "+this_player()->query_cap_name()+" and lays by Artemis's feet.%^RESET%^", environment(this_player()));
    return 1;
}

string query_guild() {
    return "illuminati";
}
