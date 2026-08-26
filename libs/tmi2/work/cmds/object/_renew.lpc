/*
// This file is part of the TMI distribution mudlib.
// Please include this header if you use this code. 
// Written by Pallando and Watcher (92-12-10)
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON;

#define SYNTAX "Syntax: renew <object>\n"

int cmd_renew( string a ) {
 
  object ob, new_ob, env;
  string name, file;
  int clone_number;

  seteuid( getuid( previous_object() ) );
  if( !a ) { notify_fail( SYNTAX ); return 0; }
 
// First find your object
 
   ob = get_object(a);
   
   if(!ob) {
   notify_fail("Renew: Could not locate " + a + "\n");
   return 0;  }
 
   if( interactive(ob) ) {
   notify_fail("Renew: You cannot renew an interactive object.\n");
   return 0;  }
 
   env = environment( ob );
 
// Second decide if it has been loaded or cloned
 
   name = file_name( ob );
   if( 2 != sscanf( name , "%s#%d", file, clone_number ) ) file = name;
 
// Third update it
 
   catch( this_player()-> force_me( "update " + file ) );
 
   if( !(new_ob = find_object(file)) ) {
   notify_fail("Renew: Couldn't update " + file + "\n");
   return 0;  }
 
// Fourth give it back, using move or clone
 
   if( ob )  {
   ob-> move( VOID );
   ob-> remove();
   }
 
   if( clone_number ) new_ob = clone_object( file );
   write("Renew: " + file_name( new_ob ) + " updated");
 
   if( env )  {
   new_ob-> move( env );
   write( " to " + file_name( env ) );
  }
 
  write( "\n" );
 
return 1; }

int help() {
 
  write( ""+
    SYNTAX +
    "\nThis command searches for an object [object] using the get_object\n" +
    "efun and if a match is located, it will update the source code, then\n" +
    "replace the old object with an updated (cloned or loaded) version.\n");    
 
return 1;  }
 
