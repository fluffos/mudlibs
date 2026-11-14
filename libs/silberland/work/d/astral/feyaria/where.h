  AddCmd(({"awhere", "awhe", "awo"}), "whe");
  AddCmd(({"aruf", "arufe","aemote"}),"astral_shout");
  AddCmd(({"ahist", "ahistory"}),"astral_history");
  SetProp(P_SUBDOMAIN, "Ebenen der Macht");
}


nosave int CheckZone(object u)
{
  if (!(ENV(u))) return 0;      // gerade einloggende Spieler...
  if (stringp(ENV(u)->QueryProp(P_ZONE)) &&
      ENV(u)->QueryProp(P_SUBDOMAIN) == "Ebenen der Macht" && 
      (IS_ARCH(TP) || !IS_LEARNER(u)))
    return 1;
  return 0;
}


int whe(string s)
{
  int i, j;
  object *usrs;
  string str;
  string u_name, u_lev, u_loc, u_zone, u_end;

  if (!(i = sizeof(usrs = filter_array(users(),"CheckZone"))))
  {
    write("Es befinden sich derzeit keine Spieler in den 10 Ebenen der Macht.\n");
    return 1;
  }
  switch(TP->QueryProp(P_TTY)) 
  {
    case "ansi" : u_name = ANSI_GREEN + ANSI_BOLD; u_lev = ANSI_YELLOW + ANSI_BOLD;
                  u_zone = ANSI_NORMAL; u_loc = ANSI_CYAN;
                  u_end = ANSI_NORMAL; break;
    case "vt100": u_name = ANSI_BOLD; u_lev = ANSI_NORMAL; u_loc = ANSI_BOLD;
                  u_zone = ANSI_NORMAL; u_end = ANSI_NORMAL; break;
    default     : u_name = u_lev = u_loc = u_zone = u_end = "";
  }
  
  str = "Derzeit befinden sich folgende Spieler in den 10 Ebenen der Macht:\n"
        "       Name      Stufe      Zone              Ort\n"
        "-+--------------+-----+-----------------+--------------------------\n";
  for (j = 0; j < i; j++) 
  {
    str += sprintf(" | %s%-12s%s | %s%3d%s | %s%-15s%s | %s%s%s\n",
        u_name, CAP(getuid(usrs[j])), u_end,
        u_lev, usrs[j]->QueryProp(P_LEVEL), u_end,
        u_zone, environment(usrs[j])->QueryProp(P_ZONE), u_end,
        u_loc, (IS_LEARNING(TP) ? file_name(environment(usrs[j])) : 
          environment(usrs[j])->QueryProp(P_INT_SHORT)), u_end
        );
  }
  TP->More(str+"\n");
  return 1;
}

void NotifyPlayerDeath(object player, object killer, int lostexp)
{
  ASTRALMASTER->AddDeath(player, lostexp);
  call_out("corpsemove", 6 + random(6));
}

void move_corpse(object ob)
{ 
  if (strstr(ob->QueryProp(P_ORIG_FILENAME), ":") != -1) // Leiche eines Spielers
  { 
    ob->SetProp("corpse_decay", ob->QueryProp(P_LEVEL) * 10 );
    ob->move(GRAVEYARD, M_NOCHECK);
    ob->SetProp(P_ASTRAL_DIE_ZONE, lower_case(QueryProp(P_ZONE)));
    ob->SetProp(P_NOMAGIC, "dusty");
    Message(ob->QueryProp(P_SHORT) + " verschwindet.\n", MSGFLAG_VISUAL);
    GRAVEYARD->Message(ob->QueryProp(P_SHORT) + " erscheint ploetzlich.\n", 
        MSGFLAG_VISUAL);

  }
}

void corpsemove()
{ 
  filter_array(filter_objects(all_inventory(), "id", "leiche"), #'move_corpse);
}

int IsInAstral(object pl)
{
  string* filenames;

  if (member(ALLOWED_UIDS, getuid(pl)) != -1) return 1;
  if (!environment(pl)) return 0;
  filenames = explode(file_name(environment(pl)), "/");
  if (sizeof(filenames) < 6 || filenames[2] != "feyaria" || 
      member(ALLOWED_ZONES, filenames[3]) == -1)
    return 0;
  return 1;
}

nosave int astral_shout(string str) 
{
  int i, no_msg, invis,lvl, emote;
  object *members;
  string *presay, *ignores, pre, msg, newmsg, addon, std_pre;
  no_msg=0;
  
  if(query_verb() == "aemote")
    emote=1;
  notify_fail("Was moechtest Du in den 10 Ebenen der Macht rufen?\n");
  if (!stringp(str)) 
    return 0;
  msg=TP->_unparsed_args();
  if(objectp(TP->QueryProp(P_PERM_STRING)))
     msg=call_other(TP->QueryProp(P_PERM_STRING),"permutate_string",msg)||"";
  members=filter_array(users(), "IsInAstral");
  std_pre="<Macht:"+TP->name(WER);
  if(emote) addon="";
  else addon=">";
  std_pre+=addon+" ";
  for(i=sizeof(members)-1;i>=0; i--) {
    if(TP->QueryProp(P_INVIS) && !IS_WIZARD(members[i]))
      pre="<Macht:Jemand"+addon+" ";
    else if(TP->QueryProp(P_INVIS) && IS_WIZARD(members[i]))
      pre="<Macht:("+CAP(getuid(TP))+")"+addon+" ";  
    else     
      pre="<Macht:"+TP->Name(WER)+
        addon+" ";
    if(emote) 
    {
      newmsg=pre+msg+">";
      pre="";
    }
    else
      newmsg=msg;
    members[i]->Message(
          (members[i]->QueryProp(P_TTY) == "ansi" ?  ANSI_BOLD + ANSI_CYAN : "") +
          break_string(newmsg +
          (members[i]->QueryProp(P_TTY) == "ansi" ?  ANSI_NORMAL : ""), 
          members[i]->QueryProp(P_SCREENWIDTH), pre),
        MSGFLAG_CHANNEL);
  }
  if(emote) 
  {
    newmsg=std_pre+"%s"+">";
    std_pre=" ";
  }
  call_other( ASTRALMASTER, "AddHistory", std_pre, msg, invis, emote, newmsg);
  return 1;
}

nosave varargs int astral_history(mixed number) 
{
  int i;
  string *msgs;
  mixed *history;
  mixed *hist_time;
 
  if(!number) number=10;
  number=to_int(number);
  history=call_other(ASTRALMASTER, "QueryHistory", number);
  hist_time=history[0];
  history=history[1];
  if (sizeof(history)==0)
  {
    write("Nichts ist in den 10 Ebenen der Macht passiert.\n");
    return 1;
  }
  if (TP->QueryProp(P_TTY) == "ansi")
    write(ANSI_BOLD+ANSI_CYAN);
  write("Das haben die Erforscher der 10 Ebenen der Macht gerufen:\n");
  write("-----------------------------------------------"
       "-------------------------------\n");
  for(i=0;i<=sizeof(history)-1;i++) {
    msgs=explode(history[i],"&&*%%");
    if( msgs[0][0..0] == " ")
      msgs[0]=msgs[0][1..];
    if (((time()+7200)/86400)>((hist_time[i]+7200)/86400)) {
      write(BS(dtime(hist_time[i])));
    }
    else {
      write(BS(dtime(hist_time[i])[19..26]));
    }
    // Wenn ein Spieler nhist macht bei jemand der invis nkreischt ...
    if(msgs[2]=="1" && !IS_WIZARD(TP)) {
      if(msgs[3] == "1") { // == emote 
        write(break_string(sprintf("<Macht:Jemand %s>",msgs[1]), TP->QueryProp(P_SCREENWIDTH)));
      }
      else {
        write(break_string(msgs[1], TP->QueryProp(P_SCREENWIDTH), "<Macht:Jemand> "));
      }
    }
    else { // ... und hier der Magier 
      if(msgs[3] == "1") { //emote
        write(break_string(sprintf(msgs[4], msgs[1]), TP->QueryProp(P_SCREENWIDTH)));
      }
      else {
        write(break_string(msgs[1], TP->QueryProp(P_SCREENWIDTH), msgs[0]));
      }
    }
  }
  write("-----------------------------------------------"
        "-------------------------------");
  if (TP->QueryProp(P_TTY) == "ansi")
    write(ANSI_NORMAL);
  write("\n");
  return 1;  


