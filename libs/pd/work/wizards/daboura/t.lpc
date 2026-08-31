#include <std.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("chancer");
    set_id(({ "chancer" }));
    set_short("chancer");
    set_long("chancer");
    set_weight(1);
    set_curr_value("gold", 0);
    set_heart_beat(1);
}

void heart_beat() {
    int x;
    x = random(400);
    if(!environment(this_object())) return;
    message("info", "The chance hit "+x, environment(this_object()));
    if(x == 200) 
        message("info", "%^RED%^%^BOLD%^CHANCE HIT!%^RESET%^", environment(this_object()));


}
