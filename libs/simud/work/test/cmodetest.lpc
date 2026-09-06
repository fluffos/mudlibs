void runtest( string s ) {
   string mesg;
   int i;
   mesg = "Received: ";
   for( i = 0; i < strlen(s); i++ )
      mesg += s[i] + " ";
   if( s != "\27" )
      input_to( "runtest", 2 );
   write( mesg + "\n" );
}

void start_test() {
   input_to( "runtest", 2 );
}

void password_test( string s ) {
   if( s == "q" ) return;
   if( s ) write( s + "\n" );
   input_to( "password_test", 3 );
}