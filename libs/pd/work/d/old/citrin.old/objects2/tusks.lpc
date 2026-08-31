// Coded by Whit

#include <std.h>

inherit WEAPON;

void create() {
::create();
set_name("tusks");
set_short("a pair of boar tusks");
set_id(({ "tusks", "boar tusks" }));
set_long("The tusks are bloody.  They are very sharp and look like it can"
"peirce heavy armour");
set_wc(36);
set_type("knife");

}
int weapon_hit(object ob) {
    int x, y;
    if((string)ob->query("race") != "faerie") return 0;
    y = random(10);
    x = (int)this_player()->query_alignment();
    if(x> 0) x = (x/100);
    else x = 0;
    y += x;
this_player()->force_me("say Ha Ha! DIE!");
    write("You feel the tusks pierce your enemy.\n");
//    say(this_player()->query_cap_name()+" \n",
// this_player());
    return y;
}
int query_autoload() { if (this_player()->query_level() > 20) return 1; }
