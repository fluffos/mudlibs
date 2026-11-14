// part of the Madmonks Guild
// made MagicTCS - 8 may 97
// questroom - library - all quests are known here, and some other infos

#include <properties.h>
#include <rooms.h>
#include <guild.h>
#include <skills.h>
#include <config.h>

#ifdef ONESTEPBEYOND
#include <secure/wizlevels.h>
#else
#include <wizlevels.h>
#endif

#include <moving.h>
#include <npc.h>
#include "/p/guilds/madmonks/madmonks.h"

#define SLIB "/lib/string"

inherit BASISROOM;

int scroll;

//********************
// properties handling
//********************

int QueryScroll() { return scroll; }
void SetScroll(int i) { scroll=i; }

int lists_guild_quests() {

}

int list_guild_quest(int num) {

}

//***************
// detailhandling
//***************
// look at quest scroll
string lookquestscroll() {
  if (present("okazi")) return
    "Ask Okazi, the librarian, to get the scroll of quests.\n";
  return
  "Take the scroll of quests and read it!\n";
}

// look at skill scroll
string lookskillscroll() {
  if (present("okazi")) return
    "Ask Okazi, the librarian, to get the scroll of skills.\n";
  return
  "Take the scroll of skills and read it!\n";
}

// look at other scroll
string lookotherscroll() {
  if (present("okazi")) return
    "Okazi, the librarian, is able to give the other scrolls to you.\n"
    "Ask him about them!\n";
  return
  "Take the scroll you want and read it!\n";
}

string lookallscrolls() {
  string ret; 
  ret="There is a scroll of quests and a scroll of skills and around\n"+
    sizeof(QUESTMASTER->QueryQuests())+" scrolls with questdescriptions.\n";
  if (!scroll) ret+="One scroll of them is hold by a player.\n";
  return ret;
}

//********
// gettake
//********
int gettake(string s) {
  string str,where;
  int num,maxq;
  object ob;
  if (!s) return 0;
  str=norm_id(s);
  // check for test of Okazi is present ???!!
  if (member(({"scroll of quests","scroll of quests from shelf",
               "scroll of quests from wooden shelf"}),str)!=-1) {
    if (present("mmscroll",TP)) {
      write("Please return the other scroll first!\n");
      return 1;
    }
    if (!scroll) return 0;
    ob=clone_object(GUILDOBJ("questscroll"));
    TP->Take(ob,PUTGET_FULL);
    scroll--;
    return 1;
  }
  if (sscanf(str,"scroll %d%s",num,where)==2) {
    if (present("mmscroll",TP)) {
      write("Please return the other scroll first!\n");
      return 1;
    }
    if (!scroll) return 0;
    maxq=sizeof(QUESTMASTER->QueryQuests());
    if (num>maxq || num<1) { return 0; }
    ob=clone_object(GUILDOBJ("questscrollx"));
    ob->SetNumber(num);
    TP->Take(ob,PUTGET_FULL);
    scroll--;
    return 1;
  }
  if (member(({"scroll of skills","scroll of skills from shelf",
               "scroll of skills from wooden shelf"}),str)!=-1) {
    write("This scroll is not available yet.\n");
    return 1;
  }
  if (member(({"scroll from shelf","scrolls from shelf"}),str)!=-1) {
      write("Which scroll do you want to take?\n");
      return 1;
  }
  if (member(({"all scrolls from shelf",
               "all scrolls from wooden shelf"}),str)!=-1) {
      write("Only one scroll can be taken at the time.\n");
      return 1;
  }

  return 0;  
}

//**************************
// return the scroll command
//**************************
int returnscroll(string str) {
  object ob;
  ob=present("mmscroll",TP);
  if (!str) { notify_fail("Return what?\n");  return 0; }
  if (str=="scroll" && ob) {
    write("You put the scroll back into the shelf.\n");
    show(NAME+" return on scroll.\n");
    ob->remove();
    return 1;
  }
  notify_fail("Return what?\n");
  return 0;
}

//************
// room create
//************
public void create()
{
  ::create();
  scroll=1;                         // nobody holds it

  SetIntShort("A madmonks library");
  SetIntLong(
    "You are entered the library of the madmonks.\n"
    "A wooden shelf is standing near the wall.\n"
    "To the west is the guildleader room of the guild.\n");
  AddDetail(({"madmonks library","madmonk's library","library"}),#'IntLong);
  AddDetail("west","To the west can be seen the guildleaderroom.\n");
  AddDetail("guildleader room","It is to the west.\n");

  /* details */
  AddDetail(({"wall","one wall"}),
    "It is made of brown paper. An old papyrus is hanging on it.\n");
  AddDetail("walls",
    "All walls are made of the same old brown paper. One wall is a little\n"
    "bit more interesting.\n");
  AddDetail(({"paper","brown paper","old paper","old brown paper"}),
    "All walls consist of this paper (as each house in japan).\n");

  AddDetail(({"shelf","wooden shelf"}),
    "It is made of oak wood and there are some scrolls on it.\n");
  AddDetail(({"scroll"}),
    "Which scroll do you mean? The scroll of quests or the scroll of\n"
    "skills or one of the others?\n");
  AddDetail(({"scroll of quests"}),#'lookquestscroll);
  AddDetail(({"scroll of skills"}),#'lookskillscroll);
  AddDetail(({"other scrolls","other scroll"}),#'lookotherscroll);
  AddDetail(({"scrolls","some scrolls","some scrolls from shelf",
    "some scrolls from wooden shelf"}),#'lookallscrolls);

  SetIndoors(1);

  AddExit("east",MONKROOM("commroom"));
  AddExit("west",MONKROOM("glroom"));
  AddExit("south",MONKROOM("skilltrain"));

  AddRoomCmd("get",#'gettake);
  AddRoomCmd("take",#'gettake);
  AddRoomCmd("return",#'returnscroll);

  AddItem(MONKNPC("okazi"),REFRESH_DESTRUCT);
}

//**************************
// entering and leaving room
//**************************
// forbid entering for non Madmonks
allow_enter(int method, mixed extra) {
  if (!interactive(PO)) return ME_OK;   // all non player (npc,items,...)
  if (IS_IMMORTAL(PO)) return ME_OK;     // wizzes allowed
  if (PO->QueryGuild()==GC_MADMONKS)
    return ME_OK;                       // madmonks allowed
  return ME_NO_ENTER;                   // forbid all others
}

// forbid leaving the room, if you are holding one of the scrolls!
int prevent_leave (object dest,int method,mixed extra) {
  if (present("mmscroll",PO)) {
    if (present("okazi")) {
      write("Okazi says: Hey - give the scroll back please!\n"
            "  I can't let you go with it!\n");
      show(NAME+" wants to leave the library, but is hold by Okazi.\n");
    } else {
      tell_room(TO,
        "Balgarion stomps out of a shadow and speaks to you:\n"
        "  Just let the scroll here for other people. They want read \n"
        "  the scroll too!\n"
        "Balgarion vanishes with these words.\n");
    }
    return ME_NO_LEAVE;
  }
  return ::prevent_leave(dest,method,extra);
}

// scroll is dropped into the room -> remove it and reset the counter
void notify_enter(object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  if (member(PO->QueryIds()||({}),"mmscroll") != -1) {
    call_out("remove_scroll",1,PO);
  }
}

// delay of 1 secs needed
void remove_scroll(object ob) {
  if(present("okazi")) {
    tell_room(TO,
      "Okazi takes quickly "+ob->QueryShort()+
      " and returns it into the shelf.\n");
  } else {
    tell_room(TO,
      "Balgarion steps out of the shadows and grummels a little bit.\n"
      "He takes "+ob->QueryShort()+" and returns it into the shelf.\n"
      "Then he vanishes in a puff of smoke.\n");
  }
  ob->remove();
  scroll=1;
}

reset() {
  ::reset();
  scroll=1;
}

