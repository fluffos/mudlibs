inherit OBJECT_OBJ;

void setup() {
   set_name("button");
   set_short("red button");
   add_adjective("red");
   set_long("This red button destructs all non-user objects in "
            "the room.  USE WITH EXTREME CAUTION.\n");
   reset_get();
   add_property("there", "embedded into the wall");
} /* setup() */

void init() {
   add_command("press");
} /* init() */

int do_press() {
   object thing, *things;

   things = (object *)environment()->query_non_destable();

   if( !things )
       things = ({ TO });
   else
       things += ({ TO });

   foreach( thing in INV( environment() ) - things )
      if( !userp( thing ) )
          thing->dest_me();

   write("You clean up.\n");
   say((string)TP->one_short()+" cleans up.\n");
   return 1;

} /* do_press() */
