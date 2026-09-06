int main( string param ) {
   mixed orphans;
   int total = 0;

   WIZ_CHECK

   if( !param ) {
      string iorphan, *olist;
      orphans = "/daemon/uptodate"->query_orphans();
      if( !mappingp(orphans) || sizeof(orphans) == 0 ) {
         notify_fail("No orphans.\n");
         return 0;
      }
      foreach( iorphan : sort_array(m_indices(orphans), #'>) ) {
         olist = orphans[iorphan];
         msg( "~CLAB" + iorphan + "~CDEF: " + sizeof(olist) + " orphan(s)" );
         total += sizeof(olist);
      }
      msg( total + " orphans total" );
   }
   else {
      string iorphan, *olist;
      orphans = "/daemon/uptodate"->query_orphans();
      if( !mappingp(orphans) || sizeof(orphans) == 0 || !pointerp(olist = orphans[param]) ) {
         notify_fail("No orphans by that name.\n");
         return 0;
      }
      msg( "~CLAB" + "/inherit/textdraw"->columns(map(olist, (: to_string($1) :))) + "~CDEF" );
   }
   return 1;
}
