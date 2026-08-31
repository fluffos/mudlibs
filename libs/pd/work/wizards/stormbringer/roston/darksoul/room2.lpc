#include <std.h>
#include <roston.h>

inherit ROOM;

 void init() {
    ::init();
    add_action("read", "read");
}
void create()
{
 ::create();
 set_short("A bar");
 set_properties( ([ "no bump":1,
                    "light":2,
                    "no attack":1,
                    "night light":2,
                    "no steal":1,
                    "no magic":1 ]) );
 set_long("%^BOLD%^%^BLACK%^This bar is old, and dusty it seems the "
          "barkeep doesnt care what his bar looks like. But this bar "
          "is used most offten, this bar is where members come to enjoy "
          "them selfs, have a drink and look for women.%^WHITE%^ Men "
          "whistle as women dance all around the room");

 set_exits( ([ "south" :DARKSOUL"room1" ]) );
}

void reset()
{
 ::reset();
 if (!present("jeeves")) 
   new(DARKSOUL"jeeves")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("jeeves");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with
blood.");
        return 1;
    }
    message("info", "These are the drinks served at jeeves bar",
this_player());
    message("info",
"-----------------------------------------------------------",
this_player());
    message("info", "A reaver\t\t\t"+
(int)ob->get_price("reaver")+" gold", this_player());
    message("info", "A elixir\t\t\t"+
(int)ob->get_price("elixir")+" gold", this_player());
    message("info", "A shot of
souls\t\t\t"+(int)ob->get_price("shot")+" gold",
this_player());
    message("info",
"-----------------------------------------------------------",
this_player());
    message("info", "<buy drink_name> gets you a drink.", this_player());
    return 1;
}

