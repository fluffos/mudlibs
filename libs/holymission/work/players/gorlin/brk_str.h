nosave varargs string
brk_str( string what, int num ) {
   string *ploder;
   int i, sz, cnt;

   ploder = explode( what, " " );
   what = "";
   cnt = num;

   for( i = 0, sz = sizeof( ploder ); i < sz; i++ ) {
      if( strlen( what + ploder[i] ) > cnt ) {
         cnt = num + strlen( what ) + 2;
         what += "\n" + ploder[i];
      }
      else
         what += " " + ploder[i];
   }
   return( what );
}
