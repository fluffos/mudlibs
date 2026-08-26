#include <mudlib.h>
#include "baator.h"

inherit ROOM ;

void create() {
    ::create();
    seteuid(getuid()) ;
    set ("light", 1) ;
    set ("short","The Verdigris Plains of Dis");
    set ("long", @EndText
You are standing on a vast landscape of rolling, lifeless hills. The 
ground here is the sickly green color of oxidized copper, and the sky
above is a solid ash-green, without features. Far to the east, a massive
city with faintly glowing, smoking walls can be seen.
EndText
    );
    set("item_desc", ([
    "hills" : "They are rocky and lifeless.\n",
    "ground" : "It seems to be made of kind of hard green substance.\n",
    "sky" : "It is completely still and featureless, without a sun or clouds.\n",
    "city" : "The air above it shimmers, as if from extreme heat.\n"
    ]) );
}
