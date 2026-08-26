#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("long", @EndText
You are on a huge sandy battle plain, stained a dark red from millenia of
ruthless carnage and bloodshed. A mountain range looms in the distance far
to the south, and a huge iron palace lay far to the east, barely visible
on the horizon against the deep red aky.
EndText
    );
    set ("short","The Blood Plains of Avernus");
    set("item_desc", ([
        "plain" : "It is stained with blood, and supports no life.\n",
        "range" : "It appears to be far to the south.\n",
        "palace" : "Somebody very important must live there...\n",
        "sky" : "It is dark red and full of yellowish-green clouds.\n",
        "clouds" : "Unidentifiable, but doubtless highly toxic.\n",
    ]) );
    set("smell", ([
        "default" : "The stale air smells like blood and sulfur.\n"
    ]) );
}
