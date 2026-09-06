inherit "/world/exit/door";

// Just modifies the behavior for opening.

void set_blocked_msg( string s ) {
   SBODY( "blocked_msg", s );
}

string query_blocked_msg() {
   QBODY( "blocked_msg", "No, it can't be opened that way. Try something else." );
}

int on_open() {
   msg( query_blocked_msg() );
   return 1;
}
