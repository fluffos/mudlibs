string well_level()
{
  string roomname;
  object ob;

  ob=interactive(previous_object()) ? environment(previous_object()) : previous_object();
  if(!ob) return 0;
  roomname=file_name(ob);
  if(strstr(roomname, "feyaria") != -1) return to_string(5 + random(5));
  if(strstr(roomname, "aaliyah") != -1) return to_string(5 + random(3));
  if(roomname[0..37] != ROOMS "level") return 0;
  if(roomname[39..39] == "/")
    return (roomname[38..38]);
  else
    return (roomname[38..39]);
}

varargs void die( int poisondeath )
{
  FRAGS "fragmaster"->give_frags();
  ::die(poisondeath);
}

void NotifyPlayerDeath(object player, object killer, int lostexp)
{
  int w;
  string fn;
  string logname;

  if ( killer==this_object() )
  {
    fn = explode(explode(file_name(this_object()),"#")[0],"/")[5];
    if (fn == "tarnbiest") logname = "Das Tarnmantelbiest";
    else if (fn == "dwarfs") logname = "Der Zwerg";
    else if (fn == "medusa_alt") logname = "Die Medusa alt";
    else if (fn == "eraditor_klein") logname = "Der Eraditor (klein)";
    else logname = Name(WER,1);
    w=write_file(LOGS "kills",
        dtime(time())+": "+ logname + " hat gerade "+
        (query_once_interactive(player)?capitalize(getuid(player)):player->name(WEN))+
        " umgebracht.( -"+lostexp+" XP )\n");
  }
#ifndef STD_WELL_NPC
  ::NotifyPlayerDeath(player, killer, lostexp);
#endif
}

void init()
{
  ::init();
  if (environment() && strstr(file_name(environment()), "astral") == -1 &&
      strstr(file_name(environment()), "feyaria") == -1 &&
      strstr(file_name(environment()), "aaliyah/hexenstadt") == -1 &&
      file_name(environment()) != "/room/npcasylraum" )
    call_out("die", 0);
}
