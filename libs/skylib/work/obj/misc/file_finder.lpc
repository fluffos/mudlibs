/*  Recursive file finder:
 *  Originally by Svenzer (?) of Newmoon
 *  Modified by Deutha to use call_outs.
 */

#define COLOUR "%^CYAN%^"

inherit OBJECT_OBJ;

int count, next_time;
string found;

int do_findfile(string file, string path);

void setup() {
   set_name( "finder" );
   set_short( "file finder" );
   add_adjective( "file" );
   set_main_plural( "file finders" );
   set_long( "This is a creator tool to do a recursive search for a "+
         "particular file, or directory, name beginning in the current "+
         "directory if no path is provided.\nSyntax: findfile <filename> "+
         "[<path>]\n" );
} /* setup() */

void init() {
   if ( creatorp(TP) ) {
      add_command("findfile", "<word>", (: do_findfile($4[0], 0) :) );
      add_command("findfile", "<word> <word>", (: do_findfile($4[0], $4[1]) :) );
      add_command("etc", "");
   }
} /* init() */

void add_to_found( string another, object finder ) {
   count++;
   found += another +"\n";
/* Some check to see if they want to be always told... */
   tell_object( finder, COLOUR +"Search: "+ another +"%^RESET%^\n" );
} /* add_to_found() */

void check_for_end( string search, object finder ) {
   if ( find_call_out( "do_findfile_level" ) > -1 )
      return;
   next_time = 0;
   if ( !count ) {
      tell_object( finder, COLOUR +"No incidences of "+ search +
            " found.%^RESET%^\n" );
      return;
   }
   tell_object( finder, COLOUR + count +" incidence"+ ( count == 1 ? "" :
         "s" ) +" of "+ search +" found.%^RESET%^\n" );
   finder->more_string( found, search );
} /* check_for_end() */

void do_findfile_level( string search, string path, object finder ) {
   int i;
   string *dir;
   if ( !finder ) {
      next_time = 0;
      return;
   }
   dir = get_dir( path + search );
   for ( i = 0; i < sizeof( dir ); i++ )
      add_to_found( path + dir[ i ], finder );
   dir = get_dir( path );
   for ( i = 0; i < sizeof( dir ); i++ )
      if ( file_size( path + dir[ i ] ) == -2 ) {
         if ( next_time < time() )
            next_time = time() + 1;
         else
            next_time++;
         call_out( "do_findfile_level", next_time - time(), search, path +
               dir[ i ] +"/", finder );
      }
   remove_call_out( "check_for_end" );
   call_out( "check_for_end", next_time - time() + 1, search, finder );
} /* do_findfile_level() */

int do_findfile( string file, string path ) {
   if ( next_time ) {
      notify_fail( "There is a search already in progress; estimated "+
            "time of completion is "+ ctime( next_time ) +".\n" );
      return 0;
   }
  if (!path)
      path = (string)this_player()->query_current_path();
   if ( path[ 0 .. 0 ] != "/" )
      path = "/" + path;
   if ( path[ strlen( path ) - 1 ] != '/' )
      path += "/";
   write( COLOUR +"Searching for "+ file +" in "+ path +"...%^RESET%^\n" );
   count = 0;
   next_time = time() + 1;
   found = "";
   call_out( "do_findfile_level", 1, file, path, this_player() );
   return 1;
} /* do_findfile() */

int do_etc() {
   if ( !next_time )
      write( "There is no search in progress.\n" );
   else
      write( "Estimated time of completion is "+ ctime( next_time ) +".\n" );
   return 1;
} /* do_etc() */
