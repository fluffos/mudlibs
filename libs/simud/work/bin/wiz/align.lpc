#include <wizard.h>

int main( string param ) {
   object ob;

   if( !param ) {
      notify_fail("==> [Format] align who\n");
      return 0;
   }

   if( ob = find_living(param) ) {
      msg( "~CLABAlignment for "+ob->query_distant() );
      msg( "~CDEF   Good/Evil: "+ob->query_alignment(0) );
      msg( "~CDEF   Lawful/Chaotic: "+ob->query_alignment(1) );
      msg( "~CDEF   Alignment: "+ob->query_alignment_string()+(ob->query_alignment(2)?" (custom)":"") );
      return 1;
   }
}