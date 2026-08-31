#include <sandcastle.h>
#include <std.h>

inherit OBJECT;

void create() {
::create();
set_name("Sea Shell");
set_id( ({ "shell", "seashell", "sea shell"}) );
set_short("A Shining Sea Shell");
set_long("It is a huge Sea Shell, with a golden-pink glow to it. Amazingly, it is very clean and empty, but you wouldn't want to play it. There is an inscription on its side.");
set_curr_value("gold", 5);
set_weight (1);
}

void init() {
::init();
add_action("read", "read");
}
int read(string str) {if(!str)if(str != "inscription") return 0;write("Encarved into the side of the shell reads the words: 'Two owners I have had, two owners I have lost. Return me to one, and they will give you what they would toss.'");return 1;}

int query_auto_load() { if (this_player()->query_level() <= 4) return 1; }
