#include <std.h>
#include <daemons.h>

inherit DAEMON;

object *bags;

void create()
{
  ::create();
  bags = ({ });
}

void register(object me)
{
    bags += ({ me })
}

void deregister(object me)
{
    bags -= ({ me })
}

object random_bag(object me)
{
    object *baglist = bags -= ({ me });
    object target = ARRAYTOOL_D->random_elements(baglist,1);
    return target;
}
