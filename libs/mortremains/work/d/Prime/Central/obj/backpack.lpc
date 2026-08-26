#include <mudlib.h>

inherit CONTAINER ;

void create()
{
    ::create();
  set("id", ({ "backpack", "pack" }) ) ;
  set("short", "a backpack") ;
    // Containers have two long descriptions: one for open and one for closed.
    // If a container can't be closed it doesn't need to set the closed one.
  set_open_long("This is a small backpack that you could put things in.\n") ;
    set ("mass", 15) ;
    // Capacity is the total amount of mass than can be put in the bag, and
    // volume is the total amount of bulk that can be put in.
    set ("capacity", 100) ;
    set ("volume", 25) ;
  set("value", 35) ;
}
