/* The garden of Joan */
inherit "/p/houses/common/room/meadow";
varargs void create() {
  ::create();
  SetIntShort("in the garden of Joan and Mistral");
  SetIntLong("You are standing in the garden of Joan and Mistral.\n\
You can leave it to the north.\n\
To the south Joan and Mistral are building a house.\n\
To the west and east you can go deeper into the garden.\n\
But maybe you can search for herbs in this garden?\n");
  AddExit("north","/d/silvere/rooms/east/mainroad1");
  AddExit("south","./011");
  AddExit("west","./garden2");
  AddExit("east","./garden8");
//  AddHerb("/d/avalon/common/obj/fruits/dandilion",2);
}

void init()
{
  ::init();
//  call_other("/players/mistral/house/001","???");
  call_other("/d/silvere/rooms/east/mistralhouse/001","???");
}
