// a library for our city - to come here, you have to break the window
// to the south
// made MagicTCS - 26 may 97
// TODO: update coords

#include <properties.h>
#include <rooms.h>
#include <guild.h>
#include <skills.h>
#include <config.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;
inherit "/obj/lib/string";

string *scrolls;

//******************
// property handling
//******************
string *QueryScrolls() { return scrolls; }

//****************
// detail handling
//****************
string lookallscrolls() {
  int i;
  string ret;
  string *exp;
  ret=
  "There are some different scrolls in the shelf near the wall.\n"
  "You can take them if you use the short title:\n";
  if (sizeof(scrolls)>0) {
    ret+=ladjust("Short titles:",15)+" - Long titles:\n";
    for (i=0;i<sizeof(scrolls);i++) {
      exp=explode(scrolls[i]," - ");
      ret+=ladjust(exp[0],15)+" - "+exp[1]+"\n";
    }
  }
  smore(ret,TP->QueryPageSize());
  return " ";
}

// needs more than 2 scrolls! (because handling of "," and "or"
string lookscroll() {
  int i;
  string ret;
  string *exp;
  ret=
  "Which scroll do you mean - ";
  if (sizeof(scrolls)>0) {
    for (i=0;i<(sizeof(scrolls)-2);i++) {
      exp=explode(scrolls[i]," - ");
      ret+=exp[0]+", ";
    }
  }
  exp=explode(scrolls[i]," - ");
  ret+=exp[0];
  exp=explode(scrolls[i+1]," - ");
  ret+=" or "+exp[0]+"?\n";
  return ret;
}

// look at special scroll
string GetDetail (string id) {
  int i;
  string *exp;
  string ret;
  ret=::GetDetail(id);                 // is there a predefined detail?
  if (ret!=0) return ret;              // one of the normal details
  for (i=0;i<sizeof(scrolls);i++) {
    exp=explode(scrolls[i]," - ");
    if (strstr(id,exp[0])==-1) continue;
    ret="This scroll has information about: "+exp[1]+"\n";
    break;
  }
  return ret;
}

//******************
// take/get handling
//******************
int gettake(string str) {
  object ob;
  int i;
  string *exp;
  string file;
  if (!str) return 0;
  for (i=0;i<sizeof(scrolls);i++) {
    exp=explode(scrolls[i]," - ");
    if (strstr(str,exp[0])!=-1) {
      ob=clone_object(OBJ("libscrollx"));
      ob->SetThemeShort(exp[0]);
      ob->SetThemeLong(exp[1]);
      file=exp[2];                  // cut "\n" at the end :(
      file[strlen(file)-1]=0;
      ob->SetFile(TXT(file));
      TP->Take(ob,PUTGET_FULL);
      return 1;
    }
  }
  return 0;
}

//**************************
// return the scroll command
//**************************
int returnscroll(string str) {
  object ob;
  if (!str) { notify_fail("Return what?\n");  return 0; }
  ob=present(str,TP);
  if (ob && ob->id("libscroll")) {
    write("You put the scroll back into the shelf.\n");
    show(NAME+" returns a scroll.\n");
    ob->remove();
    return 1;
  }
  notify_fail("Return what?\n");
  return 0;
}

//*************
// enter window
//*************
// TODO: maybe add another exit if the window is closed? (no check yet)
int enterwindow(string str) {
  if (!str) return 0;
  if(str!="window") return 0;
  write("You reach for the window and try to climb into it.\n");
  return TP->move(SYKORATH("mainroadnw"),M_GO,"enters the window");
}

//************
// room create
//************
create()
{
  int i;
  string tmp;
  ::create();
  scrolls=({});
  SetIntShort("A library");
  SetIntLong(
    "It is the library of the town. To the south is an window.\n"
    "A wooden shelf is standing near the wall.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"library"}),#'IntLong);
  AddDetail("west","To the west can be seen the guildleaderroom.\n");
  AddDetail("guildleader room","It is to the west.\n");

  AddDetail("south","There is a window in the wall.\n");
  AddDetail("window","It is the one where you come from.\n");
  AddDetail(({"wall"}),
    "A wall made of dark stones. A shelf is standing near the wall.\n");
  AddDetail(({"stone","stones","dark stone","dark stones"}),
    "A really dark stone. You never seen such a dark stone somewhere.\n");
  AddDetail("walls",
    "The walls belong to the library of the town.\n");
  AddDetail(({"shelf","wooden shelf"}),
    "It is made of oak wood and there are some scrolls on it.\n");
  AddDetail(({"scroll"}),#'lookscroll);
  AddDetail(({"scrolls","some scrolls","some scrolls from shelf",
    "some scrolls from wooden shelf","some scrolls of shelf",
    "some scrolls of wooden shelf","scrolls of shelf","scrolls from shelf"
    "scrolls of wooden shelf","scrolls from wooden shelf"}),#'lookallscrolls);
  AddReadMsg(({"scrolls","some scrolls","some scrolls from shelf",
    "some scrolls from wooden shelf","some scrolls of shelf",
    "some scrolls of wooden shelf","scrolls of shelf","scrolls from shelf"
    "scrolls of wooden shelf","scrolls from wooden shelf"}),
    "You have to take the scroll you want to read.\n");

  SetIndoors(1);

  AddItem(NPC("purzel"),REFRESH_HOME);

  /* exits */
  AddExit("enter",#'enterwindow);
  AddNowayMsg("enter","Enter where? (maybe the window?)\n");

  /* commands */
  AddRoomCmd("get",#'gettake);
  AddRoomCmd("take",#'gettake);
  AddRoomCmd("return",#'returnscroll);

  /* initialize the scrolls - array */
  /* read the index file and put all liney into the array */
  for (i=1;;i++) {
    tmp=read_file(TXT("index.txt"),i,1);
    if (tmp=="") break ;
    scrolls+=({tmp});
  }
}

//**************************
// enter/leave room handling
//**************************

// forbid leaving the room, if you are holding one of the scrolls!
int prevent_leave (object dest,int method,mixed extra) {
  if (present("libscroll",PO)) {
    if (present("purzel")) {
      write(
        "Purzel says: Hey - give the scroll from the library back please!\n"
        "  I can't let you go with it!\n");
      show(NAME+" wants to leave the library, but is hold by Purzel.\n");
    } else {
      tell_room(TO,
        "A voice speaks to you from hell:\n"
        "  Just let the scroll from the library here for other people. They\n"
        "  want to read the scroll too!\n");
    }
    return ME_NO_LEAVE;
  }
  return ::prevent_leave(dest,method,extra);
}

// scroll is dropped into the room -> remove it and reset the counter
void notify_enter(object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  if (PO->id("libscroll")) call_out("remove_scroll",1,PO);
}

// delay of 1 secs needed
void remove_scroll(object ob) {
  if(present("purzel")) {
    tell_room(TO,
      "Purzel takes quickly "+ob->QueryShort()+
      " and returns it into the shelf.\n");
  } else {
    tell_room(TO,
      "A ghost steps out of the shadows and grummels a little bit.\n"
      "He takes "+ob->QueryShort()+" and returns it into the shelf.\n"
      "Then he vanishes in a puff of smoke.\n");
  }
  ob->remove();
}

