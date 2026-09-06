object whoever;

start() {
   whoever = this_player();
   call_out("blah", 2);
}

blah() {
   msg_object( whoever, "This is a blah test. TP="+as_string(this_player())+", verb="+query_verb() );
}

void cout_test( int x ) {
   write("" + x + "\n" );
   if( x > 0 )
   call_out("cout_test", 0, x-1);
}