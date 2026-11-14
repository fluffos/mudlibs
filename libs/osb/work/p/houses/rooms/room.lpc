/*
  The prototype for the house room
  made by Magictcs - sept 1997

  This file is for inheriting only !

  The house room allows the owner and the coowner to change nearly the
  whole room, especially exits to other rooms, doors, details and items
  (normal and vitems!)

  The datas needed for storing these values are put into a file:
    "/d/domain/.../houses/houseownername/xyz.o"
  The data is loaded by restore_object() and saved by save_object()
*/

// know bugs:
// item handling is buggy!!! a saved and loaded savefile results in adding
// the items more then one time :(
// lightlevel is not saved actually!

//********************
// the needed includes
//********************
#include <properties.h>
#include <rooms.h>
#include <moving.h>
#include "/p/houses/houses.h"            // yes it is a house to buy :)

//********************
// the inherited files
//********************
inherit "/std/room";
inherit "/lib/string";

//***********
// variables:
//***********

// restore_object and save_object datas:
// (just only temporarily available!, but has to be global variables)
mapping house_details;
mapping house_exits;
mixed   *house_items;
mapping house_doors;
mapping house_vitems;
int house_vitemcounter;

// normal user datas:
string owner;                              // owner of the house
string *coowner;                           // co-owner of the house
string *allowed;                           // allowed players

//************
// Prototypes:
//************
int loadme();
int saveme();

//*******
// create
//*******
// create the room and restores the stored data, if available
// checks some other properties!
create() {
  ::create();
  SetIntShort("An empty room");
  SetIntLong("An empty room inside an house:\n"
    "  loadme - loads the variables\n"
    "  saveme - saves them\n"
  );
  SetIndoors(1);                            // yes it is inside

  // available room commands inside the house:
  AddRoomCmd("allow","allow");              // allow other to enter
  AddRoomCmd("forbid","forbid");            // forbid entering
  AddRoomCmd("set","set_privacy");          //
  AddRoomCmd("private","is_private");       //
  AddRoomCmd("coowner","coowner");          // add new coowner
  AddRoomCmd("remove","removecoowner");     // remove coowner

  AddRoomCmd("dig","dig");                  // add new room
  AddRoomCmd("close","close");              // close a direction
  AddRoomCmd("hide","hide");                // hide an exit
  AddRoomCmd("unhide","unhide");            // unhide an exit

  AddRoomCmd("setname","setname");          // set the IntShort of the room
  AddRoomCmd("setfull","setfull");          // set the IntLong of the room

  AddRoomCmd("adddetail","adddetail");      // add new details
  AddRoomCmd("removedetail","removedetail");// remove detail
  AddRoomCmd("addnoise","addnoise");        // adds noises
  AddRoomCmd("removenoise","removenoise");  // removes the noise
  AddRoomCmd("addsmell","addsmell");        // adds smells
  AddRoomCmd("removesmell","removesmell");  // removes smells
  AddRoomCmd("addread","addread");          // adds smells
  AddRoomCmd("removeread","removeread");    // removes smells
  AddRoomCmd("setlight","setlight");        // sets the light level      
  AddRoomCmd("smash","smash");              // smash furniture
  AddRoomCmd("show","show");                // show room infos

  AddRoomCmd("move","move");                // move items to another room

// to be removed!:
  AddRoomCmd("loadme","loadme");
  AddRoomCmd("saveme","saveme");

// remove the details here later!!
  // two details for testing:
//  AddDetail("blupp","A test blupp");
//  AddDetail("table","A test table");

// and remove the items too!
  // and items:
//  AddItem("/obj/torch",REFRESH_REMOVE);
//  AddItem("/std/weapon",REFRESH_REMOVE);

// and of course the exits too!
  // two dummy exits for testing:
  AddExit("north","/d/dummy/north");
  AddExit("west","/d/dummy/west");

  // initialize the user datas:
  owner=0;                      // none
  coowner=({});                 // none
  allowed=({});                 // none

  if (file_size(object_name()+".o")>0)          // save-file exists
    loadme();                                 // well then load it :)
}

//****************
// secure handling
//****************
// return 1 if allowed, return 0 if not allowed
// pl - player to check
// co - 1 if coowner is allowed too, 0 if coowner are not allowed
int Allowed(object pl,int co) {
  string rname;
  if (!pl) return 0;                              // no object
  if (!interactive(pl)) return 0;
  rname=pl->QueryRealName();
  if (rname==owner) return 1;                     // owner allowed
  if (co && member(coowner,rname)!=-1) return 1;  // co-owner allowed too
  return 0;                                       // others - not allowed
}

//*********
// SetOwner
//*********
// sets the owner of the house (there can be only one!)
// called inside the creation of the room for the first time!
string SetOwner(string rname) {
  if (!rname) return 0;
  if (!find_player(rname)) return 0;
  owner=rname;
  return owner;
}

//***********
// QueryOwner
//***********
// return the (real) name of the owner
string QueryOwner() {
  return owner;
}

//************************
// short and long handling
//************************
int setname(string str) {
  if (!str) {
    write("Use: setname <short description>\n");
    return 1;
  }
  write("Old short description:\n"+QueryIntShort()+"\n");
  SetIntShort(CAP(str));
  write("New short description:\n"+QueryIntShort()+"\n");
  saveme();
  return 1;
}

//***************
// light handling
//***************
int setlight(string str) {
  mixed level;
  if (!str) {
    write("Lightlevel: "+QueryIntLight()+"\n"
      "To set the (absolute) lightlevel use:\n"
      "  setlight <level>\n"
      "level has to be a number (-1000 ... 1000) !\n");
    return 1;
  }
  level=atoi(str);
  if (!intp(level)) {
    write("Use a number as light-level!\n"
      "Example:\nsetlight 10\nsetlight 345\nsetlight -10\nsetlight -56\n");
    return 1;
  }
  write("Old lightlevel: "+QueryIntLight()+
    "\nNew lightlevel: "+level+"\n");
  SetIntLight(level);
  saveme();                                         // stores the settings!
  return 1;
}

//********************************
// handling for the show function:
//********************************

//************
// printowners
//************
// return string for output
string printowners() {
  string ret;
  int i;
  ret="Owner:      "+CAP(owner)+"\n";
  if (sizeof(coowner)>0) ret+="Coowner:    "+CAP(coowner[i]);
  for (i=1;i<sizeof(coowner);i++) {
    ret+=", "+CAP(coowner[i]);
  }
  if (sizeof(coowner)>0) ret+="\n";
  return ret;
}

//***********
// printexits
//***********
// return string for output
string printexits() {
  string ret;
  mapping exits;
  string *plain;
  int i;
  exits=QueryExits();
  if (sizeof(exits)) {
    plain=m_indices(exits);
    ret="Exits:      ";
    ret+=plain[i]+ " - "+exits[plain[0]]+" - ";
    if (exits[plain[0],3]!=0) ret+="hidden\n";
    else ret+="visible\n";
    for (i=1;i<sizeof(plain);i++) {
      ret+="            "+plain[i]+ " - "+exits[plain[i]]+" - ";
      if (exits[plain[i],3]!=0) ret+="hidden\n";
      else ret+="visible\n";
    }
    return ret;
  }
  ret="Exits:      none\n";
  return ret;
}

//***********
// orintdoors
//***********
string printdoors() {
  string ret;
  ret="Doors:      actually not supported\n";
  return ret;
}

//*************
// printdetails
//*************
// return string for output
// no use of vitems actually :(
// TODO: add support for vitems!
string printdetails() {
  string ret;
  int i;
  mapping details;
  string *idx;
  details=QueryDetails();
  if (!sizeof(details)) {
    ret="Details:    none\n";
    return ret;
  }
  idx=m_indices(details);
  ret="Details:    "+idx[0]+"\n";
  for (i=1;i<sizeof(idx);i++) {
    ret+="            "+idx[i]+"\n";
  }
  return ret;
}

//**************
// printnoises()
//**************
// return string for output
string printnoises() {
  string ret;
  int i;
  mapping noise;
  string *idx;
  if (QueryIntNoise()) ret="IntNoise:   "+QueryIntNoise();
  else ret="IntNoise:   none\n";
  noise=QueryNoises();
  if (sizeof(noise)) {
    idx=m_indices(noise);
    ret+="Noises:     ";
    ret+=idx[i]+ " - "+noise[idx[0]];
    for (i=1;i<sizeof(idx);i++) {
      ret+="            "+idx[i]+ " - "+noise[idx[i]];
    }
  }
  return ret;
}

//************
// printsmells
//************
// return string for output
string printsmells() {
  string ret;
  int i;
  mapping smell;
  string *idx;
  if (QueryIntSmell()) ret="IntSmell:   "+QueryIntSmell();
  else ret="IntSmell:   none\n";
  smell=QuerySmells();
  if (sizeof(smell)) {
    idx=m_indices(smell);
    ret+="Smells:     ";
    ret+=idx[i]+ " - "+smell[idx[0]];
    for (i=1;i<sizeof(idx);i++) {
      ret+="            "+idx[i]+ " - "+smell[idx[i]];
    }
  }
  return ret;
}

//***********
// printitems
//***********
// return string for output
string printitems() {
  string ret,short;
  int i;
  mixed items;
  string *idx;
  items=QueryItems();
  if (!sizeof(items)) {
    ret="Items:      none\n";
    return ret;
  }
  short=items[0][0]->QueryShort();        // don't show invis items!
  if (short) ret="Items:      "+CAP(short)+"\n";
  for (i=1;i<sizeof(items);i++) {
    short=items[i][0]->QueryShort();
    if (ret && short) ret+="            "+CAP(short)+"\n";
    else if (short) ret="            "+CAP(short)+"\n";
  }
  if (!ret) ret="Items:      none\n";
  return ret;
}

//***********
// printreads
//***********
// return string for output
string printreads() {
  string ret;
  int i;
  mapping reads;
  string *idx;
  reads=QueryReadMsgs();
  if (sizeof(reads)==0) {
    ret="ReadMsgs:   none\n";
    return ret;
  }
  idx=m_indices(reads);
  ret="ReadMsgs:   "+idx[0]+"\n";
  for (i=1;i<sizeof(idx);i++) {
    ret+="            "+idx[i]+"\n";
  }
  return ret;
}

//***********
// printlight
//***********
// return string for output
string printlight() {
  return "Lightlevel: "+itoa(QueryIntLight())+"\n";
}

//*****
// show
//*****
// owner and coowner can get all informations about the room
int show(string str) {
  string infos;
  int i;
  if (!Allowed(TP,1)) return 0;
  if (!str) {
    write("Use:\n"
      "  show owners   - prints the owners and the coowners\n"
      "  show exits    - prints the exits (the hidden too)\n"
      "  show doors    - prints the doors (and locks)\n"
      "  show details  - prints all details\n"
      "  show noises   - prints the noises\n"
      "  show smells   - prints the smells\n"
      "  show read     - prints the read messages\n"
      "  show items    - prints the items (cloned by the room)\n"
      "  show light    - prints the light level\n"
      "  show all      - prints all of the above\n");
    return 1;
  }
  switch (str) {
    case "owners":
      infos=printowners();
      break;
    case "exits":
      infos=printexits();
      break;
    case "doors":
      infos=printdoors();
      break;
    case "details":
      infos=printdetails();
      break;
    case "noises":
      infos=printnoises();
      break;
    case "smells":
      infos=printsmells();
      break;
    case "read":
      infos=printreads();
      break;
    case "items":
      infos=printitems();
      break;
    case "light":
      infos=printlight();
      break;
    case "all":
      infos=printowners();
      infos+=printexits();
      infos+=printdoors();
      infos+=printdetails();
      infos+=printnoises();
      infos+=printsmells();
      infos+=printreads();
      infos+=printitems();
      infos+=printlight();
      break;
    default:
      infos=
        "This one is not implemented. Try 'show' alone or use 'show all'.\n";
  }
  smore(infos); 
  return 1;
}

//*******
// loadme
//*******
// loads all needed elements of the room (exits,doors,details,vitems,items)
int loadme() {
  restore_object(object_name());
  SetExits(house_exits);
  SetDetails(house_details);
  SetItems(house_items);               // problems during reset!
  SetVItems(house_vitems);
  Set(P_VITEM_COUNTER,house_vitemcounter);
  SetDoors(house_doors);
  house_exits=0;
  house_details=0;
  house_items=0;
  house_vitems=0;
  house_doors=0;
  return 1;
}

//*******
// saveme
//*******
// saves all elements of the room
int saveme() {
  house_exits=QueryExits();
  house_details=QueryDetails();
  house_items=QueryItems();
  house_vitems=QueryVItems();
  house_doors=QueryDoors();
  house_vitemcounter=Query(P_VITEM_COUNTER);
  save_object(object_name());
  house_exits=0;
  house_details=0;
  house_items=0;
  house_vitems=0;
  house_doors=0;
  return 1;
}

//************
// allow_enter
//************
// enable or forbid other people the entry to the house
allow_enter() {
  string rname;
  object o;
  if (!living(PO)) return ME_OK;                // no living objects can enter
  rname=PO->QueryRealName();
  if (rname==owner) return ME_OK;               // owner can enter
  if (member(coowner,rname)!=-1) return ME_OK;  // co-owner can enter
  if (member(allowed,"all")!=-1) return ME_OK;  // all can enter
  if (member(allowed,rname)!=-1) return ME_OK;  // player can enter
  o=find_living(owner);
  if (o) tell_object(o,CAP(rname)+" wants to enter your house.\n");
  return ME_NO_ENTER;
}

