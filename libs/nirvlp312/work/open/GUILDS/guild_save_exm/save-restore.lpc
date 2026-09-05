 /* TO is this_object()
    SAVE_PATH is the pathname to your member directory, with no leading "/"
       example: #define SAVE_PATH "players/blue/guild/shadows/"
 
      the guild_status has to do with whether they are suspended or banished.
      Optional.
   
   I call restore_me in the init()
   I also call save_me with a recursive call_out every 10 minutes or so.
   Also, write an add_action like ("end_game", "quit");
      end_game() { save_me(); }
   Don't return anything from that function or else they won't be able to
   quit.
  
   */


save_me() {
   string file;
   file = SAVE_PATH + RN;
    if(!save_object(file)) {
      TEOWN("Error in saving guild score!\n");
   } else {
      TEOWN("Saving guild scores.\n");
   }
}

restore_me(name) {
   object player;
   if(!name) {
      if(!ENVTO || !ENVTO->query_name()) 
         return 0;
      name = RN;
   }
   player = find_player(name);
   if(!player) return 0;
   tell_object(player, "Restoring guild stats...\n");
   restore_object(SAVE_PATH + name);
   if(guild_status == -1) {
      write("You have been banished from the shadow guild.\nMail Blue if you "+
            " have a problem with this.\n");
      destruct(TO);
   }
   if(guild_status == 0) {
      write("You have been suspended from the shadow guild.\n");
      write("Mail Blue if you have any problems with this.\n");
      destruct(TO);
   }
   if(guild_status == -2) unjoin_me();
   return 1;
}

