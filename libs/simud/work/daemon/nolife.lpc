/** This is Acius's attempt at nolife. With any luck, this one will WORK.
 */

// A number (positive or negative) giving the amount of time you have to
// add or subtract (in SECONDS) to convert GMT to local time. This is to
// allow the daemon to tick over at true midnight.
int query_timezone_offset() {
   return -7 * 60 * 60;
}

int adj_time() {
   return time() + query_timezone_offset();
}

void poll();
int query_day_num();

mapping all_players = ([ ]);
mapping current_players = ([ ]);
mapping login_times = ([ ]);
mapping session_times = ([ ]);
int last_day = 0, last_time = 0;

// Returns the current day number.
int query_day_num() {
   return adj_time() / (24 * 60 * 60);
}

mapping query_all_players() {
   return all_players;
}

void reset() {
   int key;

   // Clean out session info that's more than a week old.
   foreach( key : session_times )
      if( query_day_num() - 7 > key )
         m_delete( session_times, key );
}

mapping query_sessions( int day ) {
   if( !mappingp(session_times[day]) )
      session_times[day] = ([ ]);

   return session_times[day];
}

void store_session( string whom, int length, int day ) {
   mapping sessions_today = query_sessions(day);
   sessions_today[whom] += length;
}

int query_time_today( string whom ) {
   if( member(current_players, whom) )
      return query_sessions(query_day_num())[whom] + adj_time() - login_times[whom];
   else
      return query_sessions(query_day_num())[whom];
}

int query_time_week( string whom ) {
   int isessions, tot;
   mapping players;

   tot = 0;

   foreach( isessions, players : session_times ) {
      if( !mappingp(players) ) {
         // Ought not to happen, but...
         session_times -= ([ isessions ]);
         continue;
      }
      tot += players[whom];
   }
   if( member(current_players, whom) )
      return tot + adj_time() - login_times[whom];
   else
      return tot;
}

void create() {
   if( file_exists("/daemon/nolife.o") )
      restore_object( "/daemon/nolife" );
   else
      debug( "/daemon/nolife.o missing; The daemon will reset." );
   poll();
}

void store_login( string whom, int when ) {
   login_times[whom] = when;
}

void store_logout( string whom, int when ) {
   int session_length;
   // If we have a logout without a login, that's a bug.
   // Just ignore it so it won't twist stats.
   if( !login_times[whom] ) return;

   session_length = when - login_times[whom];
   // If they log in and out within the same minute, it
   // could be zero.
   if( session_length > 0 )
      // Store the session which just happened. Note that even if
      // this function is called *just after* midnight, the
      // time in 'when' will be "last_time", which means the
      // session should get stored *just before* midnight.
      // Clear as MUD, ne? You do lose a minute over midnight.
      store_session( whom, session_length, when / (24 * 60 * 60) );

   m_delete( login_times, whom );
}

void poll() {
   string s;
   int bounce;

   remove_call_out( "poll" );

   if( last_day != query_day_num() ) {
      // The day has changed.
      last_day = query_day_num();
      bounce = 1;
   }

   // Build a list of current players.
   mapping m = mkmapping( map(users(), (: $1->query_name() :)) ) - ([ 0 ]);

   all_players += m;

   // Detect any logout events.
   foreach( s : bounce ? m : current_players - m ) {
      store_logout( s, last_time );
   }

   // Detect any login events.
   foreach( s : bounce ? m : m - current_players ) {
      store_login( s, adj_time() );
   }

   current_players = m;

   last_time = adj_time();
   save_object( "/daemon/nolife" );

   call_out( "poll", 60 );
}

void login( string name ) {
   poll();
}

void logout( string name ) {
   poll();
}
