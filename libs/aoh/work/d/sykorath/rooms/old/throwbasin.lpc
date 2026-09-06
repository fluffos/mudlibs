// part of the town
// made by magictcs - 23 jun 97

// TODO: add exits
// TODO: make more than wet feet if you enter the fountain
// TODO: check money handling
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <money.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;
inherit MONEY_LIB;

int box;

//*********************
// enter basin,fountain
//*********************
int enter(string str) {
  if (!str) return 0;
  if (member(({"basin","small basin","fountain","little fountain"}),
    str)!=-1) {
    write("As you enter the "+str+", you got wet feet.\n");
    return 1;
  }
  return 0;
}

//***********************
// throw money into basin
//***********************
void acid(object obj) {
  tell_room(TO,
    "Uhh what's this? The water is like acid for "+obj->QueryShort()+".\n"+
    CAP(obj->QueryShort())+" vanishes.\n");
  obj->remove();                           // the water destructs the item
}

int throw(string str) {
  string *exp;
  object obj;
  notify_fail("Throw what into basin?\n");
  if (!str) return 0;
  exp=explode(str," into ");              // search for 'into'
  if (sizeof(exp)!=2) return 0;
  obj=TP->Search(exp[0],SEARCH_INV|SM_OBJECT);
  if (!obj) return 0;
  if (!obj->id("money")) {
    write("You throw "+obj->QueryShort()+" into the basin.\n"
      "You hear a loud 'Platsch' as "+obj->QueryShort()+" hits the water.\n");
    call_out("acid",2,obj);
    show(NAME+" throws something into the basin.\n"
      "You hear a loud 'Platsch'.\n");
  } else {
    write("You throw some money into the basin.\n");
    show(NAME+" throws some money into the basin.\n");
//    MONEY_LIB->PayValue(TP,1,({"copper"}));
    return 1;
  }
  return 1;
}

//************
// drink water
//************
int drink(string str) {
  string norm;
  int drink;
  notify_fail("You can drink water from basin.\n");
  if (!str) return 0;
  norm=norm_id(str);
  if (str=="water from basin" || str=="water from little basin") {
    drink=TP->QueryDrink();
    if (TP->QueryMaxDrink()<=drink) {
      write("You can't drink anymore!\n");
      say(NAME+" tries to drink water from basin, but fails.\n");
      return 1;
    }
    drink+=10;
    if (drink>=TP->QueryMaxDrink()) drink=TP->QueryMaxDrink();
    TP->SetDrink(drink);
    write("You drink some water from the basin.\n");
    say(NAME+" drinks some water from basin.\n");
    return 1;
  }
  return 0;
}

//******************************
// get/take something from basin
//******************************
int gettake(string str) {
  object obj;
  if (!str) return 0;
  if (present(str)) return 0;              // allow get item
  if (member(({"money"}),str)!=-1) {

  }
  if (member(({"box","black box","box from basin","black box from basin",
    "box from little basin","black box from little basin"}),str)!=-1) {
    if (box) {
      obj=clone_object(OBJ("bbox"));    
      TP->Take(obj,PUTGET_FULL);
      box--;
      return 1;
    }
  }
  return 0;
}

//******************************
// drop/put something into basin
//******************************
int putdrop(string str) {
  string *exp;
  object obj;
  if (!str) return 0;
  exp=explode(str," into ");              // search for 'into'
  if (sizeof(exp)!=2) return 0;
  obj=TP->Search(exp[0],SEARCH_INV|SM_OBJECT);
  if (!obj) return 0;
  if (!obj->id("money")) {
    write("You can throw it into the basin.\n");
  }
  return 1;
}

//**************
// search basin
//**************
int search(string str) {
  notify_fail("You found nothing.\n");
  if (!str) return 0;
  if (member(({"basin","little basin","marble basin"}),str)!=-1) {
    if (box) {
      write(
      "You search the little basin and find a black box.\nYou can get it!\n");
    } else {
      write(
      "You search the little basin but find only some copper coins.\n");
    }
    show(NAME+" searches the basin");
    return 1;
  }
  if (member(({"water","blue water"}),str)!=-1) {
    write(
     "You search the blue water of the basin. But you see only some copper\n"
     "coins lying there on the ground of the basin.\n"
     "Btw. you got wet hands.\n");
    show(NAME+" searches the water.\n");
    return 1;
  }
  return 0;
}

//***************
// detailhandling
//***************
string lookbox() {
  if (box) return "A black box. You can get it.\n";
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  box=1;
  SetIntShort("A small basin");
  SetIntLong(
    "You are standing near a little basin with a some water in it.\n"
    "You see the sky mirroring in the blue water.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail("sky","The sky is mirrored by the water.\n");
  AddDetail(({"basin","little basin"}),
    "The basin is made of white marble. It has some blue water in it and\n"
    "you see something blinking on the ground below the water.\n");
  AddDetail(({"water","blue water"}),
    "The water looks drinkable. Something is glittering below the water.\n");
  AddDetail("something","Maybe you can search the basin?\n");

  AddDetail(({"box","black box"}),#'lookbox);

  /* commands */
  AddRoomCmd("enter",#'enter);
  AddRoomCmd("drink",#'drink);
  AddRoomCmd("throw",#'throw);
  AddRoomCmd("search",#'search);
  AddRoomCmd("get",#'gettake);
  AddRoomCmd("take",#'gettake);
  AddRoomCmd("put",#'putdrop);
  AddRoomCmd("drop",#'putdrop);

  /* exits */
  AddExit();
}

reset() {
  ::reset();
  box=1;
}
