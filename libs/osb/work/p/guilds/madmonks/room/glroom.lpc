// the hlp room for the madmonks guild
// made by Magictcs - 7 may 97
// the room will log all missing details

// TODO: check banish command
//       add_new_gl() coden
//       goto_member() coden

#include <rooms.h>
#include <properties.h>
#include <moving.h>
#include <guild.h>

#ifdef ONESTEPBEYOND
#include <secure/wizlevels.h>
#else
#include <wizlevels.h>
#endif

#include <news.h>
#include <npc.h>
#include "/p/guilds/madmonks/madmonks.h"

#define SLIB "/lib/string"

inherit BASISROOM;           // autolog details to logdir

string * chairs;  // stores the real names of all players sitting on chairs
string lever="tail";         // tail position;
string banname;

//***********************
// handling of the chairs
//***********************
// command: sit (down) on (wooden) chair 
int sit(string s) {
  string str;
  notify_fail("Sit down on what?\n");
  if (!s) return 0;
  str=norm_id(s);
  if (member(({"down on chair","down on wooden chair","on chair",
    "on wooden chair"}),str)!=-1) {
    if (member(chairs,TP->QueryRealName())!=-1) {
      write("You are already sitting on the chair.\n");
      return 1;
    }
    write("You sit down on a chair.\n");
    show(NAME+" sits down on a chair.\n");
    chairs+=({TP->QueryRealName()});
    return 1;
  }
  return 0;
}

// command: stand up, if you sit on a chair
int standup(string str) {
  if (!str) {notify_fail("Try: stand up\n"); return 0; }
  if (str=="up") {
    if (member(chairs,TP->QueryRealName())==-1) {
      write("You are not sitting on a chair!\n");
      return 1;
    }
    write("You stand up from the chair. Now you can leave the room.\n");
    show(NAME+" stands up from the chair.\n");
    chairs-=({TP->QueryRealName()});
    return 1;
  }
  notify_fail("Try: stand up\n");
  return 0;
}

// mainly used for xprop $h   :)
string * QueryBenches() { return chairs; }

//****************
// detailhandling:
//****************
string lookchair() {
  if (member(chairs,TP->QueryRealName())!=-1)
    return "You are sitting on the chair.\n";
  return "One chair is left, so you can sit down on it.\n";
}

string lookchairs() {
  string ret;
  int i;
  switch (sizeof(chairs)) {
    case 1: return "There are some free chairs - you can sit on one.\n";
    case 2: return CAP(chairs[1])+" is sitting on a chair.\n";
    case 3:
      return CAP(chairs[1])+" and "+CAP(chairs[2])+" are sitting on chairs.\n";
    default:
      ret=CAP(chairs[1])+", ";
      for (i=2;i<sizeof(chairs)-1;i++)
        ret+=CAP(chairs[i])+", ";
      ret+="and "+CAP(chairs[sizeof(chairs)-1])+" are sitting on chairs.\n";
      return ret;
  }
}

// show the actual position of the lever
string looklever() {
  return "The lever belongs to the buttons on the desk.\n"
         "It controls the output given, if you press a button.\n"
         "You can switch it to two positions:\n"
         "The lever stands in the position of '"+lever+"' yet.\n"
         "But you can pull it.\n";
}

// command: press white button
void other_commands() {
  show(NAME+" operates with the buttons.\n");
  write(
  "Some words appear on the desk:\n"
  "There are some other commands available:\n"
  "  gone <player>     - remove someone from the list who is no longer\n"
  "                      a member.\n"
  "  rem <player>      - remove someone from the guild (must be logged in).\n"
  "  banish <player>   - banish a player. He will never be allowed to join\n"
  "                      again.\n"
  "  unbanish <player> - unbanish a banished player. He can join again.\n"
  "  add <player>      - add a new vize guildleader.\n"
  "  goto <player>     - go to player (he has to be agree before!)\n"
  "Just 'write' the command onto the desk (for example: 'write banish')!\n"
  "The words vanishes from the desk.\n");
}

//***********
// pull lever
//***********
// command: pull lever
int pulllever(string str) {
  if (!str) { notify_fail("Pull what?\n"); return 0; }
  if (str=="lever") {
    switch (lever) {
      case "full": lever="tail"; break;
      case "tail": lever="pattern"; break;
      case "pattern": lever="full"; break;
    }
    show(NAME+" pulled the lever.\n");
    write(
    "The lever moves into the other position '"+lever+"' if you pulled it.\n");
    return 1;
  }
  notify_fail("Pull what?\n");
  return 0;
}

//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
/*
int addcom(string str) {
  string who;
  if (!str || !this_player()) { notify_fail("Add whom?\n"); return 0; }
  who = lower_case(str);
  guildname->ChangeStat(who, G_LEADER);
  write("Made "+capitalize(who)+" a guildcommander.\n");
  return 1;
}

int goto(string str) {
  object dest;
  string a; 
  if (!str) { notify_fail("Go to whom?\n"); return 0; }
  if (IS_WIZARD(this_player())) return 0;
  dest=find_living(str);
  if (!dest || !dest->QueryIsPlayer()) {
     write("No such player ("+str+")!\n");
     return 1;
  }
  if (IS_WIZARD(dest)) {
     write("Never bother a wizard, my friend!\n");
     return 1;
  }
  if (this_player()->QuerySP() < 70) {
      notify_fail("Not enough SP.\n");
      return 0;
  }
  this_player()->SetSP(this_player()->QuerySP()-70);
  this_player()->move(environment(dest), M_GO, "away");
  return 1;
}


int fetch(string str) {
  object dest;
  if (!allowed(this_player())) { 
     write("You are no guildcommander.\n");
     return 1; 
  }
  dest=find_living(str);
  if (!dest || !dest->QueryIsPlayer()) {
     write("No such player ("+str+")!\n");
     return 1;
  }
  if (IS_WIZARD(dest)) {
     write("Never bother a wizard, my friend!\n");
     return 1;
  }
  dest->move(this_object(),M_TELEPORT);
  return 1;
}
*/
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

//**********************************
// if smore is finished - print text
//**********************************
void smore_finished() {
  write("The words vanishes from the desk.\n");
}

//************************
// scan a file for pattern
//************************
string ScanFile(string file, string pat) {
  int i, j;
  string ret, t, *tem;
  ret = "";
  if (!(pat && file)) return ret;
  for (i=1; t=read_file(file, i, 1000); i+=1000) {
    if (sizeof(tem=regexp(explode(t, "\n") - ({""}), pat))) {
      // if (!j++) ret+=">>> File: "+file+" <<<\n";
      ret += implode(tem, "\n")+"\n";
    }     
  }
  return ret;
}

//************
// list member
//************
// command: press green button
int list() {
  string aus;
  show(NAME+" operates with the buttons.\n");
  aus="Some words appear on the desk.\nYou read:\n";
  aus+=MAINGUILD->MemberList();
  SLIB->smore(aus,TP->QueryPageSize(),TO,"smore_finished");
  return 1;
}

//*************
// list killers
//**************
// command: press black button
int killers() {
  string aus;
  show(NAME+" operates with the buttons.\n");
  write("Some words appear on the desk.\nYou read:\nKillers:\n");
  switch (lever) {
    case "tail": {
      tail("/log/KILLER");
      smore_finished();
      return 1;
    }
    case "full": {
      aus = read_file("/log/KILLER");
      SLIB->smore(aus,TP->QueryPageSize(),TO,"smore_finished");
      return 1;
    }
    default: {           // pattern
      write("Just enter your search pattern:\n]");
      input_to("killers_pattern");
      return 1;
    }
  }
}

killers_pattern(string str) {
  string aus;
  if (str=="") {
    write("No pattern - show the tail of the log.\n");
    tail("/log/KILLER");
    smore_finished();
    return;
  }
  aus = ScanFile("/log/KILLER", str);
  SLIB->smore(aus,TP->QueryPageSize(),TO,"smore_finished");
}

//****************
// list aggressors
//****************
// command: press red button
int aggressors() {
  string aus;
  show(NAME+" operates with the buttons.\n");
  write("Some words appear on the desk.\nYou read:\nAggressors:\n");
  switch (lever) {
    case "tail": {
      tail("/log/AGGRESSORS");
      smore_finished();
      return 1;
    }
    case "full": {
      aus = read_file("/log/AGGRESSORS");
      SLIB->smore(aus,TP->QueryPageSize(),TO,"smore_finished");
      return 1;
    }
    default: {           // pattern
      write("Just enter your search pattern:\n]");
      input_to("aggressors_pattern");
      return 1;
    }
  }
}

aggressors_pattern(string str) {
  string aus;
  if (str=="") {
    write("No pattern - show the tail of the log.\n");
    tail("/log/AGGRESSORS");
    smore_finished();
    return;
  }
  aus = ScanFile("/log/AGGRESSORS", str);
  SLIB->smore(aus,TP->QueryPageSize(),TO,"smore_finished");
}

//******************************************
// remove member who is not a member anymore
//******************************************
// command: write gone <name>, write gone
gone(string name) {
  if (name!=0) {
    gone_member(name);
  } else {
    write("Some words appear on the desk:\n"
      "Which name should be removed from the list of members?\n"
      "Write the name or press <enter> to leave:\n]");
    input_to("gone_member");
  }
}

gone_member(string str)
{
  string file;
  switch (str) {
    case "": case "~q":
      write("You don't change the list of members.\n");
      smore_finished();
      return;
  }
  if (find_living(str)) {
    write("You can't remove this player.\n"+
          CAP(str)+" is online - use the 'rem' command instead!\n");
    return;
  }
  MAINGUILD->RemoveMember(str);
  write("You removed "+str+" from the list of guildmembers.\n");
  smore_finished();
}

//***********************************
// remove a member from the guildlist
//***********************************
// write rem <name>,write rem
rem(string name) {
  if (name!=0) {
    rem_member(name);
  } else {
    write("Some words appear on the desk:\n"
      "Which active player should be removed from the list of members?\n"
      "Write the name or press <enter> to leave:\n]");
    input_to("rem_member");
  }
}

rem_member(string str) {
  object dest;
  if (str=="" || str=="~q") {
    write("You don't change the list of members.\n");
    smore_finished();
    return;
  }
  dest=find_living(str);
  if (!dest) {
    write(CAP(str)+" is not in this MUD at the moment.\n");
    smore_finished();
    return;
  }
  if (dest->QueryGuild() != GC_MADMONKS  ) {
    write("That player is no member of the madmonks.\n");
    smore_finished();
    return;
  }
  MAINGUILD->check_leave("yes",dest);
  write(CAP(str)+" is thrown out of this guild.\n");
  smore_finished();
}

//****************
// banish a player
//****************
// TODO: is not working!
// command: write banish <name>, write banish
banish(string name) {
  if (name!=0) {
    ban_member(name);
  } else {
    write("Some words appear on the desk:\n"
      "Which player should be banished from the list of members?\n"
      "Write the name or press <enter> to leave:\n]");
    input_to("ban_member");
  }
}

ban_member(string str) {
  if (str=="" || str=="~q") {
    write("You don't change the list of members.\n");
    smore_finished();
    return;
  }
  write("Enter a reason for the banishing:\n]");
  banname=str;                     // store the name (global) :((
  input_to("ban_reason");
}

ban_reason(string str) {
  string ban;
  if (str=="" || str=="~q") {
    write("You don't change the list of members.\n");
    smore_finished();
    return;
  }
  ban = lower_case(banname)+" "+str+"\n";
  MAINGUILD->cmd_banish(ban);
  write("You banish "+CAP(banname)+".\n");
}

//******************
// unbanish a player
//******************
// command: write unbanish <name>, write unbanish
unbanish(string name) {
  if (name!=0) {
    unban_member(name);
  } else {
    write("Some words appear on the desk:\n"
      "Which player should be banished from the list of members?\n"
      "Write the name or press <enter> to leave:\n]");
    input_to("unban_member");
  }
}

unban_member(string str) {
  string unban;
  if (str=="" || str=="~q") {
    write("You don't change the list of members.\n");
    smore_finished();
    return;
  }
  unban = lower_case(str);
  MAINGUILD->cmd_unbanish(unban);
  write("You unbanish "+CAP(str)+".\n");
}

//************
// goto player
//************
goto_member(string name) {
  write("Not yet implemented - sorry.\n");
}

//******************
// add new commander
//******************
add_new_gl(string name) {
  write("Not yet implemented - sorry.\n");
}

//*********************
// write desk commands:
//*********************

int write_desk(string str) {
  string norm,name;
  string *s;
  if (!str) {
    notify_fail("Use a command after write - like 'write banish'\n");
    return 0; }
  norm=norm_id(str);
  s=explode(norm," ");
  name=0;                           // default value
  if (sizeof(s)==2) { name=s[1]; }
  if (sizeof(s)>2) { write("Extra value is ignored!\n"); }
  show(NAME+" operates with the desk.\n");
  switch (s[0]) {
    case "gone":     gone(name); break;
    case "rem":      rem(name); break;
    case "banish":   banish(name); break;
    case "unbanish": unbanish(name); break;
    case "add":      add_new_gl(name); break;
    case "goto":     goto_member(name); break;
    default:
      notify_fail(
      "Use one of the standard commands! (press the white button)!\n");
      return 0;
  }
  return 1;
}


//*******************************
// press <color> button (of desk)
//*******************************
int pressbutton(string s) {
  string str;
  if (!s) { notify_fail("Press what?\n"); return 0; }
  str=norm_id(s);
  switch (str) {
    case "button": case "button on desk": case "button of desk": {
      write("Use: press <colored> button (of desk)\n");
      return 1;
    }
    case "white button": case "white button of desk": {
      write("You press the white button.\n");
      other_commands(); return 1;
    }
    case "green button": case "green button of desk": {
      write("You press the green button.\n");
      list(); return 1;
    }
    case "red button": case "red button of desk": {
      write("You press the red button.\n");
      aggressors(); return 1;
    }
    case "black button": case "black button of desk": {
      write("You press the black button.\n");
      killers(); return 1;
    }
  }
  notify_fail("Press what?\n");
  return 0;
}


//************
// create room
//************
create()
{
  ::create();
  chairs=({""});

  /* decriptions and details */
  SetIntShort("The guildleader room");
  SetIntLong(
    "This is the wonderful guildleader room of the madmonk dojo.\n"
    "To the left stands some wooden chairs, to the south a desk and\n"
    "north can be seen a window.\n");

  /* detail handling */
  AddDetail(({"guildleader room","wonderful guildleader room"}),#'IntLong);
  AddDetail(({"ceiling","above"}),
    "The ceiling is around 3 metres above you.\n");
  AddDetail("ground","The ground is built from wooden planks.\n");
  AddDetail(({"plank","wooden plank"}),
    "An oak plank. It is nailed to some other planks.\n");
  AddDetail(({"planks","wooden planks","some wooden planks","some planks"}),
    "The ground consists of some wooden planks.\n");

  AddDetail(({"chair","wooden chair"}),#'lookchair);
  AddDetail(({"chairs","wooden chairs","some chairs","some wooden chairs"}),
    #'lookchairs);
  AddDetail(({"left","to left","to the left"}),
    "There are standing some chairs.\n");

  AddDetail(({"south","to south","to the south"}),
    "A desk stands there - looks interesting.\n");
  AddDetail("desk",
    "On the desk you found some buttons and a lever.\n");
  AddDetail(({"lever","lever of desk","lever from desk"}),#'looklever);

  AddDetail(({"buttons","some buttons","buttons on desk",
    "some buttons on desk","buttons of desk","some buttons of desk"}),
    "The buttons have different colors and labels:\n"
    "    white button  - 'other commands'\n"
    "    green button  - 'list'\n"
    "    red button    - 'aggressors'\n"
    "    black button  - 'killers'\n"
    "Look at the button itself to get more informations.\n"
    "   (Be careful with these commands!)\n");
  AddDetail(({"button","button on desk","button of desk"}),
    "Try to look at <color> button (of desk).\n");
  AddDetail(({"white button","white button of desk"}),
    "Pressing the white button will show some other commands.\n");
  AddDetail(({"green button","green button of desk"}),
    "Press the green button for a list of all members of the guild.\n");
  AddDetail(({"red button","red button of desk"}),
    "Pressing the red button will show who misused guildpowers to attack\n"
    "players.\n");
  AddDetail(({"black button","black button of desk"}),
    "A pressed black button will show all player killer.\n");

  /* room specific */
  SetIndoors(1);
  AddExit("east",MONKROOM("library") ); 

  /* room commands */
  AddRoomCmd("sit","sit");             // sit down on chair
  AddRoomCmd("stand","standup");       // stand up
  AddRoomCmd("pull","pulllever");      // pull lever (of desk)
  AddRoomCmd("press","pressbutton");   // press a button
  AddRoomCmd("write","write_desk");    // write desk -> command
}

//*******************************
// entering and leaving this room
//*******************************
// forbid entering for non HLP Madmonks
allow_enter(int method, mixed extra) {
  if (!interactive(PO)) return ME_OK;   // all non player (npc,items,...)
  if (IS_IMMORTAL(PO)) return ME_OK;     // wizzes allowed
  if ((PO->QueryGuild()==GC_MADMONKS) && MAINGUILD->is_leader(PO))
    return ME_OK;                       // GL madmonks allowed too 
  return ME_NO_ENTER;                   // forbid all others
}

// do not leave the room as long as you are sitting on a chair!
int prevent_leave (object dest, int method, mixed extra) {
  object who2;
  if (!PO) return 0;
  if (member(chairs,PO->QueryRealName()) == -1) {
    return 0;
  }
  // sits on a chair!
  tell_object(PO,"First you have to stand up!\n");
  show(NAME+" has to stand up before leaving this room.\n");
  return ME_NO_LEAVE;
}

// only needed for the mudlib - else a remove will throw you out of the mud!
remove() {
  ::remove();
  chairs=({""});
}

