// Alansyn May 15, 1996
// returns negative number of time() first logged in...
// time() + log_on_time   will be secs logged in

int last_log_on;

int log_on_time(string name)
{
   int TIME_ON;
   object WHO;
   if((WHO=find_player(name)))
      WHO->save_me();
   seteuid("Root");
   if(!"/secure/login"->test_user(name))
   {
      write("No such person exists on FR Mud.\n");
         return 0;
   }
   restore_object("/players/"+name[0..0]+"/"+name, 1);
   TIME_ON = -last_log_on;
   return TIME_ON;
}
