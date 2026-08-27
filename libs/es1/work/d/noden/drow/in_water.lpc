#include <mudlib.h>
#include <conditions.h>

inherit ROOM;

void create()
{
   ::create();
    
     set("underwater",1);
     set("in_well",1);
}

void init()
{
   UNDERWATER->apply_effect(this_player(),8,6);
}
