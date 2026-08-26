#include <mudlib.h>
#include <config.h>

inherit ROOM;

void create() {
    ::create();
    set("light",1);
    set("short","Entropy's Workroom");
    set("long",@EndText
This is the room where Entropy spends most of his time working. If he's not here,
then he's probably not online. It is fairly boring and there's not much to actually
see, but that may change with-in the near future.
EndText
);
    set("exits", ([
        "south":VOID,
        "north":START,
    ]) );
}
