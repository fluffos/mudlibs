/* Current version 4.0 for Final Realms, your god Baldrick
** Bashed for our great mud by the great Pinkfish, blue of Discworld
** Many improvements from orignal version.
** Cleaned up a little - Baldrick, April 1995
**     Removed transporting of players, we have auto_load
** No earmuffed shouts if below 2 minutes - Radix, January 1996
** Auto reboots fail if dested, hopefully fixed - Radix, August 1996
*/

inherit "/std/object";
#define IMUD_SERV "/net/intermud3/services"

#include "login_handler.h"
 
int time_of_crash;
varargs int ishout(string str, int muff);
void do_delay_prop();

void setup() {
/* This stops wizzes from cloning armageddon. He only needs to be loaded */
  if (file_name(this_object()) != "/obj/shut") 
    {
    write("This object can't be cloned.\n");
    dest_me();
    return;
    }
  set_name("freddy");
  set_living_name("freddy");
  enable_commands();
  set_short("Freddy, el Historiador de los Dioses");
  set_long("El es un humano de talla media, gafas y ligeramente relleno. En su tiempo "
	" libre cuida de que los Reinos no rompan el Destino escrito por los Dioses."
	" Ahora mismo esta muy ocupado contando el tiempo que le queda a esta Era.\n");
  add_alias("shut");
  move("/room/entryroom","Freddy aparece de la nada por obra divina.\n",
      "Freddy aparece de la nada por obra divina.\n");
  reset_get();
  call_out("do_delay_prop",0);
  // Radix...
  if(this_player())
  {
     call_out("delayed_safety",5,this_player()->query_cap_name());
     write("Freddy comenzara la cuenta atras en 5 segundos!\n");
  }
}
// Radix was here... 
void do_delay_prop()
{
  if(environment(this_object()))
    environment(this_object())->add_property("no_clean_up",1);
}

// More Radix stuff...
void delayed_safety(string name)
{
   if(!time_of_crash)
   {
      log_file("GAME_LOG",name+" clono o actualizo a "+
            "Freddy, reboot started. "+ctime(time())+"\n\n");
      this_object()->shut(10);
   }
   return;
}
// Radix was here
varargs int ishout(string str, int muff)
{
   object *all = users();
   int i;
   for(i=0; i<sizeof(all); i++)
   {
      if(all[i])
         if(muff && all[i]->query_earmuffs()) continue;
         tell_object(all[i],"Freddy, el Historiador, anuncia: "+str+"\n");
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

   // "Gracefully" go down on intermud - Radix : Jan 5, 1996
   if(time_to_crash < 300)
      catch(IMUD_SERV->eventShutdown(time_to_crash));

  if (time_to_crash < 10)  {
    ishout("Cambio de Era en "+time_to_crash+" segundos.",0);
    return;
  }
  if (time_to_crash < 60 && time_to_crash % 10 < 2) {
    ishout("Cambio de Era en "+time_to_crash+" segundos.",0);
    return;
  }
  if (time_to_crash % 60 > 1) return;
  time_to_crash /= 60;
  if (time_to_crash < 10 || !(time_to_crash % 10)) {
     if(time_to_crash > 3)
     {
       ishout("Cambio de Era en "+time_to_crash+
         " minutos.",1);
     }
     else
       ishout("Cambio de Era en "+time_to_crash+
         " minutos.",0);
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
  set_long("El es un humano de talla media, gafas y ligeramente relleno. En su tiempo "
	" libre cuida de que los Reinos no rompan el Destino escrito por los Dioses."
	" Ahora mismo esta muy ocupado contando el tiempo que le queda a esta Era.\n");
  if (time_of_crash)
    write("There was already a shutdown in progress, set for "+
      (time_of_crash - time()) + " seconds.\n");
  time_of_crash = time() + minutes*60;
  set_heart_beat(1);
} /* shut() */
 
string long(string str, int dark) {
  ::long();
  if (time_of_crash && this_player()->query_wizard())
   return ::long(str,dark)+
      "A esta Era le quedan "+(time_of_crash - time())+" segundos.\n";
  return ::long(str,dark);
} /* long() */
 
void end_it_all() {
  int i;
  object *obs;
 
  ishout("Cambiando de Era!");
  obs = users();
  for (i=0;i<sizeof(obs);i++)
    call_out("force_quit", 0, obs[i]);
  // el call_out a blue pone el MARGEN de tiempo PARA LAS CLONADAS LOKAS
  LOGIN_HANDLER->we_are_rebooting();
  call_out("blue", 10);
} /* end_it_all() */
 
void force_quit(object ob) {
   if(ob)
   // changed to really_quit - Radix
   ob->really_quit();
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
  log_file("GAME_LOG","  Shutdown cancelled.\n");
  // Radix...
  if(this_player())
  {
     log_file("GAME_LOG","  by "+this_player()->query_cap_name()+"\n\n");
     catch(find_object("/obj/handlers/timed")->reset_shutting());
  }
  ::dest_me();
}
