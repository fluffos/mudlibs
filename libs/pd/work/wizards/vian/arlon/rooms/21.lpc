#include <std.h>
#include <arlon2.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 2, "town" : 1, "night light" : 2]) );
set_smell("default", "The salty smell of ocean air is present here.");
set_listen("default", "The sound of peddling merchants can be heard here.");
set_short("Arlon education district");
set_long("The education district, in the western part of the Diamond District, is home to the teachers of Arlon.  There is an adventurer hall where you can train with Tibinus, the master of Arlon.  There is also a stable if you would like a horse, and a healery to gain items to increase your vitals.");
    set_exits( ([
       "enter adventurer hall" : ROOMS "22",
       "east" : ROOMS "square",
       "enter stables" : ROOMS "19",
       "enter healery" : ROOMS "25",
    ]) );
add_exit_alias("enter adventurer hall", "adventurer hall");
add_exit_alias("enter adventurer hall", "adventurer");
add_exit_alias("enter stables", "stables");
add_exit_alias("enter healery", "healery");
add_exit_alias("enter adventurer hall", "hall");
set_items(([
({"students", "teachers"}) : "Students and teachers run throughout the education district.",
]));
}
void reset() {
    ::reset();
    if(!present("arlonteenager3")){
        new(MOB"arlonteenager3")->move(this_object());
}
    if(!present("arlonteenager")){
        new(MOB"arlonteenager")->move(this_object());
}
    if(!present("arlonteenager4")){
        new(MOB"arlonteenager4")->move(this_object());
}
}

