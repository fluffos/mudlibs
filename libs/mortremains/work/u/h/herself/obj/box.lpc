
#include <mudlib.h>

inherit CONTAINER ;
inherit LOCK ;

void create() {
    ::create() ;
    set("short" , "a jewelry box");
    set("id" , ({"box" , "jewelry box" }) );
    set_closed_long(wrap(
	"A jewelry box. On the closed lid, you can see "+
	"a beautiful chinese dragon formed from antigue "+
	"glass jewels. "
      ) );
    set_open_long(wrap(
	"A jewelry box. The inside is covered by green "+
	"velvet. It looks antique, but in perfect condition. "
      ) );
    set_possible_to_close(1) ;

    set ("mass", 200) ;
    set ("capacity", 1000) ;
    set ("volume", 225) ;
    set ("value", ({ 3, "gold" }) ) ;
    set("max_lock", 10);
    set("lock", -1);
    set("key" , "dragon key") ;

}


void init() {
    container::init() ;
    lock::init() ;
}
