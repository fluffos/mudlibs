
#include <mudlib.h>

inherit CONTAINER ;
inherit LOCK ;

void create() {
    ::create() ;
    set("short", "a chest");
    set("id", ({ "chest" }));
    set_closed_long("A chest. Its lid is closed.\n") ;
    set_open_long("An treasure chest with its lid wide open.\n") ;
    set_possible_to_close(1) ;
    set ("mass", 200) ;
    set ("capacity", 1000) ;
    set ("volume", 225) ;
    set("value", 3);
    set("max_lock", 10);
    set("lock", -1);
    set("key", "gold key") ;

}
void init() {
    container::init() ;
    lock::init() ;
}
