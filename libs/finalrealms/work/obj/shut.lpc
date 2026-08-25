/* Current version 4.0 for Final Realms, your god Baldrick
** Bashed for our great mud by the great Pinkfish, blue of Discworld
** Many improvements from orignal version.
** Cleaned up a little - Baldrick, April 1995
**     Removed transporting of players, we have auto_load
** No earmuffed shouts if below 2 minutes - Radix, January 1996
*/

inherit "/std/object";
// Yes dear folks, an object with a heart_beat.. kill it kill it
 
int time_of_crash;

int ishout(string str, int muff);
void do_delay_prop();

void setup() {
/* This stops wizzes from cloning armageddon. He only needs to be loaded */
  if (file_name(this_object()) != "/obj/shut") 
    {
    write("This object can't be cloned.\n");
    dest_me();
    return;
    }
  set_name("armageddon");
  set_living_name("armageddon");
  enable_commands();
  set_short("Armageddon the game crasher");
  set_long("He is busy counting down the end of the game.\n");
  add_alias("shut");
  move("/room/entryroom","Armageddon appears in a puff of smoke.\n",
      "Armageddon appears in a puff of smoke.\n");
  reset_get();
  call_out("do_delay_prop",0);
}

// Radix was here... 
void do_delay_prop()
{
  if(environment(this_object()))
    environment(this_object())->add_property("no_clean_up",1);
}

// Radix was here
int ishout(string str, int muff)
{
   object *all = users();
   int i;
   for(i=0; i<sizeof(all); i++)
   {
      if(all[i])
         if(muff && all[i]->query_earmuffs()) continue;
         tell_object(all[i],"Armageddon shouts: "+str+"\n");
   }
   return(1);
}
 
void heart_beat() 
  {
  int time_to_crash;
 
  if (!time_of_crash) return;
  time_to_crash = time_of_crash - time();
  if (time_to_crash < 1) {
    call_out("end_it_all",0);
    set_heart_beat(0);
    return;
  }
  if (time_to_crash < 10)  {
    ishout("Game shutdown in "+time_to_crash+" seconds.",0);
    return;
  }
  if (time_to_crash < 60 && time_to_crash % 10 < 2) {
    ishout("Game is shutting down in "+time_to_crash+" seconds.",0);
    return;
  }
  if (time_to_crash % 60 > 1) return;
  time_to_crash /= 60;
  if (time_to_crash < 10 || !(time_to_crash % 10)) {
     if(time_to_crash > 3)
     {
       ishout("Game is shutting down in "+time_to_crash+
         " minutes.",1);
     }
     else
       ishout("Game is shutting down in "+time_to_crash+
         " minutes.",0);
    return;
  }
} /* heart_beat() */
 
void shut(int minutes) 
  {
  string fname;
 
  if (!intp(minutes)) {
    write("Bad argument\n");
    return;
  }
  fname = file_name(previous_object());
  if (minutes <= 0) {
    write("No time given\n");
    return;
  }
  set_long("He is firmly concentrating on counting.\n");
  if (time_of_crash)
    write("There was already a shutdown in progress, set for "+
      (time_of_crash - time()) + " seconds.\n");
  time_of_crash = time() + minutes*60;
  set_heart_beat(1);
} /* shut() */
 
string long(string str, int dark) {
  ::long(str, dark);
  if (time_of_crash && this_player()->query_wizard())
   return ::long(str,dark)+
      "Game shutdown will be in "+(time_of_crash - time())+" seconds.\n";
  return ::long(str,dark);
} /* long() */
 
void end_it_all() {
  int i;
  object *obs;
 
  ishout("Shutdown now!", 0);
  obs = users();
  for (i=0;i<sizeof(obs);i++)
    call_out("force_quit", 0, obs[i]);
  call_out("blue", 10);
} /* end_it_all() */
 
void force_quit(object ob) {
   if(ob)
  ob->quit();
} /* force_quit() */
 
void blue() {
  shutdown(0);
} /* blue() */
 
int query_time_to_crash() { return time_of_crash - time(); }
 
int clean_up()
{
   return 1;
}
 
void dest_me() {
  log_file("GAME_LOG","  Shutdown cancelled.\n\n");
  ::dest_me();
}
