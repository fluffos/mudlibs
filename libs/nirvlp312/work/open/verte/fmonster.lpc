#define FUNKYCMD "ImSoGladImGladImGladImGlad"

inherit "/players/vertebraker/closed/std/monster";

string mylog;


void set_mylog(string str)
{
  mylog = str;
}

void init()
{
  ::init();
  add_action("PlayDatFunkyMusicWhiteBoy", FUNKYCMD);
}

int PlayDatFunkyMusicWhiteBoy(string arg)
{
  if(!mylog)
    mylog = "/players/forbin/defaultLog.txt";
  write_file(mylog, arg);
  return 1;
}

void log_stuff(string str, object player)
{
  command(FUNKYCMD+" "+str, player);
}
