int main( string args ) {
   string curr, *all_players;
   all_players = "/daemon/nolife"->query_all_players();

   foreach( curr : all_players ) {
      msg( capitalize(curr) + ": " +
         "/daemon/nolife"->query_time_today(curr) + " seconds today, " +
         "/daemon/nolife"->query_time_week(curr) + " seconds this week." );
   }

   return 1;
}