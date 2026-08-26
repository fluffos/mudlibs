#include "defs.h"

inherit ROOM_OBJ;

void setup() {
   set_short( "primary room for \"add_item\"" );
   add_property( "determinate", "the " );
   set_light( 100 );
   set_long( "This is the start room for the examples for add_item.  "
            "Essentially boring, since it's only here to start you on your "
            "way :)\n" );
   add_exit( "start", __DIR__+"intro", "path" );
   add_exit( "failure", __DIR__+"verb_failure", "path" );
   add_exit( "success", __DIR__+"verb_success", "path" );
   add_exit( "patterns", __DIR__+"verb_patterns", "path" );
   add_exit( "arguments", __DIR__+"func_arguments", "path" );
   add_exit( "args_int", __DIR__+"args_integer", "path" );
   add_exit( "args_string", __DIR__+"args_string", "path" );
   add_exit( "args_object", __DIR__+"args_object", "path" );
   add_exit( "helper", __DIR__+"item_helper", "path" );
   add_exit( "exit", LEARNING+"search", "path" );
   
   /* the normal add_property() calls for the learning domain
    */
   add_property( "commented functions", ({ "add_item" }) );
   add_property( "keywords", ({ "room", "add_item", "action", "command" }) );
} /* setup() */
