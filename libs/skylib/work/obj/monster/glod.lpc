/* This is the monster part of the curse of Glod
 * clone him, and call set_owner with the person who's cursed, and the
 * thing touched as arguments
 */
inherit NPC_OBJ;

string my_owner;
object container;

void setup() {
   set_name( "glod");
   set_short( "Glod");
   add_property( "determinate", "" );
   set_long( "This small dwarf looks quite angry, perhaps it's because he's "
            "just been summoned here.\n" );
   basic_setup("dwarf", 1, 1 );
   set_main_plural( "Glods" );
} /* setup() */

void set_owner( object owner, object thing ) {
   if ( !container )
     container = clone_object( "/std/container" );
   container->set_name( "glod's store" );
   thing->move( container );
   set_long( "This small dwarf looks quite angry, perhaps it's because he's "
            "just been transformed from being "+ (string)a_short( thing ) +".\n" );
   my_owner = (string)owner->query_name();
   load_chat( 60, ({
      1, ":looks stunned.",
      1, ":frowns angrily at "+ (string)owner->query_short() +".",
      1, "'Now why did you have to go and summon me?",
      1, "'What have I ever done to you?",
   }) );
} /* set_owner() */

void event_exit( object ob ) {
   if ( !stringp( my_owner ) ) return;
   if ( ob == find_player( my_owner ) ) {
      call_out( "check_env", 1 );
   }
} /* event_exit() */

void event_dest_me( object ob ) {
   call_out( "check_env", 0 );
} /* check_env() */

void check_env() {
   if ( environment() != environment( find_player( my_owner ) ) ) {
      move( environment( find_player( my_owner ) ),
           "$N run$s in angrily.", "$N run$s out angrily." );
      command( "follow "+ my_owner );
   }
} /* check_env() */

string query_owner() { 
   return my_owner;
}

object make_corpse() {
   if ( environment() )
     if ( container )
       return first_inventory( container );
   return ::make_corpse();
}

void dest_me() {
   if ( container )
      container->dest_me();
   ::dest_me();
} /* dest_me() */
