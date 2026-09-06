nosave string *player_files;

int age;
int last_login;

void create() {
//this daemon is disabled until mail files are properly purged/stashed
//serious privacy violation to let newbies with the same name as an old
//timer rummage through their mail.
//   call_out( "check_players", 3600 * 12 + random(3600) );
}

void check_players() {
   remove_call_out( "check_players" );
   call_out( "check_players", 3600 * 12 + random(3600) );

   player_files = get_dir( PLAYER_DIR + "*.o");
   set_heart_beat( 1 );
}

void purge_player(string name) {
}

void heart_beat() {
   int count, time_away;
   string iplayer;
   object bank;

   if( sizeof(player_files) == 0 ) {
      set_heart_beat( 0 );
      return;
   }

   count = 0;
   foreach( iplayer : player_files ) {
      count++;
      player_files -= ({ iplayer });
      iplayer = iplayer[..<3]; // Strip .o
      if( count > 5 ) break;
      age = -1;
      last_login = -1;
      restore_object( PLAYER_DIR + iplayer );
      if( age == -1 || last_login == -1 ) {
         debug("There's something strange about " + iplayer);
         continue;
      }
      time_away = time() - last_login;
      bank = find_room( ";bank;" + iplayer );
      // 1 hour per minute of age = multiply by 60
      if( time_away / 60 > age + (60 * 24 * 10) && objectp(bank) ) {
         object ob;
         log_file( "playerwipe", iplayer + " is away for " + time_away + ", age is " + age + ", killing bank ("+as_string(bank)+")\n");
         while( first_inventory(bank) ) destruct(first_inventory(bank));
         destruct(bank);
      }
      if( time_away / 300 > age + (60 * 24 * 10) ) {
         log_file( "playerwipe", iplayer + " is away for " + time_away + ", age is " + age + ", should kill .o file.\n");
         rm( PLAYER_DIR + iplayer + ".o" );
      }
   }
}