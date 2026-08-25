
inherit "/std/object";

// This is the timeD, a time keeping daemon for LPC.
// This one does netdeads, idleouts and handles automatic reboots
// Written and Modified by Asmdoean, Skullslayer, Hamlet, Wonderflug, and 
// many more :)

#define REBOOT_TIME 23 * 60 * 60  /* every 23 hours, so its not always 
                                      the same time */
#define REBOOT_MEMORY 15 * 1024 * 1024

#define STAT_TIME 600 /* Do a statistics every tenth minute */

int SHUTTING=0;                         // whether in shutdown at the moment
int last_time;

object *netdeads();
int query_player_object(object pob);

//         "do_idletest", "auto_reboot", "net_dead_purge"
string *checks = ({
         "auto_reboot", "do_stat_users"
        });

// Here are the function definitions
// This is so they are known to anything that wants to call them
void do_idletest();
void do_stat_users();
void auto_reboot();
void net_dead_purge();

void setup() {
  set_name("daemon");
  set_short(0);
  set_long("This is a daemon, of a very daemonic nature.\n");
  reset_get();
  add_property("no_clean_up",1);
  call_out("do_checks",60);
  seteuid("Root");
}

// In case Armageddon gets dested - Radix
void reset_shutting()
{
   SHUTTING = 0;
   remove_call_out("do_checks");
   call_out("do_checks",60);
}

void do_checks() {
  int i,size;

  size = sizeof(checks);
  for (i=0; i<size; i++) {
    call_other(this_object(),checks[i]);
  }
  call_out("do_checks",60);
}

/*
 * This is the function that will check every player to test for idleness
 * by calling the idle_out() function in each player
 */
void do_idletest() {
  object *arr;
  int i, size;

  arr = users();
  size = sizeof(users());
  for (i=0; i < size; i++) {
    // check that the player didn't sneak out while we weren't looking
    if (userp(arr[i]))
      arr[i]->idle_out();
  }
}

/*
 * This function will automatically reboot the mud every REBOOT_TIME seconds
 * Only calls a shutdown if we have been up long enough, and no shutdown
 * is already running
 */
void auto_reboot() {
  int time;

  time = uptime();
  if( (memory_info() > REBOOT_MEMORY) ) {
    if (!SHUTTING && !find_object("/obj/shut")) {
      "/obj/shut"->shut(10);
      SHUTTING = 1;
      shout("Armageddon crawls out from behind the bar of the "
      "Ladyluck tavern, and seeing that the place is out of beer "
      "he shouts: Prepare to enter primal chaos in 10!!.\n");
      log_file("GAME_LOG", "Auto reboot at "+ctime(time())+"\n"
               "   (uptime: "+(time/3600)+" hours   memory usage: "+
               memory_info()+")\n\n");
      // This is a hack... I am not sure where the problem is...
      find_object("/obj/shut")->set_heart_beat(1);
    }
  }
}

void net_dead_purge() {
  netdeads()->do_force_on_me("quit");
} /* net_dead_purge() */

int query_player_object(object pob) {
  return (file_name(pob)[0..7] == "/global/" && clonep(pob));
} /* query_player_object() */

object *netdeads() 
  {
  object *l, *nd;
  int i;

  l = ({ });
  nd = ({ });
/*
  livs = livings();
  l = filter_array(livs,"query_player_object",this_object());
*/
 l = children("/global/player");
  for (i=0;i<sizeof(l);i++)
    if (member_array(l[i],users()) == -1)
      nd += ({ l[i] });
  return nd;
} /* netdeads */

void dest_me() {
  remove_call_out("do_checks");
  ::dest_me();
}

int clean_up()
{ 
return 1;
}

void do_stat_users()
  {
  object *foos;
  int i, mortals, immortals;
  
  if (time() < last_time + STAT_TIME)
    return;
  last_time = time();

  foos = users();
  for(i=0;i<sizeof(foos);i++)
    {
    if ((int)foos[i]->query_creator() == 1)
      immortals++;
     else
      mortals++;
    }
  log_file("STAT", ctime(time())+": " + immortals + "," + mortals + "\n");
  return; 
}
