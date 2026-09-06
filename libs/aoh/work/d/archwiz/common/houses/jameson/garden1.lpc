/* The garden of Jameson */
inherit "/d/avalon/common/std/meadow";
create() {
  ::create();
  SetIntShort("in the garden of Jameson");
  SetIntLong("You are standing in the garden of Jameson.\n\
You can leave it to the east.\n\
To the west Jameson is building a house.\n\
To the north and south you can go deeper into the garden.\n\
But maybe you can search for herbs in this garden?\n");
  AddExit("east","/d/archwiz/common/room/city/eastroad2");
  AddExit("west","./121");
  AddExit("north","./garden2");
  AddExit("south","./garden8");
  AddHerb("/d/avalon/common/obj/fruits/dandilion",2);
}

init()
{
  ::init();
  call_other("/d/archwiz/common/houses/jameson/121","???");
}
