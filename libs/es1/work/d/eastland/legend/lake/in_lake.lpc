#include <mudlib.h>
#include "../legend.h"
inherit LAKE"lakeii";
inherit ROOM;

void create()
{
    ::create();
    set( "light",1);
    reset();
}
void init()
{
    object *all;
    int i;
    ::init();
    all=all_inventory(this_object());
    for (i=0;i<sizeof(all);i++)
       if (!living(all[i]))
           all[i]->remove(); 
}