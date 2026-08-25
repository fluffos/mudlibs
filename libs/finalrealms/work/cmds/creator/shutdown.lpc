#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{
position = 1;
}

protected int cmd(string arg, object me) {
  int tim,upt;
  string str;

  if( !arg || arg == "" ) {
    write("Argument required.\n");
    return 1;
  }
  if(!"/secure/master"->query_lord( geteuid(me ) ) ){
     upt= uptime();
     if((upt/(60*60)%24) < 3) {
       write("It has not been 3 hours yet. Perhaps you should wait 
awhile.\n");
      return 0;
     }
  }
  str = (string)me->query_name()+" at "+ctime(time());
  log_file("GAME_LOG", "Game shutdown by ");
  log_file("GAME_LOG", str);
/*
  log_file("GAME_LOG", ctime(time()));
  */
  log_file("GAME_LOG", " for\n");
  log_file("GAME_LOG", arg);
  log_file("GAME_LOG"," (Memory usage: "+memory_info()+")");
  log_file("GAME_LOG", "\n\n");
  write("Ok... shutting down game... \n");
  sscanf(arg, "%d %s", tim, arg);
  if (tim < 10 && !MASTER->high_programmer(geteuid(me)))
    tim = 10;
  if (str[0..2] == "now" && MASTER->high_programmer(geteuid(me)))
    tim = 0;
   if (!tim)
    "/obj/shut"->end_it_all();
  else
    "/obj/shut"->shut(tim);
    return 1;
} /* shutdown_game() */
 
