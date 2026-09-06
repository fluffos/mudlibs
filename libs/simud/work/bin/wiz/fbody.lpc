#include <sys/functionlist.h>
#include <wizard.h>

// Ok, this isn't going to work until we get 3.3.x online.
// Rats. Will look at it later. -- Acius.
int main( string param ) {
   string obname, fname;
   object ob;
   string obfile;
   string curr, buf;
   int line, i;

   if( !param || sscanf(param, "%s->%s", obname, fname) != 2 ) {
      notify_fail( query_verb() + " obj->func\n" );
      return 0;
   }

   ob = find_thing( obname );
   if( !ob ) {
      notify_fail( "Can't find object: " + obname + "\n" );
      return 0;
   }

   obfile = function_exists( fname, ob, FEXISTS_FILENAME );
   line = function_exists( fname, ob, FEXISTS_LINENO );

   if( !obfile || !line ) {
      notify_fail("Can't find the function.\n");
      return 0;
   }

   buf = read_file( obfile, line, 1 );
   for( i = 1; i < 40 && line - i > 0; i++ ) {
      curr = read_file( obfile, line - i );
      if( curr[0..2] == "/**" || curr[0..2] == "///" || curr[0..1] == " *" || curr[0..1] == " */" )
         buf = curr + buf;
      else break;
   }

   buf += read_file( obfile, line+1, 40 );
   i = strstr(buf, "\n}\n", 0);
   if( i > 0 ) buf = buf[..i+2];
   msg("Function " + fname + " in file " + obfile + ":\n" + buf );

   return 1;
}