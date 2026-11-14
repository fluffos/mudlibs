// testobject for restore_object and save_object

#include <properties.h>
#include <rooms.h>

inherit "/std/room";

mapping house_details;
mapping house_exits;
mixed   *house_items;
mapping house_doors;
mapping house_vitems;
int house_vitemcounter;

create() {
  ::create();
  SetIntShort("Test");
  SetIntLong("Test room:\n"
    "  loadme - loads the variables\n"
    "  saveme - saves them\n"
  );
  AddRoomCmd("loadme","loadme");
  AddRoomCmd("saveme","saveme");

  // two details for testing:
  AddDetail("blupp","A test blupp");
  AddDetail("table","A test table");

  // and items:
  AddItem("/obj/torch",REFRESH_REMOVE);
  AddItem("/std/weapon",REFRESH_REMOVE);

  // two dummy exits for testing:
  AddExit("north","/d/dummy/north");
  AddExit("west","/d/dummy/west");
}

int loadme() {
  restore_object("/p/houses/rooms/check");
  SetExits(house_exits);
  SetDetails(house_details);
  SetItems(house_items);
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

int saveme() {
  house_exits=QueryExits();
  house_details=QueryDetails();
  house_items=QueryItems();
  house_vitems=QueryVItems();
  house_doors=QueryDoors();
  house_vitemcounter=Query(P_VITEM_COUNTER);
  save_object("/p/houses/rooms/check");
  house_exits=0;
  house_details=0;
  house_items=0;
  house_vitems=0;
  house_doors=0;
  return 1;
}

