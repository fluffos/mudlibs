// the hlp room for the madmonks guild
// made by Magictcs - 7 may 97
// the room will log all missing details

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

#define HLPLEVEL 20
#define HLP_NOTE_FILE        "/p/guilds/madmonks/log/hlp_log.txt"

inherit BASISROOM;           // autolog details to logdir

string * chairs;  // stores the real names of all players sitting on chairs
string * resting; // array for resting players

int pencil;                  // pencil on table
int feather;                 // searched the chair?

//***********************
// handling of the chairs
//***********************
// sit on chair 
int sit(string s) {
  string str;
  notify_fail("Sit down on what?\n");
  if (!s) return 0;
  str=norm_id(s);
  if (str=="down on chair" || str=="down on wooden chair") {
    if (member(chairs,TP->QueryRealName())!=-1) {
      write("You are already sitting on the chair.\n");
      return 1;
    }
    write("You sit down on a chair. Now you can rest for a while.\n");
    show(NAME+" sits down on a chair.\n");
    chairs+=({TP->QueryRealName()});
    return 1;
  }
  return 0;
}

// stand up, if you sit on a chair
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

string looktable() {
  if (pencil) return
    "It is made of oak and of normal height. There are some papers and a \n"
    "pencil on the table.\n";
  return
    "It is made of oak and of normal height. There are some papers on it.\n";
}

string lookpencil() {
  if (pencil) return "You can write notes with it.\n";
  return 0;
}

string lookpencils() {
  if (pencil) return "There is only one pencil on the table.\n";
  return 0;
}

string lookfeather() {
  if (feather) return "A little feather, not useful at all.\n";
  return 0;      // not searched the chair
}

//************************
// a simple search command
//************************
int search(string str) {
  if (!str) return ::search(str);
  switch (str) {
    case "equipment":
    case "some equipment":
    case "comfortable equipment":
    case "some comfortable equipment": {
      write("You should search them step by step!\n");
      return 1;
    }
    case "ground":
      write("You find nothing special - what else did you expect?\n");
      show(NAME+" searches the ground.\n");
      return 1;
    case "chair":
    case "chairs":
    case "wooden chair":
    case "wooden chairs":
    case "some chairs":
    case "some wooden chairs":
      write(
      "You find a little feather. But you don't need it and you let it here.\n");
      show(NAME+" searches the chairs.\n");
      feather++;
      return 1;
    case "table":
      write(
      "You find a pencil and some papers. Just look at them!\n");
      show(NAME+" searches the table.\n");
      return 1;
  }
  return ::search(str);
}

//****************
// resting command
//****************
// resting: - for 'xprop $h' :)
string *QueryResting() { return resting; }

// remove the name from the array of resting players
void stop_resting(string who) { resting-=({who}); }

// rest - restores some HP
int rest(string str) {
  string who;
  if (str) {
    notify_fail("Try a simple 'rest'.\n");
    return 0;
  }
  who=TP->QueryRealName();
  // do something special?
  if (member(chairs,who)==-1) {
    write("First sit down on the bench.\n");
    return 1;
  }
  if (member(resting,who)==-1) {
    write("You rest for a while.\n");
    show(NAME+" rests for a while.\n");
    TP->HealHP(random(10)+2);
    resting+=({who});
    call_out("stop_resting",30,who);
  }
  else {
    write("You are still resting.\n");
    show(NAME+" is still resting.\n");
  }
  return 1;
}

//******************
// take/get handling
//******************
int gettake(string s) {
  string str;
  object ob;
  if (!s) return 0;
  str=norm_id(s);
  switch (str) {
    case "pencils":
    case "pencils from table":
    case "pencils from the table": {
      if (pencil) write("There is only one pencil here.\n");
      else write("There is no pencil here - someone grabbed him before.\n");
      return 1;
    }
    case "pencil":
    case "pencil from table":
    case "pencil from the table": {
      if (pencil) {
        ob=clone_object("/std/thing");
        ob->SetProperties( ([
            P_SHORT: "a pencil",
            P_LONG:
              "A small but beautiful pencil. You need it to leave a note "
              "in the madmonks guild.\n",
            P_IDS: ({"pencil","mm_pencil"}),
            P_ADS: ({"small","beautiful"}),
            P_HELP_MSG: "Usage: leave note (will works only in the HLP-room "
                        "of the madmonks guild!\n",
            P_VALUE: 33,
            P_WEIGHT: 27
        ]) );
        this_player()->Take(ob,PUTGET_FULL);
        pencil--;
        return 1;
      }
      break;
    }
    case "paper":
    case "papers":
    case "papers from table":
    case "papers from the table":
    case "paper 1": case "paper 1 from table":
    case "paper 1 from the table":
    case "paper 2":
    case "paper 2 from table":
    case "paper 2 from the table":
    case "paper 3":
    case "paper 3 from table":
    case "paper 3 from the table": {
      switch (TP->Query("MM_HLP_READ")) {
        case 0: {
        write(
        "Balgarion steps out of the shadows and show you his middle finger:\n"
        "  \"There are some other people who want to read these papers too.\n"
        "   Don't take the paper with you!\"\n"
        "   You are warned!\n"
        "Then he vanished again in a huge lightning bolt.\n");
        TP->Set("MM_HLP_READ",1);
        return 1;
        }
        case 1: {
        write(
        "Balgarion steps out of the shadows and show you his middle finger:\n"
        "  \"Hey didn't you understand me?. I said - leave the papers here!\n"
        "   This is my last warning!\"\n"
        "Then he vanished again in a huge lightning bolt.\n");
        TP->Set("MM_HLP_READ",2);
        return 1;
        }
        default: {
        write(
        "Balgarion steps out of the shadows and is very angry:\n"
        "  \"You should hear what your Master says!\n"
        "Then he vanished again in a huge lightning bolt but the lightning "
        "bolt burns your flesh.\n");
        TP->Defend(random(5)+10,DT_FIRE,DEFEND_F_NOMSG);
        return 1;
        }
      }
    }
    case "feather":
    case "feather from chair": {
      write("You don't need it - so you don't get it.\n");
      return 1;
    }
  }
  return 0;
}

//****************
// read paper msgs
//****************
// 1 and 2 made by AddReadMsg
string readpaper1() {
  return
  "You read the old paper:\n"
  "/------------------------------------------------------------------\\\n"
  "| In the beginning there was a very delicate time....              |\n"
  "| There were only two races - humans and orcs.                     |\n"
  "\\------------------------------------------------------------------/\n";
}

string readpaper2() {
  return
  "You read the second paper:\n"
  "/------------------------------------------------------------------\\\n"
  "| Two mighty wizards tried to found a solution for all evil people |\n"
  "| who wants to be evil and very evil and very very evil ....       |\n"
  "|                                                                  |\n"
  "| And so they founded the MADMONKS guild - a guild for evil        |\n"
  "| minded people.                                                   |\n"
  "|   signed: Balgarion and Magictcs                                 |\n"
  "\\------------------------------------------------------------------/\n";
}

// made by AddRoomCmd !!
int readpaper3(string s) {
  string page;
  if (!s) return 0;
  page=norm_id(s);
  if (page=="paper 3") {
    page=
    "+------------------------------------------------------------------+\n";
    page+=read_file(HLP_NOTE_FILE);
    page+=
    "+------------------------------------------------------------------+\n";
    "/lib/string"->smore(page);
    return 1;
  }
  return 0;
}

//*******************
// leave note command
//*******************
int leave(string str) {
  if (!str) { write("Use: leave note\n"); return 1; }
  if (str=="note") {
    if (present("pencil",TP)) {
      if (member(chairs,TP->QueryRealName())==-1) {
        write("First take a sit on a chair!\n");
        return 1;
      }
      write("Please enter your line or ~q for quit.\n]");
      input_to("getnote");
      return 1;
    } else {
      write("You need a pencil for leaving a note.\n");
      return 1;
    }
  }
  write("Use: leave note\n");
  return 1;
}

// TODO: allow adding of  more than one line?!
getnote(string str)
{
  string file;

  switch (str) {
  case "~q":
  case "":
    write("You didn't entered any text.\n");
    return;
  }
  write_file(HLP_NOTE_FILE,CAP(REALNAME)+": "+str+"\n");
  write("Now you can read the updated paper 3.\n");
}



//************
// create room
//************
create()
{
  ::create();
  chairs=({""});
  resting=({""});
  pencil=1;
  feather=0;

  /* decriptions and details */
  SetIntShort("The room of the Lords");
  SetIntLong(
    "You are standing in the room of the Lords.\n"
    "It is the only room with some comfortable equipment in it - like a\n"
    "table of normal height,....\n"
    "Some wooden chairs are standing to the left.\n");

  /* detail handling */
  AddDetail(({"room of lords","only room","the room"}),#'IntLong);
  AddDetail("ceiling","The ceiling is around 3 metres above you.\n");
  AddDetail("ground","The ground is built from wooden planks.\n");
  AddDetail(({"plank","wooden plank"}),
    "An oak plank. It is nailed to some other planks.\n");
  AddDetail(({"planks","wooden planks","some wooden planks","some planks"}),
    "The ground consists of some wooden planks.\n");
  AddDetail(({"comfortable equipment","some comfortable equipment",
    "some equipment","equipment"}),
    "There is a table, some wooden chairs to the left, ....\n");

  AddDetail(({"table","table of oak","oak table"}),#'looktable);
  AddDetail(({"oak","oak wood"}),"You can find many oaks in OSB.\n");
  AddDetail(({"papers","some papers","papers on the table",
    "papers on table","some papers on the table","some papers on table"}),
    "You can read the papers! Maybe you can leave a note here.\n");
  AddDetail(({"paper","paper on the table","paper on table"}),
    "There are some papers on the table, not only one!\n");
  AddReadMsg(({"papers","some papers","papers on the table",
    "papers on table","some papers on the table","some papers on table",
    "paper","paper on the table","paper on table"}),
    "Which paper do you want to read - 1, 2 or 3?\n"
    "Use: read paper <number>\n");
  AddDetail(({"paper 1","paper 2"}),
    "An old paper. You can read it!\n");
  AddDetail("paper 3",
    "This paper contents the notes of our high level players.\n");
  AddReadMsg("paper 1",#'readpaper1);
  AddReadMsg("paper 2",#'readpaper2);
  AddRoomCmd("read",#'readpaper3);      // needed because SMORE

  AddDetail(({"pencil","pencil on the table","pencil on table"}),#'lookpencil);
  AddDetail(({"pencils","pencils on the table","pencils on table"}),
    #'lookpencils);

  AddDetail(({"chair","wooden chair"}),#'lookchair);
  AddDetail(({"chairs","wooden chairs","some chairs","some wooden chairs"}),
    #'lookchairs);
  AddDetail(({"left","to left"}),
    "There are standing some chairs.\n");
  AddDetail(({"feather","little feather"}),#'lookfeather);

  SetIndoors(1);
  AddExit("east",MONKROOM("skilltrain") ); 

  /* a hlpboard */
  AddItem("/std/board",REFRESH_HOME,
   ([P_SHORT:"The HLP board",
     P_LONG:
       "This board is connected to the HLP board of OSB.\n",
     "Groups":({"players.hlp"}),
   ]));

  /* room commands */
  AddRoomCmd("sit","sit");             // sit down on chair
  AddRoomCmd("stand","standup");       // stand up
  AddRoomCmd("search","search");       // search xxx
  AddRoomCmd("rest","rest");           // rest
  AddRoomCmd("get","gettake");         // get xxx
  AddRoomCmd("take","gettake");        // take xxx
  AddRoomCmd("leave","leave");         // leave note
}

//*******************************
// entering and leaving this room
//*******************************
// reset the get paper msg :)
void notify_enter (object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  if (interactive(PO)) PO->Set("MM_HLP_READ",0);
  if (member(PO->QueryIds()||({}),"mm_pencil") != -1) {
    call_out("remove_pencil",1,PO);
  }
}

// delay of 1 secs needed
void remove_pencil(object ob) {
  tell_room(TO,
    "Wow - As you drop the pencil - it lifts into the air and flies back to\n"
    "the table.\n");
  ob->remove();
  pencil=1;
}


// forbid entering for non HLP Madmonks
allow_enter(int method, mixed extra) {
  if (!interactive(PO)) return ME_OK;   // all non player (npc,items,...)
  if (IS_IMMORTAL(PO)) return ME_OK;     // wizzes allowed
  if ((PO->QueryGuild()==GC_MADMONKS) && (PO->QueryLevel() > HLPLEVEL))
    return ME_OK;                       // HLP madmonks allowed too 
  return ME_NO_ENTER;                   // forbid all others
}

// do not leave the room as long as you are sitting on a chair!
int prevent_leave (object dest, int method, mixed extra) {
  object who2;
  if (!PO) return 0;
  if (member(chairs,PO->QueryRealName()) == -1) {
    if (present("mm_pencil",PO)) {
      tell_object(PO,"A voice remembers you to let the pencil here.\n");
      return ME_NO_LEAVE;
    }
    return 0;
  }
  // sits on a chair!
  tell_object(PO,"First you have to stand up!\n");
  show(NAME+" has to stand up before leaving this room.\n");
  return ME_NO_LEAVE;
}

//******
// reset
//******
// only needed for the mudlib - else a remove will throw you out of the mud!
remove() {
  ::remove();
  chairs=({""});
  resting=({""});
  pencil=1;
  feather=0;
}

